import json

"""
Função para entrada do texto
"""
def receberTexto():
	texto = input("Digite um texto: ")

	return texto


"""
Função para exibir o resultado da contagem
"""
def exibirResultado(dicionario_palavras):
	print("\n--- Resultado da Análise ---\n")

	dicionario_palavras = dict(sorted(dicionario_palavras.items(), key=lambda item : item[1], reverse=True))

	for palavra, valor in dicionario_palavras.items():
		print(palavra, valor)

"""
Função para salvar o arquivo json na pasta Data
"""
def salvarArquivo(dicionario, caminho):

	print(f"\nSalvando dados em {caminho}...\n")

	caminho.parent.mkdir(parents=True, exist_ok=True)


	with open(caminho, 'w', encoding='utf-8') as arquivo:
		json.dump(dicionario, arquivo, ensure_ascii=False)
