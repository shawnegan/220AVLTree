#include "BSTY.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

BSTY::BSTY() {
	root = NULL;
}

// You write:  insert a new node with data x (a string) into the
// binary search tree
// This method should return true if a new node is inserted and
// false if the data x is already in the tree
// Remember to check whether the new node will be the root
// (meaning the root is currently NULL) and if so, set the root
// to be the new node.
// Note: Make sure you make the new node point to its parent!!!
// Note2: after you've inserted a new node, you should call the
// adjustHeights method that will update the heights of all the
// ancestors of the node that was just inserted.

bool BSTY:: insertit(string x) {
	NodeT *newNode = new NodeT(x);
	if(root == NULL){
		root = newNode;
		return true;
	}else{
		NodeT *n = root;
		while(n != NULL){
			if(x.compare(n->data) < 0){
				if(n->left == NULL){
					n->left = newNode;
					newNode->parent = n;
					adjustHeights(newNode);
					return true;
				}else{
					n = n->left;
				}
			}else if(x.compare(n->data) > 0){
				if(n->right == NULL){
					n->right = newNode;
					newNode->parent = n;
					adjustHeights(newNode);
					return true;
				}else{
					n = n->right;
				}
			}else{
				return false;
			}
		}
	}
}

bool BSTY::insertit(string x, string y){
	NodeT *newNode = new NodeT(x, y);
	if(root == NULL){
		root = newNode;
		return true;
	}else{
		NodeT *n = root;
		while(n != NULL){
			if(x.compare(n->data) < 0){
				if(n->left == NULL){
					n->left = newNode;
					newNode->parent = n;
					adjustHeights(newNode);
					return true;
				}else{
					n = n->left;
				}
			}else if(x.compare(n->data) > 0){
				if(n->right == NULL){
					n->right = newNode;
					newNode->parent = n;
					adjustHeights(newNode);
					return true;
				}else{
					n = n->right;
				}
			}else{
				return false;
			}
		}
	}
}
// the adjustHeights method updates the heights of every ancestor of the node n.
// This method will be massively useful with our next lab, so make sure you have
// this working now.  It should be called whenever you change the height of a
// a particular node.  So, for instance, when a new node is inserted as a leaf,
// its height is 1.  The adjustHeights method should then check the parent to see
// if the height of the parent changes (the height of each node is the maximum of
// the height of the left child and the height of the right child, plus 1).  If
// the parent's height changes, then the grandparent's height should be checked and,
// if necessary, adjusted.  If the grandparent's height is updated, then the great-
// grandparent's height should be adjusted, etc.  The checking stops when either
// the loop has worked its way up to the root, or until the currently being checked
// ancestor is not changed.
void BSTY::adjustHeights(NodeT *n) {
	if(n != root && n->parent != root){
		NodeT *z = n->parent->parent;
		NodeT *y = n->parent;
		if(y->height <= n->height){
			y->height = n->height +1;
		}
		while(y != root){
			if(z->height <= y->height){
				z->height = y->height + 1;
				if(findBalance(z) == -2){
					if(findBalance(y) == 1){
						y = rotateRight(y);
						y = rotateLeft(y->parent);
						z = y->parent;
					}else{//findBalance(y) == -1
						y = rotateLeft(z);
						z = y->parent;
					}
				}else if(findBalance(z) == 2){
					if(findBalance(y) == 1){
						y = rotateRight(z);
						z = y->parent;
					}else{//findBalance(y) = -1
						y = rotateLeft(y);
						y = rotateRight(y->parent);
						z = y->parent;
					}
				}else{
					y = z;
					z = z->parent;
				}
			}else{
				y = root;
			}
		}
	}else{
		n->height = 1;
		if(n->parent == root){
			n->parent->height = 2;
		}
	}
}

void BSTY::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreeIO(root);
	}
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is
// traversed in order
void BSTY::printTreeIO(NodeT *n) {
	if(n == NULL){
		return;
	}else{
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}
}

void BSTY::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePre(root);
	}
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void BSTY::printTreePre(NodeT *n) {
	if(n == NULL){
		return;
	}else{
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}
}

