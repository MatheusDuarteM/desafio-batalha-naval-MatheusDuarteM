#include <stdio.h>
#include <string.h> // Necessário para memset
#include <stdbool.h> // Para usar true/false (opcional, mas legível)

// Definindo constantes para os limites da matriz principal
#define LINHA 10
#define COLUNA 10

// Função auxiliar para verificar se uma coordenada é válida na matriz
bool indiceValido(int linha, int coluna) {
    return (linha >= 0 && linha < LINHA && coluna >= 0 && coluna < COLUNA);
}

int main() {

    int matriz[LINHA][COLUNA];
    int escolha;
    int escolha_poder; // Renomeado de escolha2 para clareza
    int valorX, valorY;
    int i; // Mover declaração do 'i' para fora do loop se precisar usar depois

    // Preenche a matriz principal com zeros
    memset(matriz, 0, sizeof(matriz));

    do {
        // Apresenta o menu de opções
        printf("\n--- MENU ---\n");
        printf("1 - Adicionar Navio\n");
        printf("2 - Usar Poder Cone\n");
        printf("3 - Usar Poder Cruz\n");
        printf("4 - Usar Poder Octaedro\n");
        printf("Escolha uma opcao: ");

        // Lê a escolha do usuário (CORRIGIDO: sem espaço extra)
        if (scanf("%d", &escolha_poder) != 1) {
            printf("Entrada invalida. Tente novamente.\n");
            while(getchar() != '\n'); // Limpa buffer de entrada
            continue; // Pula para a próxima iteração do do-while
        }

        // Executa a ação baseada na escolha
        switch (escolha_poder) {
            case 1: // Adicionar Navio
                printf("--- Adicionar Navio ---\n");
                printf("Digite a coordenada X inicial: ");
                 if (scanf("%d", &valorX) != 1) { printf("Entrada X invalida.\n"); while(getchar() != '\n'); break; } // Sai do case se erro
                printf("Digite a coordenada Y inicial: ");
                 if (scanf("%d", &valorY) != 1) { printf("Entrada Y invalida.\n"); while(getchar() != '\n'); break; } // Sai do case se erro

                // Validação básica dos índices iniciais
                if (!indiceValido(valorX, valorY)) {
                     printf("ERRO: Coordenadas iniciais (%d, %d) fora dos limites!\n", valorX, valorY);
                     break; // Sai do case
                }

                // Lógica original do case 1 (com a verificação externa)
                if (matriz[valorX][valorY] == 0) { // Verifica apenas o ponto inicial
                    if (valorX <= valorY) { // Define a coluna alvo e o intervalo de linhas
                        int coluna_alvo = valorY;
                        printf("Adicionando navio na coluna %d, linhas %d a %d\n", coluna_alvo, valorX, valorY);
                        for (i = valorX; i <= valorY; i++) {
                             if (indiceValido(i, coluna_alvo)) { // Verifica cada célula antes de modificar
                                 // Aqui deveria verificar se matriz[i][coluna_alvo] == 0 novamente
                                 // para seguir a regra de "não sobrescrever", mas mantendo o original:
                                 matriz[i][coluna_alvo] += 10; // Assume valor 10 para navio
                                 printf(" -> matriz[%d][%d] = %d\n", i, coluna_alvo, matriz[i][coluna_alvo]);
                             } else {
                                  printf(" -> AVISO: Coordenada (%d, %d) fora dos limites. Ignorando.\n", i, coluna_alvo);
                             }
                        }
                    } else { // valorX > valorY
                        int coluna_alvo = valorX;
                         printf("Adicionando navio na coluna %d, linhas %d a %d\n", coluna_alvo, valorY, valorX);
                        for (i = valorY; i <= valorX; i++) {
                             if (indiceValido(i, coluna_alvo)) { // Verifica cada célula antes de modificar
                                 matriz[i][coluna_alvo] += 10;
                                 printf(" -> matriz[%d][%d] = %d\n", i, coluna_alvo, matriz[i][coluna_alvo]);
                             } else {
                                  printf(" -> AVISO: Coordenada (%d, %d) fora dos limites. Ignorando.\n", i, coluna_alvo);
                             }
                        }
                    }
                } else {
                    printf("ERRO: Local inicial (%d, %d) ja preenchido com %d!\n", valorX, valorY, matriz[valorX][valorY]);
                }
                break; // *** ESSENCIAL: Termina o case 1 ***

            case 2: // Poder Cone
                printf("--- Usar Poder Cone ---\n");
                printf("Digite a coordenada X do alvo: ");
                if (scanf("%d", &valorX) != 1) { printf("Entrada X invalida.\n"); while(getchar() != '\n'); break; }
                printf("Digite a coordenada Y do alvo: ");
                 if (scanf("%d", &valorY) != 1) { printf("Entrada Y invalida.\n"); while(getchar() != '\n'); break; }

                printf("Ativando Cone em (%d, %d)\n", valorX, valorY);
                // Cone Simples: Alvo + linha abaixo (3 células) - Valor 20
                if (indiceValido(valorX, valorY)) {
                    matriz[valorX][valorY] = 20;
                    printf(" -> matriz[%d][%d] = %d\n", valorX, valorY, matriz[valorX][valorY]);
                }
                int r_cone = valorX + 1;
                int c_cone_esq = valorY - 1;
                int c_cone_cen = valorY;
                int c_cone_dir = valorY + 1;

                if (indiceValido(r_cone, c_cone_esq)) {
                     matriz[r_cone][c_cone_esq] = 20;
                     printf(" -> matriz[%d][%d] = %d\n", r_cone, c_cone_esq, matriz[r_cone][c_cone_esq]);
                }
                 if (indiceValido(r_cone, c_cone_cen)) {
                     matriz[r_cone][c_cone_cen] = 20;
                     printf(" -> matriz[%d][%d] = %d\n", r_cone, c_cone_cen, matriz[r_cone][c_cone_cen]);
                }
                 if (indiceValido(r_cone, c_cone_dir)) {
                     matriz[r_cone][c_cone_dir] = 20;
                     printf(" -> matriz[%d][%d] = %d\n", r_cone, c_cone_dir, matriz[r_cone][c_cone_dir]);
                }
                break; // Termina o case 2

            case 3: // Poder Cruz
                printf("--- Usar Poder Cruz ---\n");
                printf("Digite a coordenada X do alvo: ");
                if (scanf("%d", &valorX) != 1) { printf("Entrada X invalida.\n"); while(getchar() != '\n'); break; }
                printf("Digite a coordenada Y do alvo: ");
                 if (scanf("%d", &valorY) != 1) { printf("Entrada Y invalida.\n"); while(getchar() != '\n'); break; }

                 printf("Ativando Cruz em (%d, %d)\n", valorX, valorY);
                // Cruz: Alvo + vizinhos N, S, L, O - Valor 30
                 if (indiceValido(valorX, valorY)) { // Alvo
                    matriz[valorX][valorY] = 30;
                     printf(" -> matriz[%d][%d] = %d\n", valorX, valorY, matriz[valorX][valorY]);
                 }
                 if (indiceValido(valorX - 1, valorY)) { // Cima
                    matriz[valorX - 1][valorY] = 30;
                     printf(" -> matriz[%d][%d] = %d\n", valorX - 1, valorY, matriz[valorX - 1][valorY]);
                 }
                  if (indiceValido(valorX + 1, valorY)) { // Baixo
                    matriz[valorX + 1][valorY] = 30;
                     printf(" -> matriz[%d][%d] = %d\n", valorX + 1, valorY, matriz[valorX + 1][valorY]);
                 }
                   if (indiceValido(valorX, valorY - 1)) { // Esquerda
                    matriz[valorX][valorY - 1] = 30;
                     printf(" -> matriz[%d][%d] = %d\n", valorX, valorY - 1, matriz[valorX][valorY - 1]);
                 }
                   if (indiceValido(valorX, valorY + 1)) { // Direita
                    matriz[valorX][valorY + 1] = 30;
                     printf(" -> matriz[%d][%d] = %d\n", valorX, valorY + 1, matriz[valorX][valorY + 1]);
                 }
                break; // Termina o case 3

             case 4: // Poder Octaedro (Losango/Diamante - Raio 1, igual à Cruz neste caso)
                printf("--- Usar Poder Octaedro ---\n");
                printf("Digite a coordenada X do alvo: ");
                 if (scanf("%d", &valorX) != 1) { printf("Entrada X invalida.\n"); while(getchar() != '\n'); break; }
                printf("Digite a coordenada Y do alvo: ");
                 if (scanf("%d", &valorY) != 1) { printf("Entrada Y invalida.\n"); while(getchar() != '\n'); break; }

                 printf("Ativando Octaedro (Raio 1) em (%d, %d)\n", valorX, valorY);
                 // Octaedro (Raio 1): Alvo + vizinhos N, S, L, O - Valor 40
                  if (indiceValido(valorX, valorY)) { // Alvo
                    matriz[valorX][valorY] = 40;
                     printf(" -> matriz[%d][%d] = %d\n", valorX, valorY, matriz[valorX][valorY]);
                 }
                 if (indiceValido(valorX - 1, valorY)) { // Cima
                    matriz[valorX - 1][valorY] = 40;
                     printf(" -> matriz[%d][%d] = %d\n", valorX - 1, valorY, matriz[valorX - 1][valorY]);
                 }
                  if (indiceValido(valorX + 1, valorY)) { // Baixo
                    matriz[valorX + 1][valorY] = 40;
                     printf(" -> matriz[%d][%d] = %d\n", valorX + 1, valorY, matriz[valorX + 1][valorY]);
                 }
                   if (indiceValido(valorX, valorY - 1)) { // Esquerda
                    matriz[valorX][valorY - 1] = 40;
                     printf(" -> matriz[%d][%d] = %d\n", valorX, valorY - 1, matriz[valorX][valorY - 1]);
                 }
                   if (indiceValido(valorX, valorY + 1)) { // Direita
                    matriz[valorX][valorY + 1] = 40;
                     printf(" -> matriz[%d][%d] = %d\n", valorX, valorY + 1, matriz[valorX][valorY + 1]);
                 }
                break; // Termina o case 4

            default: // Caso a escolha não seja 1, 2, 3 ou 4
                printf("Opcao invalida! Escolha entre 1 e 4.\n");
                break; // Opcional, mas bom ter
        } // Fim do switch

        // Pergunta se quer continuar
        printf("\nDigite 1 para continuar, outro numero para sair: ");
        if (scanf("%d", &escolha) != 1) {
            printf("Entrada invalida. Saindo...\n");
            while(getchar() != '\n'); // Limpa buffer
            escolha = 0; // Força a saída
        }

    } while (escolha == 1); // Loop continua se escolha for 1

    // --- IMPRIMINDO A MATRIZ FINAL ---
    printf("\n--- Estado final da Matriz --- \n");
    for (i = 0; i < LINHA; i++) {      // Loop externo para as linhas
        for (int j = 0; j < COLUNA; j++) {  // Loop interno para as colunas (declarar 'j' aqui)
            // Imprime com um espaçamento fixo para alinhar melhor
            printf("%3d ", matriz[i][j]); // %3d reserva 3 espaços
        }
        printf("\n"); // Nova linha após cada linha da matriz
    }

    printf("\nPrograma encerrado.\n");
    return 0;
}