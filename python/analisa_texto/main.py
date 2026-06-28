from text_analyzer.config import STOP_WORDS, OBJ_FILE_PATH
from text_analyzer.analyzer import contarPalavras
from text_analyzer.interface import receberTexto, exibirResultado, salvarArquivo

def executarApp():
	print("\n--- Iniciando analizador de texto ---\n")

	texto = receberTexto()
	
	dados = contarPalavras(texto, STOP_WORDS)

	exibirResultado(dados)

	salvarArquivo(dados, OBJ_FILE_PATH)
	
	print("\n--- Fim do programa ---\n")

if __name__ == "__main__":
	executarApp()
