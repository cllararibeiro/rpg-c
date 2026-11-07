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
    p->usosHabilidade = 2;
    p->pocoesCura = 0;

    switch (opcao) {
        case 1:
            strcpy(p->nome, "Bella Cullen");
            p->classe = class_bella;
            p->vidaMax = 150;
            p->vida = 150;
            p->forca = 15;
            p->defesa = 20;
            p->agilidade = 10;
            p->inteligencia = 10;
            strcpy(p->arma, "Escudo Mental");
            strcpy(p->armadura, "Aliança dos Cullen");
            break;

        case 2:
            strcpy(p->nome, "Edward Cullen");
            p->classe = class_edward;
            p->vidaMax = 150;
            p->vida = 150;
            p->forca = 15;
            p->defesa = 12;
            p->agilidade = 15;
            p->inteligencia = 16;
            strcpy(p->arma, "Telepatia");
            strcpy(p->armadura, "Aliança dos Cullen");
            break;

        case 3:
            strcpy(p->nome, "Jacob Black");
            p->classe = class_jacob;
            p->vidaMax = 150;
            p->vida = 150;
            p->forca = 20;
            p->defesa = 10;
            p->agilidade = 8;
            p->inteligencia = 10;
            strcpy(p->arma, "Amuleto Quileute");
            strcpy(p->armadura, "Pele de Lobo");
            break;

        default:
            printf("\nOpcao invalida! Selecionando Bella por padrao.\n");
            strcpy(p->nome, "Bella Cullen");
            p->classe = class_bella;
            p->vidaMax = 150;
            p->vida = 150;
            p->forca = 15;
            p->defesa = 20;
            p->agilidade = 10;
            p->inteligencia = 10;
            strcpy(p->arma, "Escudo Mental");
            strcpy(p->armadura, "Aliança dos Cullen");
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
            printf("[.] ");   // Casa vazia
        }
    }
    printf("]\n");
    printf("Voce esta na casa %d de %d.\n", posicaoJogador + 1, tamanho);
}


// --- VETORES ESTÁTICOS DE MONSTROS POR FASE ---
static Monstro monstrosFase1[3] = {
    {"Neófito Selvagem", "Um vampiro recém-transformado e descontrolado.", 30, 30, 10, 3, 1, 15},
    {"Rastreador Volturi", "Um batedor treinado enviando informações a Aro.", 45, 45, 12, 5, 1, 25},
    {"Felix (Guarda Volturi)", "Um executor brutal da guarda real.", 70, 70, 16, 8, 2, 50}
};

static Monstro monstrosFase2[3] = {
    {"Guarda Elite Volturi", "Soldado veterano treinado em Volterra.", 60, 60, 18, 10, 2, 40},
    {"Demetri (O Rastreador)", "Consegue rastrear qualquer mente do mundo.", 85, 85, 22, 12, 3, 75},
    {"Jane Volturi", "Cria a ilusão de dor física insuportável no alvo.", 100, 100, 26, 11, 3, 100}
};

static Monstro monstrosFase3[3] = {
    {"Vanguardista de Volterra", "Guerreiro disposto a morrer por Aro.", 90, 90, 28, 15, 4, 120},
    {"Caius Volturi", "Um dos anciãos líderes, implacável.", 120, 120, 32, 18, 4, 160},
    {"Aro Volturi", "Líder supremo dos Volturi e chefe final.", 160, 160, 38, 20, 5, 300}
};

// --- FUNÇÃO PARA OBTER PONTEIRO DO MONSTRO E RESETAR VIDA ---
Monstro* obterMonstro(int fase, int idMonstro) {
    Monstro *m = NULL;

    if (fase == 1) m = &monstrosFase1[idMonstro - 1];
    else if (fase == 2) m = &monstrosFase2[idMonstro - 1];
    else if (fase == 3) m = &monstrosFase3[idMonstro - 1];

    if (m != NULL) {
        m->vida = m->vidaMax; // Restaura a vida para novo combate
    }

    return m;
}

int calcularAtaqueComFuria(const Personagem *p) {
    return p->forca * 2;
}

int aplicarEscudoBella(int danoInimigo) {
    int danoReduzido = danoInimigo / 2;
    return (danoReduzido < 1) ? 1 : danoReduzido;
}


