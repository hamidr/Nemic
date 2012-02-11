#include <iostream>

using std::cout;
using std::endl;

template<typename F>
struct FriendMaker
{
	typedef F type;
};


template < typename T>
class foo
{
	foo()
		{}
	
	foo(const int arg)
	: mMember(arg) { }

	const int mMember = 20;

//	friend class FriendMaker<T>::type; // only gcc way!
	friend T; // clang supports this!
	// fuck MSVC!
};

class bar
{
public:
	bar()
		{
			cout << mMember.mMember << endl;
		}

private:
	foo<bar> mMember;
};


int main()
{
	bar b;
	
	return 0;
}

