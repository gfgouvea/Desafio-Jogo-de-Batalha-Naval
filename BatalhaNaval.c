#include <stdio.h>
#include <stdlib.h>

void imprimetabuleiro (int tabuleiro[10][10]){
    
    //rótulos das colunas(A, B, C, D...)
    printf("    ");
    for(int i = 0; i < 10; i++){
        printf("%c  ", i+65); //65 é o código ASCII da letra 'A'.
    }
    //no primeiro for imprimo os rótulos das linhas (1, 2, 3, 4...)
    //dentro do for aninhado imprimo as casas do tabuleiro com os valores passados atravez da chamada da função.
    for (int i = 0; i < 10; i++){
        printf("\n%2.d  ", i+1);
        for (int j = 0; j < 10; j++){
            printf("%d  ", tabuleiro[i][j]);
        }
    }
        printf("\n");
}

void posicionanavio(int coordnavio[3], int tabuleiro[10][10]){
	//inicio um vetor de 3 posições com a identificação do navio.
	int navio[3] = {3, 3, 3};
	
	for(int i = 0; i < 3; i++){
        //executa esse bloco caso o navio for ser inserido na vertical.
    	if(coordnavio[2] == 0){
            //se a coordenada já estiver ocupada (diferente de zero) alerta que os navios estão sobrepondo-se e encerra o loop.
            //caso contrário (else), insere no tabuleiro a coordenada do navio na posição indicada no vetor coordnavio, usando incremento na lina.
            if(tabuleiro[coordnavio[0]][coordnavio[1]] !=0 || coordnavio[0] > 9 || coordnavio[1] > 9){
                printf("ATENÇÃO!! Os navios estão se sobrepondo ou estão sendo colocados fora do tabuleiro.\n\n\n");
				exit(0);
            } else{
                tabuleiro[coordnavio[0]][coordnavio[1]] = navio[i];
			    coordnavio[0]++;
            }		
        //executa esse bloco caso o navio for ser inserido na horizontal.    	
		} else if(coordnavio[2] == 1){
            //se a coordenada já estiver ocupada (diferente de zero) alerta que os navios estão sobrepondo-se e encerra o loop.
            //caso contrário (else), insere no tabuleiro a coordenada do navio na posição indicada no vetor coordnavio, usando incremento na coluna.
            if(tabuleiro[coordnavio[0]][coordnavio[1]] != 0 || coordnavio[0] > 9 || coordnavio[1] > 9){
                printf("ATENÇÃO!! Os navios estão se sobrepondo ou estão sendo colocados fora do tabuleiro.\n\n\n");
				exit(0);
            } else {
                tabuleiro[coordnavio[0]][coordnavio[1]] = navio[i];
			    coordnavio[1]++;
            }
        //executa esse bloco caso o navio for ser inserido na diagonal direita. 
    	}else if(coordnavio[2] == 2){
            //se a coordenada já estiver ocupada (diferente de zero) alerta que os navios estão sobrepondo-se e encerra o loop.
            //caso contrário (else), insere no tabuleiro a coordenada do navio na posição indicada no vetor coordnavio, usando incremento na linha e na coluna.
            if(tabuleiro[coordnavio[0]][coordnavio[1]] != 0 || coordnavio[0] > 9 || coordnavio[1] > 9){
                printf("ATENÇÃO!! Os navios estão se sobrepondo ou estão sendo colocados fora do tabuleiro.\n\n\n");
				exit(0);
            } else {
                tabuleiro[coordnavio[0]][coordnavio[1]] = navio[i];
                coordnavio[0]++;
			    coordnavio[1]++;
			}
		//executa esse bloco caso o navio for ser inserido na diagonal esquerda.	
		} else if(coordnavio[2] == 3){
            //se a coordenada já estiver ocupada (diferente de zero) alerta que os navios estão sobrepondo-se, encerra o loop e muda a variável de controle end para 1.
            //caso contrário (else), insere no tabuleiro a coordenada do navio na posição indicada no vetor coordnavio, usando incremento na linha e decremento na coluna.
            if(tabuleiro[coordnavio[0]][coordnavio[1]] != 0 || coordnavio[0] > 9 || coordnavio[1] > 9){
                printf("ATENÇÃO!! Os navios estão se sobrepondo ou estão sendo colocados fora do tabuleiro.\n\n\n");
				exit(0);
            } else {
                tabuleiro[coordnavio[0]][coordnavio[1]] = navio[i];
                coordnavio[0]++;
			    coordnavio[1]--;
			}
			//este bloco é executado somente quando os elementos da posição 2 do vetor coordnavio não for uma das opções possíveis:
			//0 (vertical), 1 (horizontal), 2 (diagonal direita) e nem 3 (diagonal esquerda).
		}else{
			printf("Direção invalida!\n\n");
			break;
		}
	}
}