// --- FUNÇÃO PRINCIPAL DE COMBATE ---
void iniciarCombate(Personagem *p, Monstro *m) {
    int opcao;
    int dano;
    
    // Para Bella e Jacob: limite de 2 usos por monstro
    int usosHabilidadeCombate = 2; 
    
    bool escudoAtivo = false; 

    limparTela();
    printf("=========================================================\n");
    printf("  ⚠️  ENCONTRO: %s (Nível %d)\n", m->nome, m->nivel);
    printf("  \"%s\"\n", m->descricao);
    printf("=========================================================\n\n");
    pausar();

    while (p->vida > 0 && m->vida > 0) {
        limparTela();
        escudoAtivo = false;
        
        // --- HUD DE VIDA E HABILIDADE ---
        printf("=========================================================\n");
        printf(" 👤 %-20s | Vida: %3d / %-3d\n", p->nome, p->vida, p->vidaMax);
        printf(" 👾 %-20s | Vida: %3d / %-3d\n", m->nome, m->vida, m->vidaMax);
        printf("=========================================================\n\n");

        // --- EXIBIÇÃO DA OPÇÃO DO MENU ---
        printf("Escolha sua ação:\n");
        printf("1. Atacar Normal\n");

        if (p->classe == class_edward) {
            printf("2. Usar Telepatia / Esquiva Perfeita (%d/2 usos no JOGO)\n", p->usosHabilidade);
        } else {
            printf("2. Usar Habilidade Especial (%d/2 usos no combate)\n", usosHabilidadeCombate);
        }
        printf("3. Usar Poção de Cura (%d disponíveis)\n", p->pocoesCura); // <--- NOVA OPÇÃO
        printf("4. Fugir Normal (Chance de falhar)\n");
        printf("Opção: ");
        
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); 
            opcao = 0;
        } else {
            getchar();
        }

        // --- TURNO DO JOGADOR ---
        if (opcao == 1) {
            dano = (p->forca - m->defesa) + rolarDado(6);
            if (dano < 1) dano = 1;

            m->vida -= dano;
            printf("\n⚔️  Você atacou %s e causou %d de dano!\n", m->nome, dano);
            pausar();

        } else if (opcao == 2) {
            // LÓGICA DO EDWARD (2x no Jogo Todo)
            if (p->classe == class_edward) {
                if (p->usosHabilidade <= 0) {
                    printf("\n⚠️  Edward já gastou seus 2 usos de Telepatia no jogo! Perdeu o turno.\n");
                    pausar();
                } else {
                    p->usosHabilidade--; // Desconta do total do jogo via ponteiro
                    printf("\n🔮 [TELEPATIA DE EDWARD] Edward lê os movimentos de %s!\n", m->nome);
                    printf("🏃 Você esquivou perfeitamente e escapou da luta sem levar nenhum dano!\n");
                    printf("   (Usos restantes no jogo: %d/2)\n", p->usosHabilidade);
                    pausar();
                    return; // Encerra o combate imediatamente sem o monstro contra-atacar
                }
            } 
            // LÓGICA DA BELLA E JACOB (2x por Combate)
            else {
                if (usosHabilidadeCombate <= 0) {
                    printf("\n⚠️  Você já usou sua habilidade 2 vezes neste combate! Perdeu a vez.\n");
                    pausar();
                } else {
                    usosHabilidadeCombate--;

                    if (p->classe == class_bella) {
                        escudoAtivo = true;
                        dano = (p->forca - m->defesa) + rolarDado(6);
                        if (dano < 1) dano = 1;
                        m->vida -= dano;

                        printf("\n🛡️  [ESCUDO MENTAL] Bella ataca (%d de dano) e ergue uma barreira!\n", dano);
                        printf("    O próximo dano recebido será reduzido pela METADE!\n");
                        pausar();

                    } else if (p->classe == class_jacob) {
                        dano = (calcularAtaqueComFuria(p) - m->defesa) + rolarDado(6);
                        if (dano < 1) dano = 1;
                        m->vida -= dano;

                        printf("\n🐺 [FÚRIA QUILEUTE] Jacob ataca com FORÇA DUPLA!\n");
                        printf("💥 Causou %d de dano em %s!\n", dano, m->nome);
                        pausar();
                    }
                }
            }

       } else if (opcao == 3) {
            // USAR POÇÃO DE CURA
            if (p->pocoesCura <= 0) {
                printf("\n⚠️ Você não tem nenhuma poção de cura no inventário! Perdeu a vez.\n");
                pausar();
            } else {
                p->pocoesCura--; // Consome 1 poção
                int cura = 35;   // Quantidade de vida recuperada pela poção
                p->vida += cura;
                if (p->vida > p->vidaMax) p->vida = p->vidaMax;

                printf("\n🧪 [POÇÃO USADA] Você bebeu uma poção de cura e recuperou %d de vida!\n", cura);
                printf("   Vida atual: %d / %d | Poções restantes: %d\n", p->vida, p->vidaMax, p->pocoesCura);
                pausar();
            }

        } else if (opcao == 4) { // Mudou de 3 para 4
            if (rolarDado(6) >= 4) {
                printf("\n🏃 Você conseguiu fugir do combate!\n");
                pausar();
                return;
            } else {
                printf("\n❌ Falha ao fugir! O inimigo bloqueou sua saída.\n");
                pausar();
            }
        } else {
            printf("\nOpção inválida! Você perdeu o turno.\n");
            pausar();
        }

        // --- TURNO DO MONSTRO ---
        if (m->vida > 0) {
            dano = (m->ataque - p->defesa) + rolarDado(6);
            if (dano < 1) dano = 1;

            if (escudoAtivo) {
                dano = aplicarEscudoBella(dano);
                printf("\n🛡️  O Escudo de Bella absorveu o impacto! Dano reduzido para %d.\n", dano);
            }

            p->vida -= dano;
            printf("\n💥 %s atacou você e causou %d de dano!\n", m->nome, dano);
            pausar();
        }
    }

    // --- RESULTADO FINAL ---
    limparTela();
    if (p->vida <= 0) {
        printf("=========================================================\n");
        printf("  ☠️  VOCÊ FOI DERROTADO! GAME OVER.\n");
        printf("=========================================================\n\n");
    } else if (m->vida <= 0) {
        printf("=========================================================\n");
        printf("  🎉 VOCÊ DERROTOU %s!\n", m->nome);
        p->xp += m->xpRecompensa;
        printf("  ✨ Você ganhou %d de XP! (XP Total: %d)\n", m->xpRecompensa, p->xp);
        printf("=========================================================\n\n");
    }
    pausar();
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


