#include <iostream>
#include <future>
#include <vector>

class InterfaceOrBase
{
	public:
	virtual void function() = 0; 	// This means you should override this if you wanna inherite from it!
};

class DerivedType1 : public InterfaceOrBase //Inherite from Derive and get whatever it has.
{
	//we must override this
	void function() {
		std::cout << "DerivedType1" << std::endl;
	}
};

class DerivedType2 : public InterfaceOrBase //Inherite from Derive and get whatever it has.
{
	//we must override this
	void function() {
		std::cout << "DerivedType2" << std::endl;
	}
};

class DerivedType3 : public InterfaceOrBase //Inherite from Derive and get whatever it has.
{
	//we must override this
	void function() {
		std::cout << "DerivedType3"  << std::endl;
	}
};

int main()
{

	//make objects and push their address to array
	InterfaceOrBase *array[] = { 
								new DerivedType1,
								new DerivedType2,
								new DerivedType3
								};

	InterfaceOrBase *currentPtr;

	for (int i = 0; i < 3; ++i ) {
		currentPtr = array[i];

		currentPtr->function(); // [currentPtr function:i];

		delete currentPtr; // this calls destructor.
	}

	return 0;
}
