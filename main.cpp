#include <iostream>

using namespace std;

class Node
{

private:

    int m_nVal;

    Node* m_pLeftNode;

    Node* m_pRightNode;

    static int m_nCount;

public:

    Node(const Node&, int);
//    Node& operater=(const Node&);
    ~Node();


    // constructor
    Node(int nVal):m_nVal(nVal),m_pLeftNode(nullptr),m_pRightNode(nullptr)
    {
    //        cout << "constructor called" << endl;
//        cout << "Node constructor called... set value: " << nVal << endl;
        cout << "constructor@ " << this << endl;
        m_nCount++;
    };


    //functions
    int get_m_nVal() { return m_nVal; }
    Node* get_m_pLeftNode() { return m_pLeftNode; }
    Node* get_m_pRightNode() { return m_pRightNode; }
    int get_m_nCount() { return m_nCount; }

    void set_m_pLeftNode(Node *pSmall) { this->m_pLeftNode = pSmall; }
    void set_m_pRightNode(Node *pLarge) { this->m_pRightNode = pLarge; }

} *rootNode=nullptr;

// 6. 總節點數
int Node::m_nCount=0;

Node::Node(const Node& SourceNode, int nVal):m_nVal(nVal),m_pLeftNode(nullptr),m_pRightNode(nullptr)
{
    if(SourceNode.m_pLeftNode)
    {
        m_pLeftNode = new Node(*SourceNode.m_pLeftNode);
    }
    if(SourceNode.m_pRightNode)
    {
        m_pRightNode = new Node(*SourceNode.m_pRightNode);
    }
}

//Node& Node::operater=(const Node& other)
//{
//    m_nVal = other.m_nVal;

//    Node* left_orig = m_pLeftNode;
//    m_pLeftNode = new Node(*other.m_pLeftNode);
//    delete left_orig;

//    Node* right_orig = m_pRightNode;
//    m_pRightNode = new Node(*other.m_pRightNode);
//    delete right_orig;

//    return *this;
//}

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
void Create(int nVal, Node* pNode)
{
    if(!pNode)
    {
        cout << "First Node created." << endl;
        Node* newNode = new Node(nVal);
        rootNode = newNode;
        return;
    }

    // if nVal less than current node value
    else
    {
//        cout << "pNode value: " << pNode->get_m_nVal() << endl;
        if(nVal < pNode->get_m_nVal() )
        {
            if( !pNode->get_m_pLeftNode())
            {
                Node* newNode = new Node(nVal);
//                cout << "Small vlaue Node created." << endl;
                pNode->set_m_pLeftNode(newNode);
                return;
            }
            else
            {
//                cout << "going <<<< -------- LEFT." << endl;
                Create(nVal, pNode->get_m_pLeftNode());
            }
        }

        // if nVal larger than current value
        else if( nVal > pNode->get_m_nVal() )
        {
            if( !pNode->get_m_pRightNode() )
            {
                Node* newNode = new Node(nVal);
//                cout << "Large value Node created." << endl;
                pNode->set_m_pRightNode(newNode);
                return;
            }
            else
            {
//                cout << "going -------- >>>> RIGHT." << endl;
                Create(nVal, pNode->get_m_pRightNode());
            }
        }
        else
            cout << nVal << " has been added." << endl;
    }

}

// 2.由小到大遍巡並列出值
void PrintSToL(Node* pNode)
{
    if(!rootNode)
    {
        cout << "it's empty." << endl;
        return;
    }
    if(pNode)
    {
        if(pNode->get_m_pLeftNode())
            PrintSToL(pNode->get_m_pLeftNode());

        cout << pNode->get_m_nVal() << " ";

        if(pNode->get_m_pRightNode())
            PrintSToL(pNode->get_m_pRightNode());
    }
}

// 3.由大到小遍巡並列出值
void PrintLToS(Node* pNode)
{
    if(!rootNode)
    {
        cout << "it's empty." << endl;
        return;
    }
    if(pNode)
    {
        if(pNode->get_m_pRightNode())
            PrintLToS(pNode->get_m_pRightNode());

        cout << pNode->get_m_nVal() << " ";

        if(pNode->get_m_pLeftNode())
            PrintLToS(pNode->get_m_pLeftNode());
    }
}

// 4. 由最根處從上而下、從左至右列出值
void PrintFromRoot(Node* pNode)
{
    if(!rootNode)
    {
        cout << "it's empty." << endl;
        return;
    }
    if(pNode)
    {
        cout << pNode->get_m_nVal() << " ";
        PrintFromRoot(pNode->get_m_pLeftNode());
        PrintFromRoot(pNode->get_m_pRightNode());
    }
}

// 5.search
void Search(int nVal, Node* pNode)
{

    if(pNode->get_m_nVal() == nVal)
    {
        cout << "true" << endl;
        return;
    }
    else
    {
        if(nVal < pNode->get_m_nVal() && pNode->get_m_pLeftNode())
        {
//            cout << "going <<<< -------- LEFT." << endl;
            Search(nVal, pNode->get_m_pLeftNode());
        }
        else if(nVal > pNode->get_m_nVal() && pNode->get_m_pRightNode())
        {
//            cout << "going -------- >>>> RIGHT." << endl;
            Search(nVal, pNode->get_m_pRightNode());
        }
        else
        {
            cout << "false" << endl;
            return;
        }
    }
}

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
            cout << "Create Node value";
            int nVal = InputVal();
            Create(nVal, rootNode);
            break;
        }
        case 2:
            PrintSToL(rootNode);
            break;
        case 3:
            PrintLToS(rootNode);
            break;
        case 4:
            PrintFromRoot(rootNode);
            break;
        case 5:
        {
            cout << "Search Node value ";
            int nVal = InputVal();
            cout << "result is: ";
            Search(nVal, rootNode);
            break;
        }
        case 6:
            cout << "There are " << rootNode->get_m_nCount() << " node now." << endl;
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
