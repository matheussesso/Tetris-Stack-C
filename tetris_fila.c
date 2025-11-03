// TETRIS STACK - FILA DE PECAS (Nivel Novato)
// Simula a fila FIFO de pecas futuras do jogo Tetris Stack

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_FILA 5

// Estrutura de uma peca do Tetris
typedef struct {
    char nome;  // I, O, T, L
    int id;     // Identificador unico
} Peca;

// Estrutura da fila circular
typedef struct {
    Peca itens[TAMANHO_FILA];
    int inicio;
    int fim;
    int quantidade;
} Fila;

Fila fila;
int proximo_id = 0;

// Inicializa a fila com 5 pecas aleatorias
void inicializar_fila() {
    fila.inicio = 0;
    fila.fim = 0;
    fila.quantidade = 0;
    
    srand(time(NULL));
    
    for (int i = 0; i < TAMANHO_FILA; i++) {
        char tipos[] = {'I', 'O', 'T', 'L'};
        int tipo_aleatorio = rand() % 4;
        
        fila.itens[i].nome = tipos[tipo_aleatorio];
        fila.itens[i].id = proximo_id;
        proximo_id++;
    }
    
    fila.quantidade = TAMANHO_FILA;
    fila.fim = TAMANHO_FILA - 1;
}

// Exibe o estado atual da fila
void exibir_fila() {
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║        FILA DE PECAS DO TETRIS            ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("Total de pecas na fila: %d/%d\n\n", fila.quantidade, TAMANHO_FILA);
    
    if (fila.quantidade == 0) {
        printf("Fila vazia!\n");
        return;
    }
    
    printf("[ ");
    for (int i = 0; i < fila.quantidade; i++) {
        int indice = (fila.inicio + i) % TAMANHO_FILA;
        printf("%c %d ", fila.itens[indice].nome, fila.itens[indice].id);
        if (i < fila.quantidade - 1) {
            printf("| ");
        }
    }
    printf("]\n\n");
}

// Remove uma peca da frente da fila (DEQUEUE)
void jogar_peca() {
    if (fila.quantidade == 0) {
        printf("\nErro: Fila vazia! Nao ha pecas para jogar.\n");
        return;
    }
    
    Peca peca_removida = fila.itens[fila.inicio];
    
    fila.inicio = (fila.inicio + 1) % TAMANHO_FILA;
    fila.quantidade--;
    
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║           PECA JOGADA COM SUCESSO!        ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("Tipo: %c | ID: %d\n\n", peca_removida.nome, peca_removida.id);
}

// Gera uma nova peca aleatoria com ID unico
Peca gerar_peca() {
    Peca nova_peca;
    char tipos[] = {'I', 'O', 'T', 'L'};
    int tipo_aleatorio = rand() % 4;
    
    nova_peca.nome = tipos[tipo_aleatorio];
    nova_peca.id = proximo_id;
    proximo_id++;
    
    return nova_peca;
}

// Adiciona uma nova peca ao final da fila (ENQUEUE)
void inserir_peca() {
    if (fila.quantidade == TAMANHO_FILA) {
        printf("\nErro: Fila cheia! Nao ha espaco para novas pecas.\n");
        return;
    }
    
    Peca nova_peca = gerar_peca();
    
    fila.fim = (fila.fim + 1) % TAMANHO_FILA;
    fila.itens[fila.fim] = nova_peca;
    fila.quantidade++;
    
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║        PECA ADICIONADA COM SUCESSO!       ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("Tipo: %c | ID: %d\n\n", nova_peca.nome, nova_peca.id);
}

// Exibe o menu principal
void exibir_menu() {
    printf("╔════════════════════════════════════════════╗\n");
    printf("║            MENU PRINCIPAL                 ║\n");
    printf("╠════════════════════════════════════════════╣\n");
    printf("║ 1 - Jogar peca (remover da frente)       ║\n");
    printf("║ 2 - Inserir nova peca (adicionar no fim)  ║\n");
    printf("║ 0 - Sair do programa                      ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("Escolha uma opcao: ");
}

// Programa principal - controla o fluxo do jogo
int main() {
    int opcao;
    
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║        TETRIS STACK - FILA DE PECAS       ║\n");
    printf("║         Nivel Novato - Estrutura FIFO     ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    
    inicializar_fila();
    exibir_fila();
    
    while (1) {
        exibir_menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                jogar_peca();
                exibir_fila();
                break;
            case 2:
                inserir_peca();
                exibir_fila();
                break;
            case 0:
                printf("\n");
                printf("╔════════════════════════════════════════════╗\n");
                printf("║   Obrigado por jogar Tetris Stack!        ║\n");
                printf("║           Ate a proxima!                  ║\n");
                printf("╚════════════════════════════════════════════╝\n");
                printf("\n");
                return 0;
            default:
                printf("\nOpcao invalida! Tente novamente.\n\n");
        }
    }
    
    return 0;
}