void BSTY::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePost(root);
		cout << endl;
	}
}

// Prints the tree using pre-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void BSTY::printTreePost(NodeT *n) {
	if(n == NULL){
		return;
	}else{
		printTreePost(n->left);
		printTreePost(n->right);
		n->printNode();
	}
}
void BSTY::myPrint() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrint(root);
		cout << endl;
	}
}
void BSTY::myPrint(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrint(n->left);
		cout << n->data.length()-1;
		if (mine) {
			cout <<".";
			mine = false;
		}
		myPrint(n->right);
	}
}

// the find method takes as input a string, and finds whether that string is already
// in the tree or not.  If it is in the tree, that node is returned from the tree.
// If it isn't, NULL is returned.
// NOTE: If the node can't be found, this method prints out that x can't be found.
// if it is found, the printNode method is called for the node.
NodeT *BSTY::find(string x) {
	int numComps = 0;
	NodeT *n = root;
	while(n != NULL){
		numComps += 1;
		if(x.compare(n->data) > 0){
			n = n->right;
		}else if(x.compare(n->data)  < 0){
			n = n->left;
		}else{
			if(n != root){
				numComps += 1;
			}
			cout << numComps << ": ";
			n->printNode();
			return n;
		}
	}
	cout << "Node can't be found" << endl;
	return NULL;
}

NodeT *BSTY::rotateRight(NodeT *n){
	cout << n->data << " must rotate right (" << findBalance(n) << ")" << endl;
	NodeT *m = n->left;
	m->parent = n->parent;
	n->left = m->right;
	if(n->left != NULL){
		n->left->parent = n;
	}
	m->right = n;
	n->parent = m;
	if(m->parent != NULL){
		if(m->parent->right == n){
			m->parent->right = m;
		}else{
			m->parent->left = m;
		}
	}else{
		root = m;
	}
	if(n->right != NULL && n->left != NULL){
		if(n->left->height > n->right->height){
			n->height = n->left->height + 1;
		}else{
			n->height = n->right->height + 1;
		}
	}else if(n->right == NULL && n->left != NULL){
		n->height = n->left->height + 1;
	}else if(n->right != NULL && n->left == NULL){
		n->height = n->right->height + 1;
	}else{
		n->height = 1;
	}
	if(m->left != NULL){
		if(m->left->height > m->right->height){
			m->height = m->left->height + 1;
		}else{
			m->height = m->right->height + 1;
		}
	}else{
		m->height = m->right->height + 1;
	}

	return m;
}

NodeT *BSTY::rotateLeft(NodeT *n){
	cout << n->data << " must rotate left (" << findBalance(n) << ")" << endl;
	NodeT *m = n->right;
	m->parent = n->parent;
	n->right = m->left;
	if(n->right != NULL){
		n->right->parent = n;
	}
	m->left = n;
	n->parent = m;
	if(m->parent != NULL){
		if(m->parent->right == n){
			m->parent->right = m;
		}else{
			m->parent->left = m;
		}
	}else{
		root = m;
	}
	if(n->left != NULL && n->right != NULL){
		if(n->left->height > n->right->height){
			n->height = n->left->height + 1;
		}else{
			n->height = n->right->height + 1;
		}
	}else if(n->left == NULL && n->right != NULL){
		n->height = n->right->height + 1;
	}else if(n->left != NULL && n->right == NULL){
		n->height = n->left->height + 1;
	}else{
		n->height = 1;
	}
	if(m->right != NULL){
		if(m->left->height > m->right->height){
			m->height = m->left->height + 1;
		}else{
			m->height = m->right->height + 1;
		}
	}else{
		m->height = m->left->height + 1;
	}

	return m;
}

int BSTY::findBalance(NodeT *n){
	if(n->right == NULL &&  n->left == NULL){
		return 0;
	}else if(n->left != NULL && n->right == NULL){
		return n->left->height;
	}else if(n->right != NULL && n->left == NULL){
		return 0 - (n->right->height);
	}else{
		int bal = n->left->height - n->right->height;
		return bal;
	}

}
