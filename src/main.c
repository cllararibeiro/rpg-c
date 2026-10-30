#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include <time.h> // Necessario para o srand(time(NULL))

int main() {
    srand(time(NULL));
    Personagem jogador;

    exibirIntroducao();
    limparTela();

    escolherPersonagem(&jogador);
    limparTela();

    exibirStatus(&jogador);
    limparTela();

    // 2. Criação do Tabuleiro da Fase 1 (10 casas)
    // 0 = CASA_VAZIA, 1 = CASA_INIMIGO, 2 = CASA_CHEFE
    int tabuleiro[TAMANHO_TABULEIRO] = {
        casa_vazia,    // Casa 0 (Inicio)
        casa_vazia,    // Casa 1
        casa_inimigo,  // Casa 2
        casa_vazia,    // Casa 3
        casa_vazia,    // Casa 4
        casa_inimigo,  // Casa 5
        casa_vazia,    // Casa 6
        casa_vazia,    // Casa 7
        casa_inimigo,  // Casa 8
        casa_chefe     // Casa 9 (Final)
    };

    int posicaoAtual = 0; // Jogador começa na primeira casa (índice 0)

    limparTela();
    printf("=== INICIO DA JORNADA ===\n");
    exibirTabuleiro(tabuleiro, TAMANHO_TABULEIRO, posicaoAtual);
    pausar();

    // 3. Simulação de 3 movimentos no tabuleiro
    for (int rodada = 1; rodada <= 3; rodada++) {
        limparTela();
        int passos = rolarDado(6);
        printf("Rodada %d: Voce rolou um D6 e tirou o numero %d!\n", rodada, passos);

        // Atualiza a posição com o tratamento de limites
        posicaoAtual = moverJogador(posicaoAtual, passos, TAMANHO_TABULEIRO);

        exibirTabuleiro(tabuleiro, TAMANHO_TABULEIRO, posicaoAtual);
        pausar();
    }

    return 0;
}