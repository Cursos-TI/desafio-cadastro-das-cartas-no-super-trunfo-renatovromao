// CartasSuperTrunfo.c — Projeto final unificado com seleção de nível em tempo de execução
// Níveis: 1) Novato  2) Aventureiro  3) Mestre
// Compile uma única vez e escolha o nível ao executar:
//   gcc -std=c11 -Wall -Wextra -O2 CartasSuperTrunfo.c -o CartasSuperTrunfo
// Execute:
//   ./CartasSuperTrunfo   (Windows: CartasSuperTrunfo.exe)
//
// Resumo:
// - rodarNovato(): cadastro de duas cartas; apenas scanf/printf; sem laços/ifs.
// - rodarAventureiro(): idem ao Novato + cálculo e exibição de Densidade e PIB per capita; sem laços/ifs.
// - rodarMestre(): comparação atributo a atributo e cálculo do Super Poder (com densidade invertida).
//
// Observações de entrada:
// - Use PONTO para decimais em floats (ex.: 12.34).
// - Há um espaço antes de %c nos scanf de 'estado' para consumir o newline pendente.

#include <stdio.h>
#include <string.h>

/* -------------------- NÍVEL NOVATO --------------------
   Sem laços e sem condicionais nesta função.
   Lê e mostra duas cartas com:
   estado (A..H), cidade (1..4), população (int), área (float),
   PIB (float) e pontos turísticos (int). */
