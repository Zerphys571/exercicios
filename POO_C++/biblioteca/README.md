# 📚 Sistema de Gerenciamento de Biblioteca em C++

Um projeto prático desenvolvido em C++ no terminal para consolidar conhecimentos em Programação Orientada a Objetos (POO). 

## 🎯 Objetivo
Criar um sistema interativo que simule o funcionamento básico de uma biblioteca, gerenciando o acervo de itens, o cadastro de usuários e as operações de empréstimo e devolução.

## 🚀 Funcionalidades Principais
* **Gerenciamento de Acervo:** Adicionar, listar e remover itens (como livros e revistas).
* **Gerenciamento de Usuários:** Cadastrar novos leitores no sistema.
* **Sistema de Empréstimos:** * Permitir que um usuário pegue um item emprestado (caso esteja disponível).
  * Registrar a devolução de um item, tornando-o disponível novamente.
* **Busca:** Procurar itens específicos por título ou autor.

## 🧠 Conceitos de POO Aplicados
Durante o desenvolvimento deste projeto, os seguintes pilares serão aplicados:
1. **Abstração & Classes:** Modelagem de entidades do mundo real (`Livro`, `Usuario`, `Biblioteca`) para o sistema.
2. **Encapsulamento:** Proteção do estado interno dos objetos (ex: impedir que o status de um livro mude para "emprestado" sem passar pela validação correta).
3. **Herança:** Criação de uma hierarquia para o acervo (ex: uma classe base `Item` e classes derivadas como `Livro` e `Revista`).
4. **Composição:** A classe `Biblioteca` gerenciando coleções de `Usuarios` e `Itens`.

## 🗺️ Estrutura Planejada (Entidades)
* `Item` (Base)
* `Livro` (Derivado)
* `Usuario`
* `Biblioteca` (Gerenciador central)

---
*Projeto desenvolvido com foco em aprendizado e boas práticas de C++.*
