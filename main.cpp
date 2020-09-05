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
    Node(const Node&, int);
    ~Node();


    //functions
    static int print_m_nCount() { return m_nCount; }
    void printSToL(const Node&);
    void printLToS(const Node&);
    void printFromRoot(const Node&);

} *m_pRoot = nullptr;

// 6. 總節點數
int Node::m_nCount=0;

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

// constructor
Node::Node(int nVal):m_nVal(nVal),m_pLeftNode(nullptr),m_pRightNode(nullptr)
{
    cout << "Node constructor called... set value: " << nVal << endl;
    m_nCount++;
};

// copy constructor
Node::Node(const Node& source, int nVal)
{
    cout << "COPY construtor called" << endl;

    if(source == nullptr)
    {
        m_pRoot = new Node(nVal);
        cout << "first node created" << endl;
    }
    else
    {
        cout << "source value: " << source.m_nVal;
        if(nVal < source.m_nVal)
        {
            if(!source.m_pLeftNode)
            {
                m_pLeftNode = new Node(nVal);
                cout << "small value node created" << endl;
            }
            else
            {
                cout << "going <<<< -------- LEFT." << endl;
                Node(*source.m_pLeftNode, nVal);
            }
        }
        if(nVal > source.m_nVal)
        {
            if(!source.m_pRightNode)
            {
                m_pRightNode = new Node(nVal);
                cout << "large value node created" << endl;
            }
            else
            {
                cout << "going <<<< -------- RIGHT." << endl;
                Node(*source.m_pRightNode, nVal);
            }
        }
        else
            cout << nVal << " has been added." << endl;
    }
};




Node::~Node()
{
    cout << "destructor called ..... deleting " << m_nVal << endl;
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



// 2.由小到大遍巡並列出值
//void Node::printSToL()
//{
//    if(!rootNode)
//    {
//        cout << "it's empty." << endl;
//        return;
//    }
//    if(pNode)
//    {
//        if(pNode->get_m_pLeftNode())
//            PrintSToL(pNode->get_m_pLeftNode());

//        cout << pNode->get_m_nVal() << " ";

//        if(pNode->get_m_pRightNode())
//            PrintSToL(pNode->get_m_pRightNode());
//    }
//}


// 3.由大到小遍巡並列出值
//void Node::printLToS()
//{
//    if(!rootNode)
//    {
//        cout << "it's empty." << endl;
//        return;
//    }
//    if(pNode)
//    {
//        if(pNode->get_m_pRightNode())
//            PrintLToS(pNode->get_m_pRightNode());

//        cout << pNode->get_m_nVal() << " ";

//        if(pNode->get_m_pLeftNode())
//            PrintLToS(pNode->get_m_pLeftNode());
//    }
//}


// 4. 由最根處從上而下、從左至右列出值
void Node::printFromRoot(const Node& source)
{
    if(!source.m_pRoot)
    {
        cout << "it's empty." << endl;
        return;
    }
    else
    {
        cout << source.m_nVal << " ";
        printFromRoot(*source.m_pRightNode);
        printFromRoot(*source.m_pRightNode);
    }
}


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
        {
            int nVal=0;
            cout << "create Node value: ";
            cin >> nVal;
            Node::Node(*m_pRoot,nVal);
        }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            Node::printFromRoot(*m_pRoot);
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
