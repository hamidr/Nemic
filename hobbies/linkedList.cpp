#include<iostream>
using std::cout;
using std::endl;

template <typename T>
struct Node {
    Node(){}
    Node(T &val) {
        next = NULL;
        data = val;
    }

    T data;

    Node *next;
//    Node *pre;
};

template<typename T>
class linkedList
{
public:
    linkedList() { first = list = NULL ; }
    ~linkedList() {
        Node<T> *n = first;
        Node<T> *tmp = NULL;
        
        while ( n ) {
            tmp = n->next;
            delete n;
            n = tmp;
        }
    }

    void insert(T val) {

        if (!list) {
            list = new Node<T>(val);
            first = list;
        } else {
            Node<T> *n = new Node<T>(val);
            list->next = n;
            list = list->next;
        }
    }
    void showList() {
        Node<T> *n = first;
        while ( n ) {
            cout << n->data << '\t';
            n = n->next;
        }
    }
private:
    Node<T> *list;
    Node<T> *first;

};

int main()
{
    linkedList<int> list;

    int k=0;
    while( k < 100 )
    {
        list.insert(k);
        k+= 10;
    }

    list.showList();
    return 0;
}
