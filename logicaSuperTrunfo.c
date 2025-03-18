#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    int estado;
    int codigo;
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

float calcular_densidade_populacional(Carta carta) {
    return (float)carta.populacao / carta.area;
}

float calcular_pib_per_capita(Carta carta) {
    return carta.pib / carta.populacao;
}

float calcular_super_poder(Carta carta) {
    float inverso_densidade = 1 / carta.densidade_populacional;
    return carta.populacao + carta.area + carta.pib + carta.pontos_turisticos + carta.pib_per_capita + inverso_densidade;
}

void comparar_atributos(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    float valor1_attr1, valor2_attr1, valor1_attr2, valor2_attr2;
    float soma_carta1, soma_carta2;
    int v1, v2;
    
    switch (atributo1) {
        case 1:
            valor1_attr1 = carta1.populacao;
            valor2_attr1 = carta2.populacao;
            break;
        case 2:
            valor1_attr1 = carta1.area;
            valor2_attr1 = carta2.area;
            break;
        case 3:
            valor1_attr1 = carta1.pib;
            valor2_attr1 = carta2.pib;
            break;
        case 4:
            valor1_attr1 = carta1.pontos_turisticos;
            valor2_attr1 = carta2.pontos_turisticos;
            break;
        case 5:
            valor1_attr1 = carta1.densidade_populacional;
            valor2_attr1 = carta2.densidade_populacional;
            break;
        case 6:
            valor1_attr1 = carta1.pib_per_capita;
            valor2_attr1 = carta2.pib_per_capita;
            break;
        case 7:
            valor1_attr1 = carta1.super_poder;
            valor2_attr1 = carta2.super_poder;
            break;
        default:
            printf("Opção inválida\n");
            return;
    }

    switch (atributo2) {
        case 1:
            valor1_attr2 = carta1.populacao;
            valor2_attr2 = carta2.populacao;
            break;
        case 2:
            valor1_attr2 = carta1.area;
            valor2_attr2 = carta2.area;
            break;
        case 3:
            valor1_attr2 = carta1.pib;
            valor2_attr2 = carta2.pib;
            break;
        case 4:
            valor1_attr2 = carta1.pontos_turisticos;
            valor2_attr2 = carta2.pontos_turisticos;
            break;
        case 5:
            valor1_attr2 = carta1.densidade_populacional;
            valor2_attr2 = carta2.densidade_populacional;
            break;
        case 6: 
            valor1_attr2 = carta1.pib_per_capita;
            valor2_attr2 = carta2.pib_per_capita;
            break;
        case 7:
            valor1_attr2 = carta1.super_poder;
            valor2_attr2 = carta2.super_poder;
            break;
        default:
            printf("Opção inválida\n");
            return;
    }

    printf("Comparação de Atributos:\n");

    printf("Atributo 1: ");
    v1 = (atributo1 == 5) ? (valor1_attr1 < valor2_attr1) : (valor1_attr1 > valor2_attr1);
    printf("Carta 1: %.2f, Carta 2: %.2f -> Vencedor: Carta %d\n", valor1_attr1, valor2_attr1, (v1 ? 1 : 2));

    printf("Atributo 2: ");
    v2 = (atributo2 == 5) ? (valor1_attr2 < valor2_attr2) : (valor1_attr2 > valor2_attr2);
    printf("Carta 1: %.2f, Carta 2: %.2f -> Vencedor: Carta %d\n", valor1_attr2, valor2_attr2, (v2 ? 1 : 2));

    soma_carta1 = valor1_attr1 + valor1_attr2;
    soma_carta2 = valor2_attr1 + valor2_attr2;

    printf("\nSoma dos Atributos:\n");
    printf("Carta 1: %.2f, Carta 2: %.2f\n", soma_carta1, soma_carta2);

    if (soma_carta1 > soma_carta2)
        printf("\nCarta 1 venceu!\n");
    else if (soma_carta1 < soma_carta2)
        printf("\nCarta 2 venceu!\n");
    else
        printf("\nEmpate!\n");
}

int main() {
    Carta carta1, carta2;

    strcpy(carta1.nome, "Brasil");
    carta1.populacao = 210000000;
    carta1.area = 8516000;
    carta1.pib = 2000000000;
    carta1.pontos_turisticos = 100;
    carta1.densidade_populacional = calcular_densidade_populacional(carta1);
    carta1.pib_per_capita = calcular_pib_per_capita(carta1);
    carta1.super_poder = calcular_super_poder(carta1);

    strcpy(carta2.nome, "Argentina");
    carta2.populacao = 45000000;
    carta2.area = 2780000;
    carta2.pib = 600000000;
    carta2.pontos_turisticos = 150;
    carta2.densidade_populacional = calcular_densidade_populacional(carta2);
    carta2.pib_per_capita = calcular_pib_per_capita(carta2);
    carta2.super_poder = calcular_super_poder(carta2);

    int atributo1, atributo2;
    
    printf("Escolha o primeiro atributo para comparação:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n7. Super Poder\n");
    scanf("%d", &atributo1);

    printf("Escolha o segundo atributo para comparação (diferente do primeiro):\n");
    do {
        printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n7. Super Poder\n");
        scanf("%d", &atributo2);
    } while (atributo2 == atributo1);

    comparar_atributos(carta1, carta2, atributo1, atributo2);

    return 0;
}
