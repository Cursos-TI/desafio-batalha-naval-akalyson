#include <stdio.h>

int main() {
    //criaçao do tabuleiro
    char tabuleiro[10][10] = {0};

    //criacao dos navios
    int linha1 = 2, coluna1 = 1;
    int linha2 = 4, coluna2 = 6;

    //verificando se o navio cabe no tabuleiro e colocando no tabuleiro
    if((coluna1 + 3 )< 9){
        for(int i = 0; i < 3; i++){
            tabuleiro[linha1][coluna1 + i] = 3;
        }
    }else{
        printf("Erro no navio horizontal \n");
    }
    if((linha2 + 3) < 9){
        for(int i = 0; i < 3; i++){
            tabuleiro[linha2 + i][coluna2] = 3;
        }        
    }else{
        printf("Erro no navio vertical \n");
    }

    //imprimindo tabuleiro
    printf("  A B C D E F G H I J\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", (i + 1) % 10);
        for(int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}