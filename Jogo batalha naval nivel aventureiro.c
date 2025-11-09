#include <stdio.h>
#include <stdbool.h>

// Definicoes de constantes
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Tipo de direcao
typedef enum {
    HORIZONTAL,
    VERTICAL,
    DIAGONAL_PRINCIPAL, // Cima-Esquerda para Baixo-Direita (i++, j++)
    DIAGONAL_SECUNDARIA // Cima-Direita para Baixo-Esquerda (i++, j--)
} Direcao;

// Declaracao da matriz do tabuleiro
int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

/**
 * @brief Inicializa o tabuleiro com o valor de AGUA (0).
 */
void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

/**
 * @brief Verifica se as coordenadas e a direcao estao dentro dos limites do tabuleiro.
 * @param linha Linha inicial.
 * @param coluna Coluna inicial.
 * @param direcao Direcao do navio.
 * @return true se o navio cabe no tabuleiro, false caso contrario.
 */
bool validarLimites(int linha, int coluna, Direcao direcao) {
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        return false; // Coordenadas iniciais invalidas
    }

    switch (direcao) {
        case HORIZONTAL:
            return (coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO);
        case VERTICAL:
            return (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO);
        case DIAGONAL_PRINCIPAL:
            return (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO);
        case DIAGONAL_SECUNDARIA:
            return (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna - TAMANHO_NAVIO + 1 >= 0);
        default:
            return false;
    }
}

/**
 * @brief Verifica se um navio se sobrepoe a outro na posicao atual do tabuleiro.
 * @param linha Linha inicial.
 * @param coluna Coluna inicial.
 * @param direcao Direcao do navio.
 * @return true se houver sobreposicao, false caso contrario.
 */
bool validarSobreposicao(int linha, int coluna, Direcao direcao) {
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        int r = linha;
        int c = coluna;

        // Calcula a proxima posicao com base na direcao
        switch (direcao) {
            case HORIZONTAL:
                c += k;
                break;
            case VERTICAL:
                r += k;
                break;
            case DIAGONAL_PRINCIPAL:
                r += k;
                c += k;
                break;
            case DIAGONAL_SECUNDARIA:
                r += k;
                c -= k;
                break;
        }

        // Se a posicao ja tem um navio (valor 3), ha sobreposicao
        if (tabuleiro[r][c] == NAVIO) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Posiciona um navio no tabuleiro, apos validar limites e sobreposicao.
 * @param linha Linha inicial.
 * @param coluna Coluna inicial.
 * @param direcao Direcao do navio.
 * @return true se o navio foi posicionado com sucesso, false caso contrario.
 */
bool posicionarNavio(int linha, int coluna, Direcao direcao) {
    // 1. Validacao de Limites
    if (!validarLimites(linha, coluna, direcao)) {
        printf("ERRO: Navio em (%d, %d) na direcao %d ultrapassa os limites.\n", linha, coluna, direcao);
        return false;
    }

    // 2. Validacao de Sobreposicao
    if (validarSobreposicao(linha, coluna, direcao)) {
        printf("ERRO: Navio em (%d, %d) na direcao %d se sobrepoe a outro navio.\n", linha, coluna, direcao);
        return false;
    }

    // 3. Posicionamento (se a validacao passou)
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        int r = linha;
        int c = coluna;

        switch (direcao) {
            case HORIZONTAL:
                c += k;
                break;
            case VERTICAL:
                r += k;
                break;
            case DIAGONAL_PRINCIPAL:
                r += k;
                c += k;
                break;
            case DIAGONAL_SECUNDARIA:
                r += k;
                c -= k;
                break;
        }
        tabuleiro[r][c] = NAVIO;
    }

    printf("SUCESSO: Navio posicionado em (%d, %d), direcao %d.\n", linha, coluna, direcao);
    return true;
}

/**
 * @brief Exibe o tabuleiro 10x10 no console.
 */
void exibirTabuleiro() {
    printf("\n==============================================\n");
    printf("           TABULEIRO BATALHA NAVAL 10x10      \n");
    printf("==============================================\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n"); // Cabecalho das colunas

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Cabecalho das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Usa ' ' para agua e '3' para navio, com espacos para alinhamento
            printf(" %d", tabuleiro[i][j]); 
        }
        printf("\n");
    }
    printf("==============================================\n");
}

int main() {
    // Inicializa todas as posicoes como agua (0)
    inicializarTabuleiro();

    printf("Iniciando posicionamento dos %d navios (tamanho %d):\n", 4, TAMANHO_NAVIO);
    printf("------------------------------------------\n");

    // NAVIO 1: Horizontal (OK)
    // Comeca em [1][1] e vai ate [1][3]
    posicionarNavio(1, 1, HORIZONTAL); 

    // NAVIO 2: Vertical (OK)
    // Comeca em [4][8] e vai ate [6][8]
    posicionarNavio(4, 8, VERTICAL); 

    // NAVIO 3: Diagonal Principal (i++, j++) (OK)
    // Comeca em [7][0] e vai ate [9][2]
    posicionarNavio(7, 0, DIAGONAL_PRINCIPAL); 
    
    // NAVIO 4: Diagonal Secundaria (i++, j--) (OK)
    // Comeca em [0][6] e vai ate [2][4]
    posicionarNavio(0, 6, DIAGONAL_SECUNDARIA); 

    // Teste de Erro (Sobreposicao) - Nao deve ser posicionado
    // Tentativa em [1][2], que ja tem parte do Navio 1
    printf("\n--- Teste de Sobreposicao (Deve falhar) ---\n");
    posicionarNavio(1, 0, HORIZONTAL); 

    // Teste de Erro (Limites) - Nao deve ser posicionado
    // Tenta posicionar verticalmente no limite inferior
    printf("\n--- Teste de Limites (Deve falhar) ---\n");
    posicionarNavio(8, 0, VERTICAL); 
    
    // Exibe o tabuleiro final
    exibirTabuleiro();

    return 0;
}