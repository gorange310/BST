#ifndef NODE_H
#define NODE_H
class Node
{

private:

    int m_nVal;

    Node* m_pLeftNode;

    Node* m_pRightNode;

public:

    static int m_nCount;

    Node(int);
    Node(const Node&);
    ~Node();


    //functions
    int get_m_nVal() { return m_nVal; }
    Node* get_m_pLeftNode() { return m_pLeftNode; }
    Node* get_m_pRightNode() { return m_pRightNode; }

    static int print_m_nCount() { return m_nCount; }

    void set_m_pLeftNode(Node *pSmall) { this->m_pLeftNode = pSmall; }
    void set_m_pRightNode(Node *pLarge) { this->m_pRightNode = pLarge; }

} *rootNode=nullptr;

// 6. 總節點數
int Node::m_nCount=0;

// constructor
Node::Node(int nVal):m_nVal(nVal),m_pLeftNode(nullptr),m_pRightNode(nullptr)
{
    m_nCount++;
};

// copy constructor
Node::Node(const Node& source):m_nVal(source.m_nVal),m_pLeftNode(nullptr),m_pRightNode(nullptr)
{

    if(source.m_pLeftNode)
    {
       m_pLeftNode = new Node(*source.m_pLeftNode);

    }
    if(source.m_pRightNode)
    {
       m_pRightNode = new Node(*source.m_pRightNode);

    }


    m_nCount++;
};

Node::~Node()
{
    if(m_pLeftNode)
    {
        delete m_pLeftNode;
        m_pLeftNode=nullptr;
    }
    if(m_pRightNode)
    {
        delete m_pRightNode;
        m_pRightNode=nullptr;
    }
}
#endif // NODE_H
