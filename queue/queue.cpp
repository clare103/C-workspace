//
//  queue.cpp
//  queue
//
//  Created by David Clare on 4/6/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include "queue.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


void dqueue :: insert_from_front()
{
    link_list *newnode;
    newnode = new link_list;
    int a[] = {5,1,2,5,10,3,1,4};
    int size = sizeof(a)/sizeof(a[0]);
    list=head;

    for(int i=0; i < size; i++)
    {
        list=head;
        newnode -> data = a[i];
        list = newnode -> next;
        //list->prev=newnode;
        newnode->next=list;
        newnode->prev=NULL;
        if(list -> prev != NULL)
        {
            list->prev=newnode;
        }
        //newnode->prev=NULL;
        //list->prev=newnode;
        head=newnode;


    }
    
    //display(size);
    /*
    cout << endl;
    
    if(list==NULL)
     {
     head=newnode;
     newnode->next=NULL;
     newnode->prev=NULL;
     return;
     
     }
    
    list=head;
    newnode->next=list;
    newnode->prev=NULL;
    list->prev=newnode;
    head=newnode;
     */
}

void dqueue :: insert_last()
{
    link_list *newnode;
    newnode= new link_list;
    cout<<"Enter Number :";
    cin>>newnode->data;
    
    list=head;
    if(list==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
        return;
    }
    while(list->next!=NULL)
    {
        list=list->next;
    }
    list->next=newnode;
    newnode->prev=list;
    newnode->next=NULL;
}

void dqueue :: display()
{
    cout<<endl;
    link_list *tail = NULL;
    list=head;
    if(head==NULL)
    {
        cout<<"Empty Queue !!!";
        return;
    }
    cout<<endl;
    cout<<"Forward Display ..."<<endl;
    while(list!=NULL)
    {
        cout<<list->data<<"\t";
        if(list->next==NULL)
        {
            tail=list;
        }
        list=list->next;
    }
    list=tail;
    cout<<endl<<"Backward Display ..."<<endl;
    while(list!=NULL)
    {
        cout << list->data<< "\t";
        list=list->prev;
    }
}

void dqueue :: delete_first()
{
    list=head;
    list->next->prev=NULL;
    head=list->next;
}

void dqueue::delete_last()
{
    list=head;
    while(list->next->next!=NULL)
    {
        list=list->next;
    }
    list->next=NULL;
}
