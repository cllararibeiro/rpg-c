#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Necessario para o srand(time(NULL))
#define TAMANHO_TABULEIRO 10

typedef enum {
    class_bella,
    class_edward,
    class_jacob,
}ClassPersonagem;

typedef enum {
    casa_vazia = 0,
    casa_inimigo = 1,
    casa_chefe = 2
} TipoCasa;

typedef struct {
    char nome[30];
    ClassPersonagem classe;
    int vida;
    int vidaMax;
    int forca;
    int defesa;
    int agilidade;
    int inteligencia;
    int xp;
    int nivel;
    char arma[40];
    char armadura[40];
} Personagem;

void exibirMenuPersonagens(void);
void escolherPersonagem(Personagem *p);
void exibirStatus(const Personagem *p);
void exibirIntroducao(void);
void pausar(void);
void limparTela(void);
int rolarDado(int lados);
void exibirTabuleiro(int tabuleiro[], int tamanho, int posicaoJogador);
int moverJogador(int posicaoAtual, int passos, int tamanho);