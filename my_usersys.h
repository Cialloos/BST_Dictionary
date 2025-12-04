#pragma once
#include "my_system.h"

class user {
private:
	dicsys dic;
public:
	void start() {
		int choice;
		while (true) {
			cout << "-----------------" << endl;
			cout << "0.addbyfile\n" << "1.add\n" << "2.delete\n" << "3.revise\n" << "4.find\n"
				<< "5.display\n" << "6.exit\n";
			cout << "-----------------" << endl;

			cout << "input choice: ";
			cin >> choice;

			switch (choice) {
			case 0: addbyfile(); break;
			case 1: add(); break;
			case 2: dele(); break;
			case 3: revise(); break;
			case 4: find(); break;
			case 5: display(); break;
			case 6: return; break;
			}
			system("pause");
			system("cls");
		}
	}
	
	void addbyfile() {
		dic.addByFile();
	}

	void add() {
		string w, m;
		cout << "请输入单词：";
		cin >> w;
		cout << "请输入词义：";
		cin >> m;

		dic.add(w, m);
	}

	void dele() {
		string w;
		cout << "请输入要删除单词：";
		cin >> w;
		if (dic.remove(w)) {
			cout << "删除成功！" << endl;
		}
		else {
			cout << "该单词不存在！" << endl;
		}
	}

	void revise() {
		string w,m;
		cout << "请输入要更改的单词：";
		cin >> w;
		cout << "请输入更新的词义：";
		cin >> m;
		if (dic.revise(w,m)) 
			cout << "词义更新成功！" << endl;
		else
			cout << "该单词不存在！" << endl;
	}

	void find() {
		string w;
		cout << "请输入单词：";
		cin >> w;
		
		node* ptr = dic.find(w);
		if (ptr != nullptr) {
			cout << w << ':' << ptr->getmeaning() << endl;
		}else
			cout << "该单词不存在！" << endl;
	}

	void display() {
		dic.showStruct();
	}

};