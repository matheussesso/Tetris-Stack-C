// TETRIS STACK - FILA + PILHA (Nivel Aventureiro)
// Simula o gerenciamento de pecas com fila circular e pilha de reserva

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_FILA 5
#define TAMANHO_PILHA 3

typedef struct {
    char nome;  // I, O, T, L
    int id;     // Identificador unico
} Peca;

// Fila circular de pecas futuras
typedef struct {
    Peca itens[TAMANHO_FILA];
    int inicio;
    int fim;
    int quantidade;
} Fila;

// Pilha linear de reserva
typedef struct {
    Peca itens[TAMANHO_PILHA];
    int topo;
} Pilha;

Fila fila;
Pilha pilha;
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

// Inicializa a pilha de reserva vazia
void inicializar_pilha() {
    pilha.topo = -1;
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

// Exibe o estado atual da fila
void exibir_fila() {
    printf("Fila de pecas: [ ");
    for (int i = 0; i < fila.quantidade; i++) {
        int indice = (fila.inicio + i) % TAMANHO_FILA;
        printf("%c %d ", fila.itens[indice].nome, fila.itens[indice].id);
        if (i < fila.quantidade - 1) {
            printf("| ");
        }
    }
    printf("]\n");
}

// Exibe o estado atual da pilha
void exibir_pilha() {
    printf("Pilha de reserva: ");
    if (pilha.topo == -1) {
        printf("(vazia)\n");
        return;
    }
    
    printf("(Topo -> Base): ");
    for (int i = pilha.topo; i >= 0; i--) {
        printf("[%c %d] ", pilha.itens[i].nome, pilha.itens[i].id);
    }
    printf("\n");
}

// Exibe fila e pilha juntas
void exibir_estado() {
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║        ESTADO ATUAL DO JOGO               ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    exibir_fila();
    exibir_pilha();
    printf("\n");
}

// Remove uma peca da frente da fila e gera uma nova no final
void jogar_peca() {
    if (fila.quantidade == 0) {
        printf("\nErro: Fila vazia!\n");
        return;
    }
    
    Peca peca_jogada = fila.itens[fila.inicio];
    
    fila.inicio = (fila.inicio + 1) % TAMANHO_FILA;
    
    // Gera nova peca e insere no final da fila
    Peca nova_peca = gerar_peca();
    fila.fim = (fila.fim + 1) % TAMANHO_FILA;
    fila.itens[fila.fim] = nova_peca;
    
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║           PECA JOGADA COM SUCESSO!        ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("Tipo: %c | ID: %d\n", peca_jogada.nome, peca_jogada.id);
    printf("Nova peca gerada: %c %d\n", nova_peca.nome, nova_peca.id);
}

// Move a peca da frente da fila para a pilha de reserva
void reservar_peca() {
    if (pilha.topo >= TAMANHO_PILHA - 1) {
        printf("\nErro: Pilha de reserva cheia!\n");
        return;
    }
    
    Peca peca_reservada = fila.itens[fila.inicio];
    
    fila.inicio = (fila.inicio + 1) % TAMANHO_FILA;
    
    // Insere na pilha
    pilha.topo++;
    pilha.itens[pilha.topo] = peca_reservada;
    
    // Gera nova peca para a fila
    Peca nova_peca = gerar_peca();
    fila.fim = (fila.fim + 1) % TAMANHO_FILA;
    fila.itens[fila.fim] = nova_peca;
    
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║        PECA RESERVADA COM SUCESSO!        ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("Peca reservada: %c %d\n", peca_reservada.nome, peca_reservada.id);
    printf("Nova peca gerada: %c %d\n", nova_peca.nome, nova_peca.id);
}

// Remove uma peca do topo da pilha de reserva
void usar_peca_reservada() {
    if (pilha.topo == -1) {
        printf("\nErro: Pilha de reserva vazia!\n");
        return;
    }
    
    Peca peca_usada = pilha.itens[pilha.topo];
    pilha.topo--;
    
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║      PECA DE RESERVA USADA COM SUCESSO!   ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("Tipo: %c | ID: %d\n", peca_usada.nome, peca_usada.id);
}

// Exibe o menu principal
void exibir_menu() {
    printf("╔════════════════════════════════════════════╗\n");
    printf("║            MENU PRINCIPAL                 ║\n");
    printf("╠════════════════════════════════════════════╣\n");
    printf("║ 1 - Jogar peca                            ║\n");
    printf("║ 2 - Reservar peca                         ║\n");
    printf("║ 3 - Usar peca reservada                   ║\n");
    printf("║ 0 - Sair do programa                      ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("Escolha uma opcao: ");
}

// Programa principal - controla o fluxo do jogo
int main() {
    int opcao;
    
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║      TETRIS STACK - FILA + PILHA          ║\n");
    printf("║    Nivel Aventureiro - FIFO e LIFO        ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    
    inicializar_fila();
    inicializar_pilha();
    
    exibir_estado();
    
    while (1) {
        exibir_menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                jogar_peca();
                exibir_estado();
                break;
            case 2:
                reservar_peca();
                exibir_estado();
                break;
            case 3:
                usar_peca_reservada();
                exibir_estado();
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
