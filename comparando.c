#include <stdio.h>

#define TAM_NOME 50

int main() {
    // Dados fixos das cartas 
    char nomeCidade1[TAM_NOME] = "Cidade A";
    int populacao1 = 1000000;
    float area1 = 500.0;
    float pib1 = 25.0;
    int pontosTuristicos1 = 12;

    char nomeCidade2[TAM_NOME] = "Cidade B";
    int populacao2 = 800000;
    float area2 = 300.0;
    float pib2 = 30.0;
    int pontosTuristicos2 = 15;

    // Densidade demográfica
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // Menu de seleção
    int atributo1, atributo2;

    printf("===== SUPER TRUNFO - DESAFIO FINAL =====\n");
    printf("Cartas disponíveis: %s e %s\n", nomeCidade1, nomeCidade2);

    // Exibir opções
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua escolha (1 a 5): ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida! Encerrando programa.\n");
        return 1;
    }

    // Exibir segundo menu (sem o atributo já escolhido)
    printf("\nEscolha o segundo atributo para comparar:\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
            }
        }
    }
    printf("Digite sua escolha: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida! Encerrando programa.\n");
        return 1;
    }

    // Variáveis auxiliares
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;
    float soma1, soma2;

    // Função auxiliar para buscar valor do atributo
    float getAtributo(int escolha, int carta) {
        switch (escolha) {
            case 1: return carta == 1 ? populacao1 : populacao2;
            case 2: return carta == 1 ? area1 : area2;
            case 3: return carta == 1 ? pib1 : pib2;
            case 4: return carta == 1 ? pontosTuristicos1 : pontosTuristicos2;
            case 5: return carta == 1 ? densidade1 : densidade2;
            default: return 0;
        }
    }

    // Atribuir valores dos atributos
    valor1_carta1 = getAtributo(atributo1, 1);
    valor1_carta2 = getAtributo(atributo1, 2);
    valor2_carta1 = getAtributo(atributo2, 1);
    valor2_carta2 = getAtributo(atributo2, 2);

    // Exibir valores
    printf("\nAtributos escolhidos:\n");
    for (int i = 0; i < 2; i++) {
        int escolha = (i == 0) ? atributo1 : atributo2;
        const char* nome = (escolha == 1) ? "População" :
                           (escolha == 2) ? "Área" :
                           (escolha == 3) ? "PIB" :
                           (escolha == 4) ? "Pontos Turísticos" :
                                            "Densidade Demográfica";
        float v1 = (i == 0) ? valor1_carta1 : valor2_carta1;
        float v2 = (i == 0) ? valor1_carta2 : valor2_carta2;

        printf("%s:\n", nome);
        printf("  %s: %.2f\n", nomeCidade1, v1);
        printf("  %s: %.2f\n", nomeCidade2, v2);
    }

    // Lógica de comparação por atributo (considera inversão para densidade)
    float resultado1 = (atributo1 == 5) ? 
        (valor1_carta1 < valor1_carta2 ? 1 : (valor1_carta1 > valor1_carta2 ? -1 : 0)) :
        (valor1_carta1 > valor1_carta2 ? 1 : (valor1_carta1 < valor1_carta2 ? -1 : 0));

    float resultado2 = (atributo2 == 5) ? 
        (valor2_carta1 < valor2_carta2 ? 1 : (valor2_carta1 > valor2_carta2 ? -1 : 0)) :
        (valor2_carta1 > valor2_carta2 ? 1 : (valor2_carta1 < valor2_carta2 ? -1 : 0));

    // Soma dos valores para decisão final
    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    printf("\nSoma dos atributos:\n");
    printf("  %s: %.2f\n", nomeCidade1, soma1);
    printf("  %s: %.2f\n", nomeCidade2, soma2);

    // Resultado final
    printf("\nResultado Final: ");
    printf("%s\n", 
        soma1 > soma2 ? nomeCidade1 :
        soma2 > soma1 ? nomeCidade2 : "Empate!");

    return 0;
}
