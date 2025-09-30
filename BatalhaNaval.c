#include <stdio.h>

void imprimematrix (int tabuleiro[10][10]){
    int lin = 1; char col = 'A';
    
    printf("\n    ");
    for(int i = 0; i < 10; i++){
        printf("%c  ", col);
        col++;
    }
    for (int i = 0; i < 10; i++){
        //rótulos das linhas
        if(lin < 10){
            printf("\n%2.d  ", lin);
        } else{
        printf("\n%d  ", lin);
        }
        lin++;
        //impressão dos dados
        for (int j = 0; j < 10; j++){
            printf("%d  ", tabuleiro[i][j]);
        }
        }
        printf("\n\n");
}
void posicionanavio(int coord[3], int tabuleiro[10][10]){
	int navio[3] = {3, 3, 3};
	for(int i = 0; i < 3; i++){
        //executa esse bloco caso o navio for ser inserido na vertical.
    	if(coord[2] == 0){
            //se a coordenada já estiver ocupada (diferente de zero) alerta que os navios estão sobrepondo-se, encerra o loop e muda a variável de controle end para 1.
            if(tabuleiro[coord[0]][coord[1]] !=0 || coord[0] > 9 || coord[1] > 9){
                printf("ATENÇÃO!! Os navios estão se sobrepondo ou estão sendo colocados fora do tabuleiro.\n");
                break;
            } else{
                tabuleiro[coord[0]][coord[1]] = navio[i];
			    coord[0]++;
            }		
        //executa esse bloco caso o navio for ser inserido na horizontal.    	
		} else if(coord[2] == 1){
            //se a coordenada já estiver ocupada (diferente de zero) alerta que os navios estão sobrepondo-se, encerra o loop e muda a variável de controle end para 1.
            if(tabuleiro[coord[0]][coord[1]] != 0 || coord[0] > 9 || coord[1] > 9){
                printf("ATENÇÃO!! Os navios estão se sobrepondo ou estão sendo colocados fora do tabuleiro.\n");
                break;
            } else {
                tabuleiro[coord[0]][coord[1]] = navio[i];
			    coord[1]++;
            }
        //executa esse bloco caso o navio for ser inserido na diagonal. 
    	}else if(coord[2] == 2){
            //se a coordenada já estiver ocupada (diferente de zero) alerta que os navios estão sobrepondo-se, encerra o loop e muda a variável de controle end para 1.
            if(tabuleiro[coord[0]][coord[1]] != 0 || coord[0] > 9 || coord[1] > 9){
                printf("ATENÇÃO!! Os navios estão se sobrepondo ou estão sendo colocados fora do tabuleiro.\n");
                break;
            } else {
                tabuleiro[coord[0]][coord[1]] = navio[i];
                coord[0]++;
			    coord[1]++;
			}
		//este bloco é executado somente quando os elementos da posição 2 das variáveis coord1 e coord2 não forem nem 0 (vertical), nem 1 (horizontal) e nem 2 (diagonal).
		} else{
			printf("Direção invalida!\n\n");
			break;
		}
	}
}

int main(){

    //Nos vetores coord1 e coord2 primeiro e o segundo valor são respectivamente a linha e a coluna onde começa o navio.
    //O terceiro valor é referente o posicionamento (0 para vertical e 1 para horizontal)
    int tabuleiro[10][10];
    int coord1[3] = {1, 1, 0};
    int coord2[3] = {10, 6, 1};
    int coord3[3] = {2, 7, 2};
    int coord4[3] = {6, 1, 2};
    
    //inicialização da matriz tabuleiro
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }
    imprimematrix(tabuleiro);

    //posicionando o primeiro navio.
    posicionanavio(coord1, tabuleiro);

	//posicionando o segundo navio.
	posicionanavio(coord2, tabuleiro);

    //posicionando o terceiro navio.
	posicionanavio(coord3, tabuleiro);

    //posicionando o quarto navio.
	posicionanavio(coord4, tabuleiro);

    imprimematrix(tabuleiro);
    return 0;
}