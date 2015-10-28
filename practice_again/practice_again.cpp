//
//  practice_again.cpp
//  practice_again
//
//  Created by David Clare on 4/23/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include "practice_again.h"

using namespace std;


DoublyLinkedList_h::DoublyLinkedList_h()
{
    
}
DoublyLinkedList_h::~DoublyLinkedList_h()
{
    
}

void DoublyLinkedList_h::addFront(struct node*& head, int data){
	//cout << "in the add method\n";
	
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = head;
    head = newNode;
	//cout << "int the add method2\n"
	//if(isEmpty()){
	//	last = node;
		//cout << "in the add method3\n"
	//}else {
		//cout << "in the add method4\n"
	//	first->prev = node;
	//}
	
	//node->next = first;
	//first = node;
	//++size;
}
