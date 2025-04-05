#include <stdio.h>

int main()
{   //  Matriz do tabuleiro de batalha naval
    int tabuleiro[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    int navio1[3] = {3,3,3}; // array do navio-1
    int navio2[3] = {3,3,3}; // array do navio-2

    int LinhaV = 4; // Posição vertical do navio-1
    int ColunaV = 6; // posição vertical do navio-1

    for(int i = 0; i < 3; i++) // loop, para adicionar ao tabuleiro o navio-1
    {
        tabuleiro[LinhaV][ColunaV + i] = navio1[i];
    };

    int LinhaH = 7; // posição horizontal do navio-2
    int ColunaH = 4; // posição horizontal do navio-2

    for(int i = 0; i < 3; i++) // loop, para adicionar ao tabuleiro o navio-2
    {
        tabuleiro[LinhaH + i][ColunaH] = navio2[i];
    };

    for(int i = 0; i < 10; i++) // loops aninhados, para exibição completa da matriz, e seus navios
    {
        for(int j = 0; j < 10;j++)
        {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}