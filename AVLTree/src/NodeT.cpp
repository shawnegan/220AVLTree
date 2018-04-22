#include "NodeT.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

NodeT::NodeT(string x) {
	data = x;
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	def = "";
}

NodeT::NodeT(string x, string y) {
	data = x;
	def = y;
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
}
NodeT::~NodeT() {
	if ((left != NULL) || (right != NULL)) {
		cout << "deleting may leave dangling SNodes" << endl;
	}
}

void NodeT::printNode() {
	if(def != ""){
		cout << "|"<< data << "(" << height << "): " << def << "|" << endl;
	}else{
		cout << "|"<< data << ", "<< height << "|" << endl;
	}

}
