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

int profundidade(NoArvore *raiz) {
    int profEsquerda = 0;
    int profDireita = 0;

    NoArvore *auxEsquerda = raiz;
    while (auxEsquerda != NULL) {
        profEsquerda += 1;
        auxEsquerda = auxEsquerda->esquerda;
    }

    NoArvore *auxDireita = raiz;

    while (auxDireita != NULL) {
        profDireita += 1;
        auxDireita = auxDireita->direita;
    }

    return (profEsquerda > profDireita) ? profEsquerda : profDireita;
}

void caminhos(NoArvore* raiz, int caminho[], int profund) {
    int cont = 1;
    if (raiz == NULL)
        return;

    caminho[profund] = raiz->data;
    profund++;

    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        cout << "Caminho "<< cont << ": ";
        for (int i = 0; i < profund - 1; i++) {
            cout << caminho[i] << "->";
            cont++;
		}
        cout << caminho[profund - 1] << endl;

    } else {
        caminhos(raiz->esquerda, caminho, profund);
        caminhos(raiz->direita, caminho, profund);
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

int main(int argc, char** argv) {
    NoArvore *raiz = new NoArvore;
    raiz->data = 1;
    raiz->esquerda = NULL;
    raiz->direita = NULL;

    NoArvore *elementoEsquerda = new NoArvore;
    elementoEsquerda->data = 2;
    elementoEsquerda->esquerda = NULL;
    elementoEsquerda->direita = NULL;
    raiz->esquerda = elementoEsquerda;

    NoArvore *elementoDireita = new NoArvore;
    elementoDireita->data = 3;
    elementoDireita->esquerda = NULL;
    elementoDireita->direita = NULL;
    raiz->direita = elementoDireita;

    elementoEsquerda->direita = new NoArvore;
    elementoEsquerda->direita->data = 5;
    elementoEsquerda->direita->esquerda = NULL;
    elementoEsquerda->direita->direita = NULL;

	cout << "Arvore em pos-ordem: " ;
	posOrdem(raiz);
    cout << "\n06 - Dado uma arvore retorne a profundidade dela: " << profundidade(raiz) << endl;

    const int MAX = profundidade(raiz);
    int caminho[MAX];
	//pra exibir daquele jeito era com vetor?  nao consegui deixar igual
	cout << "05 - Dado uma arvore retorne todos os caminhos da raiz ate as folhas: " << endl;
    caminhos(raiz, caminho, 0);

	cout << "07 - Dado uma arvore retorne a altura dela: " << altura(raiz) << endl;
	altura(raiz);
	
	cout << "07 - Dado uma arvore retorne se ela esta balanceada ou nao: (1-Sim 0-Nao):" << arvoreBalanceada(raiz) << endl;
	return 0;
}
