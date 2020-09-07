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
    std::cout << "copy constructor called for-- " << m_nVal << std::endl;

//    m_nVal = source.m_nVal;
    if(m_nVal<source.m_nCount)
    {
        m_pLeftNode = new Node(m_nVal);
        *m_pLeftNode = *source.m_pLeftNode;
    }
    if(m_nVal>source.m_nCount)
    {
        m_pRightNode = new Node(m_nVal);
        *m_pRightNode = *source.m_pRightNode;
    }

};

//Node::Node(Node&& source) noexcept: m_pLeftNode(source.m_pLeftNode),m_pRightNode(source.m_pRightNode)
//{
//    source.m_pLeftNode=nullptr;
//    source.m_pRightNode=nullptr;

//    std::cout << "Move constructor - Move for " << m_nVal << std::endl;
//}


Node::~Node()
{
    std::cout << "delete..." << m_nVal << std::endl;

        delete m_pLeftNode;
        m_pLeftNode=nullptr;


        delete m_pRightNode;
        m_pRightNode=nullptr;

    --m_nCount;
}



int Node::get_m_nCount() { return m_nCount; }
