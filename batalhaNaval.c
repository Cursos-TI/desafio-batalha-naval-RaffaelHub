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
#define habilidade_linha 5
#define habilidade_coluna 5


int main()
{   // Declarações de variaveis e inicializações
    // Matrizes e valores de posição
    int tabuleiro[Linha][Coluna];
    int cone[habilidade_linha][habilidade_coluna];
    int cruz[habilidade_linha][habilidade_coluna];
    int octoedro[habilidade_linha][habilidade_coluna];
    int opcao;
    int navio1[3] = {3,3,3}, navio2[3] = {3,3,3}, navio3[3] = {3,3,3};
    int navio1_vertical_linha = 4,navio1_ventical_coluna = 1;
    int navio2_horizontal_linha = 7,navio2_horizontal_coluna = 4;
    int visualizar_novamente = 1;

    // inicializando o tabuleiro do cone 
    for(int i = 0; i  < habilidade_linha; i++)
    {
        for(int j = 0; j < habilidade_coluna; j++)
        {
            cone[i][j] = 0;
        }
    }

    // inicializando o tabuleiro da cruz
    for(int i = 0; i < habilidade_linha; i++)
    {
        for(int j = 0; j < habilidade_coluna; j++)
        {
            cruz[i][j] = 0;
        }
    }
    // inicializando o tabuleiro do octoedro
    for(int i = 0; i < habilidade_linha; i++)
    {
        for(int j = 0; j < habilidade_coluna; j++)
        {
            octoedro[i][j] = 0;
        }
    }


    // adicionando a habilidade cone no tabuleiro
    for(int i = 0; i < habilidade_linha; i++)
    {
        for(int j = 0; j < habilidade_coluna; j++)
        {
            // logica para adicionar a habilidade cone
            if((i == 0 && j == 2) || (i == 1 && j == 1) || (i == 1 && j == 2) ||
                (i == 1 && j == 3) || (i == 2 && (j >= 0 && j <= 4)))
                {
                    cone[i][j] = 5;
                }

        }

    }
    // adicionando a habilidade cruz no tabuleiro
    for(int i = 0; i < habilidade_linha; i++)
    {
        for(int j = 0; j < habilidade_coluna; j++)
        {   // logica para adicionar a habilidade cruz
            cruz[2][i] = 5;
            cruz[i][2] = 5;
        }
    }
    // adicionando a habilidade octoedro no tabuleiro
    for(int i = 0; i < habilidade_linha; i++)
    {
        for(int j = 0; j < habilidade_coluna; j++)
        {   // logicas para adicionar o octoedro
            octoedro[2][i] = 5;
            octoedro[i][2] = 5;

            if((i == 1 && j == 1) || (i == 1 && j == 3) || (i == 3 && j== 1) || (i == 3 && j == 3 ))
            {
                octoedro[i][j] = 5;
            }
        }
    }


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

        // usando swtich para amplas escolhas do usuario 
        switch (opcao)
        {
        case 1:
            // Estrutura para adicionar o alfabeto, nas colunas 
        printf("  ");
        for(char letra = 'A'; letra <= 'J'; letra++)
        {
            printf(" %2c", letra);
        }
        printf("\n");

        // Loop aninhado, mostrar o tabuleiro com os navios nas posições
        for(int i = 0; i < Linha; i++)
        {   
            printf("%2d", i + 1);
            // Exibindo o tabuleiro
            for(int j = 0; j < Coluna; j++)
            {   
                
                printf(" %2d", tabuleiro[i][j]);
            }
            printf("\n");
        }
        
        
        linha(); // função para adicionar linhas, deixar o ambiente mais organziado

        // apresentando mais opções ao ususario
        // imprimindo mensagem, anunciando que tera como usar habilidade
        printf("Muito bem!\n");
        printf("Conseguimos ver um pouco do tabuleiro e seus navios, que tal agora vermos habilidades\n");
        printf("Você terá algumas opções abaixo, escolha uma delas\n");

        printf("1. Habilidade CONE\n");
        printf("2. Habilidade CRUZ\n");
        printf("3. Habilidade OCTOPEDRO\n");
        printf("Escolha uma: ");
        scanf("%d", &opcao);


        // novamente switch, para habilidades
        switch(opcao)
        {
        case 1:
            // bloco de código da habilidade cone
            linha(); // função para adicionar linhas, deixar o ambiente mais organziado
            printf("ATIVAR HABILIDADE CONEEE NA ÁGUAAAAAAA\n");

            for(int i = 0; i < habilidade_linha; i++)
            {
                for(int j = 0; j < habilidade_coluna; j++)
                {
                    if(cone[i][j] != 0)
                    {
                        tabuleiro[2 + i][3 + j] = cone[i][j];
                    }
                }
            }
            // essa parte adiciona o alfabeto
                printf("   ");
            for(char letra = 'A'; letra <= 'J'; letra++)
            {
                printf("%2c ", letra);
            }
            printf("\n");

            for(int i = 0; i < Linha; i++)
            {
                printf("%2d", i + 1);
                for(int j = 0; j < Coluna; j++)
                {
                    printf(" %2d", tabuleiro[i][j]);
                    
                }
                printf("\n");
            }
            printf("---------------------------------------------------\n");
            printf("A HABILIDADE CONE FOI SPAWNADA NA LOCALIZAÇÃO: F-5 \n");



            break;
        
        case 2:
            // Bloco de código da habilidade Cruz
            linha(); // função para adicionar linhas, deixar o ambiente mais organziado
            printf("ATIVAR HABILIDADE CRUZ NA ÁGUAAAAAA!!\n");

            for(int i = 0; i < habilidade_linha; i++)
            {
                for(int j = 0; j < habilidade_coluna; j++)
                {
                    if(cruz[i][j] != 0)
                    {
                        tabuleiro[2 + i][3 + j] = cruz[i][j];
                    }
                }
            }

                printf("   ");
            for(char letra = 'A'; letra <= 'J'; letra++)
            {
                printf("%2c ", letra);
            }
            printf("\n");


            for(int i = 0; i < Linha; i++)
            {
                printf("%2d", i + 1);
                for(int j = 0; j < Linha; j++)
                {
                    printf(" %2d", tabuleiro[i][j]);
                }
                printf("\n");
            }
            printf("---------------------------------------------------\n");
            printf("A HABILIDADE CRUZ FOI SPAWNADA NA LOCALIZAÇÃO: F-5 \n");



            break;

        case 3:
            // bloco de código da habilidade octoedro
            linha(); // função para adicionar linhas, deixar o ambiente mais organziado
            printf("ATIVAR HABILIDADE OCTOEDRO NA ÁGUAAAAA!!!\n");
            
            for(int i = 0 ;i < habilidade_linha; i++)
            {
                for(int j = 0; j < habilidade_coluna; j++)
                {
                    if(octoedro[i][j] != 0)
                    {
                        tabuleiro[2 + i][3 + j] = octoedro[i][j];
                    }
                }
            }

             printf("   ");
            for(char letra = 'A'; letra <= 'J'; letra++)
            {
                printf("%2c ", letra);
            }
            printf("\n");


            for(int i = 0; i < Linha; i++)
            {
                printf("%2d", i + 1);
                for(int j = 0; j < Coluna; j++)
                {
                    printf(" %2d", tabuleiro[i][j]);
                }
                printf("\n");
            }
            printf("---------------------------------------------------\n");
            printf("A HABILIDADE OCTOEDRO FOI SPAWNADA NA LOCALIZAÇÃO: F-5 \n");


            break;
        }

            break;
        
        // Estrutura para adicionar emojis no tabuleiro
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
            // Explicando sobre o sistema de habilidades
            linha(); // função para adicionar linhas, deixar o ambiente mais organziado
            printf("Muito bem!\n");
            printf("Conseguimos ver um pouco do tabuleiro e seus navios, que tal agora vermos habilidades\n");
            printf("Você terá algumas opções abaixo, escolha uma delas\n");

            printf("1. Habilidade CONE\n");
            printf("2. Habilidade CRUZ\n");
            printf("3. Habilidade OCTOEDRO\n");
            printf("Escolha uma: ");
            scanf("%d", &opcao);

            switch(opcao)
            {
                // bloco de código da habilidade cone, versão emoji
            case 1:

                linha();
                printf("ATIVAR HABILIDADE CONEEE NA ÁGUAAAAAAA\n");

                for(int i = 0; i < habilidade_linha; i++)
                {
                    for(int j = 0; j < habilidade_coluna; j++)
                    {
                        if(cone[i][j] != 0)
                        {
                            tabuleiro[2 + i][3 + j] = cone[i][j];
                        }
                    }
                }

                    printf("  ");
                for(char letra = 'A'; letra <= 'J'; letra++)
                {
                    printf("%2c ", letra);
                }
                printf("\n");

                for(int i = 0; i < Linha; i++)
                {
                    printf("%2d", i + 1);
                    for(int j = 0; j < Coluna; j++)
                    {
                        
                    if(tabuleiro[i][j] == 0)
                        {
                            printf("🌊 ");
                        }
                        else if(tabuleiro[i][j] == 3)
                        {
                            printf("🚢 ");
                        }
                        else if(tabuleiro[i][j] == 5)
                        {
                            printf("💥 ");
                        }
                        }
                        printf("\n");
                }
                printf("---------------------------------------------------\n");
                printf("A HABILIDADE CONE FOI SPAWNADA NA LOCALIZAÇÃO: F-5 \n");

                break;

            case 2:
            // bloco de código da habilidade cruz, versão emoji
            linha(); // função para adicionar linhas, deixar o ambiente mais organziado
            printf("ATIVAR HABILIDADE CRUZ NA ÁGUAAAAAA!!\n");

            for(int i = 0; i < habilidade_linha; i++)
            {
                for(int j = 0; j < habilidade_coluna; j++)
                {
                    if(cruz[i][j] != 0)
                    {
                        tabuleiro[2 + i][3 + j] = cruz[i][j];
                    }
                }
            }

                printf("  ");
            for(char letra = 'A'; letra <= 'J'; letra++)
            {
                printf("%2c ", letra);
            }
            printf("\n");


            for(int i = 0; i < Linha; i++)
            {
                printf("%2d ", i + 1);
                for(int j = 0; j < Linha; j++)
                {
                    if(tabuleiro[i][j] == 0)
                    {
                        printf("🌊 ");
                    }
                    else if(tabuleiro[i][j] == 3)
                    {
                        printf("🚢 ");
                    }
                    else if(tabuleiro[i][j] == 5)
                    {
                        printf("💥 ");
                    }
                }
                printf("\n");
            }

                printf("---------------------------------------------------\n");
                printf("A HABILIDADE CRUZ FOI SPAWNADA NA LOCALIZAÇÃO: F-5 \n");
                break;
            case 3:
                // bloco de código da habilidade octoedro, versão emoji
                linha(); // função para adicionar linhas, deixar o ambiente mais organziado
                printf("ATIVAR HABILIDADE OCTOEDROOO NA ÁGUAAAAAA!!\n");

                for(int i = 0; i < habilidade_linha; i++)
                {
                    for(int j = 0; j < habilidade_coluna; j++)
                    {
                        if(octoedro[i][j] != 0)
                        {
                            tabuleiro[2 + i][3 + j] = octoedro[i][j];
                        }
                    }
                }

                    printf("  ");
                for(char letra = 'A'; letra <= 'J'; letra++)
                {
                    printf("%2c ", letra);
                }
                printf("\n");


                for(int i = 0; i < Linha; i++)
                {
                    printf("%2d ", i + 1);
                    for(int j = 0; j < Linha; j++)
                    {
                        if(tabuleiro[i][j] == 0)
                        {
                            printf("🌊 ");
                        }
                        else if(tabuleiro[i][j] == 3)
                        {
                            printf("🚢 ");
                        }
                        else if(tabuleiro[i][j] == 5)
                        {
                            printf("💥 ");
                        }
                    }
                    printf("\n");
                }
                    printf("---------------------------------------------------\n");
                    printf("A HABILIDADE OCTOEDRO FOI SPAWNADA NA LOCALIZAÇÃO: F-5 \n");

                break;

            }

    
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
    // mensagem de finalização
    printf("Obrigado por jogar! Até mais! 👋\n");
    return 0;


}