void disparahabilidade(int coordhab[3], int habilidade[3][5], int tabuleiro[10][10]){for (int i = 0; i < 3; i++){
    for (int j = 0; j < 5; j++) {
        // ...inicialização das matrizes cone, cruz e octa...
    }
}
	//Essa função posiciona o efeito da habilidade no tabuleiro.
	//Essas duas variávais servem para indicar (baseado na origem de cada habilidade) a linha e coluna onde a matriz de habiliade vai começar a ser lançada no tabuleiro.
	int iniciolin = coordhab[2] == 0 ? coordhab[0] : coordhab[0] - 1;
	int iniciocol = coordhab[1]-2;
	
	//Esse bloco de código testa se o efeito de cada habilidade está totalmente dentro do tabuleiro.
	if(coordhab[2] == 0){
		if(coordhab[0] > 7 || coordhab[1] < 2 || coordhab[1] > 7){
			printf("A área de efeito do cone está total ou parcialmente fora do tabuleiro.\n\n\n");
			exit(0);
		}
	}else if(coordhab[2] == 1){
		if(coordhab[0] < 1 || coordhab[0] > 8 || coordhab[1] < 2 || coordhab[1] > 7){
			printf("A área de efeito da cruz está total ou parcialmente fora do tabuleiro.\n\n\n");
			exit(0);
		}
		}else{
			if(coordhab[0] < 1 || coordhab[0] > 8 || coordhab[1] < 1 || coordhab[1] > 8){
				printf("A área de efeito do octaedro está total ou parcialmente fora do tabuleiro.\n\n\n");
				exit(0);
			}
		}
	
	//Esse bloco lança a habilidade no tabuleiro.
	//quando o valor do elemento na matriz de habilidade é 0 ele se abstem de alterar o tabuleiro, mas quando é 1 ele mar a casa com valor 5.
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 5; j++){
			if(habilidade[i][j] == 1){
				tabuleiro[iniciolin + i][iniciocol + j] = habilidade[i][j]+4;
			}	
		}
	}	
}		

