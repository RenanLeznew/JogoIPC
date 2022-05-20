#include <stdio.h>

int main(){
    int gameGrid[6][8];
    int x, y;

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
    
    printf("Digite as coordenadas: \n");
    scanf("%d\n%d", &x, &y);

    if(x < 6 && y < 9){
        while (x != 5 && y != 0)
        {
            for (int row = 0; row < x; row++)
            {
                for (int column = y; column < 8; column++)
                {
                    gameGrid[row][column] = 0;
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
            printf("%d\n%d\n", gameGrid[x-1], gameGrid[y+1]);
            
            while(gameGrid[x-1] == 0 && gameGrid[y] == 0){
                printf("Essa coordenada agora eh zero, digite as coordenadas novas: ");
                scanf("%d%d", &x, &y);
            }
            
        }
    }
    else
    {
        while(x >= 6 && y>=9){
            printf("Esses valores ultrapassam o tamanho do tabuleiro do jogo, insira outros valores de x, y:\n ");
            scanf("%d\n%d", &x, &y);
        }        
    }

    //todo: nao deixar digitar a coordenada que ja esta com zero

    return 0;
}