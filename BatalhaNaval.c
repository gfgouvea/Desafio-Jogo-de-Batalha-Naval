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
    int coord1[3] = {4, 4, 0}; //primeiro valor é a linha onde começa o navio, o segundo é a coluna onde começa o navio e o terceiro valor é 0 para vertica e 1 para horizontal
    int coord2[3] = {4, 6, 1};

    //posicionando o primeiro navio.
    for(int i = 0; i < 3; i++){
    	if(coord1[2] == 0){
			tabuleiro [coord1[0]][coord1[1]] = navio1[i];
			coord1[0]++;
		} else if(coord1[2] == 1){
			tabuleiro [coord1[0]][coord1[1]] = navio1[i];
			coord1[1]++;
		} else{
			printf("Direção invalida!\n\n");
			break;
		}
	}
	//posicionando o segundo navio.
	for(int i = 0; i < 3; i++){
    	if(coord2[2] == 0){
			tabuleiro [coord2[0]][coord2[1]] = navio2[i];
			coord2[0]++;
		} else if(coord2[2] == 1){
			tabuleiro [coord2[0]][coord2[1]] = navio2[i];
			coord2[1]++;
		} else{
			printf("Direção invalida!\n\n");
			break;
		}
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