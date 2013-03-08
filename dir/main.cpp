// clang++ -std=c++11 main.cpp

#include "node.hpp"
#include <iostream>

int main()
{
	Node<int>& tree = makeTree<int>(5);
	
	tree.insertNode(8);
	tree.insertNode(32);
	tree.insertNode(4);
	tree.insertNode(6);
	tree.insertNode(7);
	tree.insertNode(-1);

	//prints values sorted :)
	tree.applyAll(
					[] ( int &n ) { std::cout << n << std::endl; }
		);

	removeTree(tree);
	return 0;
}
