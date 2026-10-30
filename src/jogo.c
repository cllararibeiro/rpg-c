#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"

// contextualização da história de Crepúsculo
void exibirIntroducao(void) {
    limparTela();
    printf("=========================================================\n");
    printf("         CREPUSCULO: A PROTECAO DE RENESMEE              \n");
    printf("=========================================================\n\n");
    printf("O nascimento de Renesmee Cullen gerou um grande alarde no\n");
    printf("mundo dos vampiros. Os Volturi, a antiga e implacavel   \n");
    printf("guarda de Volterra, acreditam que a menina e uma crianca \n");
    printf("imortal proibida pelas leis dos vampiros.\n\n");
    printf("Liderados por Aro, os Volturi marcham em direcao a Forks \n");
    printf("para destruir a garota e punir a familia Cullen.\n\n");
    printf("Sua missao e liderar a defesa, romper o cerco inimigo,  \n");
    printf("proteger Renesmee na travessia e derrotar Aro na grande \n");
    printf("batalha final da clareira.\n");
    printf("=========================================================\n\n");
    pausar();
}

void exibirMenuPersonagens(void) {
    limparTela();
    printf("===========================================\n");
    printf("       ESCOLHA O SEU PERSONAGEM\n");
    printf("===========================================\n");
    printf("1. Bella Cullen (Mãe)  (Escudo Mental / Defesa Alta)\n");
    printf("2. Edward Cullen (Pai) (Telepatia / Agilidade Alta)\n");
    printf("3. Jacob Black (Protetor) (Furia Quileute / Forca Alta)\n");
    printf("===========================================\n");
    printf("Digite o numero da sua opcao: ");
}

void escolherPersonagem(Personagem *p) {
    int opcao;

    exibirMenuPersonagens();
    scanf("%d", &opcao);
    getchar();

    p->xp = 0;
    p->nivel = 1;

    switch (opcao) {
        case 1:
            strcpy(p->nome, "Bella Cullen");
            p->classe = class_bella;
            p->vidaMax = 120;
            p->vida = 120;
            p->forca = 10;
            p->defesa = 14;
            p->agilidade = 9;
            p->inteligencia = 12;
            strcpy(p->arma, "Anel dos Cullen");
            strcpy(p->armadura, "Casaco de Neve");
            break;

        case 2:
            strcpy(p->nome, "Edward Cullen");
            p->classe = class_edward;
            p->vidaMax = 95;
            p->vida = 95;
            p->forca = 9;
            p->defesa = 8;
            p->agilidade = 15;
            p->inteligencia = 16;
            strcpy(p->arma, "Brasao dos Cullen");
            strcpy(p->armadura, "Traje de Caca");
            break;

        case 3:
            strcpy(p->nome, "Jacob Black");
            p->classe = class_jacob;
            p->vidaMax = 140;
            p->vida = 140;
            p->forca = 16;
            p->defesa = 10;
            p->agilidade = 8;
            p->inteligencia = 6;
            strcpy(p->arma, "Amuleto Quileute");
            strcpy(p->armadura, "Bermuda de Couro");
            break;

        default:
            printf("\nOpcao invalida! Selecionando Bella por padrao.\n");
            strcpy(p->nome, "Bella Cullen");
            p->classe = class_bella;
            p->vidaMax = 120;
            p->vida = 120;
            p->forca = 10;
            p->defesa = 14;
            p->agilidade = 9;
            p->inteligencia = 12;
            strcpy(p->arma, "Anel dos Cullen");
            strcpy(p->armadura, "Casaco de Neve");
            break;
    }
}

void exibirStatus(const Personagem *p) {
    printf("\n===========================================\n");
    printf("         FICHA DO PERSONAGEM\n");
    printf("===========================================\n");
    printf("Nome: %s\n", p->nome);
    printf("Nivel: %d | XP: %d\n", p->nivel, p->xp);
    printf("Vida: %d/%d\n", p->vida, p->vidaMax);
    printf("Forca: %d | Defesa: %d\n", p->forca, p->defesa);
    printf("Agilidade: %d | Inteligencia: %d\n", p->agilidade, p->inteligencia);
    printf("Arma: %s\n", p->arma);
    printf("Armadura: %s\n", p->armadura);
    printf("===========================================\n\n");
    pausar();
}

// Exibe o desenho do tabuleiro e a posicao atual do jogador
void exibirTabuleiro(int tabuleiro[], int tamanho, int posicaoJogador) {
    printf("\n=== TABULEIRO DA FASE ===\n[ ");
    for (int i = 0; i < tamanho; i++) {
        if (i == posicaoJogador) {
            printf("[P] "); // Representa o Personagem
        } else if (tabuleiro[i] == casa_chefe) {
            printf("[C] "); // Representa o Chefe no final
        } else if (tabuleiro[i] == casa_inimigo) {
            printf("[I] "); // Representa um Inimigo no caminho
        } else {
            printf(". ");   // Casa vazia
        }
    }
    printf("]\n");
    printf("Voce esta na casa %d de %d.\n", posicaoJogador + 1, tamanho);
}

// Calcula a nova posicao do jogador e garante que ele nao passe do limite
int moverJogador(int posicaoAtual, int passos, int tamanho) {
    int novaPosicao = posicaoAtual + passos;

    // Se passar da ultima casa, trava na casa final (onde esta o Chefe)
    if (novaPosicao >= tamanho - 1) {
        novaPosicao = tamanho - 1;
    }

    return novaPosicao;
}

void pausar(void) {
    printf("\nPressione ENTER para continuar...");
    getchar(); 
}

// Procedimento inteligente para limpar a tela
void limparTela(void) {
    #ifdef _WIN32
        system("cls");   // Se for Windows
    #else
        system("clear"); // Se for Linux ou Mac
    #endif
}

int rolarDado(int lados) {
    int numeroSorteado = rand();                 
    int resultado = (numeroSorteado % lados) + 1;
    
    return resultado;                           
}