int main(){
	
	//declaração das matrizes de habilidades e do tabuleiro.
    int tabuleiro[10][10];
    int cone[3][5], cruz[3][5], octa[3][5];

	//variável para armazenar a opção do menu.
	int op;
    
    //Estes vetores armazenam as coodenadas onde serão colocados os navios.
    //O primeiro valor é a linha, o segundo valor é a coluna e o terceiro é o posicionamento:
    //0 para vertical; 1 para horizontal; 2 para diagonal direita e 3 para diagonal esquerda.
    int coordnavio1[3] = {0, 0, 0};
    int coordnavio2[3] = {0, 2, 1};
    int coordnavio3[3] = {1, 7, 2};
    int coordnavio4[3] = {6, 8, 3};
    
    //Estas vetores armazenam as coodenadas do ponto de origem das habilidades.
	////O primeiro valor é a linha, o segundo valor é a coluna e o terceiro valor identifica a habilidade (para dentro da função)
    int coordcone[3] = {2, 2, 0};
    int coordcruz[3] = {7, 2, 1};
    int coordocta[3] = {4, 7, 3};
    
    //inicialização das matrizes cone, cruz e octa. Inicializei todas no mesmo for aninhado.
    for (int i = 0; i < 3; i++){
    	for (int j = 0; j < 5; j++) {
    		//cone
        	if ((i == 0 && j == 2) || (i == 1 && (j == 1 || j == 2 || j == 3)) || i == 2){
            	cone[i][j] = 1;
        	} else {
            	cone[i][j] = 0;
        	}
           	//cruz
        	if (
				(i == 0 && j == 2) || (i == 1) || (i == 2 && j == 2)){
            	cruz[i][j] = 1;
        	} else {
            	cruz[i][j] = 0;
        	}
        	//octaedro
        	if ((i == 0 && j == 2) || (i == 1 && (j == 1 || j == 2 || j == 3)) || (i == 2 && j == 2)){
            	octa[i][j] = 1;
        	} else {
            	octa[i][j] = 0;
        	}
    	}
	}
	
	/*Exibição das matrizes cone, cruz e octa.
	Esse código foi gerado apenas para fins de visualização durante o desenvolvimento da atividade.
	Este código se ficar descomentado mostra as matrizes de habilidades impressas antes do tabuleioro vazio.
    for (int i = 0; i < 3; i++){
    	printf("\n");
    	for (int j = 0; j < 5; j++) {
        	printf("%d ", cone[i][j]);
    	}
	}
	printf("\n");

    for (int i = 0; i < 3; i++){
    	printf("\n");
    	for (int j = 0; j < 5; j++) {
        	printf("%d ", cruz[i][j]);
    	}
	}
	printf("\n");
    
    for (int i = 0; i < 3; i++){
    	printf("\n");
    	for (int j = 0; j < 5; j++) {
        	printf("%d ", octa[i][j]);
    	}
	}
	printf("\n");
	*/
        
    //inicialização da matriz tabuleiro.
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }
    
	//aqui começa o menu principal do jogo.
	//A cada ação que modifica o tabuleiro ele éexibido novamente.
	printf("============================================================\n");
	printf("		  BATALHA NAVAL\n");
	printf("Oceanic Games 2025 - Todos os direitos reservados.\n");
	printf("============================================================\n\n");
	printf("Menu Principal\n\n");

	printf("[1] Iniciar o jogo\n");
	printf("[2] Sair do jogo\n\n");
	printf("Escolha uma opção: ");
	scanf("%d", &op);

	//Para economizar espaço vertical, optei por criar, como funções, as lógicas que se repetem.
    //As funções utilizam informações inicializadas nos vetores descritos anteriormente.

	switch (op){
		case 1:
			printf("\nEste é o tabuleiro que jogaremos. Dez linhas por dez colunas.\n\n");
			imprimetabuleiro(tabuleiro);

			printf("\nOs navios no campo de batalha serão identificados pelo número 3.\n");
			printf("Posicionando os navios...\n\n");

			posicionanavio(coordnavio1, tabuleiro);
			posicionanavio(coordnavio2, tabuleiro);
			posicionanavio(coordnavio3, tabuleiro);
			posicionanavio(coordnavio4, tabuleiro);

			imprimetabuleiro(tabuleiro);

			printf("\nOs efeitos das habilidades serão identificados pelo número 5.\n");
			printf("Disparando as habilidades...\n\n");

			disparahabilidade(coordcone, cone, tabuleiro);
			disparahabilidade(coordcruz, cruz, tabuleiro);
			disparahabilidade(coordocta, octa, tabuleiro);

			imprimetabuleiro(tabuleiro);
			printf("\n\nObrigado por jogar! Saindo...\n\n\n");
		break;
		case 2:
			printf("\n\n\nObrigado por jogar! Saindo...\n\n\n");
			return 0;
		break;
		default:
			break;
	}
return 0;
}