#include <iostream>

using namespace std;

struct NoArvore{
	int data;
	NoArvore *esquerda;
	NoArvore *direita;
};
	
void posOrdem (NoArvore *raiz){
	if (raiz != NULL){
		posOrdem (raiz -> esquerda);
		posOrdem (raiz -> direita);
		cout << raiz -> data << " ";
	}
}

int altura(NoArvore *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int alturaEsq = altura(raiz->esquerda);
    int alturaDir = altura(raiz->direita);

    if (alturaEsq > alturaDir) {
        return alturaEsq + 1;
    } else {
        return alturaDir + 1;
    }
}

bool arvoreBalanceada(NoArvore *raiz) {
    if (raiz == NULL) {
        return true;
    }

    int alturaEsq = altura(raiz->esquerda);
    int alturaDir = altura(raiz->direita);

    int diferenca = alturaEsq - alturaDir;

    if (diferenca > 1 || diferenca < -1) {
        return false;
    }

    return arvoreBalanceada(raiz->esquerda) && arvoreBalanceada(raiz->direita);
}

int somaFolhas(NoArvore *raiz) {
  if (raiz == NULL) {
    return 0;
  }

  if (raiz->esquerda == NULL && raiz->direita == NULL) {
    return raiz->data;
  }

  return somaFolhas(raiz->esquerda) + somaFolhas(raiz->direita);
}

bool verificacao(NoArvore *raiz) {
  if (raiz == NULL) {
    return true;
  }

  int soma = somaFolhas(raiz);

  return (raiz->data == soma);
}

int main(int argc, char** argv) {
    NoArvore *raiz = new NoArvore;
    raiz->data = 10;
    raiz->esquerda = NULL;
    raiz->direita = NULL;

    NoArvore *elementoEsquerda = new NoArvore;
    elementoEsquerda->data = 4;
    elementoEsquerda->esquerda = NULL;
    elementoEsquerda->direita = NULL;
    raiz->esquerda = elementoEsquerda;

    NoArvore *elementoDireita = new NoArvore;
    elementoDireita->data = 6;
    elementoDireita->esquerda = NULL;
    elementoDireita->direita = NULL;
    raiz->direita = elementoDireita;
    
    posOrdem(raiz);
    cout << "\nA arvore esta balanceada? (1-Sim 0-Nao): " << arvoreBalanceada(raiz) << endl;
    cout << "13 - A soma dos filhos e igual ao valor da raiz? (1-Sim 0-Nao): " << verificacao(raiz) << endl;
	cout << "15 - A soma das folhas eh:  " << somaFolhas(raiz) << endl;

    return 0;
}
