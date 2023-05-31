#include <iostream>
#include <algorithm>
using namespace std;


template<class T>
class ArvoreNo {
public:
    T el;
    ArvoreNo<T>* left, * right;

    ArvoreNo() {
        left = right = 0;
    }

    ArvoreNo(T e, ArvoreNo<T>* l = 0, ArvoreNo<T>* r = 0) {
        el = e;
        left = l;
        right = r;
    }
};

template<class T>
class Arvore {
protected:
    ArvoreNo<T>* root;
public:
    Arvore() {
        root = 0;
    }


    ArvoreNo<T>* getRoot() {
        return root;
    }
    bool isEmpty() const {
        return root = 0;
    }

    void visit(ArvoreNo<T>* p) {
        cout << p->el << " ";
    }

    //obs: pg 209 figura 6.23
    void insert(T el) {
        ArvoreNo<T>* p = root, * prev = 0;
        while (p != 0) {
            prev = p;
            if (el < p->el)
                p = p->left;
            else p = p->right;
        }
        if (root == 0) //a arvore esta vazia
            root = new ArvoreNo<T>(el);
        else if (el < prev->el)
            prev->left = new ArvoreNo<T>(el);
        else prev->right = new ArvoreNo<T>(el);
    }

    int treeHeight(ArvoreNo<T>* root) {
        if (root == NULL) {
            return 0;
        }

        int left_height = treeHeight(root->left);
        int right_height = treeHeight(root->right);

        if (left_height > right_height) return left_height + 1;
        return right_height + 1;
    }

    void printTreeFormated(ArvoreNo<T>* root) {
        if (root != NULL) {
            cout << "<" << root->el;

            printTreeFormated(root->left);
            printTreeFormated(root->right);
            cout << ">";
        }
    }

    void balancear(T vetor[], int first, int last) {
        if (first <= last) {
            int middle = (first + last) / 2;
            this->insert(vetor[middle]);

            balancear(vetor, first, middle - 1);
            balancear(vetor, middle + 1, last);
        }
        else {
            return;
        }
    }



    void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

}

    int main() {

        /*1) Inclua os seguintes valores na seguinte ordem em uma árvore binária:
            7, 6, 22, 14, 40, 63.*/
        Arvore<int>* tree = new Arvore<int>();

        tree->insert(7);
        tree->insert(6);
        tree->insert(22);
        tree->insert(14);
        tree->insert(40);
        tree->insert(63);

        cout << "1.1 Altura resultante da árvore: " << tree->treeHeight(tree->getRoot()) << endl;

        cout << "1.2) Mostre a árvore resultante: " << endl;
        tree->printTreeFormated(tree->getRoot());

        /* 1.3) A árvore resultante está balanceada ou não?
            Não está balanceada porque a diferença entre a altura das subárvores direita e esquerda é 2 e para uma árvore ser balanceada ela deve ter uma diferença de 0 ou 1.
        */

        /*
        1.4) No caso da árvore resultante NÃO ESTAR balanceada aplique o algoritmo de reordenação dos dados para balancear a árvore.

        a) Método sort para ordenar o vetor resultante
        */

        cout << endl;
        int array[] = { 7, 6, 22, 14, 40, 63 };
        int size = sizeof(array) / sizeof(array[0]);
        sort(array, array + size);

        Arvore<int>* tree2 = new Arvore<int>();

        tree2->balancear(array, 0, 5);
        tree2->printTreeFormated(tree2->getRoot());


        /*Método com método in order*/
        cout << endl;
        Arvore<int>* tree3 = new Arvore<int>();
    }
//template<class T>

//1 - A árvore resultante possui altura 3
//
//2 - Em pre-order a impressão fica assim -> 7 -> 6 -> 14 -> 40 -> 22 -> 63
//
//3 - A árvore resultante não está balanceada
//
//4 - 