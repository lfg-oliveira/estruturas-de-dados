#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int valor;
  struct Node *prox;
} Node;

void insereNoComeco(Node **root, int valor) {
  Node novo = {valor, NULL};
  if (*root == NULL) {
    *root = (Node *)malloc(sizeof(Node));
    **root = novo;
    return;
  }
  Node *tmp = *root;
  while (tmp->prox != NULL) {
    tmp = tmp->prox;
  }
  tmp->prox = (Node *)malloc(sizeof(Node));
  if (tmp->prox == NULL) {
    fprintf(stderr, "Não foi possivel fazer a alocação.");
    return;
  }
  *(tmp->prox) = novo;
}

void insereEm(Node **root, int pos, int valor) {
  Node *tmp = *root;
  for (int i = 0; i < pos; i++) {
    if (tmp->prox == NULL) {
      if(i != pos - 1) printf("Lista menor que que o esperado...Inserindo na posicao %d\n", i+1);
      Node novo = {valor, NULL};
      tmp->prox = (Node *)malloc(sizeof(Node));
      *(tmp->prox) = novo;
      return;
    }
    tmp = tmp->prox;
  }
  Node novo = {valor, tmp};
  *tmp = novo;
  return;
}