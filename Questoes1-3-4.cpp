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

	return 0;
}
