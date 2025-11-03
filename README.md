# Tetris Stack - Desafios em C

Série de três trabalhos educacionais em C que simulam o gerenciamento de peças do jogo Tetris Stack, progredindo em complexidade com estruturas de dados.

## Arquivos

- `tetris_fila.c` - Nível Novato: Fila circular simples
- `tetris_fila_pilha.c` - Nível Aventureiro: Fila + Pilha
- `tetris_mestre.c` - Nível Mestre: Fila + Pilha + Trocas

## Compilação

```bash
gcc -o tetris_fila tetris_fila.c
gcc -o tetris_fila_pilha tetris_fila_pilha.c
gcc -o tetris_mestre tetris_mestre.c
```

## Execução

```bash
./tetris_fila
./tetris_fila_pilha
./tetris_mestre
```

## Nível Novato

**Arquivo**: `tetris_fila.c`

Implementa uma fila circular com 5 peças (I, O, T, L).

Operações:
- Jogar peça (remove da frente)
- Inserir nova peça (adiciona no fim)
- Sair

## Nível Aventureiro

**Arquivo**: `tetris_fila_pilha.c`

Combina fila circular (5 peças) com pilha de reserva (3 peças).

Operações:
- Jogar peça
- Reservar peça (fila → pilha)
- Usar peça reservada (pilha)
- Sair

## Nível Mestre

**Arquivo**: `tetris_mestre.c`

Adiciona trocas entre fila e pilha.

Operações:
- Jogar peça
- Reservar peça
- Usar peça reservada
- Trocar peça atual (1:1)
- Trocar múltipla (3:3)
- Sair

## Estruturas de Dados

- **Fila Circular**: FIFO, reaproveitamento de espaço
- **Pilha Linear**: LIFO, último a entrar é primeiro a sair

## Atributos das Peças

- `nome`: Tipo da peça (I, O, T, L)
- `id`: Identificador único incremental

## Conceitos Trabalhados

- Fila circular
- Pilha linear
- Structs e arrays
- Operações FIFO/LIFO
- Trocas entre estruturas
- Geração aleatória com seed de tempo
