#include "node.hpp"
#include <iostream>

int main()
{
	Node<int>* node = new Node<int>(5);
	for(int i = 1; i <= 20; ++i )
		node->insertNode(i);

/*	node->insertNode(1);
	node->insertNode(3);
	node->insertNode(4);
	node->insertNode(6);
	node->insertNode(7);
	node->insertNode(8);*/

	std::cout << *node << std::endl;
	delete node;
	return 0;
}
