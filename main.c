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

        // ******** RESPOSTAS DO JOGADOR *********
        // le respostas do jogador

        printf("Entre com uma letra (ou * para encerrar) + <enter>: ");
        scanf ("%c", &chute);
        scanf("%c", &c);

        // Testa-se a letra informada encontra-se na palavra escolhida
        encontrei = 0;
        for (i=0; i<strlen(palavra); i++)
            if (palavra[i] == chute) {
                tentativa[i] = chute;
                corretas ++;
        }

        if (encontrei == 0)
            n_tentativas++;

        if (n_tentativas >= limite_tentativas || corretas == strlen(palavra) || chute == '*')
            fim = 1;


    } while (fim == 0);




    return 0;
}
