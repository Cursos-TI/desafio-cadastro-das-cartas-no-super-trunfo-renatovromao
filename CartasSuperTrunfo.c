// CartasSuperTrunfo.c — Projeto final unificado
// ---------------------------------------------------------
// Este programa é a versão final do desafio Super Trunfo.
// Ele junta os 3 níveis em um único código:
//
// - Nível Novato: cadastra 2 cartas e mostra os dados básicos.
// - Nível Aventureiro: além dos dados, calcula densidade e PIB per capita.
// - Nível Mestre: compara atributos entre as cartas e calcula o “Super Poder”.
//
// Observações:
// - Sempre use ponto (.) para decimais (ex.: 12.34).
// - O espaço antes de %c no scanf é para ignorar o “Enter” que sobra no buffer.
// ---------------------------------------------------------

#include <stdio.h>
#include <string.h>

/* ==================== NÍVEL NOVATO ====================
   Aqui só cadastramos duas cartas e mostramos os valores.
   Não usamos laços ou if/else, apenas scanf e printf. */
static void rodarNovato(void) {
    // Estrutura de dados usada neste nível
    typedef struct {
        char estado;     // letra do estado (A..H)
        int  cidade;     // número da cidade (1..4)
        char codigo[4];  // código gerado (ex.: A01)
        int  populacao;
        float area;
        float pib;
        int  pontos;     // pontos turísticos
    } CartaN;

    CartaN c1, c2;

    // Cadastro da carta 1
    printf("Carta 1 — Estado (A-H): "); scanf(" %c", &c1.estado);
    printf("Carta 1 — Cidade (1-4): "); scanf("%d", &c1.cidade);
    printf("Carta 1 — Populacao: "); scanf("%d", &c1.populacao);
    printf("Carta 1 — Area (km2): "); scanf("%f", &c1.area);
    printf("Carta 1 — PIB (R$): "); scanf("%f", &c1.pib);
    printf("Carta 1 — Pontos turisticos: "); scanf("%d", &c1.pontos);
    snprintf(c1.codigo, sizeof c1.codigo, "%c%02d", c1.estado, c1.cidade);

    // Cadastro da carta 2
    printf("\nCarta 2 — Estado (A-H): "); scanf(" %c", &c2.estado);
    printf("Carta 2 — Cidade (1-4): "); scanf("%d", &c2.cidade);
    printf("Carta 2 — Populacao: "); scanf("%d", &c2.populacao);
    printf("Carta 2 — Area (km2): "); scanf("%f", &c2.area);
    printf("Carta 2 — PIB (R$): "); scanf("%f", &c2.pib);
    printf("Carta 2 — Pontos turisticos: "); scanf("%d", &c2.pontos);
    snprintf(c2.codigo, sizeof c2.codigo, "%c%02d", c2.estado, c2.cidade);

    // Exibe os dados cadastrados
    printf("\n=== CARTA 1 ===\n");
    printf("Codigo: %s\n", c1.codigo);
    printf("Populacao: %d\n", c1.populacao);
    printf("Area: %.2f\n", c1.area);
    printf("PIB: %.2f\n", c1.pib);
    printf("Pontos turisticos: %d\n", c1.pontos);

    printf("\n=== CARTA 2 ===\n");
    printf("Codigo: %s\n", c2.codigo);
    printf("Populacao: %d\n", c2.populacao);
    printf("Area: %.2f\n", c2.area);
    printf("PIB: %.2f\n", c2.pib);
    printf("Pontos turisticos: %d\n", c2.pontos);
}

/* ==================== NÍVEL AVENTUREIRO ====================
   Mesmo processo do Novato, mas agora calculamos:
   - Densidade = população / área
   - PIB per capita = PIB / população
   Também mostramos esses novos valores no final. */
