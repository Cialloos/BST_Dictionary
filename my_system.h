#pragma once
#include "my_BST.h"
#include<fstream>
#include<sstream>
class dicsys {
private:
	BST tree;
public:
	void add(string w, string m) {
		tree.add(w, m);
	}

	bool remove(string w) {
		return tree.remove(w);
	}

	bool revise(string w,string m) {
		node* ptr = tree.find(w);
		if (ptr != nullptr) {
			ptr->setmeaning(m);
			return true;
		}
		else {
			return false;
		}
	}

	node* find(string w) {
		return tree.find(w);
	}

	void addByFile() {
		ifstream file("data.txt");
		if (!file) {
			cerr << "file open failed for reading";
			exit(1);
		}
		string line;
		while (getline(file, line)) {
			istringstream iss(line);
			string w, m;
			iss >> w >> m;
			tree.add(w, m);
		}
		file.close();
	}

	void showStruct() {
		tree.show();
	}

};