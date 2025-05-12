#include <stdio.h>
#include <locale.h>
#include <string.h>

struct jogo {
    char nome[50];
    char genero[30];
    int ano_lancamento;
    float preco;
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct jogo jogos[25];
    int quantidade, i;

    printf("Quantos jogos serão registrados? (máx. 25):\n");
    scanf("%d", &quantidade);

    if (quantidade > 25 || quantidade <= 0) {
        printf("Quantidade inválida.\n");
        return 1;
    }

    getchar(); // Limpar buffer do teclado

    for (i = 0; i < quantidade; i++) {
        printf("\n--- Cadastro do %dº jogo ---\n", i + 1);

        printf("Nome do jogo:\n");
        fgets(jogos[i].nome, sizeof(jogos[i].nome), stdin);
        jogos[i].nome[strcspn(jogos[i].nome, "\n")] = '\0';  // Remove '\n'

        printf("Gênero do jogo:\n");
        fgets(jogos[i].genero, sizeof(jogos[i].genero), stdin);
        jogos[i].genero[strcspn(jogos[i].genero, "\n")] = '\0';

        printf("Ano de lançamento:\n");
        scanf("%d", &jogos[i].ano_lancamento);

        printf("Preço:\n");
        scanf("%f", &jogos[i].preco);

        getchar(); // Limpar buffer após entrada numérica
    }

    printf("\n=== Lista de Jogos Registrados ===\n");

    for (i = 0; i < quantidade; i++) {
        printf("\nJogo %d\n", i + 1);
        printf("Nome: %s\n", jogos[i].nome);
        printf("Gênero: %s\n", jogos[i].genero);
        printf("Ano de lançamento: %d\n", jogos[i].ano_lancamento);
        printf("Preço: R$ %.2f\n", jogos[i].preco);
    }

    return 0;
}