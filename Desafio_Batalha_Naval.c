#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10 // Define o tamanho do tabuleiro como 10x10
#define TAM_HABILIDADE 5// Tamanho das matrizes de habilidades 


// Nível Iniciante 

// Função para imprimir o tabuleiro completo com valores númericos 
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]){
    printf("\n Tabuleiro Completo:\n\n");
    for (int y = 0; y < TAMANHO; y++){ //Percorre as linhas
        for (int x = 0; x < TAMANHO; x++){ // Percorre as colunas
        printf(" %d ", tabuleiro[y][x]); // Exibe o valor da célula (0 = água, 3 = navio)
    }
    printf("\n");
}

}

// Nível Mestre : Habilidades 

// Função para imprimir habilidade em formato de cone 
void habilidadeCone(){
    int matriz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    for (int i = 0; i < TAM_HABILIDADE; i++){
        for (int j = TAM_HABILIDADE / 2 - i; j <= TAM_HABILIDADE / 2 + i; j++){
            if(j >= 0 && j < TAM_HABILIDADE){
                matriz[i][j] = 1;
            }
        }
    }

    printf("\n Habilidade: Cone\n\n");
    for(int i = 0; i < TAM_HABILIDADE; i++){
        for(int j = 0; j < TAM_HABILIDADE; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para imprimi habilidade em formato de cruz
void habilidadeCruz(){
    int matriz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    for(int i = 0; i < TAM_HABILIDADE; i++){
        matriz[i][TAM_HABILIDADE / 2] = 1;
        matriz[TAM_HABILIDADE / 2 ][i] = 1;
    }

    printf("\n Habilidade: Cruz \n\n");
    for(int i = 0; i < TAM_HABILIDADE; i++){
        for(int j = 0; j < TAM_HABILIDADE; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para imprimir habilidade em forma de octaedro
void habilidadeOctaedro(){
    int matriz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    for (int i = 0; i < TAM_HABILIDADE; i++){
        for( int j = 0; j < TAM_HABILIDADE; j++){
            if (abs(i - TAM_HABILIDADE / 2 ) + abs (j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2 ){
                matriz[i][j] = 1;
            }
        }
    }

    printf("\n Habilidade: Octaedro \n\n");
    for(int i = 0; i < TAM_HABILIDADE; i++){
        for (int j = 0; j < TAM_HABILIDADE; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    // Inicializa o tabuleiro com zeros (0 = água)
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicia tudo com (água)

    // Navio Vertical
    // Posicional um navio vertical de tamnaho 4 na coluna 1 começando na linha 2
    int x_vert = 2, y_vert = 3, tamanho_vert = 4;
    printf(" Navio Vertical: \n");
    for(int i = 0; i < tamanho_vert; i++){
        tabuleiro[y_vert + i][x_vert] = 3; // Marca a posição com 3
        printf(" Parte %d: (%d, %d)\n", i + 1, x_vert, y_vert + 1); // Exibe a coordenada
    }

    // Navio Horizontal
    // Posiciona um navio horizontal de tamanho 3 na linha 0, começando na coluna 4
    int x_horiz = 5, y_horiz = 1, tamanho_horiz = 3;
    printf("\n Coordenadas do Navio Horizontal: \n");
    for ( int i = 0; i < tamanho_horiz; i++){
        tabuleiro[y_horiz][x_horiz + i] = 2; // Marca a posição com 3
        printf("Parte %d (%d, %d)\n", i + 1, x_horiz + 1, y_horiz); // Exibe coordenada
    }

    // Nível Aventureiro

    // Navio Diagonal (principal)
     // Posiciona um navio diagonal de tamanho 4 começando em (0,0) e indo para (3,3)
    int x_diag1 = 0, y_diag1 = 0, tamanho_diag1 = 4;
    printf("\n Navio Diagonal: \n");
    for (int i = 0; i < tamanho_diag1; i++){
        tabuleiro[y_diag1 + i][x_diag1 + i] = 3;  // Marca a posição com 3
        printf("Parte %d: (%d, %d)\n", i + 1, x_diag1 + 1, y_diag1 + 1); // Exibe coordenada
    } 

    // Navio diagonal (secundária)
      // Posiciona um navio diagonal de tamanho 4 começando em (9,0) e indo para (6,3)
    int x_diag2 = 9, y_diag2 = 0, tamanho_diag2 = 4;
    printf("\n Navio Diagonal: \n");
    for (int i = 0; i < tamanho_diag2; i++){
        tabuleiro[y_diag2 + i][x_diag2 - i] = 3; // Marca a posição com 3
        printf("Parte %d: (%d, %d)\n", i + 1, x_diag2 - i, y_diag2 + i); // Exibe coordenada
    }

     // Exibe o tabuleiro completo com todos os navios posicionados
    imprimirTabuleiro(tabuleiro);

    // Nível Mestre: Habilidades especiais
    habilidadeCone();
    habilidadeCruz();
    habilidadeOctaedro();

    return 0;

}