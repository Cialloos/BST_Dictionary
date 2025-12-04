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
	node(string w, string m) :word(w), meaning(m) {}

	string getword() { return word; }
	string getmeaning() { return meaning; }
	void setword(string w) { this->word = w; }
	void setmeaning(string m) { this->meaning = m; }


	node* getleft() { return left; }
	node* getright() { return right; }
	void setleft(node* l) { this->left = l; }
	void setright(node* r) { this->right = r; }


};

class BST {
private:
	node* root;
public:
	BST() {}

	void add(node* ptr) {
	
	
	}

	bool remove() {}

	node* find() {}

	bool isempty() {
		if (root == NULL) {
			return true;
		}
		else
			return false;
	}

	void show() {}

};
