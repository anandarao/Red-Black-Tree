//
// Red Black Tree Definition
//

#ifndef RED_BLACK_TREE_RBTREE_H
#define RED_BLACK_TREE_RBTREE_H

enum Color {RED, BLACK};

struct Node
{
    int data;
    int color;
    Node *left, *right, *parent;

    explicit Node(int);
};

class RBTree
{
    private:
        Node *root;
    protected:
        void rotateLeft(Node *&);
        void rotateRight(Node *&);
        void fixRBTree(Node *&);
        void inorderBST(Node *&);
        void preorderBST(Node *&);
        Node* insertBST(Node *&, Node *&);
    public:
        RBTree();
        void insert(int);
        void inorder();
        void preorder();
};


#endif //RED_BLACK_TREE_RBTREE_H
