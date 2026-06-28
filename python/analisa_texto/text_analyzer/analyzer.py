def contarPalavras(texto, stop_words):

    resultado = {}

    copia_texto = texto.lower()
    
    copia_texto = copia_texto.replace(",", "").replace(".", "")

    copia_texto = copia_texto.split()

    for palavra in copia_texto:
        if palavra in stop_words:
            continue

        else:
            if palavra in resultado:
                resultado[palavra] += 1
            else:
                resultado[palavra] = 1
                
    return resultado