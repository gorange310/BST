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


    Node(int, Node*, Node*);
    Node(const Node&);
    ~Node();

    //getter
    int get_m_nVal()const{ return m_nVal;};
    const Node* get_m_pLeftNode()const{ return m_pLeftNode;};
    const Node* get_m_pRightNode()const{ return m_pRightNode;};

    //setter
    void set_m_nVal(int nVal){ m_nVal =nVal; };
    void set_m_pLeftNode(Node* left){m_pLeftNode = left;};
    void set_m_pRightNode(Node* right){m_pRightNode = right;};

    //function
    void increment_m_nCount(){++m_nCount;};
    void display()const;

};

#endif // NODE_H
