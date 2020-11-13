#ifndef BST_H
#define BST_H
#include "Node.h"
#include <vector>

class BST
{
private:
    std::vector <Node*> m_vTree;
    Node* rootNode;

public:

    BST();
    ~BST();

    bool insert(int nVal);
    bool increment_nCount();
    void display()const;

};

#endif // BST_H
