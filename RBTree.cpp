//
// Red Black Tree Implementation
//
#include <bits/stdc++.h>
#include "RBTree.h"
using namespace std;

Node::Node(int data)
{
    this->data = data;
    left = right = parent = nullptr;
}

RBTree::RBTree()
{
    root = nullptr;
}