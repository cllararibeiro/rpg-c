#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h> // Necessario para o srand(time(NULL))
#define TAMANHO_TABULEIRO 30

typedef enum {
    class_bella,
    class_edward,
    class_jacob,
}ClassPersonagem;

typedef enum {
    casa_vazia = 0,
    casa_inimigo = 1,
    casa_chefe = 2,
    casa_cura = 3,
    casa_bonus = 4
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
    int pocoesCura;
    int usosHabilidade;
    int nivel;
    char arma[40];
    char armadura[40];
} Personagem;


typedef struct {
    char nome[40];
    char descricao[100];
    int vida;
    int vidaMax;
    int ataque;
    int defesa;
    int nivel;
    int xpRecompensa;
} Monstro;

// Retorna um ponteiro para o monstro da lista
Monstro* obterMonstro(int fase, int idMonstro);

// Função de combate principal
void iniciarCombate(Personagem *p, Monstro *m);

void exibirMenuPersonagens(void);
void escolherPersonagem(Personagem *p);
void exibirStatus(const Personagem *p);
void exibirIntroducao(void);
void pausar(void);
void limparTela(void);
int rolarDado(int lados);
void exibirTabuleiro(int tabuleiro[], int tamanho, int posicaoJogador);
int moverJogador(int posicaoAtual, int passos, int tamanho);
bool executarFase(Personagem *p, int numeroFase, int *posicaoAtual, int tabuleiro[]);
int calcularAtaqueComFuria(const Personagem *p);
int aplicarEscudoBella(int danoInimigo);
void aplicarBonusAleatorio(Personagem *p);