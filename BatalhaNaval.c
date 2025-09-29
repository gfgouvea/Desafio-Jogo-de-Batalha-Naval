#include <stdio.h>

int main(){
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int lin = 1;
    char col = 'A';

    //posicionando o primeiro navio na vertical.
    for(int i = 0; i < 3; i++){
        tabuleiro [i+1][1] = navio1[0];
    }

    //posicionando o segundo navio na horiziontal.
    for(int i = 0; i < 3; i++){
        tabuleiro [6][i+6] = navio1[0];
    }
    
    //impressão da matriz
    //rótulos das colunas
    printf("  ");
    for(int i = 0; i < 10; i++){
        printf("  %c", col);
        col++;
    }

    for (int i = 0; i < 10; i++){
        //rótulos das linhas
        if(lin < 10){
            printf("\n0%d  ", lin);
        } else{
        printf("\n%d  ", lin);
        }
        lin++;
        //impressão dos dados
        for (int j = 0; j < 10; j++){
            printf("%d  ", tabuleiro[i][j]);
        }
    }
    printf("\n\n\n");
    
    return 0;
}