static void rodarAventureiro(void) {
    typedef struct {
        char estado;
        int  cidade;
        char codigo[4];
        int  populacao;
        float area;
        float pib;
        int  pontos;
        float densidade;
        float pib_per_capita;
    } CartaA;

    CartaA c1, c2;

    // Cadastro da carta 1
    printf("Carta 1 — Estado (A-H): "); scanf(" %c", &c1.estado);
    printf("Carta 1 — Cidade (1-4): "); scanf("%d", &c1.cidade);
    printf("Carta 1 — Populacao: "); scanf("%d", &c1.populacao);
    printf("Carta 1 — Area (km2): "); scanf("%f", &c1.area);
    printf("Carta 1 — PIB (R$): "); scanf("%f", &c1.pib);
    printf("Carta 1 — Pontos turisticos: "); scanf("%d", &c1.pontos);
    snprintf(c1.codigo, sizeof c1.codigo, "%c%02d", c1.estado, c1.cidade);
    c1.densidade = (float)c1.populacao / c1.area;
    c1.pib_per_capita = c1.pib / (float)c1.populacao;

    // Cadastro da carta 2
    printf("\nCarta 2 — Estado (A-H): "); scanf(" %c", &c2.estado);
    printf("Carta 2 — Cidade (1-4): "); scanf("%d", &c2.cidade);
    printf("Carta 2 — Populacao: "); scanf("%d", &c2.populacao);
    printf("Carta 2 — Area (km2): "); scanf("%f", &c2.area);
    printf("Carta 2 — PIB (R$): "); scanf("%f", &c2.pib);
    printf("Carta 2 — Pontos turisticos: "); scanf("%d", &c2.pontos);
    snprintf(c2.codigo, sizeof c2.codigo, "%c%02d", c2.estado, c2.cidade);
    c2.densidade = (float)c2.populacao / c2.area;
    c2.pib_per_capita = c2.pib / (float)c2.populacao;

    // Exibe dados incluindo os cálculos extras
    printf("\n=== CARTA 1 ===\n");
    printf("Codigo: %s\n", c1.codigo);
    printf("Populacao: %d\n", c1.populacao);
    printf("Area: %.2f\n", c1.area);
    printf("PIB: %.2f\n", c1.pib);
    printf("Pontos turisticos: %d\n", c1.pontos);
    printf("Densidade: %.2f\n", c1.densidade);
    printf("PIB per capita: %.2f\n", c1.pib_per_capita);

    printf("\n=== CARTA 2 ===\n");
    printf("Codigo: %s\n", c2.codigo);
    printf("Populacao: %d\n", c2.populacao);
    printf("Area: %.2f\n", c2.area);
    printf("PIB: %.2f\n", c2.pib);
    printf("Pontos turisticos: %d\n", c2.pontos);
    printf("Densidade: %.2f\n", c2.densidade);
    printf("PIB per capita: %.2f\n", c2.pib_per_capita);
}

