#include <iostream>

using namespace std;
//
class Node
{

private:

    int m_nVal;

    Node* m_pLeftNode;

    Node* m_pRightNode;

public:

    //constructor
    Node(int nVal):m_nVal(nVal),m_pLeftNode(nullptr),m_pRightNode(nullptr)
    {
        cout << "constructor called" << endl;
    };

//    destructor
    ~Node(){
        cout << "destructor called @" << this  << " ..... deleting " << this->m_nVal << endl;
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



    //functions
    int get_m_nVal() { return m_nVal; }
    Node* get_m_pLeftNode() { return m_pLeftNode; }
    Node* get_m_pRightNode() { return m_pRightNode; }

    void set_m_pLeftNode(Node *pSmall) { this->m_pLeftNode = pSmall; }
    void set_m_pRightNode(Node *pLarge) { this->m_pRightNode = pLarge; }

    void Create(int nVal);
    bool Search(int nVal);

}*current, *rootNode=nullptr;

int nCount=0;

// 1.create  2.由小到大遍巡並列出值 3.由大到小遍巡並列出值
// 4. 由最根處從上而下、從左至右列出值  5.search 6. 總節點數

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



// 1
void Create(int nVal, Node* pNode)
{

     pNode = rootNode;
    if(!rootNode)
    {
        cout << "first Node created." << endl;
        Node* newNode = new Node(nVal);
        rootNode = newNode;
        nCount++;
    }

    // if nVal less than current node value

    if(nVal < pNode->get_m_nVal() )
    {
        Node* newNode = new Node(nVal);
        if( !pNode->get_m_pLeftNode())
            Create(nVal, pNode->get_m_pLeftNode());
        else
            pNode->set_m_pLeftNode(newNode);
        cout << "small vlaue Node created." << endl;
    }

    // if nVal larger than current value
    else if( nVal > pNode->get_m_nVal() )
    {
        Node* newNode = new Node(nVal);
        if( !pNode->get_m_pRightNode() )
            Create(nVal, pNode->get_m_pRightNode());
        else
            pNode->set_m_pRightNode(newNode);
        cout << "large value Node created." << endl;
    }
    else
        cout << nVal << " has been added." << endl;
}

// 2
void PrintSToL(Node* ptr)
{
    if(rootNode)
    {
        cout << "it's empty." << endl;
        return;
    }
    if(!rootNode)
    {

        if(ptr->get_m_pLeftNode())
        {
            PrintSToL(ptr->get_m_pLeftNode());
        }
        cout << ptr->get_m_nVal() << " ";

//        cout << rootNode->get_m_nVal() << " ";

        if(ptr->get_m_pLeftNode())
        {
            PrintSToL(ptr->get_m_pRightNode());
        }
    }
    cout << endl;

}

// 3
void PrintLToS(Node* ptr)
{
    if(rootNode)
    {
        cout << "it's empty." << endl;
        return;
    }
    if(!rootNode)
    {

        if(ptr->get_m_pRightNode())
        {
            PrintSToL(ptr->get_m_pRightNode());
        }
        cout << ptr->get_m_nVal() << " ";

//        cout << rootNode->get_m_nVal() << " ";

        if(ptr->get_m_pLeftNode())
        {
            PrintSToL(ptr->get_m_pLeftNode());
        }
    }
    cout << endl;

}


// 4
void PrintFromRoot(Node* ptr)
{
    if(rootNode)
    {
        cout << "it's empty." << endl;
        return;
    }
    if(!rootNode)
    {
        cout << ptr->get_m_nVal() << " ";
        PrintFromRoot(ptr->get_m_pLeftNode());
        PrintFromRoot(ptr->get_m_pRightNode());
    }
}

// 5
void Search(int nVal, Node* pNode)
{
    if(pNode->get_m_nVal() == nVal)
        cout << "true" << endl;
    if(pNode->get_m_nVal() != nVal)
        cout << "false" << endl;
    if(pNode->get_m_nVal() < nVal)
        Search(nVal, pNode->get_m_pLeftNode());
    if(pNode->get_m_nVal() > nVal)
        Search(nVal, pNode->get_m_pRightNode());

}

// 7


void Menu()
{
    do
    {
        cout << endl << endl;
        cout << "1.create  2.由小到大遍巡並列出值 3.由大到小遍巡並列出值" << endl;
        cout << "4. 由最根處從上而下、從左至右列出值  5.search 6. 總節點數 7. Exit" << endl;
        cout << "------------------------------------------------------------------" << endl;
        cout << "Choice ";
        int nChoice = InputVal();

        switch(nChoice)
        {
        case 1:
        {
            cout << "create :";
            int nVal = InputVal();
            Create(nVal, rootNode);
        }
            break;
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
            cout << "Search value: " <<endl;
            int nVal = InputVal();
            cout << "result is: ";
            Search(nVal, rootNode);
        }
            break;

        case 6:
            cout << "There are " <<  nCount << " node now." << endl;

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
    Node(10);
    Menu();
    return 0;
}
