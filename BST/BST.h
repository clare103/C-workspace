//
//  BST.h
//  BST
//
//  Created by David Clare on 10/9/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef __BST__BST__
#define __BST__BST__

#include <iostream>
#include "Student.h"
#include "Faculty.h"


using namespace std;

template<typename T>
class TreeNode
{
public:
    TreeNode(T d)
    {
        data = d;
        left = right = 0;
    }
public:
    //virtual ~TreeNode();
    TreeNode<T>* left;
    TreeNode<T>* right;
   // TreeNode<T>* getSuccessor(TreeNode<T> d);
    T data;
};

template <typename T>
class BST
{
public:
    BST()
    {
        size =0;
        root =0;
    }
     //~BST(){}
    int getSize();
    bool isEmpty();
    bool contains(T d);
    void recAdd(T d);
    
    bool remove(T d);
    bool lookup(T d);
    void mirror();
    T getMin();
    T getMax();
    void print();

    
private:
    TreeNode<T>* root;
    void recAddHelper(T d, TreeNode<T>*& p);
    void printHelper(TreeNode<T>* n);
    TreeNode<T>* getSuccessor(TreeNode<T> d);
    TreeNode<T>* lookupHelper(TreeNode<T>*& p, T d);
    void mirrorHelper(TreeNode<T>*& p);
    int size;

};




template<typename T>
bool BST<T>::lookup(T d)
{
    return(lookupHelper(root, d));
}

template<typename T>
TreeNode<T>* BST<T>::lookupHelper(TreeNode<T>*& p, T data)
{
    if(p == NULL)
    {
        return false;
    }
    if(data == p -> data)
    {
        return(true);
    }
    else if(data < p -> data)
    {
        return(lookup(p -> left, data));
    }
    else
    {
        return(lookup(p -> right, data));
    }
}


template<typename T>
void BST<T>::mirror()
{
    mirrorHelper(root);
}

template<typename T>
void BST<T>::mirrorHelper(TreeNode<T>*& p)
{
    if( p != NULL)
    {
        mirrorHelper(p -> left);
        mirrorHelper(p -> right);
        
        
        TreeNode<T>* temp = p -> left;
        p -> left = p -> right;
        p -> right = temp;
    }
}


template<typename T>
void BST<T>::print()
{
    printHelper(root);
};

template<typename T>
void BST<T>::printHelper(TreeNode<T> *n)
{
    if(n -> left != 0)
    {
        printHelper(n -> left);
    }
    if(n != 0)
        cout << n-> data << endl;
    if(n -> right != 0)
        printHelper(n -> right);
}


template<typename T>
bool BST<T>::isEmpty()
{
    return(size ==0);
}

template<typename T>
void BST<T>::recAdd(T d)
{
    recAddHelper(d, root);
}



template <typename T>
void BST<T>::recAddHelper(T d, TreeNode<T>*& p)
{
    if(p==0)
    {
        p = new TreeNode<T>(d);
    }
    else if(d > p -> data)
    {
        recAddHelper(d, p->right);
    }
    else
        recAddHelper(d, p->left);
}



template<typename T>
T BST<T>::getMin()
{
    TreeNode<T>* curr = root;
    while(curr -> left != 0)
    {
        curr = curr -> left;
    }
    return curr -> data;
}

template<typename T>
T BST<T>::getMax()
{
    TreeNode<T>* curr = root;
    while(curr -> right != 0)
    {
        curr = curr -> right;
    }
    return curr -> data;
}


template <typename T>
bool BST<T>::contains(T d){
    bool ret = false;
    
    TreeNode<T>* curr = root;
    while(curr!= 0){
        if(d> curr->data)
        {
            curr = curr->right;
        }
        else if(d <curr->data)
        {
            curr = curr->left;
        }
        else
        {
            ret = true;
            break;
        }
    }
    return ret;
}

template <typename T>
bool BST<T>::remove(T d)
{
        if (root == NULL) return false;  //like weíre ever this lucky
        
        TreeNode<T>* current = root;
        TreeNode<T>* parent = root;
        bool isLeft = true;
        
        while(current->data != d){ //usual code to find the node
            parent = current;
            if(d < current->data){  //need to go left
                
                isLeft = true;
                current = current->left;
            }
            else{ //need to go right
                
                isLeft = false;
                current = current->right;
            }
            if(current == NULL)  //the thing isnít in the tree
                return false;
        }
        
        
        //no children ñ this would be nice
        if(current->left==NULL && current->right==NULL){
            
            if(current == root)             // deleting root
                root = NULL;
            else if(isLeft)
                parent->left = NULL;     // disconnect from parent
            else
                parent->right = NULL;
        }
        
        //one child ñ still not too bad
        // no right child, replace with left subtree
        else if(current->right==NULL){
            if(current == root)  //always have to check for root
                root = current->left;
            else if(isLeft)
                parent->left = current->left;
            else
                parent->right = current->left;
        }
        // no left child, replace with right subtree
        else if(current->left==NULL){
            if(current == root)
                root = current->right;
            else if(isLeft)
                parent->left = current->right;
            else
                parent->right = current->right;
        }
        else{  // two children ñ things are about to get scary
            
            // find successor of node to delete (current)
            TreeNode<T>* successor = getSuccessor(*current);
            
            // connect parent of current to successor
            if(current == root)  //usual root check
                root = successor;
            else if(isLeft)
                parent->left = successor;
            else
                parent->right = successor;
            
            // connect successor to current's left child
            successor->left = current->left;
        }
        return true;
}

    //At this point we begin to cry and take a 4 hour nap.
    
    
template<typename T>
TreeNode<T>* BST<T>:: getSuccessor(TreeNode<T> d){ //d to be deleted
        
        TreeNode<T>* sp = new TreeNode<T>(d);  //successorís parent
        TreeNode<T>* successor =new TreeNode<T>(d);
        TreeNode<T>* current = d.right;   // go to right first
        while(current != NULL){
            
            sp = successor;
            successor = current;
            current = current->left;      // go to left
        }
        
        if(successor != d.right){  // descendant of right child
            
            sp->left = successor->right;
            successor->right = d.right;
        }
        return successor;

}
#endif /* defined(__BST__BST__) */
