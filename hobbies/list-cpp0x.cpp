#include <algorithm>
#include <ostream>
#include <iostream>


using namespace std;
template <typename L>
class list
{
public:
    const int size;

    list(int n = 10)
        : size(n) {
        ptr_list = new L[size+1];
    }

    L at(const int n) const
    {
        if ( ! this->out_of_range(n) )
            exit(1);
        return ptr_list[n];
    }


    L & operator[] (int n)
    {
        if ( ! this->out_of_range(n) )
            exit(1);
        return ptr_list[n];
    }

    friend ostream & operator<< ( ostream &os, list<L> &l) {
        for(int i=0;i<l.size;i++)
            os<< l[i] << endl;
        return os;
    }

    bool isEmpty()
    {
        if ( this->top == 0 )
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ( this->top == size )
            return true;
        else
            return false;
    }

    void do_each(void(*fp)(L&))
    {
        for(int i=0;i<size;i++)
            fp(ptr_list[i]);
    }


    ~list()
    {
        delete[] ptr_list;
    }

private:
    L* ptr_list;
    int top;

    bool out_of_range(int &n) const
    {
        if ( n > this->size || 0 > n  ) {
            cerr << "out-of-range!" << endl;
            return false;
        }
        return true;
    }
};



int main(int argc, char *argv[])
{
    list<double> l(5);
    for(int i=0;i<l.size;i++)
        l[i] = i;
    l.do_each( [](double &x) 
                {
                        cout <<x<<endl; 
                } );

    return 0;
}
