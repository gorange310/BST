#include <iostream>
#include <vector>

//#include "Node.h"

using namespace std;

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
    Node *m_pRoot = nullptr;


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
    cout << "Node constructor called... set value: " << nVal << endl;
    m_nCount++;
};

// copy constructor
Node::Node(const Node& source)
{
    cout << "COPY construtor called" << endl;
    if(!source.m_pRoot)
    {
       m_pRoot = nullptr;
    }
    else
    {
        this->m_pRoot = new Node(source.m_nVal);
        this->m_pLeftNode = source.m_pLeftNode;
        this->m_pRightNode = source.m_pRightNode;
    }
    m_nCount++;
};

Node::~Node()
{
    cout << "destructor called ..... deleting " << this->m_nVal << endl;
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

int InputVal()
{
    int nInput=0;
    cout << "-- Input (integer) --->>";
    cin >> nInput;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "invaild input, try again ->>"<< endl;
        cin >> nInput;
    }
    return nInput;
}

// 1. create Node


// 2.由小到大遍巡並列出值


// 3.由大到小遍巡並列出值


// 4. 由最根處從上而下、從左至右列出值


// 5.search



void Menu()
{
    do
    {
        cout << endl << endl;
        cout << "1.Create  2.小到大遍巡 3.大到小遍巡 4. 由最根處從上而下、從左至右  " << endl;
        cout << "5.Search 6. 總節點數 7. Exit" << endl;
        cout << "------------------------------------------------------------------" << endl;
        cout << "Choice ";
        int nChoice = InputVal();

        switch(nChoice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            delete rootNode;
            return;
        default:
            cout<<"invaild choice :("<<endl;
            break;
        }
    }while(true);
}

int main()
{

    Menu();
    cout << "Exit." << endl;
    return 0;
}
