//
//  Node.h
//  Node
//
//  Created by David Clare on 4/8/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef __Node__Node__
#define __Node__Node__

#include <iostream>

template<class T>
class Node
{
public:
    Node();
    Node(const T& item, Node<T>* ptrnext = NULL);
    T data;
    // access to the next node
    Node<T>* NextNode();
    // list modification methods
    void InsertAfter(Node<T>* p);
    Node<T>* DeleteAfter();
    Node<T> * GetNode(const T& item, Node<T>* nextptr = NULL);
private:
    
    Node<T> * next;
};

#endif /* defined(__Node__Node__) */
