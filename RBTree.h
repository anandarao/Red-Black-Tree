//
// Red Black Tree Definition
//

#ifndef RED_BLACK_TREE_RBTREE_H
#define RED_BLACK_TREE_RBTREE_H

enum Color {RED, BLACK};

struct Node
{
    int data;
    bool color;
    Node *left, *right, *parent;

    explicit Node(int);
};

class RBTree
{
    private:
        Node *root;
    protected:
        void rotateLeft(Node *&, Node *&);
        void rotateRight(Node *&, Node *&);
        void fixViolation(Node *&, Node *&);
    public:
        RBTree();
        void insert(const int &n);
        void inorder();
        void levelOrder();
};


#endif //RED_BLACK_TREE_RBTREE_H
