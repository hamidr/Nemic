#include "node.hpp"
#include <iostream>

int main()
{
	auto node = makeNode<int>(nullptr, 10);
	std::cout << node << std::endl;
	return 0;
}
