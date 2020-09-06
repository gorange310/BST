#include <iostream>
#include <vector>

#include "Node.h"

using namespace std;

Node* rootNode=nullptr;



// 6. 總節點數
void display_node_count()
{
    cout << "there is " << Node::get_m_nCount() << endl;
}

void create(Node* current, int nVal)
{
    if(!rootNode)
    {
        Node* newNode= new Node(nVal);
        rootNode = newNode;
        return;
    }
    else
    {
        if(nVal < current->get_m_nVal() )
        {
            if(!current->get_m_pLeftNode())
            {
                Node* newNode= new Node(nVal);
                current->set_m_pLeftNode(newNode);
                cout << "small node created"<<endl;
                return;
            }
            else
            {
                create(current->get_m_pLeftNode(),nVal);
                cout << "going LEft" << endl;
            }
        }
        if(nVal > current->get_m_nVal())
        {
            if(!current->get_m_pRightNode())
            {
                Node* newNode= new Node(nVal);
                current->set_m_pRightNode(newNode);
                cout << "large node created"<<endl;
                return;
            }
            else
            {
                create(current->get_m_pRightNode(),nVal);
                cout << "going right" <<endl;
            }
        }
        else
            cout << "value exist." << endl;
    }
}



// 2. 由小到大遍巡並列出值
// 3. 由大到小遍巡並列出值
// 4. 由最根處從上而下、從左至右列出值
// 5. search


int main()
{

    vector<Node> BST;

    display_node_count();
    BST.push_back(10);
//    Node rootNode(10);

    display_node_count();
    BST.push_back(290);

    display_node_count();

//        Node second(5);
    create(rootNode,5);
    display_node_count();
//        rootNode.set_m_pLeftNode(&second);

//    Node *dynamic= new Node(29);
    create(rootNode,29);
    display_node_count();


    create(rootNode,2);
    display_node_count();


    create(rootNode,12);
    display_node_count();

    delete rootNode;

    return 0;
}
