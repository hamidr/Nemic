#include <iostream>
class foo 
{
public:
    foo ();

    void show();
    friend class bar;

private:
    int *m;
};

class bar
{
public:
    bar() { mbar = new int [10]; }
    void set(foo *arg)
    {
        for(int j=0;j<10;j++)
            mbar[j] = 10 -j ;
        arg->m = mbar;

    }

protected:
    int *mbar;
};

    foo::foo () { bar b; b.set(this); }

    void foo::show()
    {
        for(int i=0; i<10; i++)
            std::cout << m[i] << '\t' ;

        std::cout << '\n' ;

    }


int main()
{
    foo f;
    f.show();
    return 0;
}
