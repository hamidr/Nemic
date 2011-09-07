#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;
class allocate
{

public:
    allocate(){
        ptr = new char[1024];
        cout << (void*)ptr << endl;
    }
    char * ptr;
    ~allocate(){
        delete[] ptr;
    }
};

int main(int argc, char** argv)
{
    allocate* al;
    int sec;
    try {
        al = new allocate[1024]; 
    } catch ( bad_alloc &bad ) {
        cout << bad.what() << endl;
    }
    if ( argc > 1 && (sec=atoi(argv[1])))
        sleep(sec);
    delete[] al;
	return 0;
}
