#include "BST.h"
#include "Node.h"
#include <vector>

BST::BST()
{}
BST::~BST()
{}

bool BST::insert(int nVal)
{
    if(!rootNode)
    {
        Node* temp = new Node(nVal,nullptr,nullptr);
        rootNode = temp;
        return true;
    }
    else
    {

    }



}

bool BST::increment_nCount()
{}
void BST::display()const
{}