/* ==================== NÍVEL MESTRE ====================
   Aqui entram comparações entre as cartas.
   - Agora a população é unsigned long (números maiores).
   - Calculamos os mesmos derivados do Aventureiro.
   - Criamos o “Super Poder”: soma de todos atributos,
     mas a densidade entra invertida (1/densidade).
   - Mostramos quem vence em cada atributo:
     (1 = carta 1, 0 = carta 2).
*/
static void rodarMestre(void) {
    // Dados da carta 1
    char e1; int c1num; char cod1[4];
    unsigned long pop1; float area1, pib1; int pts1;
    // Dados da carta 2
    char e2; int c2num; char cod2[4];
    unsigned long pop2; float area2, pib2; int pts2;

    // Entrada
    printf("Carta 1 — Estado (A-H): "); scanf(" %c", &e1);
    printf("Carta 1 — Cidade (1-4): "); scanf("%d", &c1num);
    printf("Carta 1 — Populacao: "); scanf("%lu", &pop1);
    printf("Carta 1 — Area (km2): "); scanf("%f", &area1);
    printf("Carta 1 — PIB (R$): "); scanf("%f", &pib1);
    printf("Carta 1 — Pontos turisticos: "); scanf("%d", &pts1);

    printf("\nCarta 2 — Estado (A-H): "); scanf(" %c", &e2);
    printf("Carta 2 — Cidade (1-4): "); scanf("%d", &c2num);
    printf("Carta 2 — Populacao: "); scanf("%lu", &pop2);
    printf("Carta 2 — Area (km2): "); scanf("%f", &area2);
    printf("Carta 2 — PIB (R$): "); scanf("%f", &pib2);
    printf("Carta 2 — Pontos turisticos: "); scanf("%d", &pts2);

    // Cria códigos das cartas
    snprintf(cod1, sizeof cod1, "%c%02d", e1, c1num);
    snprintf(cod2, sizeof cod2, "%c%02d", e2, c2num);

    // Calcula derivados
    float dens1 = area1 != 0.0f ? (float)((double)pop1 / (double)area1) : 0.0f;
    float dens2 = area2 != 0.0f ? (float)((double)pop2 / (double)area2) : 0.0f;
    float ppc1  = pop1 != 0UL  ? (float)((double)pib1 / (double)pop1)   : 0.0f;
    float ppc2  = pop2 != 0UL  ? (float)((double)pib2 / (double)pop2)   : 0.0f;

    // Calcula Super Poder
    float inv_d1 = dens1 != 0.0f ? 1.0f / dens1 : 0.0f;
    float inv_d2 = dens2 != 0.0f ? 1.0f / dens2 : 0.0f;
    float sp1 = (float)pop1 + area1 + pib1 + (float)pts1 + inv_d1 + ppc1;
    float sp2 = (float)pop2 + area2 + pib2 + (float)pts2 + inv_d2 + ppc2;

    // Comparações (1 = carta 1 vence; 0 = carta 2 vence)
    int r_pop  = (pop1  > pop2)  ? 1 : 0;
    int r_area = (area1 > area2) ? 1 : 0;
    int r_pib  = (pib1  > pib2)  ? 1 : 0;
    int r_pts  = (pts1  > pts2)  ? 1 : 0;
    int r_den  = (dens1 < dens2) ? 1 : 0; // aqui vence a menor densidade
    int r_ppc  = (ppc1  > ppc2)  ? 1 : 0;
    int r_sp   = (sp1   > sp2)   ? 1 : 0;

    // Exibe todos os dados
    printf("\n=== CARTA 1 (%s) ===\n", cod1);
    printf("Populacao: %lu\n", pop1);
    printf("Area: %.2f\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos: %d\n", pts1);
    printf("Densidade: %.4f\n", dens1);
    printf("PIB per capita: %.4f\n", ppc1);
    printf("Super Poder: %.4f\n", sp1);

    printf("\n=== CARTA 2 (%s) ===\n", cod2);
    printf("Populacao: %lu\n", pop2);
    printf("Area: %.2f\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos: %d\n", pts2);
    printf("Densidade: %.4f\n", dens2);
    printf("PIB per capita: %.4f\n", ppc2);
    printf("Super Poder: %.4f\n", sp2);

    // Exibe quem venceu em cada atributo
    printf("\n=== RESULTADOS (1 = Carta 1 venceu; 0 = Carta 2 venceu) ===\n");
    printf("Populacao: %d\n", r_pop);
    printf("Area: %d\n", r_area);
    printf("PIB: %d\n", r_pib);
    printf("Pontos turisticos: %d\n", r_pts);
    printf("Densidade (menor vence): %d\n", r_den);
    printf("PIB per capita: %d\n", r_ppc);
    printf("Super Poder: %d\n", r_sp);
}

/* ==================== PROGRAMA PRINCIPAL ====================
   Mostra um menu de escolha do nível e chama a função certa.
   Obs: usamos switch no menu, mas dentro das funções
   Novato e Aventureiro continuamos sem if/loops.
*/
int main(void) {
    int nivel;

    printf("===== Super Trunfo — Países (selecione o nível) =====\n");
    printf("1) Novato\n");
    printf("2) Aventureiro\n");
    printf("3) Mestre\n");
    printf("Escolha: ");

    if (scanf("%d", &nivel) != 1) return 0;

    switch (nivel) {
        case 1:  rodarNovato();      break;
        case 2:  rodarAventureiro(); break;
        case 3:
        default: rodarMestre();      break;
    }
    return 0;
}