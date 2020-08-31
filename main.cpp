#include <iostream>
#include <vector>

using namespace std;

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


    //functions
    int get_m_nVal() { return m_nVal; }
    Node* get_m_pLeftNode() { return m_pLeftNode; }
    Node* get_m_pRightNode() { return m_pRightNode; }

    void set_m_pLeftNode(Node *pSmall) { this->m_pLeftNode = pSmall; }
    void set_m_pRightNode(Node *pLarge) { this->m_pRightNode = pLarge; }

} *rootNode=nullptr;

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

//    pNode = rootNode;
    if(!pNode)
    {
        cout << "first Node created." << endl;
        Node* newNode = new Node(nVal);
        rootNode = newNode;
        nCount++;
        return;
    }

    // if nVal less than current node value
    else
    {
        cout << "pNode value: " << pNode->get_m_nVal() << endl;
        if(nVal < pNode->get_m_nVal() )
        {
            if( !pNode->get_m_pLeftNode())
            {
                Node* newNode = new Node(nVal);
                cout << "Small vlaue Node created." << endl;
                pNode->set_m_pLeftNode(newNode);
                nCount++;
                return;
            }
            else
            {
                cout << "Small Node exsited." << endl;
                Create(nVal, pNode->get_m_pLeftNode());
            }
        }

        // if nVal larger than current value
        else if( nVal > pNode->get_m_nVal() )
        {
            if( !pNode->get_m_pRightNode() )
            {
                Node* newNode = new Node(nVal);
                cout << "Large value Node created." << endl;
                pNode->set_m_pRightNode(newNode);
                nCount++;
                return;
            }
            else
            {
                cout << "Large Node exsited." << endl;
                Create(nVal, pNode->get_m_pRightNode());
            }
        }
        else
            cout << nVal << " has been added." << endl;
    }

}

// 2
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
        {
            PrintSToL(pNode->get_m_pLeftNode());
        }

        cout << pNode->get_m_nVal() << " ";

        if(pNode->get_m_pLeftNode())
        {
            PrintSToL(pNode->get_m_pRightNode());
        }
    }
}

// 3
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
        {
            PrintSToL(pNode->get_m_pRightNode());
        }
        cout << pNode->get_m_nVal() << " ";

        if(pNode->get_m_pLeftNode())
        {
            PrintSToL(pNode->get_m_pLeftNode());
        }
    }
}


// 4
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

// 5
void Search(int nVal, Node* pNode)
{
    if(pNode->get_m_nVal() == nVal)
    {
        cout << "true" << endl;
        return;
    }
    if(pNode->get_m_nVal() != nVal)
    {
        cout << "false" << endl;
        return;
    }
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
        cout << "1.Create  2.小到大遍巡 3.大到小遍巡 4. 由最根處從上而下、從左至右  " << endl;
        cout << "5.Search 6. 總節點數 7. Exit" << endl;
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
    return 0;
}
