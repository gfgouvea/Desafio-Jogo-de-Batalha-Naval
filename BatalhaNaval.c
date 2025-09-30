#include <stdio.h>

int main(){
    int tabuleiro[10][10], lin = 1, end = 0;
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int coord1[3] = {4, 4, 0}; //primeiro valor é a linha onde começa o navio, o segundo é a coluna onde começa o navio e o terceiro valor o posicionamento. 0 para vertical e 1 para horizontal
    int coord2[3] = {3, 3, 1};
    char col = 'A';
    
    //inicialização da matriz tabuleiro
    for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                tabuleiro[i][j] = 0;
            }
        }

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
        //executa esse bloco caso o navio for ser inserido na vertical.
    	if(coord2[2] == 0){
            //se a coordenada já estiver ocupada (diferente de zero) alerta que os navios estão sobrepondo-se, encerra o loop e muda a variável de controle end para 1.
            if(tabuleiro[coord2[0]][coord2[1]] !=0){
                printf("ATENÇÃO!! Os navios estão se sobrepondo.\n\n");
                break;
            } else{
                tabuleiro[coord2[0]][coord2[1]] = navio2[i];
			    coord2[0]++;
            }		
        //executa esse bloco caso o navio for ser inserido na horizontal.    	
		} else if(coord2[2] == 1){
            //se a coordenada já estiver ocupada (diferente de zero) alerta que os navios estão sobrepondo-se, encerra o loop e muda a variável de controle end para 1.
            if(tabuleiro[coord2[0]][coord2[1]] != 0){
                printf("ATENÇÃO!! Os navios estão se sobrepondo.\n\n");
                end = 1;
                break;
            } else {
                tabuleiro[coord2[0]][coord2[1]] = navio2[i];
			    coord2[1]++;
            }
        //este bloco é executado somente quando os elementos da posição 2 das variáveis coord1 e coord2 não forem nem 0 (vertical) e nem 1 (horizontal).
		} else{
			printf("Direção invalida!\n\n");
            end = 1;
			break;
		}
	}
    
    //impressão da matriz
    //rótulos das colunas
    //nas linhas 40 e 50 se o condicional foi verdadeiro a variável de controle end foi setada para 1
    //dessa forma a matriz preenchida não será exibida. Em vez disso mostra a mensagem da linha 89.
    if(end == 0){
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
} else{
    printf("Encerrando o jogo!\n\n");
}
    
    return 0;
}