//
//  DLL.h
//  DLL
//
//  Created by David Clare on 4/7/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef DLL_DLL_h
#define DLL_DLL_h

#include <iostream>
using namespace std;

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
ListNode<T>::ListNode(T d){
	next = 0;
	prev = 0;
	data = d;
}

template<typename T>
ListNode<T>::~ListNode(){
}

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

template<typename T>
DList<T>::DList(){	//Constructor
	size = 0;
	first = 0;
	last = 0;
}

template<typename T>
DList<T>::~DList(){	//Deconstructor
}

template<typename T>
void DList<T>:: addFront(T d){
	//cout << "in the add method\n";
	ListNode<T>* node = new ListNode<T>(d);
	//cout << "int the add method2\n"
	if(isEmpty()){
		last = node;
		//cout << "in the add method3\n"
	}else {
		//cout << "in the add method4\n"
		first->prev = node;
	}
	
	node->next = first;
	first = node;
	++size;
}

template<typename T>
void DList<T>::addBack(T d){
	
	ListNode<T>* node = new ListNode<T>(d);
	if(isEmpty()){
		first = node;
	} else{
		last->next = node;
	}
	node->prev = last;
	last = node;
	++size;
}

template<typename T>
void DList<T>::add(T d, int pos){
	ListNode<T>* helper = first;
	ListNode<T>* node = new ListNode<T>(d);
	for(int i = 0; i < pos; i++){
		helper = helper -> next;
	}
	helper -> prev -> next = node;
	node -> next = helper;
	node -> prev = helper -> prev;
	helper -> prev = node;
}


template<typename T>
T DList<T>::getBack(){
	return last->data;
}

template<typename T>
T DList<T>::getFront(){
	return first->data;
}


template<typename T>
T DList<T>::removeFront(){
	//cout << "In remove front\n";
	ListNode<T>* tap = first;
	T value = tap->data;
	if(first->next == 0){
		last = 0;
	} else {
		first->next->prev = 0;
	}
	first = first->next;
	delete tap;
	--size;
	//cout << "Done with remove front\n";
	return value;
}

template<typename T>
T DList<T>::removeBack(){
	
	ListNode<T>* tap = last;
	T value = tap->data;
	last = last->prev;
	last->next->prev = 0;
	last->next = 0;
	if(isEmpty()){
		first = 0;
	}
	delete tap;
	--size;
	return value;
}


#endif
