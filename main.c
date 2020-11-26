#include <stdio.h>
#include <string.h>
#include "funcoes.h"

// JOGO DA FORCA

int main () {
    char palavra[50], tentativa[50];
    int i, fim = 0, encontrei;
    int n_tentativas = 0, limite_tentativas, corretas = 0;
    char chute, c;

    // busca uma palavra
    strcpy (palavra, "exemplo");

    // define o limite de tentativas
    limite_tentativas = strlen (palavra) * 1.5;

    // armazena string com espaços com tamanho da palavra sorteada
    for (i = 0; i < strlen(palavra); i++)
        tentativa[i] = ' ';

    do {
        // apresenta cabeçalho do jogo
        system("cls");
        printf("\n      FORCA EM C\n");
        printf("_____________________________\n\n\n");

        // apresenta letras já encontradas
        for (i = 0; i < strlen(palavra); i++)
            printf(" %c  ", tentativa[i]);
        printf("\n");

        // apresentar posições para letras
        for (i = 0; i < strlen(palavra); i++)
            printf("___ ");
        printf("\n");


    } while (fim == 0);




    return 0;
}
