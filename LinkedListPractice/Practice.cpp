//
//  Practice.cpp
//  LinkedListPractice
//
//  Created by David Clare on 4/13/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include "Practice.h"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

template<class T>
Stack<T>::Stack() : top(NULL)
{
}

/*
template<class T>
Stack<T>::Stack(const Stack<T>& aStack)
{
    if(aStack.isEmpty())
        top = NULL;
    else
    {
        Node<T> *temp = aStack.top;
        Node<T> *end;
        
        end = new Node<T>(temp -> getData(), NULL);
        top = end;
        
        temp = temp -> getLink();
        
        while(temp != NULL)
        {
            end -> setLink(new Node<T> (temp -> getData(), NULL));
            temp = temp -> getLink();
            end = end -> getLink();
        }
    }
}

template<class T>
Stack<T>& Stack<T>::operator =(const Stack<T>& rightSide)
{
    if(top==rightSide.Top)
    {
        return *this;
    }
    else
    {
        T next;
        while(! isEmpty())
        {
            next = pop();
        }
    }
    if(rightSide.isEmpty())
    {
        top = NULL;
        return *this;
    }
    else
    {
        Node<T> *temp = rightSide.top;
        Node<T> *end;
        end = new Node<T>(temp -> getData(), NULL);
        top = end;
        
        temp = temp -> getLink();
        while(temp != NULL)
        {
            end -> setLink(new Node<T>(temp-> getData(), NULL));
            temp = temp -> getLink();
            end = end -> getLink();
        }
    }
    return *this;
}

template<class T>
Stack<T> :: ~Stack()
{
    T next;
    while(!isEmpty())
        next = pop();
}

template<class T>
bool Stack<T>::isEmpty() const
{
    return(top == NULL);
}

template<class T>
void Stack<T>::push(T stackFrame)
{
    top = new Node<T>(stackFrame, top);
}

template<class T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        cout << "Error. Popping an empty stack." << endl;
        exit(1);
    }
    T result = top-> getData();
    
    Node<T> *discard;
    discard = top;
    top = top->getLink();
    
    delete discard;
    return result;
}
*/
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
/*
void isPalindrome(string a)
{
    Stack<char> s;
    string reverse ="";
    
    for(int i =0; i < a.length(); i++)
    {
        s.push(a[i]);
    }
    for(int g=0; g < a.length(); g++)
    {
        reverse += s.pop();
    }
    if(a == reverse)
    {
        cout << "It is a palindrome" << endl;
    }
    else
    {
        cout << "It is not a palindrome." << endl;
    }
}*/



int Length(struct node* head)
{
    int count = 0;
    struct node* current = head;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
};

int Count(struct node* head, int searchFor)
{
    int count =0;
    struct node* current = head;
    while(current != NULL)
    {
        //current = current -> next;
        if(current-> data == searchFor)
        {
            count++;
        }
        current = current -> next;
    }
    
    
    return count;
};

/*
void Print_list(struct node* head)
{
    //int count =0;
    struct node* current = head;
    while(current != NULL)
    {
        cout << current->data << endl;
        current = current -> next;
    }
}*/

struct node* BuildOneTwoThree()
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    
    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    
    head -> data =1;
    head -> next = second;
    
    second -> data = 2;
    second -> next = third;
    
    third -> data =3;
    third -> next = NULL;
    
    return head;
};


void LengthTest()
{
    struct node* myList = BuildOneTwoThree();
    int len = Length(myList);
    cout << len << endl;
}

void Push(struct node*& head, int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void CountTest()
{
    struct node* myList = BuildOneTwoThree();
    Push(myList, 2);
    
    int count = Count(myList, 2);
    
    cout << count << endl;
};

/*
void PushTest()
{
    struct node* head = BuildOneTwoThree();
    Push(head, 0);
    Push(head, -1);
    Print_list(head);
}

void BuildWithSpecialCase()
{
    struct node* head= NULL;
    struct node* tail;
    int i;
    
    Push(head, 1);
    tail = head;
    
    for(int i =2; i < 6; i++)
    {
        Push((tail->next), i);
        tail = tail-> next;
        cout << tail -> data << endl;
    }
}

struct node* AddAtHead()
{
    struct node* head = NULL;
    int i;
    for(i=1; i < 6; i++)
    {
        Push(head, i);
    }
    return head;
}
*/
int getNth(struct node* head, int index)
{
    int count = 0;
    struct node* current = head;
    while(current != NULL)
    {
        if(count == index)
        {
            return current -> data;
        }
            count++;
            current = current -> next;
        
    }
    cout << "Number not found." << endl;
    return -1;
};

void GetNthTest()
{
    struct node* myList = BuildOneTwoThree();
    
    int lastNode = getNth(myList, 2);
    
    cout << lastNode << endl;
}

void DeleteList(struct node*& headRef)
{
    struct node* current = headRef;
    struct node* next;
    
    while(current != NULL)
    {
        next = current -> next;
        free(current);
        current = next;
    }
    headRef = NULL;
}

int Pop(struct node*& headRef)
{
    struct node* head;
    int result;
    head = headRef;
    if(head != NULL)
    {
    result = head -> data;
    headRef = head -> next;
    }
    else
    {
        cout << "error" << endl;
        exit(1);
    }
    
    free(head);
    return result;
    
};

void InsertNth(struct node*& headRef,int index, int data)
{
    if(index == 0)
    {
        Push(headRef, data);
    }
    else
    {
        struct node* current = headRef;
        int i;
        
        for(i=0; i < index-1; i++)
        {
            if(current != NULL)
            {
                current = current -> next;
            }
        }
        if( current != NULL)
        {
            Push(current->next, data);
        }
    }
   /*
    struct node* head;
    int count =0;
    //head = headRef;
    
    if(count == index)
    {
        Push(head, data);
    }
    else
    {
        count++;
    }
    */
};

void InsertNthTest()
{
    struct node* head = NULL;
    InsertNth(head, 0, 13);
    InsertNth(head, 1, 42);
    InsertNth(head, 1, 5);
    //Print_list(head);
    
    DeleteList(head);
};
/*
template<typename T>
ListNode<T>::ListNode(T d){
	next = NULL;
	prev = NULL;
	data = d;
}
template<typename T>
ListNode<T>::~ListNode(){
}
template<typename T>
DList<T>::DList(){	//Constructor
	size = 0;
	first = NULL;
	last = NULL;
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
*/
