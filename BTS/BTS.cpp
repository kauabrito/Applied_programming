#include <iostream>
#include <stdlib.h>

using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;
};

class ArvoreBinaria {
private:
    No* raiz;

    int contarNosRecursivo(No* no) {
        if (no == NULL)
            return 0;
        return 1 + contarNosRecursivo(no->esquerda) + contarNosRecursivo(no->direita);
    }

public:
    ArvoreBinaria() {
        raiz = NULL;
    }

    void inserir(int valor) {
        raiz = inserirRecursivo(raiz, valor);
    }

    void remover(int valor) {
        raiz = removerRecursivo(raiz, valor);
    }

    bool buscar(int valor) {
        No* atual = raiz;
        while (atual != NULL) {
            if (valor == atual->valor)
                return true;
            else if (valor < atual->valor)
                atual = atual->esquerda;
            else
                atual = atual->direita;
        }
        return false;
    }

    void imprimirInOrder() {
        imprimirInOrder(raiz);
        cout << endl;
    }

    void imprimirPreOrder() {
        imprimirPreOrder(raiz);
        cout << endl;
    }

    void imprimirPostOrder() {
        imprimirPostOrder(raiz);
        cout << endl;
    }

    int contarNos() {
        return contarNosRecursivo(raiz);
    }

private:
    No* inserirRecursivo(No* no, int valor) {
        if (no == NULL) {
            No* novoNo = new No;
            novoNo->valor = valor;
            novoNo->esquerda = NULL;
            novoNo->direita = NULL;
            return novoNo;  
        }

        if (valor < no->valor)
            no->esquerda = inserirRecursivo(no->esquerda, valor);
        else if (valor > no->valor)
            no->direita = inserirRecursivo(no->direita, valor);

        return no;
    }

    No* removerRecursivo(No* no, int valor) {
        if (no == NULL)
            return no;

        if (valor < no->valor)
            no->esquerda = removerRecursivo(no->esquerda, valor);
        else if (valor > no->valor)
            no->direita = removerRecursivo(no->direita, valor);
        else {
            if (no->esquerda == NULL) {
                No* temp = no->direita;
                delete no;
                return temp;
            }
            else if (no->direita == NULL) {
                No* temp = no->esquerda;
                delete no;
                return temp;
            }

            No* temp = minValorNo(no->direita);
            no->valor = temp->valor;
            no->direita = removerRecursivo(no->direita, temp->valor);
        }
        return no;
    }

    No* minValorNo(No* no) {
        No* atual = no;
        while (atual->esquerda != NULL)
            atual = atual->esquerda;
        return atual;
    }

    void imprimirInOrder(No* no) {
        if (no != NULL) {
            imprimirInOrder(no->esquerda);
            cout << no->valor << " ";
            imprimirInOrder(no->direita);
        }
    }

    void imprimirPreOrder(No* no) {
        if (no != NULL) {
            cout << no->valor << " ";
            imprimirPreOrder(no->esquerda);
            imprimirPreOrder(no->direita);
        }
    }

    void imprimirPostOrder(No* no) {
        if (no != NULL) {
            imprimirPostOrder(no->esquerda);
            imprimirPostOrder(no->direita);
            cout << no->valor << " ";
        }
    }
};

int main() {
    ArvoreBinaria arvore;

    int opcao;
    int valor;
    bool loop = true;

    while (loop) {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Inserir" << endl;
        cout << "2. Remover" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Imprimir In-Order" << endl;
        cout << "5. Imprimir Pre-Order" << endl;
        cout << "6. Imprimir Post-Order" << endl;
        cout << "7. Contar nós" << endl;
        cout << "8. Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                arvore.inserir(valor);
                break;
            case 2:
                cout << "Digite o valor a ser removido: ";
                cin >> valor;
                arvore.remover(valor);
                break;
            case 3:
                cout << "Digite o valor a ser buscado: ";
                cin >> valor;
                if (arvore.buscar(valor))
                    cout << "Valor encontrado." << endl;
                else
                    cout << "Valor não encontrado." << endl;
                break;
            case 4:
                cout << "Imprimir In-Order: ";
                arvore.imprimirInOrder();
                break;
            case 5:
                cout << "Imprimir Pre-Order: ";
                arvore.imprimirPreOrder();
                break;
            case 6:
                cout << "Imprimir Post-Order: ";
                arvore.imprimirPostOrder();
                break;
            case 7:
                cout << "Quantidade de nós na árvore: " << arvore.contarNos() << endl;
                break;
            case 8:
                loop = false;
                break;
            default:
                cout << "Opção inválida. Por favor, escolha novamente." << endl;
                break;
        }
    }

    return 0;
}
