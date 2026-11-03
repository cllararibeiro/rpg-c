#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"

int main() {
    srand(time(NULL));
    Personagem jogador;

    // 1. Passo 1: Escolha de Personagem
    exibirIntroducao();
    limparTela();
    escolherPersonagem(&jogador);
    limparTela();
    exibirStatus(&jogador);
    limparTela();

    int tabuleiro[TAMANHO_TABULEIRO] = {
    // FASE 1 (Casas 0 a 9)
    casa_vazia, casa_cura, casa_inimigo, casa_vazia, casa_bonus, casa_vazia, casa_inimigo, casa_cura, casa_vazia, casa_chefe,

    // FASE 2 (Casas 10 a 19)
    casa_vazia, casa_cura, casa_inimigo, casa_vazia, casa_bonus, casa_vazia, casa_inimigo, casa_cura, casa_vazia, casa_chefe,

    // FASE 3 (Casas 20 a 29)
    casa_vazia, casa_cura, casa_inimigo, casa_vazia, casa_bonus, casa_vazia, casa_inimigo, casa_cura, casa_vazia, casa_chefe
};

    int posicaoAtual = 0; // Inicia na Casa 0
    bool venceuJogo = true;

    // 3. Loop das 3 Fases Sequenciais
    for (int fase = 1; fase <= 3; fase++) {
        bool sucesso = executarFase(&jogador, fase, &posicaoAtual, tabuleiro);

        if (!sucesso) {
            venceuJogo = false;
            break; // Se morreu, interrompe o loop
        }
    }

    // 4. Encerramento do Jogo
    limparTela();
    if (venceuJogo) {
        printf("=========================================================\n");
        printf("  🏆 VITÓRIA FINAL! VOCÊ SUPEROU AS 3 FASES!\n");
        printf("  Você derrotou a Guarda Volturi e protegeu Cullens e Quileutes.\n");
        printf("=========================================================\n\n");
        exibirStatus(&jogador);
    } else {
        printf("=========================================================\n");
        printf("  ☠️ GAME OVER - Sua jornada terminou na metade do caminho.\n");
        printf("=========================================================\n");
    }

    return 0;
}