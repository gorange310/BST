#include <iostream>

using namespace std;
//
class Node
{

    int m_nVal;

    Node* m_pLeftNode;

    Node* m_pRightNode;

public:

    //constructor
    Node(int nVal):
        m_nVal(nVal),m_pLeftNode(nullptr),m_pRightNode(nullptr)
    {
        cout << "constructor called" << endl;
    };

    //destructor
//    ~Node(){
//        cout << "destructor called" << endl;
//        delete m_pLeftNode;
//        delete m_pRightNode;
//    }

    //functions
//    int get_m_nVal() { return m_nVal; }
//    Node* get_m_pLeftNode() { return m_pLeftNode; }
//    Node* get_m_pRightNode() { return m_pRightNode; }

//    void set_m_nVal(int nVel) { m_nVal = nVel; }
//    void set_m_pLeftNode(Node *pSmall) { m_pLeftNode = pSmall; }
//    void set_m_pRightNode(Node *pLarge) { m_pRightNode = pLarge; }

}*rootNode=NULL;

// 1.create  2.由小到大遍巡並列出值 3.由大到小遍巡並列出值
// 4. 由最根處從上而下、從左至右列出值  5.search 6. 總節點數

//int InputVal()
//{
//    int nInput=0;

//    cout << "-- Input (integer) --->>";
//    cin >> nInput;
//    while (cin.fail())
//    {
//        cin.clear();
//        cin.ignore();
//        cout << "invaild input, try again ->>"<< endl;
//        cin >> nInput;
//    }

//    return nInput;
//}



////1
//Node* Create(int nVal, Node* newNode)
//{

//    cout << "Create Value ";
//    nVal = InputVal();

//    if(!rootNode)
//    {
//        newNode = new Node(nVal);
//        cout << "first Node created." << endl;
//        rootNode = newNode;
//    }

//    else if(nVal < newNode->get_m_nVal())
//    {
//        cout << "small Node created." << endl;
//        newNode->set_m_pLeftNode(Create(nVal ,newNode->get_m_pLeftNode()));
//    }

//    else
//    {
//        cout << "large Node created." << endl;
//        newNode->set_m_pRightNode(Create(nVal ,newNode->get_m_pRightNode()));
//    }
//    return newNode;
//}



int main()
{
    Node(10);
    return 0;
}
