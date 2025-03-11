#include <stdio.h>

int main() {
    //criaçao do tabuleiro
    char tabuleiro[10][10] = {0};

    //criacao dos navios
    int linha1 = 4, coluna1 = 1; //navio horizontal
    int linha2 = 4, coluna2 = 6; //navio vertical
    int linha3 = 0, coluna3 = 0; //navio diagonal primaria
    int linha4 = 7, coluna4 = 2; //navio diagonal secundaria

    //verificando se o navio cabe no tabuleiro e colocando no tabuleiro
    if((coluna1 + 3 ) <= 9){
        for(int i = 0; i < 3; i++){
            tabuleiro[linha1][coluna1 + i] = tabuleiro[linha1][coluna1 + i] +3;
        }
    }else{
        printf("Erro no navio horizontal \n");
    }
    if((linha2 + 3) <= 9){
        for(int i = 0; i < 3; i++){
            tabuleiro[linha2 + i][coluna2] = tabuleiro[linha2 + i][coluna2] +3;
        }        
    }else{
        printf("Erro no navio vertical \n");
    }
    if(((coluna3 + 3) <= 9) && ((linha3 + 3) <= 9)){
            for(int i =  0; i < 3; i++){
                tabuleiro[linha3 + i][coluna3 + i] = tabuleiro[linha3 + i][coluna3 + i] +3;
            }
    }else{
        printf("Erro no navio da digonal principal \n");
    }
    if(((coluna4 - 2) >= 0) && ((linha4 - 2) >= 0) ){
        for(int i = 0; i < 3; i++){
            tabuleiro[linha4 + i][coluna4 - i] = tabuleiro[linha4 + i][coluna4 - i] +3;
        }
    }else{
        printf("Erro no navio da diagonal secundaria \n");
    }

    //checando se nao ha navios sobrepostos
    for(int i = 0; i < 10; i++){
        for(int j = 0;j < 10; j++){
            if(tabuleiro[i][j] == 6){
                printf("Navios sobrepostos \n");
            }
        }
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