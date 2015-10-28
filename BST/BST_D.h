//
//  BST_D.h
//  BST
//
//  Created by David Clare on 10/28/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef BST_BST_D_h
#define BST_BST_D_h


#include <iostream>
#include "Student.h"
#include "Faculty.h"


using namespace std;

template<typename T>
class TreeNode_D
{
public:
    TreeNode_D(T d)
    {
        data = d;
        left = right = 0;
    }
public:
    //virtual ~TreeNode();
    TreeNode_D<T>* left;
    TreeNode_D<T>* right;
    // TreeNode<T>* getSuccessor(TreeNode<T> d);
    T data;
};

template <typename T>
class BST_D
{
public:
    BST_D()
    {
        size =0;
        root =0;
    }
    //~BST(){}
    int getSize();
    bool isEmpty();
    bool contains(T d);
    void recAdd(T d);
    
    void recAdd_student(T d);
    void recAdd_faculty(T d);
    
    bool remove(T d);
    bool lookup(T d);
    void mirror();
    T getMin();
    T getMax();
    
    
    void print_student();
    void print_faculty();
    
    void print_stud_fac(TreeNode_D<T> *n, TreeNode_D<T> *p);
    
    void create_student(Student s);
    void create_faculty(Faculty f);
    void create_student_tree();
    void create_faculty_tree();
    
    
private:
    TreeNode_D<T>* root;
    void recAddHelper(T d, TreeNode_D<T>*& p);
    
    void recAddHelper_student(T d, TreeNode_D<T>*& p);
    void recAddHelper_faculty(T d, TreeNode_D<T>*& p);
    
    
    void printHelper_stud_fac(TreeNode_D<T> *n, TreeNode_D<T> *p);
    
    
    void printHelper(TreeNode_D<T>* n);
    void printHelper_student(TreeNode_D<T>* n);
    void printHelper_faculty(TreeNode_D<T>* n);
    
    
    
    TreeNode_D<T>* getSuccessor(TreeNode_D<T> d);
    TreeNode_D<T>* lookupHelper(TreeNode_D<T>*& p, T d);
    void mirrorHelper(TreeNode_D<T>*& p);
    int size;
    
};



template<typename T>
void BST_D<T>::create_student(Student s)
{
    recAdd_student(s);
}

template<typename T>
void BST_D<T>::create_faculty(Faculty f)
{
    recAdd_faculty(f);
}

template<typename T>
bool BST_D<T>::lookup(T d)
{
    return(lookupHelper(root, d));
}

template<typename T>
TreeNode_D<T>* BST_D<T>::lookupHelper(TreeNode_D<T>*& p, T data)
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
void BST_D<T>::mirror()
{
    mirrorHelper(root);
}

template<typename T>
void BST_D<T>::mirrorHelper(TreeNode_D<T>*& p)
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
void BST_D<T>::print_student()
{
    printHelper_student(root);
    
};

template<typename T>
void BST_D<T>::printHelper_student(TreeNode_D<T> *n)
{
    if(n -> left != 0)
    {
        printHelper_student(n -> left);
    }
    if(n != 0)
    {
        cout << endl;
        cout << "Student ID: " << n-> data.get_student_id() << endl;
        cout << "Student Name: " << n-> data.get_student_name() << endl;
        cout << "Class level: " << n-> data.get_student_level() << endl;
        cout << "Major: " << n-> data.get_student_major() << endl;
        cout << "GPA: " << n-> data.get_student_GPA() << endl;
        cout << "Student Faculty Advisor ID: " << n-> data.get_student_advisor_id() << endl;
    }
    if(n -> right != 0)
        printHelper_student(n -> right);
}






template<typename T>
bool BST_D<T>::isEmpty()
{
    return(size ==0);
}

template<typename T>
void BST_D<T>::recAdd(T d)
{
    recAddHelper(d, root);
}


template<typename T>
void BST_D<T>::recAdd_student(T d)
{
    recAddHelper_student(d, root);
}

template<typename T>
void BST_D<T>::recAdd_faculty(T d)
{
    recAddHelper_faculty(d, root);
}



template <typename T>
void BST_D<T>::recAddHelper(T d, TreeNode_D<T>*& p)
{
    if(p==0)
    {
        p = new TreeNode_D<T>(d);
    }
    else if(d > p -> data)
    {
        recAddHelper(d, p->right);
    }
    else
        recAddHelper(d, p->left);
}



template <typename T>
void BST_D<T>::recAddHelper_student(T d, TreeNode_D<T>*& p)
{
    if(p==0)
    {
        p = new TreeNode_D<T>(d);
    }
    else if(d.get_student_id() > p -> data.get_student_id())
    {
        recAddHelper_student(d, p->right);
    }
    else
        recAddHelper_student(d, p->left);
}


template <typename T>
void BST_D<T>::recAddHelper_faculty(T d, TreeNode_D<T>*& p)
{
    if(p==0)
    {
        p = new TreeNode_D<T>(d);
    }
    else if(d.get_faculty_id() > p -> data.get_faculty_id())
    {
        recAddHelper_faculty(d, p->right);
    }
    else
        recAddHelper_faculty(d, p->left);
}



template<typename T>
T BST_D<T>::getMin()
{
    TreeNode<T>* curr = root;
    while(curr -> left != 0)
    {
        curr = curr -> left;
    }
    return curr -> data;
}

template<typename T>
T BST_D<T>::getMax()
{
    TreeNode<T>* curr = root;
    while(curr -> right != 0)
    {
        curr = curr -> right;
    }
    return curr -> data;
}


template <typename T>
bool BST_D<T>::contains(T d){
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
bool BST_D<T>::remove(T d)
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

//i cried here

template<typename T>
TreeNode_D<T>* BST_D<T>:: getSuccessor(TreeNode_D<T> d){ //d to be deleted
    
    TreeNode_D<T>* sp = new TreeNode_D<T>(d);  //successorís parent
    TreeNode_D<T>* successor =new TreeNode_D<T>(d);
    TreeNode_D<T>* current = d.right;   // go to right first
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
 
/* defined(__BST__BST__) */


#endif
