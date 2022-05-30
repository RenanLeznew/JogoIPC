#include <stdio.h>
//Integrantes do grupo:
//Renan Wenzel - 11169472
//Ana Cl�udia Rodrigues- 13696241
//Laura Alonso Ribeiro - 11858690

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

int main(){
    int gameGrid[8][10];
    int x, y, winner;
    int play = 1;

    //criacao da matriz do jogo
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

    //printa a matriz
    for (int row = 0; row < 8; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            printf("%d      ", gameGrid[row][column]);
        }
        printf("\n");
    }

    printf("Jogador 1:\nDigite as coordenadas: \n");
    scanf("%d\n%d", &x, &y);
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
            for (int row = 0; row < x; row++)
            {
                for (int column = y; column < 11; column++)
                {
                    gameGrid[row][column-1] = 0;
                }

            }

            for (int row = 0; row < 8; row++)
            {
                for (int column = 0; column < 10; column++)
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
        if (winner == 1)
        {
            printf("Jogador 2 encontrou a pimentinha, Jogador 1 eh o vencedor.");
        }
        else{
            printf("Jogador 1 encontrou a pimentinha, Jogador 2 eh o vencedor");
        }
        
    return 0;
}
