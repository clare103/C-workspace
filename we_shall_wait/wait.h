//
//  wait.h
//  we_shall_wait
//
//  Created by David Clare on 10/8/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef __we_shall_wait__wait__
#define __we_shall_wait__wait__

#include <iostream>

template <typename T>
class ListNode
{
public:
    ListNode(T d);
public:
   // virtual ~ListNode(); for some reason the destructor needs to be commented out
    T data;
    ListNode<T>* next;
    ListNode<T>* prev;
};


template <typename T>
ListNode<T>::ListNode(T d)
{
    data =d;
    next =0;
    prev =0;
}


template <typename T>
class DList
{
public:
    DList();
    virtual ~DList()
    {
        
    }
    void addFront(T d);
    T getFront();
    void addBack(T d);
    T deleteBack();
    T deleteFront();
    T getBack();
    T deletePos(int p);
    bool isEmpty();
    bool contains(T d);
    T getPost(int d);
    int getSize()
    {
        return size;
    }
private:
    ListNode<T>* front;
    ListNode<T>* back;
    int size;
};


template <typename T>
T DList<T>::getFront()
{
    return front->data;
}

template <typename T>
T DList<T>::getBack()
{
    return back->data;
}



template <typename T>
void DList<T>::addBack(T d)
{
    ListNode<T>* newNode = new ListNode<T>(d);
    if(isEmpty())
    {
        front = newNode;
    }
    else
    {
        back -> next = newNode;
    }
    
    newNode -> prev = front;
    back = newNode;
    ++size;
}




template <typename T>
void DList<T>::addFront(T d)
{
    ListNode<T>* newNode = new ListNode<T>(d);
    if(isEmpty())
    {
        back = newNode;
    }
    else
    {
        front -> prev = newNode;
    }
    
    newNode -> next = front;
    front = newNode;
    ++size;
}

template <typename T>
DList<T>::DList()
{
    size =0;
    front =0;
    back =0;
}

template <typename T>
bool DList<T>::isEmpty()
{
    return(size ==0);
}

template <typename T>
bool DList<T>::contains(T d)
{
    bool found = false;
    ListNode<T>* curr = front;
    while(curr != 0 && !found)
    {
        if(curr-> data == d)
        {
            found = true;
        }
        curr = curr -> next;
    }
    return found;
}

template <typename T>
T DList<T>::getPost(int p)
{
    int count =0;
    
    ListNode<T>* curr = front;
    while(count !=p && curr !=0)
    {
        curr = curr->next;
        count++;
    }
    return curr -> data;
}

template <typename T>
T DList<T>::deleteFront()
{
    ListNode<T>* ret = front;
    if(front -> next ==0)
    {
        back =0;
    }
    else
    {
        front -> next -> prev = 0;
    }
    front = front -> next;
    T datum = ret -> data;
    delete ret;
    return datum;
}

template <typename T>
T DList<T>::deleteBack()
{
    ListNode<T>* ret = back;
    if(back -> prev ==0)
    {
        front =0;
    }
    else
    {
        back-> prev -> next = 0;
    }
    back = back -> prev;
    T datum = ret -> data;
    delete ret;
    return datum;
}

template <typename T>
T DList<T>::deletePos(int p)
{
    int count =0;
    
    ListNode<T>* curr = front;
    while(count !=p && curr !=0)
    {
        curr = curr->next;
        count++;
    }
    
    curr -> next -> prev = curr -> prev;
    curr -> prev -> next = curr -> next;
    curr -> next =0;
    curr -> prev =0;
    --size;
    
    T datum = curr -> data;
    delete curr;
    return datum;
}




#endif /* defined(__we_shall_wait__wait__) */
