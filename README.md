# 🐺 Crepúsculo: A Proteção de Renesmee

**Aluno:** Maria Clara Ribeiro de Brito
**Matrícula:** 20260015755 
**Disciplina:** DCT1106 - Programação (2026.2)  
**Professor:** Thommas K. S. Flores  
**Curso:** Bacharelado em Sistemas de Informação (BSI) - UFRN  

---

## 📜 História e Contexto

O nascimento de Renesmee Cullen gerou um grande alarde no mundo dos vampiros. Os Volturi, a antiga e implacável guarda de Volterra, acreditam erradamente que a menina é uma criança imortal — uma criação proibida pelas leis milenares dos vampiros.

Liderados por Aro, os Volturi marcham com sua guarda de elite em direção a Forks para destruir a garota e punir a família Cullen. Sua missão é liderar a defesa na região, romper o cerco inimigo ao longo do tabuleiro, proteger Renesmee durante a travessia e derrotar Aro e seus anciãos na grande batalha final.

---

## 🎭 Personagens Jogáveis

O jogo conta com 3 heróis jogáveis com atributos, equipamentos e habilidades únicas:

| Personagem | Classe (Enum) | Vida | Força | Defesa | Agilidade | Inteligência | Arma | Armadura | Habilidade Especial |
| :--- | :--- | :---: | :---: | :---: | :---: | :---: | :--- | :--- | :--- |
| **Bella Cullen** | `class_bella` | 150 | 15 | 20 | 10 | 10 | Escudo Mental | Aliança dos Cullen | **Escudo Mental:** Reduz pela metade o próximo dano recebido no combate. |
| **Edward Cullen** | `class_edward` | 150 | 15 | 12 | 15 | 16 | Telepatia | Aliança dos Cullen | **Telepatia:** Lê mentes para esquivar perfeitamente e fugir sem tomar dano (2x por jogo). |
| **Jacob Black** | `class_jacob` | 150 | 20 | 10 | 8 | 10 | Amuleto Quileute | Pele de Lobo | **Fúria Quileute:** Realiza um ataque devastador com força dobrada ($2 \times \text{Força}$). |

---

## 👾 Fases e Monstros

O jogo possui 3 fases de dificuldade progressiva no tabuleiro, com 3 monstros distintos em cada fase:

### Fase 1: Floresta de Forks (Casas 0 a 9)
* **Missão:** Romper a patrulha inicial e defender o perímetro da floresta.
* **Monstros:**
  1. *Neófito Selvagem* (Vida: 30, Ataque: 10, Defesa: 3, Recompensa XP: 15)
  2. *Rastreador Volturi* (Vida: 45, Ataque: 12, Defesa: 5, Recompensa XP: 25)
  3. **Chefe da Fase:** *Felix - Guarda Volturi* (Vida: 70, Ataque: 16, Defesa: 8, Recompensa XP: 50)

### Fase 2: Passagem de Volterra (Casas 10 a 19)
* **Missão:** Interceptara guarda de elite em avanço rápido.
* **Monstros:**
  1. *Guarda Elite Volturi* (Vida: 60, Ataque: 18, Defesa: 10, Recompensa XP: 40)
  2. *Demetri (O Rastreador)* (Vida: 85, Ataque: 22, Defesa: 12, Recompensa XP: 75)
  3. **Chefe da Fase:** *Jane Volturi* (Vida: 100, Ataque: 26, Defesa: 11, Recompensa XP: 100)

### Fase 3: A Clareira de Forks (Casas 20 a 29)
* **Missão:** Enfrentar a liderança dos Volturi e garantir a sobrevivência de Renesmee.
* **Monstros:**
  1. *Vanguardista de Volterra* (Vida: 90, Ataque: 28, Defesa: 15, Recompensa XP: 120)
  2. *Caius Volturi* (Vida: 120, Ataque: 32, Defesa: 18, Recompensa XP: 160)
  3. **Chefe da Fase:** *Aro Volturi (Líder Supremo)* (Vida: 160, Ataque: 38, Defesa: 20, Recompensa XP: 300)

---

## 🎲 Dinâmica e Regras do Jogo

### 1. Tabuleiro e Movimentação
* O tabuleiro é representado por um vetor estático de 30 posições divididas em 3 fases (10 casas por fase).
* Em cada turno, o jogador lança um dado de 6 faces (D6) para avançar no tabuleiro.
* Tipos de Casa (`TipoCasa` enum):
  * **Casa Vazia (`[.]`):** Nenhum evento.
  * **Casa Cura (`[.]`):** Encontra uma poção de cura e adiciona ao inventário.
  * **Casa Bônus (`[.]`):** Concede +2 de Defesa ao herói.
  * **Casa Inimigo (`[I]`):** Inicia um combate por turnos contra um soldado Volturi.
  * **Casa Chefe (`[C]`):** Inicia o combate obrigatorio contra o chefe da fase.

### 2. Sistema de Combate por Turnos
* **Ação do Jogador:** Pode escolher entre Atacar Normal, Usar Habilidade Especial, Beber Poção de Cura ou Tentar Fugir.
* **Fórmulas:**
  $$\text{Dano do Jogador} = \max(1, (\text{Força} - \text{Defesa Inimiga}) + \text{D6})$$
  $$\text{Dano do Inimigo} = \max(1, (\text{Ataque Inimigo} - \text{Defesa do Jogador}) + \text{D6})$$
* **Recompensa e Evolução por Ponteiro:** Ao derrotar um inimigo, além do XP, a função `aplicarBonusAleatorio(Personagem *p)` é chamada via ponteiro, aumentando aleatoriamente um dos atributos do herói (Força, Defesa, Agilidade ou Vida Máxima).

---

## 🛠️ Requisitos Técnicos Implementados

1. **Estruturas (`struct`):** Modelagem completa para `Personagem` e `Monstro`.
2. **Enumeradores (`enum`):** Uso de `ClassPersonagem` para as classes e `TipoCasa` para os eventos do tabuleiro.
3. **Ponteiros:** Atualização direta na memória de status como Vida, XP, Habilidades e bônus de atributos (`Personagem *p`, `Monstro *m`).
4. **Modularização:** Separação limpa em arquivos de cabeçalho (`jogo.h`), implementação (`jogo.c`) e ponto de entrada (`main.c`).
5. **Tratamento de Entradas:** Validação de buffer no `scanf` para prevenir travamentos com caracteres inválidos.

---

## 💻 Como Compilar e Jogar

### Pré-requisitos
* Compilador GCC instalado (`build-essential` no Linux, MinGW no Windows ou Xcode Command Line Tools no macOS).

### Passo a Passo

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/cllararibeiro/rpg-c.git
   cd rpg-c
   ```

2. **Compilação via Terminal (Linux / macOS / Windows):**
   ```bash
   gcc -Wall -Wextra src/main.c src/jogo.c -I src -o jogo
   ```

3. **Execução:**
   * **Linux / macOS:**
     ```bash
     ./jogo
     ```
   * **Windows (PowerShell / CMD):**
     ```cmd
     jogo.exe
     ```

---

## 📁 Estrutura do Repositório

```text
.
├── README.md           # Documentação completa do projeto
├── src/                # Código-fonte do jogo
│   ├── main.c          # Ponto de entrada do programa e controle das fases
│   ├── jogo.c          # Implementação das funções, combate e regras
│   └── jogo.h          # Declaração das structs, enums e protótipos de funções
└── video/
    └── link_video.md   # Link para o vídeo de gameplay demonstrativo
```

---

## 📽️ Vídeo de Demonstração

* **Link da Apresentação:** 