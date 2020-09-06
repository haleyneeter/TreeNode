#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
using namespace std;
class Tree
{
    public:
        struct TreeNode
        {
            char letter;
            int count;
            TreeNode *left;
            TreeNode *right;
            
        };
        TreeNode *root;
        void insert(TreeNode *&, TreeNode *&, char);
        void displayInOrder(TreeNode *) const;
    
        Tree()
        {root=nullptr;}
        void insertNode (char);
        void displayInOrder() const
        {displayInOrder(root);}
        
};

void Tree::insertNode (char letter)
{
   if(root==NULL)
   {
       root=new TreeNode;
       root-> letter=letter;
       root->count=1;
       root->left=root->right=NULL;
   }
   else 
   {
        if(root->letter > letter)
        {
           insert(root->left, root, letter); 
        }
            

        else
        {
            insert(root->right, root, letter);
            
        }
    }
}
void Tree:: insert(TreeNode *&nodePtr, TreeNode *&newNode, char letter)
{
    if(nodePtr==NULL)
    {
        TreeNode *nextNode= new TreeNode;
        nextNode->letter=letter;
        nextNode->count=1;
        nextNode->left = nextNode->right = NULL;
        if(newNode->letter > nextNode->letter)
        {
            newNode->left=nextNode;
        }
        else
        {
            newNode->right=nextNode;
        }
        
    }
    else if (nodePtr->letter >letter)
    {
        insert(nodePtr->left, nodePtr, letter);
        
        
    }
    else 
    {
        insert(nodePtr->right, nodePtr, letter);
        
        
    }

}

void Tree::displayInOrder(TreeNode *nodePtr)const
{
    if(nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout <<nodePtr->letter<< ":"<<nodePtr->count<< endl;
        displayInOrder(nodePtr->right);
    }
}
#endif
