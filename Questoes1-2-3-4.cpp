#include <iostream>

using namespace std;

struct NoArvore{
	int data;
	NoArvore *esquerda;
	NoArvore *direita;
};
	
void preOrdem(NoArvore *raiz){
	if (raiz != NULL){
		cout << raiz -> data << " ";
		preOrdem (raiz -> esquerda);
		preOrdem (raiz -> direita);
	}
};

void emOrdem(NoArvore *raiz){
	if (raiz != NULL){
		emOrdem(raiz -> esquerda);
		cout << raiz -> data << " ";
		emOrdem(raiz -> direita);
	}
};

void posOrdem (NoArvore *raiz){
	if (raiz != NULL){
		posOrdem (raiz -> esquerda);
		posOrdem (raiz -> direita);
		cout << raiz -> data << " ";
	}
}

bool saoIguais(NoArvore *raiz, NoArvore *raiz2) {
    if (raiz == NULL && raiz2 == NULL) {
        return true;
    }

    if (raiz == NULL || raiz2 == NULL) {
        return false;
    }

    return (raiz->data == raiz2->data) &&
           saoIguais(raiz->esquerda, raiz2->esquerda) &&
           saoIguais(raiz->direita, raiz2->direita);
}

int main(int argc, char** argv) {
    NoArvore *raiz = new NoArvore;
    raiz->data = 1;
    raiz->esquerda = NULL;
    raiz->direita = NULL;

    NoArvore *elementoDireita = new NoArvore;
    elementoDireita->data = 2;
    elementoDireita->esquerda = NULL;
    elementoDireita->direita = NULL;
    raiz->direita = elementoDireita;

    elementoDireita->esquerda = new NoArvore;
    elementoDireita->esquerda->data = 3;
    elementoDireita->esquerda->esquerda = NULL;
    elementoDireita->esquerda->direita = NULL;
	
	cout << "01 - Dado uma arvore binaria, retorne todos os nos percorrendo a arvore em ordem:" << endl;
	emOrdem(raiz);
	cout << "\n03 - Dado uma arvore binaria, retorne todos os nos percorrendo a arvore em pos-ordem:" << endl;
	posOrdem(raiz);
	cout <<"\n04 - Dado uma árvore binaria, retorne todos os nos percorrendo a arvore em pre-ordem:" << endl;
	preOrdem(raiz);

	NoArvore *raiz2 = new NoArvore;
    raiz2->data = 1;
    raiz2->esquerda = NULL;
    raiz2->direita = NULL;

    NoArvore *elementoDireita2 = new NoArvore;
    elementoDireita2->data = 2;
    elementoDireita2->esquerda = NULL;
    elementoDireita2->direita = NULL;
    raiz2->direita = elementoDireita2;

    elementoDireita2->esquerda = new NoArvore;
    elementoDireita2->esquerda->data = 3;
    elementoDireita2->esquerda->esquerda = NULL;
    elementoDireita2->esquerda->direita = NULL;
	
	cout << "\nNova arvore em posOrdem:" << endl;
	posOrdem(raiz2);
	
	cout << "\n02 - Escreva um Programa que receba duas arvores binarias e diga se elas sao iguais.: (1-Sim 0-Nao):" << (saoIguais(raiz, raiz2)) << endl;
	return 0;
}
