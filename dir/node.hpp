#include <ostream>
#include <memory>
#include <vector>

using std::ostream;
using std::unique_ptr;
using std::vector;

template < typename T >
class Node
{
public:
    inline Node();

	//! I'm not in the mood of writing the depth copy for this node.
    Node(Node<T> &) = delete;

    inline Node(const T &val, const Node<T> *parent = nullptr );

    inline ~Node()
	{ freeBranch(); }

    inline Node<T> *parent() const
    { return m_parent; }

    inline const T &data() const
    { return *m_data; }

    inline bool hasData() const
    { return (bool) m_data; }

	template<typename F>
	void applyAll( F f );

    Node<T> &insertNode(const T &val);

    void freeBranch();

private:
    void clearNode();

private:
    unique_ptr<T> m_data;

    const Node<T> * m_parent = nullptr;
	vector<Node<T> *> m_innerNodes;
};


//Constructor: Intialiases node
template<typename T> inline 
Node<T>::Node( const T &val, const Node<T> *parent )
    : m_data(new T(val)), m_parent(parent)
{}


//cleans the inside of the node
template<typename T> 
void Node<T>::clearNode()
{ 
    m_data.reset();
    m_innerNodes.clear();
}

template<typename T>
template<typename F>
void Node<T>::applyAll( F f )
{
	if ( !hasData() )
		return;

	f( *m_data );
	for( auto e : m_innerNodes )
		e->applyAll(f);
}

template<typename T>
Node<T> &Node<T>::insertNode(const T &val)
{
    Node<T> *node = new Node(val, this);
	m_innerNodes.push_back(node);
    return *node;
}


//frees all branch
template<typename T>
void Node<T>::freeBranch()
{
	for( auto e : m_innerNodes ) {
		e->freeBranch();
		delete e;
	}
    clearNode();
}

template<typename T>
ostream & operator<<( ostream &o, Node<T> &n) 
{
//   if ( n.leftNode() )
  //      o << *n.leftNode() ;
   if ( n.hasData() )
        o << n.data() << ' ';
   //if ( n.rightNode() )
     //  o <<*n.rightNode();

	return o;
}

template< typename T >
Node<T> &makeTree( T &&val, Node<T> *parent = nullptr )
{
    Node<T> *root = new Node<T>(val);
    return *root;
}
	
template< typename T >
void removeTree( Node<T> &root )
{ 
	delete &root;
}
