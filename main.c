#include <stdio.h>
#include <string.h>
#include "funcoes.h"

// JOGO DA FORCA
char *escolhePalavra (char [], char[]);

int main () {
    char palavra[50], tentativa[50], copiaPalavra[50], escolha[50];
    int i, fim = 0, encontrei;
    int n_tentativas = 0, limite_tentativas, corretas = 0;
    char chute, c;

    // busca uma palavra
    strcpy(palavra, escolhePalavra("palavras.txt", escolha));
    strcpy (copiaPalavra, palavra);

    // define o limite de tentativas
    limite_tentativas = strlen (palavra) * 1.5;

    // armazena string com espaços com tamanho da palavra sorteada
    for (i = 0; i < strlen(palavra); i++)
        tentativa[i] = ' ';

    do {
        // apresenta cabeçalho do jogo
        system("cls");
        printf("\n     FORCA EM C\n");
        printf("_____________________________\n\n\n");

        // apresenta letras já encontradas
        for (i = 0; i < strlen(palavra); i++)
            printf(" %c  ", tentativa[i]);
        printf("\n");

        // apresentar posições para letras
        for (i = 0; i < strlen(palavra); i++)
            printf("___ ");
        printf("\n");

        // Adiciona número de tentativas e quantas estão corretas
        printf("\n\n\n________________________________\n\n\n");
        printf("Restantes: %d\n", limite_tentativas - n_tentativas);
        printf("Corretas: %d\n", corretas);
        printf("\n\n\n________________________________\n\n\n");


        // ******** RESPOSTAS DO JOGADOR *********
        // le respostas do jogador

        printf("\n\n\nEntre com uma letra (ou * para encerrar) + <enter>: ");
        scanf ("%c", &chute);
        scanf("%c", &c);

        // Testa-se a letra informada encontra-se na palavra escolhida
        encontrei = 0;
        for (i=0; i<strlen(palavra); i++)
            if (toupper(copiaPalavra[i]) == toupper(chute)) {
                    copiaPalavra[i]= '*';
                    tentativa[i] = toupper(chute);
                    corretas ++;
        }

        if (encontrei == 0)
            n_tentativas++;

        if (n_tentativas >= limite_tentativas || corretas >= strlen(palavra) || chute == '*')
            fim = 1;


    } while (fim == 0);

    system("cls");

    // Mensagem de conclusão do jogo
    if (n_tentativas >= limite_tentativas) {
        printf("*** Que pena! Tente novamente. ***");
        printf("A palavra era: >>> %s <<<\n\n", palavra);
    } else if ( chute != '*') {
        printf("\n**** PARABÉNS!****\n");
        printf(" Voce acertou a palavra: %s\n", palavra);
    }


    return 0;
}

char *escolhePalavra(char nomeArquivo[], char escolha[]) {
    char linha[100] [50];
    int contador = 0, i;
    FILE *arq;

    // Abre o arquivo
    if ((arq = fopen("palavras.txt", "r")) == NULL)
        puts("Erro na abertura do arquivo!\n\n");
    else {
        do {
            // Lê linha do arquivo
            fgets(escolha, 50, arq);

            // Retira as quebras esxtras de linhas
            for (i = 0; i < strlen(escolha); i++)
                if (escolha[i] == '\n')
                    escolha[i] = '\0';

            // Testa se string não está vazia e armazena no vetor
            if (strcmp(escolha, "")) {
                strcpy(linha[contador], escolha);
                contador++;
            }
        } while (!feof(arq));
    }

    // Sorteia uma palavra pelo indice
    srand(time(NULL));
    i = rand() % contador + 1;

    strcpy(escolha, linha[i]);
    return escolha;

}
