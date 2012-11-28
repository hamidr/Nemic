
#include <list>
#include <ostream>

using std::list;
using std::ostream;

template < typename T >
class Node
{
public:
	Node( Node<T> *parent, T *value );
	inline ~Node();

	inline Node<T> *parent() const;
	inline T &operator*() const;
	inline void setParent(Node<T> *parent);
	
	void setValue(T *ptr);
	void clearValue();

	//friend ostream & operator<<( ostream &o, Node<T> &n);
	//{ o << *n.m_value; return o; }

private:
	T *m_value;
	Node<T> *m_parent;
	list< Node<T>* > m_nodes;
};

template<typename T> inline 
Node<T>::Node( Node<T> *parent, T *value )
	: m_parent(parent), m_value(value)
{}


template<typename T> inline 
Node<T>::~Node()
{ clearValue(); }


template<typename T> inline
T &Node<T>::operator*() const
{ return *m_value; }


template<typename T> inline
Node<T> *Node<T>::parent() const
{ return parent; }


template<typename T>
void Node<T>::setValue(T *ptr)
{ 
	clearValue();
	m_value = ptr;
}


template<typename T> inline
void Node<T>::setParent(Node<T> *parent)
{ m_parent = parent; }


template<typename T> 
void Node<T>::clearValue()
{ 
	if ( m_value ) 
		delete m_value;
}

template<typename T>
ostream & operator<<( ostream &o, Node<T> &n) 
{
	o << "Node:" << *n << "\t" ;
	return o;
}

template< typename T >
Node<T> makeNode( Node<T> *parent, T &&val )
{
	T *ptr = new T(val);
	auto node = Node<T>(parent, ptr);
	return node;
}
