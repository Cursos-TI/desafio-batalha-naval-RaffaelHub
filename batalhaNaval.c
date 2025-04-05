#include <stdio.h>

int main()
{
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

    int navio1[3] = {3,3,3};
    int navio2[3] = {3,3,3};

    int LinhaV = 4;
    int ColunaV = 6;

    for(int i = 0; i < 3; i++)
    {
        tabuleiro[LinhaV][ColunaV + i] = navio1[i];
    };

    int LinhaH = 7;
    int ColunaH = 4;

    for(int i = 0; i < 3; i++)
    {
        tabuleiro[LinhaH + i][ColunaH] = navio2[i];
    };

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10;j++)
        {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}