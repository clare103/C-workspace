//
//  practice_again.h
//  practice_again
//
//  Created by David Clare on 4/23/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef __practice_again__practice_again__
#define __practice_again__practice_again__

#include <iostream>

//typedef struct node;

struct node
{
	int data;
	struct node *next,*previous;
	node(char a, node *pre, node *next) : data(a), previous(pre), next(next)
	{
		if(pre) previous -> next = this;
		if (next) next -> previous = this;
	}
};

class DoublyLinkedList_h
{
public:
	DoublyLinkedList_h();
	DoublyLinkedList_h(int);
	~DoublyLinkedList_h();
	node *head;
	int size;
    void addFront(struct node*& head, int d);
	void addNodeBefore (int);
	void addNodeAfter (int);
	void addNodeBeforeData (int, node*);
	void addNodeAfterData (int, node*);
	void out(bool);
	void setData (int);
	void setNext (node*);
	void setPrevious (node*);
	void deleteData (int, bool);
	bool empty();
	bool findData(int);
};


#endif /* defined(__practice_again__practice_again__) */
