#include <iostream>
#include "Node.h"

//no Arg cstr
Node::Node(int nVal, Node* left=nullptr, Node* right=nullptr):
    m_nVal(nVal),m_pLeftNode(left),m_pRightNode(right)
{

}

Node::Node(const Node& source)
{
    m_nVal = source.m_nVal;
    m_pLeftNode = new Node(source.get_m_pLeftNode()->get_m_nVal());
    *m_pLeftNode = *source.m_pLeftNode;
    m_pRightNode = new Node(source.get_m_pRightNode()->get_m_nVal());
    *m_pRightNode = *source.m_pRightNode;
}



Node::~Node()
{
    delete m_pLeftNode;
    delete m_pRightNode;
}

//function
void Node::display()const
{
    std::cout << m_nVal;
}
