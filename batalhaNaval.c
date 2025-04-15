#include <stdio.h>
#include <string.h> // Necessário para memset

// Função separada para imprimir a matriz (opcional, mas organizado)
void imprimirMatrizFormatada(int mat[10][10]) {
    int i, j;
    printf("{\n"); // Imprime a chave de abertura e começa na nova linha

    for (i = 0; i < 10; i++) { // Loop para as linhas
        printf("  "); // Adiciona uma pequena indentação para cada linha

        for (j = 0; j < 10; j++) { // Loop para as colunas
            printf("%d", mat[i][j]); // Imprime o valor do elemento

            // Adiciona uma vírgula APENAS se NÃO for o último elemento da linha
            if (j < 9) {
                printf(",");
            }
        }

        // Adiciona uma quebra de linha APENAS se NÃO for a última linha da matriz
        if (i < 9) {
             printf("\n");
        } else {
             // Adiciona a quebra de linha final antes da chave de fechamento
             printf("\n");
        }
    }

    printf("}\n"); // Imprime a chave de fechamento na sua própria linha
}

int main() {

    int matriz[10][10];

    int escolha;
    int escolha2;
    
    int valorX;
    int valorY;
    
    // Preenche o bloco de memória ocupado pela matriz com zeros
    // memset(ponteiro_para_memoria, valor_byte, numero_de_bytes);
    memset(matriz, 0, sizeof(matriz));
    do{
        printf("Digite o valor X: ");
        scanf("%d",&valorX);
        printf("Digite o valor Y: ");
        scanf("%d",&valorY);
        
        if(matriz[valorX][valorY] == 0)
        {
        if(valorX <= valorY)
        {
            
        for(int i = valorX; i <= valorY; i++){
            matriz[i][valorY] = matriz[i][valorY] + 10;
            printf("O valor referente a matriz[%d][%d] = %d\n", i, valorY, matriz[i][valorY]);
           
        }
        }else if (valorX >= valorY && matriz[valorX][valorY] == 0){
            for(int i = valorY; i <= valorX; i++){
            matriz[i][valorX] = matriz[i][valorX] + 10;
            printf("O valor referente a matriz[%d][%d] = %d\n", i, valorX, matriz[i][valorX]);
           
        }
        }
        }else{
            printf("Local já preenchido \n");
        }
        printf("Se quer continua digite 1 !");
        scanf("%d",&escolha);
    }while(escolha == 1);
 // --- IMPRIMINDO A MATRIZ FINAL ---
    printf("\n--- Estado final da Matriz --- \n");
    imprimirMatrizFormatada(matriz); // Chama a função para imprimir
    
    return 0;
}