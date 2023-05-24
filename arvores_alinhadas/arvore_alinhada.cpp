#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#ifndef THREADED_TREE
#define THREADED_TREE

template<class T>
class ThreadedNode {
    public:
        ThreadedNode() {
            left = right = 0;
        }

        ThreadedNode (const T& e, ThreadedNode *l = 0, ThreadedNode *r = 0) {
            el = e, left = l, right = r, the_successor = 0;
        };
        T el;
        ThreadedNode *left, *right;
        unsigned int the_successor: 1;
};

template<class T>
class ThreadedTree {
    public: 
    ThreadedTree() {
        root = 0;
    }

    void insert_in_tree(const T& el) {
        ThreadedNode<T>* p;
        ThreadedNode <T>* prev;
        ThreadedNode<T>* newTreeNode = new ThreadedNode<T>(el);

        if(root == 0) {
            root = newTreeNode;
            return;
        }
        p = root;
        
        while(p != 0) {
            prev = p;
            if(p->el > el) {
                p = p->left;
            } else if (p->the_successor == 0) {
                p = p->right;
            } else break;
        }

        if(prev->el > el) {
            prev->left = newTreeNode;
            newTreeNode->the_successor = 1;
            newTreeNode->right = prev;
            
        } else if (prev->the_successor == 1) {
            newTreeNode->the_successor = 1;
            prev->the_successor = 0;
            newTreeNode->right = prev->right;
            prev->right = newTreeNode;
            
        } else {
            prev->right = newTreeNode;
        }
    }

    void inorder_search() {
        ThreadedNode<T>* p = root;
        ThreadedNode <T>* prev;
    
        if(p != 0) {
            while(p->left != 0) {
                p = p->left;
            };

            while (p != 0) {
                cout << p->el << endl;

                prev = p;
                p = p->right;

                if( p != 0 && prev->the_successor == 0) {
                    while(p->left != 0) {
                        p = p->left;
                    };
                }
            };
        }
    }

    void preorder_search() {
        ThreadedNode<T>* p = root;
    
        while (p != 0) {
            cout << p->el << endl;
    
            if (p->left != 0) {
                p = p->left;
            } else if (p->the_successor == 0) {
                p = p->right;
            } else {
                while (p != 0 && p->the_successor == 1) {
                    p = p->right;
                }
    
                if (p != 0) {
                    p = p->right;
                }
            }
        }
    }

    protected:
        ThreadedNode<T>* root;
};

#endif


int main () {

    ThreadedTree<int> *tree = new ThreadedTree<int>();

    tree->insert_in_tree(89);
    tree->insert_in_tree(1);
    tree->insert_in_tree(12);
    tree->insert_in_tree(3);
    tree->insert_in_tree(6);
    tree->insert_in_tree(15);
    tree->insert_in_tree(31);
    tree->insert_in_tree(13);

    tree->inorder_search();
    cout << "=======FIM==========" << endl;
    cout << "=======OUTRO_COMECO==========" << endl;
    tree->preorder_search();
};