static void rodarNovato(void) {
    // Estrutura local do nível Novato
    typedef struct {
        char estado;     // 'A'..'H'
        int  cidade;     // 1..4
        char codigo[4];  // ex.: "A01"
        int  populacao;  // int
        float area;      // km²
        float pib;       // R$
        int  pontos;     // pontos turísticos
    } CartaN;

    CartaN c1, c2;

    // Carta 1
    printf("Carta 1 — Estado (A-H): "); scanf(" %c", &c1.estado);
    printf("Carta 1 — Cidade (1-4): "); scanf("%d", &c1.cidade);
    printf("Carta 1 — Populacao (int): "); scanf("%d", &c1.populacao);
    printf("Carta 1 — Area (float, km2): "); scanf("%f", &c1.area);
    printf("Carta 1 — PIB (float, R$): "); scanf("%f", &c1.pib);
    printf("Carta 1 — Pontos turisticos (int): "); scanf("%d", &c1.pontos);
    snprintf(c1.codigo, sizeof c1.codigo, "%c%02d", c1.estado, c1.cidade);

    // Carta 2
    printf("\nCarta 2 — Estado (A-H): "); scanf(" %c", &c2.estado);
    printf("Carta 2 — Cidade (1-4): "); scanf("%d", &c2.cidade);
    printf("Carta 2 — Populacao (int): "); scanf("%d", &c2.populacao);
    printf("Carta 2 — Area (float, km2): "); scanf("%f", &c2.area);
    printf("Carta 2 — PIB (float, R$): "); scanf("%f", &c2.pib);
    printf("Carta 2 — Pontos turisticos (int): "); scanf("%d", &c2.pontos);
    snprintf(c2.codigo, sizeof c2.codigo, "%c%02d", c2.estado, c2.cidade);

    // Saída formatada (com \n corretos!)
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

/* -------------------- NÍVEL AVENTUREIRO --------------------
   Sem laços e sem condicionais nesta função.
   Além dos campos do Novato, calcula:
   - densidade = população / área
   - pib_per_capita = PIB / população */
static void rodarAventureiro(void) {
    typedef struct {
        char estado;     // 'A'..'H'
        int  cidade;     // 1..4
        char codigo[4];  // "A01"
        int  populacao;  // int
        float area;      // km²
        float pib;       // R$
        int  pontos;     // pontos turísticos
        float densidade;      // pop/area
        float pib_per_capita; // pib/pop
    } CartaA;

    CartaA c1, c2;

    // Carta 1
    printf("Carta 1 — Estado (A-H): "); scanf(" %c", &c1.estado);
    printf("Carta 1 — Cidade (1-4): "); scanf("%d", &c1.cidade);
    printf("Carta 1 — Populacao (int): "); scanf("%d", &c1.populacao);
    printf("Carta 1 — Area (float, km2): "); scanf("%f", &c1.area);
    printf("Carta 1 — PIB (float, R$): "); scanf("%f", &c1.pib);
    printf("Carta 1 — Pontos turisticos (int): "); scanf("%d", &c1.pontos);
    snprintf(c1.codigo, sizeof c1.codigo, "%c%02d", c1.estado, c1.cidade);
    c1.densidade = (float)c1.populacao / c1.area;      // conforme enunciado
    c1.pib_per_capita = c1.pib / (float)c1.populacao;  // idem

    // Carta 2
    printf("\nCarta 2 — Estado (A-H): "); scanf(" %c", &c2.estado);
    printf("Carta 2 — Cidade (1-4): "); scanf("%d", &c2.cidade);
    printf("Carta 2 — Populacao (int): "); scanf("%d", &c2.populacao);
    printf("Carta 2 — Area (float, km2): "); scanf("%f", &c2.area);
    printf("Carta 2 — PIB (float, R$): "); scanf("%f", &c2.pib);
    printf("Carta 2 — Pontos turisticos (int): "); scanf("%d", &c2.pontos);
    snprintf(c2.codigo, sizeof c2.codigo, "%c%02d", c2.estado, c2.cidade);
    c2.densidade = (float)c2.populacao / c2.area;
    c2.pib_per_capita = c2.pib / (float)c2.populacao;

    // Saída
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

/* -------------------- NÍVEL MESTRE --------------------
   Com condicionais.
   - População agora é unsigned long.
   - Calcula derivados (densidade, PIB per capita).
   - Calcula o Super Poder: soma de todos os atributos, com densidade invertida (1/densidade).
   - Compara as cartas e imprime 1 (carta 1 vence) ou 0 (carta 2 vence). */
static void rodarMestre(void) {
    // Carta 1
    char e1; int c1num; char cod1[4];
    unsigned long pop1; float area1, pib1; int pts1;
    // Carta 2
    char e2; int c2num; char cod2[4];
    unsigned long pop2; float area2, pib2; int pts2;

    // Entrada (note o espaço antes de %c)
    printf("Carta 1 — Estado (A-H): "); scanf(" %c", &e1);
    printf("Carta 1 — Cidade (1-4): "); scanf("%d", &c1num);
    printf("Carta 1 — Populacao (unsigned long): "); scanf("%lu", &pop1);
    printf("Carta 1 — Area (float, km2): "); scanf("%f", &area1);
    printf("Carta 1 — PIB (float, R$): "); scanf("%f", &pib1);
    printf("Carta 1 — Pontos turisticos (int): "); scanf("%d", &pts1);

    printf("\nCarta 2 — Estado (A-H): "); scanf(" %c", &e2);
    printf("Carta 2 — Cidade (1-4): "); scanf("%d", &c2num);
    printf("Carta 2 — Populacao (unsigned long): "); scanf("%lu", &pop2);
    printf("Carta 2 — Area (float, km2): "); scanf("%f", &area2);
    printf("Carta 2 — PIB (float, R$): "); scanf("%f", &pib2);
    printf("Carta 2 — Pontos turisticos (int): "); scanf("%d", &pts2);

    // Códigos (A01, B02...)
    snprintf(cod1, sizeof cod1, "%c%02d", e1, c1num);
    snprintf(cod2, sizeof cod2, "%c%02d", e2, c2num);

    // Derivados (conversões para evitar perda de precisão na divisão)
    float dens1 = area1 != 0.0f ? (float)((double)pop1 / (double)area1) : 0.0f;
    float dens2 = area2 != 0.0f ? (float)((double)pop2 / (double)area2) : 0.0f;
    float ppc1  = pop1 != 0UL  ? (float)((double)pib1 / (double)pop1)   : 0.0f;
    float ppc2  = pop2 != 0UL  ? (float)((double)pib2 / (double)pop2)   : 0.0f;

    // Super Poder: soma de todos os atributos, com densidade invertida
    float inv_d1 = dens1 != 0.0f ? 1.0f / dens1 : 0.0f;
    float inv_d2 = dens2 != 0.0f ? 1.0f / dens2 : 0.0f;
    float sp1 = (float)pop1 + area1 + pib1 + (float)pts1 + inv_d1 + ppc1;
    float sp2 = (float)pop2 + area2 + pib2 + (float)pts2 + inv_d2 + ppc2;

    // Resultados (1 = Carta 1 vence; 0 = Carta 2 vence)
    int r_pop  = (pop1  > pop2)  ? 1 : 0;
    int r_area = (area1 > area2) ? 1 : 0;
    int r_pib  = (pib1  > pib2)  ? 1 : 0;
    int r_pts  = (pts1  > pts2)  ? 1 : 0;
    int r_den  = (dens1 < dens2) ? 1 : 0; // menor densidade vence
    int r_ppc  = (ppc1  > ppc2)  ? 1 : 0;
    int r_sp   = (sp1   > sp2)   ? 1 : 0;

    // Saída detalhada
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

    printf("\n=== RESULTADOS (1 = Carta 1 venceu; 0 = Carta 2 venceu) ===\n");
    printf("Populacao: %d\n", r_pop);
    printf("Area: %d\n", r_area);
    printf("PIB: %d\n", r_pib);
    printf("Pontos turisticos: %d\n", r_pts);
    printf("Densidade (menor vence): %d\n", r_den);
    printf("PIB per capita: %d\n", r_ppc);
    printf("Super Poder: %d\n", r_sp);
}

/* -------------------- PROGRAMA PRINCIPAL --------------------
   Mostra um menu simples e chama o nível escolhido.
   Nota: aqui usamos 'switch' (condicional), mas as funções
   Novato/Aventureiro continuam sem if/loops como pedido. */
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