bool executarFase(Personagem *p, int numeroFase, int *posicaoAtual, int tabuleiro[]) {
    // 10 casas por fase: Fase 1 (0..9), Fase 2 (10..19), Fase 3 (20..29)
    int casaInicial = (numeroFase - 1) * 10;
    int casaFinal = casaInicial + 9;
    bool chefeDerrotado = false;
    
    *posicaoAtual = casaInicial;

    limparTela();
    printf("=========================================================\n");
    printf("                  INICIANDO FASE %d DE 3\n", numeroFase);
    printf("        Território: Casas %d a %d no Tabuleiro\n", casaInicial, casaFinal);
    printf("=========================================================\n\n");
    pausar();

    while (p->vida > 0 && !chefeDerrotado) {
        limparTela();
        
        int passos = rolarDado(6);
        printf("🎲 Você jogou o D6 e tirou %d!\n", passos);
        
        *posicaoAtual += passos;
        
        // Trava para não passar da casa do Chefe
        if (*posicaoAtual >= casaFinal) {
            *posicaoAtual = casaFinal;
            printf("\n⛔ Ops, não é possível ultrapassar sem derrotar o chefe final!\n");
        }

        exibirTabuleiro(tabuleiro, TAMANHO_TABULEIRO, *posicaoAtual);
        pausar();

        int tipoCasa = tabuleiro[*posicaoAtual];

        if (tipoCasa == casa_cura) {
            p->pocoesCura++; // Adiciona a poção ao inventário via ponteiro
            printf("\n🧪 VOCÊ ENCONTROU UMA POÇÃO DE CURA!\n");
            printf("   A poção foi guardada na sua bolsa. (Poções no inventário: %d)\n", p->pocoesCura);
            pausar();
        }
        else if (tipoCasa == casa_bonus) {
            int bonusDef = 2;
            p->defesa += bonusDef;
            printf("\n🛡️  CASA BÔNUS! Sua defesa aumentou em +%d! (Defesa total: %d)\n", bonusDef, p->defesa);
            pausar();
        } 
        else if (tipoCasa == casa_inimigo) {
            // Se estiver na primeira metade do bloco da fase enfrenta o Monstro 1, senão o Monstro 2
            int idMonstro = (*posicaoAtual <= casaInicial + 5) ? 1 : 2;
            Monstro *inimigo = obterMonstro(numeroFase, idMonstro);
            
            printf("\n⚔️  Você caiu numa casa de INIMIGO! Enfrentando %s...\n", inimigo->nome);
            pausar();
            iniciarCombate(p, inimigo);
        } 
        else if (tipoCasa == casa_chefe || *posicaoAtual == casaFinal) {
            Monstro *chefe = obterMonstro(numeroFase, 3);
            printf("\n⚠️  Você chegou à casa do CHEFE da Fase %d! Enfrentando %s...\n", numeroFase, chefe->nome);
            pausar();
            iniciarCombate(p, chefe);

            if (p->vida > 0) {
                chefeDerrotado = true;
            }
        } 
        else {
            printf("\n🍃 Casa vazia. O caminho está calmo.\n");
            pausar();
        }

        if (p->vida <= 0) {
            return false;
        }
    }

    printf("\n🎉 FASE %d CONCLUÍDA COM SUCESSO!\n", numeroFase);
    pausar();
    return true;
}
