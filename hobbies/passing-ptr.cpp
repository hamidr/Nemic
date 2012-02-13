#include <iostream>

class bar
{
public:
	bar() {
		mbar = new int [10];
		for(int j=0;j<10;++j)
			mbar[j] = j ;
	}
	
	void set(int **arg) {
		*arg = mbar;
	}
	
	~bar() {
		delete [] mbar;
	}

protected:
	int *mbar;
};

class foo 
{
public:
	foo ();

	void show();
	friend class bar;

	bar b;

private:
	int *m;
};

foo::foo () {

	//not a bug!
	//this will tell you that there's no pass by reference!
	b.set(&m);
}

void foo::show()
{
	for(int i=0; i<10; ++i)
		std::cout << m[i] << '\t' ;

	std::cout << '\n' ;

}


int main()
{
	foo f;
	f.show();
	return 0;
}
