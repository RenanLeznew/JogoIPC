#include <stdio.h>

int main(){
    int gameGrid[6][8];
    int chosenPosition[2];
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
    
    printf("Digite as coordenadas: ");
    scanf("%d%d", &x, &y);
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

        printf("Digite as coordenadas: ");
        scanf("%d%d", &x, &y);
    }
    //todo: nao deixar digitar a coordenada que ja esta com zero

    //Usuario escolhe as casas que serao usadas
    // printf("Digite a casa que deseja selecionar, com a linha primeiro e a coluna depois: "));
    // scanf("%d", &chosenPosition[0]);
    // scanf("%d", &chosenPosition[1]);
    // while (chosenPosition[0] != 5 && chosenPosition[1] != 0){
    //     printf("Digite a casa que deseja selecionar, com a linha primeiro e a coluna depois: "));
    //     scanf("%d", &chosenPosition[0]);
    //     scanf("%d", &chosenPosition[1]);
    // }
    return 0;
}