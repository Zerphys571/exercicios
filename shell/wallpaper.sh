#!/bin/bash

# ==============================================================================
# SCRIPT DE GERENCIAMENTO DE WALLPAPER (Imagens e Vídeos)
# Descrição: Altera o fundo de tela usando mpvpaper (vídeo) ou awww (imagem).
# ==============================================================================

# --- Verificação e Criação de Pastas Base ---
[[ ! -d "${HOME}/Imagens/Wallpapers" ]] && mkdir -p "${HOME}/Imagens/Wallpapers"
[[ ! -d "${HOME}/Imagens/videos" ]] && mkdir -p "${HOME}/Imagens/videos"

# --- Configuração de Caminhos ---
DIR_WALLPAPER="${HOME}/Imagens/Wallpapers"
DIR_LOG="${HOME}/.logs"
ARQUIVO_LOG="${DIR_LOG}/wallpaper.log"
SCRIPT_RELOGIO="${HOME}/custom/scripts/data.sh"
CSS_RELOGIO="${HOME}/custom/css/relogio.css"

# --- Definição de Cores e Estética ---
RED="\e[31m"
GREEN="\e[32m"
YELLOW="\x1b[33m"
RESET="\e[0m"
# --- Parâmetros de Transição (awww) ---
TRANS_TYPE="wipe"
FPS="60"
STEP="90"
TRANS_DURATION="3"
ANGULO_POSSIVEIS=(0 45 90 135 180 225 270 315)

# ==============================================================================
# FUNÇÕES AUXILIARES
# ==============================================================================

# Função para registro de atividades
criacao_log() {
    local STATUS="$1"
    local NOME_SCRIPT=$(basename "$0")
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] [$NOME_SCRIPT] $STATUS: ${PATH_WALLPAPER}" >>"${ARQUIVO_LOG}"
}
template_video() {
    local FRAME_TEMP="/tmp/frame_wallust.jpg"
    ffmpeg -i "${PATH_WALLPAPER}" -vframes 1 -q:v 2 -y "${FRAME_TEMP}" &>/dev/null
    wallust run "${FRAME_TEMP}" && pkill nwg-wrapper
    nwg-wrapper -s "${SCRIPT_RELOGIO}" -c "${CSS_RELOGIO}" -p center -r 1000 &

    killall -SIGUSR2 waybar &
}
verificar_dependencias(){
    for cmd in mpvpaper awww ffmpeg wallust waybar; do
        if ! command -v $cmd >/dev/null; then
            echo -e "${RED}Erro: $cmd não instalado.${RESET}"
            exit 1
        fi
    done
}
# --- Preparação do Ambiente ---
#Cria a pasta dos LOG
mkdir -p "${DIR_LOG}"

# ==============================================================================
# 1. VERIFICAÇÃO DE DEPENDÊNCIAS
# ==============================================================================

verificar_dependencias

# ==============================================================================
# 2. LÓGICA DE ENTRADA
# ==============================================================================

if [[ "${1}" == "--help" || "${1}" == "-h" ]]; then
    echo -e "${YELLOW}Uso: wallpaper [opção] ou [caminho]${RESET}"
    echo -e "\nDescrição: Altera o wallpaper da área de trabalho."
    echo -e "\nOpções:"
    echo -e " -h, --help    Mostra esta ajuda"
    exit 0
else
    PATH_WALLPAPER="$1"
    [[ -z "$PATH_WALLPAPER" ]] && exit 1
fi

# ==============================================================================
# 3. EXECUÇÃO E APLICAÇÃO
# ==============================================================================

if [[ -f "$PATH_WALLPAPER" ]]; then
    EXTENSAO="${PATH_WALLPAPER##*.}"
    EXTENSAO="${EXTENSAO,,}"

    pkill mpvpaper
    pkill waypaper
    # Vídeos
    if [[ "$EXTENSAO" == "mp4" || "$EXTENSAO" == "mkv" || "$EXTENSAO" == "webm" ]]; then
        { nohup mpvpaper -o "hwdec=auto no-audio profile=fast framedrop=vo --vf=fade=t=in:st=0:d=1 loop" '*' "${PATH_WALLPAPER}" &>/dev/null && criacao_log "Sucesso (Vídeo)"; } &
        template_video
    # Imagens e GIFs
    elif [[ "$EXTENSAO" == "jpeg" || "$EXTENSAO" == "png" || "$EXTENSAO" == "jpg" || "$EXTENSAO" == "gif" ]]; then
        ANGULO=${ANGULO_POSSIVEIS[$RANDOM % ${#ANGULO_POSSIVEIS[@]}]}

        if awww img "${PATH_WALLPAPER}" \
            --transition-type "${TRANS_TYPE}" \
            --transition-fps "${FPS}" \
            --transition-step "${STEP}" \
            --transition-duration "${TRANS_DURATION}" \
            --transition-angle "${ANGULO}"; then
            wallust run "${PATH_WALLPAPER}" && killall -SIGUSR2 waybar 
            pkill nwg-wrapper; nwg-wrapper -s "${SCRIPT_RELOGIO}" -c "${CSS_RELOGIO}" -p center -r 1000 &
            
            criacao_log "Sucesso (Imagem)"
        else
            echo -e "${RED}Erro na aplicação${RESET}"
            criacao_log "Erro na aplicação"
            exit 1
        fi
    fi
else
    echo -e "${RED}Erro: Arquivo não encontrado.${RESET}"
    exit 1
fi
