#include <ostream>
#include <memory>

using std::ostream;
using std::unique_ptr;

// Binary Tree
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

    inline Node<T> *leftNode() const
    { return m_left; }

    inline Node<T> *rightNode() const
    { return m_right; }

    bool isRoot() const
    { return (bool) m_parent; }

    inline const T &data() const
    { return *m_data; }

    inline bool hasData() const
    { return (bool) m_data; }

    Node<T> *insertNode(const T &val);

    void freeBranch();

private:
    void clearNode();

private:
    unique_ptr<T> m_data;

    const Node<T> * m_parent = nullptr;
    Node<T> * m_left  = nullptr;
    Node<T> * m_right = nullptr;
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
    m_left = m_right = nullptr;
}


template<typename T>
Node<T> *Node<T>::insertNode(const T &val)
{
    Node<T> *res;

    if ( !m_data || val == data() ) {
        m_data.reset( new T(val) );
        res = this;
    }
    else if ( val > data() ) {
        res = m_right ?
                    m_right->insertNode(val)
                  : m_right = new Node(val, this);
    }
    else // if ( val <= data())
        res = m_left ?
                    m_left->insertNode(val)
                  : m_left = new Node(val, this);

    return res;
}


//frees all branch
template<typename T>
void Node<T>::freeBranch()
{
    if ( m_left ) {
        m_left->freeBranch();
        delete m_left;
        m_left = nullptr;
    }

    if ( m_right ) {
        m_right->freeBranch();
        delete m_right;
        m_right = nullptr;
    }
    clearNode();
}

template<typename T>
ostream & operator<<( ostream &o, Node<T> &n) 
{
   if ( n.leftNode() )
        o << *n.leftNode() ;
   if (n.hasData())
        o << n.data() << ' ';
   if ( n.rightNode() )
       o <<*n.rightNode();

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
