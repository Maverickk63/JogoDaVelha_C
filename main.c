#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int game[3][3];

bool checkWin(int jogador);
void jogada(int jogador);
void tela();
void IAfacil(int jogador);

int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      game[i][j] = 0;
    }
  }
  int jogadas = 0;
  while (true) {
    if (jogadas % 2 == 0) // Turno do player
    {
      printf("Seu Turno (Você é o X)\n");
      jogada(1);
      tela();
      if (checkWin(1)) {
        printf("Você venceu!!!!");
        return 0;
      }
      jogadas++;
    }
    if (jogadas == 9) {
      break;
    }
    if (jogadas % 2 != 0) // Turno da IA
    {
      printf("Turno da IA (O)\n");
      IAfacil(2);
      tela();
      if (checkWin(2)) {
        printf("Você Perdeu");
        return 0;
      }
      jogadas++;
    }
  }
  printf("Deu velha...");
  return 0;
}

bool checkWin(int jogador) {
  // Teste de vitoria por linha
  for (int y = 0; y < 3; y++) {
    if (game[y][0] == jogador && game[y][1] == jogador &&
        game[y][2] == jogador) {
      return true;
    }
  }
  // teste de vitoria por coluna
  for (int x = 0; x < 3; x++) {
    if (game[0][x] == jogador && game[1][x] == jogador &&
        game[2][x] == jogador) {
      return true;
    }
  }
  // teste de vitoria diagonal
  if (game[0][0] == jogador && game[1][1] == jogador && game[2][2] == jogador) {
    return true;
  }
  if (game[0][2] == jogador && game[1][1] == jogador && game[2][0] == jogador) {
    return true;
  }
  return false;
}

void jogada(int jogador) {
  bool posval = false;
  while (!posval) {
    int x = 4, y = 4;
    bool valido = false;
    // pegar cordenada Y
    while (!valido) {
      printf("\n[Indique a Linha a jogar]\n");
      scanf("%d", &y);
      if (y > 0 || y < 4) {
        valido = true;
      } else {
        printf("[Valor Invalido , insira um numero de 1 a 3]\n\n");
      }
    }
    // Pegar cordenada X
    valido = false;
    while (!valido) {
      printf("\n[Indique a Coluna a jogar]\n");
      scanf("%d", &x);
      if (x > 0 || x < 4) {
        valido = true;
      } else {
        printf("[Valor Invalido , insira um numero de 1 a 3]\n\n");
      }
    }

    // Checkar se a posição ja foi jogada
    x = x - 1;
    y = y - 1;
    if (game[y][x] != 0) {
      printf("[posição ja usada]\n_________________\n");
    } else {
      posval = true;
      game[y][x] = jogador;
    }
  }
}

void tela() {
  for (int y = 0; y < 3; y++) {
    printf("\n=============\n");
    for (int x = 0; x < 3; x++) {
      if (game[y][x] == 0) {
        printf("|   ");
      } else if (game[y][x] == 1) {
        printf("| X ");
      } else {
        printf("| O ");
      }
    }
    printf("|\n");
  }
  printf("=============\n\n");
}

void IAfacil(int jogador) {
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      if (game[y][x] == 0) {
        game[y][x] = jogador;
        return;
      }
    }
  }
}