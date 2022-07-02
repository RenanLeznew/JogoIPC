#include <stdio.h>
#include <stdlib.h>
//Integrantes do grupo:
//Renan Wenzel - 11169472
//Ana Cl�udia Rodrigues- 13696241
//Laura Alonso Ribeiro - 11858690

//funcao para alocar e criar a matriz
int **allocateMatrix(int numberRows, int numberColumns){
    int **matrix;

    matrix = (int**)malloc(sizeof(int*)*numberRows);
    if(matrix==NULL){   
        return NULL; 
    }

    for(int addColumns=0; addColumns<numberRows; addColumns++){
        matrix[addColumns]=(int*)malloc(sizeof(int)*numberRows);
        if(matrix[addColumns]==NULL){  
            return NULL;
        }
    }

    return matrix;
}

int **createMatrix(int **gameGrid, int columns, int rows){
    for (int row = 0; row < 8; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            if((row == 7) && (column == 0)){
                gameGrid[row][column] = 2;
            }
            else{
                gameGrid[row][column] = 1;
            }
        }
    }

}

//funcao para exibir a matriz
void printMatrix(int **gameGrid){
    for (int row = 0; row < 8; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            printf("%d      ", gameGrid[row][column]);
        }
        printf("\n\n");
    }
}

//funcao para conferir se esta dentro dos limites do tabuleiro
void checkGreater(int *x, int *y){
    while(*x > 8 || *y > 10){
        printf("Esses valores ultrapassam o tamanho do tabuleiro do jogo, insira outros valores de x, y: ");
        scanf("%d\n%d", &*x, &*y);
    }
    while(*x < 1 || *y < 1){
       printf("Os valores digitados devem ser maiores que 1, insira outros valores de x, y: ");
        scanf("%d\n%d", &*x, &*y);
    }
}

void removeCoordinate(int **gameGrid, int x, int y){
    for (int row = 0; row < x; row++)
    {
        for (int column = y; column < 11; column++)
        {
            gameGrid[row][column-1] = 0;
        }

    }    
}

void playerVsPlayer(int **gameGrid, int x, int y){
    int play = 1;
    int winner;

    printMatrix(gameGrid);
    
    printf("Jogador 1:\nDigite as coordenadas: \n");
    scanf("\n%d\n%d", &x, &y);
    printf("Beep Bop! Removendo as coordenadas: (%d, %d)\n", x, y);
    play++;

    checkGreater(&x, &y);
    while (x != 8 || y != 1)
    {
        if(play%2 == 0){
            printf("Jogador 2:\n");
            winner = 1;
        }else{
            printf("Jogador 1:\n");
            winner = 2;
        }
        removeCoordinate(gameGrid, x, y);

        printMatrix(gameGrid);

        printf("Insira outros valores de x, y: ");
        scanf("%d%d", &x, &y);
        checkGreater(&x, &y);
        while(gameGrid[x-1][y-1] == 0){
            while(x < 1 || y < 1){
                printf("Os valores digitados devem ser maiores que 1, insira outros valores de x, y: ");
                scanf("\n%d\n%d", &x, &y);
            }
            printf("Essa coordenada ja eh zero, digite as coordenadas novas: ");
            scanf("%d%d", &x, &y);
        }
        printf("Beep Bop! Removendo as coordenadas: (%d, %d)\n", x, y);    
        play++;
    }
    if (winner == 1)
    {
        printf("Jogador 2 encontrou a pimentinha, Jogador 1 eh o vencedor.");
    }
    else{
        printf("Jogador 1 encontrou a pimentinha, Jogador 2 eh o vencedor");
    }    
}

void playerVsComputer(int **gameGrid, int x, int y){
    int play = 1;
    int winner;
    
    x = 1;
    y = 10;
    printf("O computador removeu as coordenadas: (%d, %d)\n", x, y);
    removeCoordinate(gameGrid, x, y);
    printMatrix(gameGrid);

    checkGreater(&x, &y);
    while (x != 8 || y != 1)
    {
        if(play%2 == 1){
            printf("Jogador 1:\n");
            removeCoordinate(gameGrid, x, y);

            printMatrix(gameGrid);

            printf("Insira outros valores de x, y: ");
            scanf("%d%d", &x, &y);
            checkGreater(&x, &y);
            while(gameGrid[x-1][y-1] == 0){
                while(x < 1 || y < 1){
                    printf("Os valores digitados devem ser maiores que 1, insira outros valores de x, y: ");
                    scanf("\n%d\n%d", &x, &y);
                }
                printf("Essa coordenada ja eh zero, digite as coordenadas novas: ");
                scanf("%d%d", &x, &y);
            }
            printf("Beep Bop! Removendo as coordenadas: (%d, %d)\n", x, y);    
            play++;
        }
        else{
            x = 1;
            y = 10;
            printf("O computador removeu as coordenadas: (%d, %d)\n", x, y);
            removeCoordinate(gameGrid, x, y);
            printMatrix(gameGrid);
        }
    }
    if (winner == 1)
    {
        printf("Jogador 2 encontrou a pimentinha, Jogador 1 eh o vencedor.");
    }
    else{
        printf("Jogador 1 encontrou a pimentinha, Jogador 2 eh o vencedor");
    }    
}

int main(){
    int **gameGrid;
    int x, y;
    char gameMode[1];

    gameGrid = allocateMatrix(8, 10);

    createMatrix(gameGrid, 8, 10);
    
    printf("Digite P para ir contra player ou C para ir contra computador: ");
    scanf("%c", &gameMode);
    //printa a matriz        
    if (gameMode[0] == 'P'){
        printf("Voce escolheu ir contra player!\n");
        playerVsPlayer(gameGrid, x, y);
    }
    else{
        printf("Voce escolheu ir contra computador!\n");
        playerVsComputer(gameGrid, x, y);
    } 

    return 0;
}