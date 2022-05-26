#include <stdio.h>
//Integrantes do grupo:
//Renan Wenzel - 
//Ana Cláudia Rodrigues- 13696241
//Laura Ribeiro - 

void checkGreater(int *x, int *y){
    while(*x > 6 || *y > 8){
        printf("Esses valores ultrapassam o tamanho do tabuleiro do jogo, insira outros valores de x, y: ");
        scanf("%d\n%d", &*x, &*y);
    }
    while(*x < 1 || *y < 1){
       printf("Os valores digitados devem ser maiores que 1, insira outros valores de x, y: ");
        scanf("%d\n%d", &*x, &*y); 
    }
}

int main(){
    int gameGrid[6][8];
    int x, y;
    int play = 1;

    //criacao da matriz do jogo
    for (int row = 0; row < 6; row++)
    {
        for (int column = 0; column < 8; column++)
        {
            if((row == 5) && (column == 0)){
                gameGrid[row][column] = 2;
            }
            else{
                gameGrid[row][column] = 1;
            }
        }    
    }
    
    //printa a matriz
    for (int row = 0; row < 6; row++)
    {
        for (int column = 0; column < 8; column++)
        {
            printf("%d      ", gameGrid[row][column]);
        }
        printf("\n");
    }
    
    printf("Jogador 1:\nDigite as coordenadas: \n");
    scanf("%d\n%d", &x, &y);
    play++;
    
    checkGreater(&x, &y);
        while (x != 6 || y != 0)
        {   
            if(play%2 == 0){
                printf("Jogador 2:\n");
            }else{
                printf("Jogador 1:\n");
            }
            for (int row = 0; row < x; row++)
            {
                for (int column = y; column < 9; column++)
                {
                    gameGrid[row][column-1] = 0;
                }
                
            }
            
            for (int row = 0; row < 6; row++)
            {
                for (int column = 0; column < 8; column++)
                {
                    printf("%d      ", gameGrid[row][column]);
                }
                printf("\n");
            }
            
            printf("Insira outros valores de x, y: ");
            scanf("%d%d", &x, &y);
            checkGreater(&x, &y);
            while(gameGrid[x-1][y-1] == 0){
                while(x < 1 || y < 1){
                    printf("Os valores digitados devem ser maiores que 1, insira outros valores de x, y: ");
                    scanf("%d\n%d", &x, &y); 
                }
                printf("Essa coordenada ja eh zero, digite as coordenadas novas: ");
                scanf("%d%d", &x, &y);
            }
            
            play++;
        }
    return 0;
}
