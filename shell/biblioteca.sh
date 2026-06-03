#!/bin/bash

# ==============================================================================
# AUTOR: Luis Guilherme Viana Camargo
# ==============================================================================
# ------------------------------------------------------------------------------
# ==============================================================================
# BIBLIOTECA SHELL SCRIPT -- GERENCIADOR DE WALLPAPER
# Descrição: Armazena todas as funções necessárias para o SCRIPT
# ==============================================================================


verificar_pastas(){
    local $imagens =  $1
    local $videos  =  $2

    [[ ! -d "${imagens}"]] && mkdir -p "${imagens}"
    [[ ! -d "${videos}" ]] && mkdir -p "${videos}"
}
criacao_log() {
    local STATUS="$1"
    local NOME_SCRIPT=$(basename "$0")
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] [$NOME_SCRIPT] $STATUS: ${PATH_WALLPAPER}" >>"${ARQUIVO_LOG}"
}
template_video(){
    local FRAME_TEMP=/tmp/frame_wallust.jpg
    ffmpeg -i "${PATH_WALLPAPER}" -vframes 1 -q:v 2 -y "${FRAME_TEMP}" &>/dev/null
    wallust -run "${PATH_WALLPAPER}" && pkill nwg-wrapper
    killall -SIGUSR2 waybar &
}
verificar_dependencias(){
    for cmd in mpv mpvpaper awww nwg-wrapper wallust waybar ffmpeg waypaper
}
