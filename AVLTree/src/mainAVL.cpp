#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "TreePuzzle.hpp"

/*
 * How many nodes in the dictionary tree?
 *
 * 		There are 439 Nodes in the tree.
 *
 * What is the maximum number of comparisons needed to find any node in the tree?
 *
 *		Perfect case (balanced and complete) would be ceil(log(439)) + 1 = 10. Since the tree is
 *		not complete, the worst case to find any node is 11 comparisons.
 *
 *		This is shown in the output under FIND.
 * 		Since the root of the tree (pichiciego) has height 11, the max comparisons to find any node
 * 		occurs when searching for a leaf that has all ancestors whose parent's height is one more than
 * 		the child below (that child being on the direct path from root to the leaf). The number of
 * 		comparisons in this case is 11.
 *
 */



using namespace std;
int main() {
	//PART 2

	cout << endl << "A LOT OF LEFT ROTATIONS " << endl;
	string sarr3[10] = {"a","b","c","d","e","f","g","h","i","j"};
	treePuzzle(10,sarr3,3);

	cout << endl << endl << "A LOT OF RIGHT ROTATIONS " << endl;
	string sarr4[10] = {"j","i","h","g","f","e","d","c","b","a"};
	treePuzzle(10,sarr4,3);

	cout << endl << endl << "A LOT OF RIGHT-LEFT ROTATIONS " << endl;
	string sarr5[10] = {"g","j","i","c","f","h","e","d","a","b"};
	treePuzzle(10,sarr5,3);

	cout << endl << endl << "A LOT OF LEFT-RIGHT ROTATIONS " << endl;
	string sarr6[10] = {"a","p","d","g","f","e","k","j","v","b"};
	treePuzzle(10,sarr6,3);

	//PART 3

	treePuzzle("strangeAnimalDict.txt",439);
}


