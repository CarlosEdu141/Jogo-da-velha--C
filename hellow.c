#include <stdio.h>
#include <stdlib.h>

int main (){

    int L, C, linha, coluna, jogador = 1, ganhou = 0, jogadas = 0, opcao;
    char jogo[3] [3];

    do{
        jogador = 1, ganhou = 0, jogadas = 0;

         for (L = 0; L < 3; L++){
            for (C = 0; C < 3; C++){
                jogo[L][C] = ' ';

            }
        }

        // print tela \/
        do {
            printf("\n\n\t 0   1   2\n\n");

            for (L = 0; L < 3; L++){
            for (C = 0; C < 3; C++){
            if (C == 0)
            printf("\t");
            printf(" %C ", jogo[L][C]);
            if( C < 2)
            printf("|");
            if( C == 2)
            printf("  %d", L);

            }
            if(L < 2)
            printf("\n\t-----------");
            printf("\n");
            }

            // interação com jogador
            do{
            printf(" PLAYER %d: digite a linha e a coluna que deseja jogar: ", jogador);
            scanf("%d%d", &linha, &coluna);
            }while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');

            //Dados do jogo
            if(jogador == 1){
                jogo[linha][coluna] = '0';
                jogador++;
            }
            else{
                jogo[linha][coluna] = 'X';
                jogador = 1;
            }
            jogadas++;

            //detectar vitoria por linha 
            if(jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0' ||
               jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0' ||
               jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0' ){
               printf("\nParabens ! O jogador 1 venceu!\n");
               ganhou = 1;
            }

            if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
               jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
               jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X' ){
               printf("\nParabens ! O jogador 2 venceu!\n");
               ganhou = 1;
            }


            //vencedor por coluna
            if(jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0' ||
               jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0' ||
               jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0' ){
               printf("\nParabens ! O jogador 1 venceu!\n");
               ganhou = 1;
            }

            if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
               jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
               jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X' ){
               printf("\nParabens ! O jogador 2 venceu!\n");
               ganhou = 1;
            }

            //diagonal principal
            if (jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0'){
                printf("\nParabens ! O jogador 1 venceu!\n");
                ganhou = 1;
            }

            if (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
                printf("\nParabens ! O jogador 2 venceu!\n");
                ganhou = 1;
            }


            //diagonal secundária
            if(jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0'){
                printf("\nParabens ! O jogador 1 venceu!\n");
                ganhou = 1;
            }

            if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
                printf("\nParabens ! O jogador 2 venceu!\n");
                ganhou = 1;
            }
        }while(ganhou == 0 && jogadas < 9);

        if(ganhou == 0)
            printf("\nO jogo finalizou sem ganhador!\n");
            printf("\n\n Digite 1 para jogar novamente: \n");
            scanf("%d", &opcao);

     }while(opcao == 1);
    return 0;
}