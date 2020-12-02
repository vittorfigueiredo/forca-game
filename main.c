#include "funcoes.h"

// JOGO DA FORCA

int main() {
    ortografia();
    int opcao = 1;

    do {
        system("cls");
        printf("_____________________\n\n");
        printf("     FORCA EM C\n");
        printf("_____________________\n\n");
        printf("1 - JOGAR\n");
        printf("2 - VER RANKING\n");
        printf("3 - CADASTRAR PALAVRAS\n");
        printf("4 - CRÉDITOS\n");
        printf("5 - SAIR");
        printf("\n\nSelecione: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                selecModo();
                break;

            //case 2:
                //verRanking();
                //break;

            case 3:
                cadastrarPalavra();
                break;

            case 4:
                creditos();
                break;

            case 5:
                system("cls || clear");
                printf("\n\nSaindo...\n\n");
                exit(0); // Função para fechar o programa;

            default:
                printf("Escolha uma opção válida!");
                break;
        }

    }   while (opcao != 5);

    return 0;
}
