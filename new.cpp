#include <iostream>
#include <cstddef>
#include <cstdlib>
using std::cout;
using std::endl;

void *operator new(std::size_t size) throw(std::bad_alloc)
{
	cout << "allocated " << size << endl;
	return malloc(size);
}

void operator delete(void *ptr)
{
	cout << "deallocated " << ptr << endl;
	free(ptr);
}

int main()
{
	int *n = new int;
	cout << n << endl;
	delete(n);
	return 0;
}

