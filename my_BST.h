#pragma once
#include<iostream>

using namespace std;
class node {
private:
    string word;
    string meaning;

    node* left;
    node* right;

public:
    node(string w, string m, node* l = NULL, node* r = NULL) :word(w), meaning(m), left(l), right(r) {}

    string getword() { return word; }
    string getmeaning() { return meaning; }
    void setword(string w) { this->word = w; }
    void setmeaning(string m) { this->meaning = m; }


    node* getleft() { return left; }
    node* getright() { return right; }
    void setleft(node* l) { this->left = l; }
    void setright(node* r) { this->right = r; }

    void show() {
        cout << word << ":" << meaning << endl;
    }
    void showAll(string s = "") {
        cout << s;
        show();
        if (left != NULL) {
            left->showAll(s + "  ");
        }
        if (right != NULL) {
            right->showAll(s + "  ");
        }
    }
};

class BST {
private:
    node* root;
public:
    BST(node* r = NULL) :root(r) {}
    ~BST() {
        release(root);
    }

    void release(node* current) {
        if (current != NULL) {
            release(current->getleft());
            release(current->getright());
            delete current;
        }
    }

    void add(node* ptr) {
        if (this->isempty()) { root = ptr; return; }
        node* p = root;
        while (1) {
            if (p->getword() < ptr->getword()) {
                if (p->getright() != NULL) {
                    p = p->getright();
                    continue;
                }
                else {
                    p->setright(ptr);
                    break;
                }
            }
            else if (p->getword() > ptr->getword()) {
                if (p->getleft() != NULL) {
                    p = p->getleft();
                    continue;
                }
                else {
                    p->setleft(ptr);
                    break;
                }
            }
            else {
                p->setmeaning(ptr->getmeaning());
                break;
            }
        }
    }

    void add(string word, string meaning) {
        add(new node(word, meaning));
    }

    bool remove(node* ptr) {

    }

    node* find(node* ptr) {
        if (this->isempty()) { return NULL; }
        node* p = root;
        while (1) {
            if (p->getword() > ptr->getword() && p->getright() != NULL) {
                p = p->getright();
                continue;
            }
            else if (p->getword() < ptr->getword() && p->getleft() != NULL) {
                p = p->getleft();
                continue;
            }
            else if (p->getword() == ptr->getword()) {
                return p;
            }
            else {
                break;
            }
        }
        return NULL;
    }

    bool isempty() {
        if (root == NULL) {
            return true;
        }
        else
            return false;
    }

    void show() {
        if (root != NULL) {
            root->showAll();
        }
    }

};