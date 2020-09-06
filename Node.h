#ifndef NODE_H
#define NODE_H


class Node
{
private:

    int m_nVal;

    Node* m_pLeftNode;

    Node* m_pRightNode;

    static int m_nCount;

public:


    Node(int nVal, Node* nodeLVal=nullptr, Node* nodeRVal=nullptr);
//    Node(const Node&, int);
    Node(const Node&);
    Node(Node&&) noexcept;
    ~Node();

    //functions
    int get_m_nVal(){ return m_nVal;}
    Node* get_m_pLeftNode(){ return m_pLeftNode;}
    Node* get_m_pRightNode(){ return m_pRightNode;}
    static int get_m_nCount();


    void set_m_pLeftNode(Node* left){ m_pLeftNode = left;}
    void set_m_pRightNode(Node* right){ m_pRightNode = right;}

};

#endif // NODE_H
