//
// Red Black Tree Implementation
//
#include <bits/stdc++.h>
#include "RBTree.h"
using namespace std;

Node::Node(int data)
{
    this->data = data;
    color = RED;
    left = right = parent = nullptr;
}

RBTree::RBTree()
{
    root = nullptr;
}

Node* RBTree::insertBST(Node *&root, Node *&ptr)
{
    if (root == nullptr)
        return ptr;

    if (ptr->data < root->data)
    {
        root->left = insertBST(root->left, ptr);
        root->left->parent = root;
    }
    else if ( ptr->data > root->data)
    {
        root->right = insertBST(root->right, ptr);
        root->right->parent = root;
    }

    return root;
}

void RBTree::insert(int n)
{
    Node *node = new Node(n);
    root = insertBST(root, node);
    fixRBTree(node);
}

void RBTree::rotateLeft(Node *&ptr)
{
    Node *right_child = ptr->right;
    ptr->right = right_child->left;

    if (ptr->right != nullptr)
        ptr->right->parent = ptr;

    right_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
        root = right_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;

    right_child->left = ptr;
    ptr->parent = right_child;
}

void RBTree::rotateRight(Node *&ptr)
{
    Node *left_child = ptr->left;
    ptr->left = left_child->right;

    if (ptr->left != nullptr)
        ptr->left->parent = ptr;

    left_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
        root = left_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;

    left_child->right = ptr;
    ptr->parent = left_child;
}

void RBTree::fixRBTree(Node *&ptr)
{
    Node *parent = nullptr;
    Node *grandparent = nullptr;
    while (ptr != root && ptr->color == RED && ptr->parent->color == RED)
    {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left)
        {
            Node *uncle = grandparent->right;
            if (uncle != nullptr && uncle->color == RED)
            {
                uncle->color = BLACK;
                parent->color = BLACK;
                grandparent->color = RED;
                ptr = grandparent;
            }
            else
            {
                if(ptr == parent->right)
                {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
                ptr = parent;
            }
        }
        else
        {
            Node *uncle = grandparent->left;
            if(uncle != nullptr && uncle->color == RED)
            {
                uncle->color = BLACK;
                parent->color = BLACK;
                grandparent->color = RED;
                ptr = grandparent;
            }
            else
            {
                if(ptr == parent->left)
                {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
                ptr = parent;
            }
        }
    }
    root->color = BLACK;
}

void RBTree::inorderBST(Node *&ptr)
{
    if (ptr == nullptr)
        return;

    inorderBST(ptr->left);
    cout << ptr->data << " " << ptr->color << endl;
    inorderBST(ptr->right);
}

void RBTree::inorder()
{
    inorderBST(root);
}

void RBTree::preorderBST(Node *&ptr)
{
    if (ptr == nullptr)
        return;

    cout << ptr->data << " " << ptr->color << endl;
    preorderBST(ptr->left);
    preorderBST(ptr->right);
}

void RBTree::preorder()
{
    preorderBST(root);
}