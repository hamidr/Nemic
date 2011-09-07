#include <algorithm>
using std::for_each;

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstdint>

int main()
{
    char16_t v[]=u"Hello World\n";
    for_each( v, v+(sizeof(v)/sizeof(char16_t)), [](char16_t &x)  
                                                                {
                                                                    cout << (char)x;
                                                                });

    return 0;
}
