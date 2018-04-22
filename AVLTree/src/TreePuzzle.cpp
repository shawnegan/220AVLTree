/*
 * TreePuzzle.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: Debra
 */

#include "treePuzzle.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

treePuzzle::treePuzzle(int x, string sarr[],int k) {
	tree = new BSTY();
	for (int i = 0; i < x; i++) {
		tree->insertit(sarr[i]);
	}
	cout << endl<<"*******************************"<<endl<<"PREORDER " << endl;
	tree->printTreePre();
	cout << "*******************************"<<endl<<"INORDER " << endl;
	tree->printTreeIO();
	cout << "*******************************"<<endl<<"POSTORDER " << endl;
	tree->printTreePost();
	cout << endl;
}
treePuzzle::treePuzzle(string fname,int k) {
	tree = new BSTY();
	readFile2(fname,k);
	cout << "*******************************"<<endl<<"INORDER " << endl;
	tree->printTreeIO();
	cout <<endl << "*******************************FIND" << endl;
	tree->find("pichiciego");
	tree->find("falanouc");
	tree->find("blauwbok");
	tree->find("dibatag");
	tree->find("gharial");
	tree->find("duarf");
	tree->find("kinkajou");
	tree->find("zyzzyva");
	tree->find("tucutucu");
	tree->find("tabanid");
	tree->find("solenodon");
	tree->find("axolotl");
}

void treePuzzle::readFile2(string fname, int size) {
	ifstream file(fname.c_str());
	string word;
	string def;
	int ct = 0;
	while (!file.eof() && ct < size) {
		file >> word;
		cout << word << endl;
		getline(file,def);
		def = def.substr(2);
		tree->insertit(word,def);

		cout << def << endl;
	}

}

treePuzzle::~treePuzzle() {
	delete tree;
}
