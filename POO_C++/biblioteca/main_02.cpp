#include <iostream>
#include <string>
#include "biblioteca.hpp"


int
main(void)
{   
    Biblioteca sistema;
    string nome, id;
    int i = 3;

    while(true)
    {
        nome = lerLinha("Digite o nome: ");
        id = lerInt("Digite o id: ");

        Item item(nome, id);

        if(i == 3)
        {
            break;
        }
    }



    return EXIT_SUCCESS;
}