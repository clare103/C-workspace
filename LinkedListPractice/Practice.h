//
//  Practice.h
//  LinkedListPractice
//
//  Created by David Clare on 4/13/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef __LinkedListPractice__Practice__
#define __LinkedListPractice__Practice__

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

template<class T>
class Node
{
public:
    Node(T theData, Node<T>* theLink) : data(theData), link(theLink){}
    Node<T>* getLink() const {return link;}
    const T getData() const {return data;}
    void setData(const T& theData) {data = theData;}
    void setLink(Node<T>* pointer) {link = pointer;}
private:
    T data;
    Node<T> *link;
};

template<class T>
class Stack
{
public:
    Stack();
    //Stack(const Stack<T>& aStack);
    //Stack<T>& operator =(const Stack<T>& rightSide);
    virtual ~Stack();
    void push(T stackFrame);
    T pop();
    bool isEmpty() const;
private:
    Node<T> *top;
};

template<typename T>
class ListNode{
public:
	ListNode(T d);
	virtual ~ListNode();
	
	T data;
	ListNode<T>* next;
	ListNode<T>* prev;
};
template<typename T>
class DList{
public:
	DList();
	virtual ~DList();
	inline bool isEmpty(){
		return (size=0);
	}
	
	inline int getSize(){
		return size;
	}
	
	void addFront(T d);
	void addBack(T d);
	void add(T d, int pos);
	T removeFront();
	T removeBack();
	T getFront();
	T getBack();
	
private:
	ListNode<T>* first;
	ListNode<T>* last;
	int size;
};

#endif /* defined(__LinkedListPractice__Practice__) */
