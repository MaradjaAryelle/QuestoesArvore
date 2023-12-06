#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;
};

void posOrdem(NoArvore *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        cout << raiz->data << " ";
    }
}

void maiorDoNivel(NoArvore *raiz, int nivel, int &auxMaior) {
  if (raiz == NULL) {
    return;
  }

  if (nivel == 0) {
    auxMaior = raiz->data;
    cout << "Maior valor do nivel " << nivel << ": " << auxMaior << endl;
  } else {
    if (raiz->data > auxMaior) {
      auxMaior = raiz->data;
      cout << "Maior valor do nivel " << nivel << ": " << auxMaior << endl;
    }
  }

  maiorDoNivel(raiz->esquerda, nivel + 1, auxMaior);
  maiorDoNivel(raiz->direita, nivel + 1, auxMaior);
}

int somaSubarvores(NoArvore *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int somaEsquerda = somaSubarvores(raiz->esquerda);
    int somaDireita = somaSubarvores(raiz->direita);

    return raiz->data + somaEsquerda + somaDireita;
}

int main(int argc, char **argv) {
    NoArvore *raiz = new NoArvore;
    raiz->data = 1;
    raiz->esquerda = NULL;
    raiz->direita = NULL;

    NoArvore *elementoEsquerda = new NoArvore;
    elementoEsquerda->data = 3;
    elementoEsquerda->esquerda = NULL;
    elementoEsquerda->direita = NULL;
    raiz->esquerda = elementoEsquerda;

    NoArvore *elementoDireita = new NoArvore;
    elementoDireita->data = 2;
    elementoDireita->esquerda = NULL;
    elementoDireita->direita = NULL;
    raiz->direita = elementoDireita;

    elementoEsquerda->esquerda = new NoArvore;
    elementoEsquerda->esquerda->data = 5;
    elementoEsquerda->esquerda->esquerda = NULL;
    elementoEsquerda->esquerda->direita = NULL;

    elementoEsquerda->direita = new NoArvore;
    elementoEsquerda->direita->data = 3;
    elementoEsquerda->direita->esquerda = NULL;
    elementoEsquerda->direita->direita = NULL;

    elementoDireita->direita = new NoArvore;
    elementoDireita->direita->data = 9;
    elementoDireita->direita->esquerda = NULL;
    elementoDireita->direita->direita = NULL;

    posOrdem(raiz);

    int auxMaior = raiz->data;
    cout << endl;
    //mao sei como nao exibir o 5, tentei usar ate altura da arvore
    maiorDoNivel(raiz, 0, auxMaior);
	somaSubarvores(raiz);
	
	int somaEsquerda = somaSubarvores(raiz->esquerda);
    int somaDireita = somaSubarvores(raiz->direita);

    if (somaEsquerda > somaDireita) {
        cout << "A subarvore da esquerda tem a maior soma, no valor de " << somaEsquerda << endl;
    } else if (somaEsquerda < somaDireita) {
        cout << "A subarvore da direita tem a maior soma, no valor de " << somaDireita << endl;
    } else {
        cout << "As subarvores tem somas iguais, no valor de " << somaEsquerda << endl;
    }
    return 0;
}
