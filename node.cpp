#include <iostream>
#include "Node.h"

int Node::m_nCount=0;

Node::Node(int nVal, Node* nodeLVal, Node* nodeRVal):
    m_nVal(nVal),m_pLeftNode(nodeLVal),m_pRightNode(nodeRVal)
{
    std::cout << "constructor called -- " << m_nVal << std::endl;
    ++m_nCount;
};


Node::Node(const Node& source)
{
    m_nVal = source.m_nVal;
    m_pLeftNode = new Node(source.m_nVal);
    m_pRightNode = new Node(source.m_nVal);
//    *m_pLeftNode = *source.m_pLeftNode;
//    *m_pRightNode = *source.m_pRightNode;
    std::cout << "copy constructor called for-- " << m_nVal << std::endl;
};

Node::Node(Node&& source) noexcept: m_pLeftNode(source.m_pLeftNode),m_pRightNode(source.m_pRightNode)
{
    source.m_pLeftNode=nullptr;
    source.m_pRightNode=nullptr;

    std::cout << "Move constructor - Move for " << m_nVal << std::endl;
}


Node::~Node()
{
    std::cout << "delete..." << m_nVal << std::endl;
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
    --m_nCount;
}



int Node::get_m_nCount() { return m_nCount; }
