#include <stdio.h>

#define TAMANHO 10   // tamanho fixo do tabuleiro 10x10
#define NAVIO 3      // tamanho fixo dos navios (3 posições)

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    
    // imprimir cabeçalho (colunas)
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i); // imprime o número da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navio horizontal
int posicionarNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    // Verifica se cabe no tabuleiro
    if (coluna + NAVIO > TAMANHO) {
        return 0; // não cabe
    }

    // Verifica se já existe navio nessas posições
    for (int j = coluna; j < coluna + NAVIO; j++) {
        if (tabuleiro[linha][j] != 0) {
            return 0; // sobreposição
        }
    }

    // Posiciona o navio
    for (int j = coluna; j < coluna + NAVIO; j++) {
        tabuleiro[linha][j] = 3;
    }

    return 1; // sucesso
}

// Função para posicionar navio vertical
int posicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    // Verifica se cabe no tabuleiro
    if (linha + NAVIO > TAMANHO) {
        return 0; // não cabe
    }

    // Verifica se já existe navio nessas posições
    for (int i = linha; i < linha + NAVIO; i++) {
        if (tabuleiro[i][coluna] != 0) {
            return 0; // sobreposição
        }
    }

    // Posiciona o navio
    for (int i = linha; i < linha + NAVIO; i++) {
        tabuleiro[i][coluna] = 3;
    }

    return 1; // sucesso
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (definidas direto no código)
    int linhaHorizontal = 2, colunaHorizontal = 4;
    int linhaVertical = 5, colunaVertical = 7;

    // Posicionar navio horizontal
    if (!posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    // Posicionar navio vertical
    if (!posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical)) {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
