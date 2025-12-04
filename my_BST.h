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
    node(string w, string m, node* l = nullptr, node* r = nullptr) :word(w), meaning(m), left(l), right(r) {}

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
        if (left != nullptr) {
            left->showAll(s + "  ");
        }
        if (right != nullptr) {
            right->showAll(s + "  ");
        }
    }
};

class BST {
private:
    node* root;
public:
    BST(node* r = nullptr) :root(r) {}
    ~BST() {
        release(root);
    }

    void release(node* current) {
        if (current != nullptr) {
            release(current->getleft());
            release(current->getright());
            delete current;
        }
    }

    void add(node* ptr) {
        if (this->isempty()) { root = ptr; return; }
        node* p = root;
        while (true) {
            if (p->getword() < ptr->getword()) {
                if (p->getright() != nullptr) {
                    p = p->getright();
                    continue;
                }
                else {
                    p->setright(ptr);
                    break;
                }
            }
            else if (p->getword() > ptr->getword()) {
                if (p->getleft() != nullptr) {
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

    node* find(string w) {
        if (this->isempty()) { return nullptr; }
        node* p = root;
        while (true) {
            if (p->getword() < w && p->getright() != nullptr) {
                p = p->getright();
                continue;
            }
            else if (p->getword() > w && p->getleft() != nullptr) {
                p = p->getleft();
                continue;
            }
            else if (p->getword() == w) {
                return p;
            }
            else {
                break;
            }
        }
        return nullptr;
    }

    bool remove(string word) {
        node* current = root;
        node* back = nullptr;
        while (current != nullptr) {
            if (word < current->getword()) {
                back = current;
                current = current->getleft();
            }
            else if (word > current->getword()) {
                back = current;
                current = current->getright();
            }
            else {
                break;
            }
        }
        if (current == nullptr) {//找不到
            return false;
        }
        else if (current->getleft() == nullptr && current->getright() == nullptr) {//叶子结点
            if (back != nullptr) {
                if (back->getleft() == current)back->setleft(nullptr);
                if (back->getright() == current)back->setright(nullptr);
            }
            else {
                root = nullptr;
            }
            delete(current);
        }
        else if (current->getleft() != nullptr && current->getright() == nullptr) {//只有左孩子
            if (back != nullptr) {
                if (back->getleft() == current)back->setleft(current->getleft());
                if (back->getright() == current)back->setright(current->getleft());
            }
            else {
                root = current->getleft();
            }
            delete current;
        }
        else if (current->getleft() == nullptr && current->getright() != nullptr) {//只有右孩子
            if (back != nullptr) {
                if (back->getleft() == current)back->setleft(current->getright());
                if (back->getright() == current)back->setright(current->getright());
            }
            else {
                root = current->getright();
            }
            delete current;
        }
        else {//有两个孩子
            node* Replace = current->getleft();
            node* reBack = current;
            while (Replace != nullptr && Replace->getright() != nullptr) {
                reBack = Replace;
                Replace = Replace->getright();
            }

            current->setword(Replace->getword());
            current->setmeaning(Replace->getmeaning());

            if (reBack->getleft() == Replace)reBack->setleft(Replace->getleft());
            if (reBack->getright() == Replace)reBack->setright(Replace->getleft());
            delete Replace;
        }
        return true;
    }

    bool isempty() {
        if (root == nullptr) {
            return true;
        }
        else
            return false;
    }

    void show() {
        if (root != nullptr) {
            root->showAll();
        }
    }

};