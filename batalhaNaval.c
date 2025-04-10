#include <stdio.h> // Biblioteca padrão
// função de linhas, para uma visualização mais bonita
void linha()
{
    printf("========================================\n");
    printf("////////////////////////////////////////\n");
    printf("========================================\n");
}

// Constantes do tabuleiro
#define Linha 10 // 10 linhas no tabuleiro
#define Coluna 10 // 10 colunas no tabuleiro


int main()
{   // Declarações de variaveis e inicializações
    // Matrizes e valores de posição
    int tabuleiro[Linha][Coluna];
    int opcao;
    int navio1[3] = {3,3,3}, navio2[3] = {3,3,3}, navio3[3] = {3,3,3};
    int navio1_vertical_linha = 2,navio1_ventical_coluna = 4;
    int navio2_horizontal_linha = 7,navio2_horizontal_coluna = 4;
    int visualizar_novamente = 1;

    // while para uma dinâmica melhor
    while(visualizar_novamente == 1) {
        // Loops aninhados para construir o tabuleiro
        for(int i = 0; i < Linha; i++)
        {
            for(int j = 0; j < Coluna; j++)
            {
                tabuleiro[i][j] = 0; // definindo o valor das linhas e coluna para 0 'Água'
                
            }
            
        }
        // Loop para adicionar o navio na vertical, NAVIO1
        for(int i = 0; i < 3; i++)  
        {
            tabuleiro[navio1_vertical_linha + i][navio1_ventical_coluna] = navio1[i];

        }

        // Loop para adicionar o navio na horizontal, NAVIO2
        for(int i = 0; i < 3; i++)
        {
            tabuleiro[navio2_horizontal_linha][navio2_horizontal_coluna + i] = navio2[i];
        }


        // Loop para adicionar o navio na diagonal, Esquerda para direita
        for(int i = 0; i < 3; i++)
        {
            tabuleiro[i][i] = navio3[i];
        }

        // Loop para adicionar o navio na diagonal, Direita para esquerda
        for(int i = 0; i < 3; i++)
        {
            tabuleiro[i][9 - i] = navio3[i];
        }

        linha(); // Função para exibição de linhas
        // Mensagem de introdução
        printf("*****Bem-vindo!*****\n");
        printf("Abaixo você tem duas opções\n");
        printf("1. Visualizar o tabuleiro com números\n");
        printf("2. Visualizar o tabuleiro com emojis\n");
        printf("Selecione uma opção: ");
        scanf("%d", &opcao);
        linha(); // Função para exibição de linhas


        switch (opcao)
        {
        case 1:
            // Estrutura para adicionar o alfabeto, nas colunas 
        printf("  ");
        for(char letra = 'A'; letra <= 'J'; letra++)
        {
            printf(" %c", letra);
        }
        printf("\n");

        // Loop aninhado, mostrar o tabuleiro com os navios nas posições
        for(int i = 0; i < Linha; i++)
        {   
            printf("%2d", i + 1);
            // Exibindo o tabuleiro
            for(int j = 0; j < Coluna; j++)
            {   
                
                printf(" %d", tabuleiro[i][j]);
            }
            printf("\n");
        }
        // Retorna FALSE
        


            break;
        
        case 2:

            // Estrutura para adicionar o alfabeto, nas colunas 
        printf(" ");
        for(char letra = 'A'; letra <= 'J'; letra++)
        {
            printf("  %c", letra);
        }
        printf("\n");

        // Loop aninhado, mostrar o tabuleiro com os navios nas posições
        for(int i = 0; i < Linha; i++)
        {   
            printf("%2d", i + 1);
            // Exibindo o tabuleiro
            for(int j = 0; j < Coluna; j++)
            {   
                // Adicionando emojis para uma melhor visualização
                if(tabuleiro[i][j] == 0)
                {
                    printf("🌊 ");
                }
                else if(tabuleiro[i][j] == 3)
                {
                    printf("🚢 ");
                }
                
            }
            printf("\n");
        }
        // Retorna FALSE
    
            break;
        }
        linha(); // Função para exibição de linhas
        // Solicitando um valor de 0 ou 1, para realizar a repetição ou o termino do programa
        printf("*****Muito bem*****\n");
        printf("Deseja voltar para o menu? e ver outras opções?\n");
        printf("Digite 1 para sim, 0 para não: ");
        scanf("%d", &visualizar_novamente);
        linha(); // Função para exibição de linhas

       
    }

}