#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    bool red;
    struct node *left,*right,*parent;
};
struct node *getnode(int key)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->key=key;
    ptr->red=1;
    ptr->left=ptr->right=ptr->parent=NULL;
    return ptr;
}
struct node *insertBST(struct node *root,struct node *ptr)
{
    if(root==NULL)
        return ptr;
    if(ptr->key < root->key)
    {
        root->left=insertBST(root->left,ptr);
        root->left->parent=root;
    }
    else if(ptr->key > root->key)
    {
        root->right=insertBST(root->right,ptr);
        root->right->parent=root;
    }
    return root;
}
void rotateLeft(struct node *&root,struct node *&ptr)
{
    struct node *pright=ptr->right;
    ptr->right=pright->left;
    if(ptr->right!=NULL)
        ptr->right->parent=ptr;
    pright->parent=ptr->parent;
    if(ptr->parent==NULL)
        root=pright;
    else if(ptr==ptr->parent->left)
        ptr->parent->left=pright;
    else
        ptr->parent->right=pright;
    pright->left=ptr;
    ptr->parent=pright;
}
void rotateRight(struct node *&root,struct node *&ptr)
{
    struct node *pleft=ptr->left;
    ptr->left=pleft->right;
    if(ptr->left!=NULL)
        ptr->left->parent=ptr;
    pleft->parent=ptr->parent;
    if(ptr->parent==NULL)
        root=pleft;
    else if(ptr==ptr->parent->left)
        ptr->parent->left=pleft;
    else
        ptr->parent->right=pleft;
    pleft->right=ptr;
    ptr->parent=pleft;
}
void fixRBTree(struct node *&root,struct node *&ptr)
{
    struct node *parent=NULL;
    struct node *grandparent=NULL;
    while(ptr!=root && ptr->red==1 && ptr->parent->red==1)
    {
        parent=ptr->parent;
        grandparent=parent->parent;
        if(parent==grandparent->left)
        {
            struct node *uncle=grandparent->right;
            if(uncle!=NULL && uncle->red==1)
            {
                uncle->red=0;
                parent->red=0;
                grandparent->red=1;
                ptr=grandparent;
            }
            else
            {
                if(ptr==parent->right)
                {
                    rotateLeft(root,parent);
                    ptr=parent;
                    parent=ptr->parent;
                }
                rotateRight(root,grandparent);
                int temp=parent->red;
                parent->red=grandparent->red;
                grandparent->red=temp;
                ptr=parent;
            }
        }
        else
        {
            struct node *uncle=grandparent->left;
            if(uncle!=NULL && uncle->red==1)
            {
                uncle->red=0;
                parent->red=0;
                grandparent->red=1;
                ptr=grandparent;
            }
            else
            {
                if(ptr==parent->left)
                {
                    rotateRight(root,parent);
                    ptr=parent;
                    parent=ptr->parent;
                }
                rotateLeft(root,grandparent);
                int temp=parent->red;
                parent->red=grandparent->red;
                grandparent->red=temp;
                ptr=parent;
            }
        }
    }
    root->red=0;
}
int main()
{
    int n;
    struct node *root1=NULL,*root2=NULL;
    printf("Enter elements in first Red black tree. Enter 0 to end\n");
    scanf("%d",&n);
    while(n!=0)
    {
        struct node *ptr=getnode(n);
        root1=insertBST(root1,ptr);
        fixRBTree(root1,ptr);
        scanf("%d",&n);
    }
    printf("Enter elements in second Red black tree. Enter 0 to end\n");
    scanf("%d",&n);
    while(n!=0)
    {
        struct node *ptr=getnode(n);
        root2=insertBST(root2,ptr);
        fixRBTree(root2,ptr);
        scanf("%d",&n);
    }
    return 0;
}
