#include <stdio.h>

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[10][10]) {
    printf("   A B C D E F G H I J \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", (i + 1) % 10);
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para sobrepor a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[10][10], int habilidade[5][5], int x, int y) {
    int inicioX = x - (5 / 2);
    int inicioY = y - (5 / 2);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int posX = inicioX + i;
            int posY = inicioY + j;

            if (posX >= 0 && posX < 10 && posY >= 0 && posY < 10 && habilidade[i][j] == 1) {
                tabuleiro[posX][posY] = 5;  // Marca a área afetada
            }
        }
    }
}

// Matrizes das habilidades
int habilidadeCone[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

int habilidadeCruz[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

int habilidadeOctaedro[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}
};

int main() {
    int tabuleiro[10][10] = {0};

    int linha1 = 4, coluna1 = 1;
    int linha2 = 4, coluna2 = 6;
    int linha3 = 0, coluna3 = 0;
    int linha4 = 7, coluna4 = 2;

    if ((coluna1 + 3) < 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha1][coluna1 + i] = 3;
        }
    } else {
        printf("Erro no navio horizontal \n");
    }

    if ((linha2 + 3) < 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha2 + i][coluna2] = 3;
        }
    } else {
        printf("Erro no navio vertical \n");
    }

    if (((coluna3 + 3) < 10) && ((linha3 + 3) < 10)) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha3 + i][coluna3 + i] = 3;
        }
    } else {
        printf("Erro no navio da diagonal principal \n");
    }

    if (((coluna4 - 2) >= 0) && ((linha4 + 2) < 10)) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha4 + i][coluna4 - i] = 3;
        }
    } else {
        printf("Erro no navio da diagonal secundaria \n");
    }

    aplicarHabilidade(tabuleiro, habilidadeCone, 5, 5);
    aplicarHabilidade(tabuleiro, habilidadeCruz, 3, 3);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 7, 7);

    imprimirTabuleiro(tabuleiro);

    return 0;
}
