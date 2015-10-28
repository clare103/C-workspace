//
//  queue.cpp
//  new_queue
//
//  Created by David Clare on 4/28/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include "queue.h"

using namespace std;

void doubleLinkedList::appendNodeFront(char a, double x, int z)
{
    Node *n = new Node(a,x, z);
    if( front == NULL)
    {
        front = n;
        back = n;
    }
    else
    {
        front->P = n;
        n->N = front;
        front = n;
    }
}
void doubleLinkedList::appendNodeBack(char a, double x, int z)
{
    Node *n = new Node(a,x,z);
    if( back == NULL)
    {
        front = n;
        back = n;
    }
    else
    {
        back->N = n;
        n->P = back;
        back = n;
    }
    
}

void doubleLinkedList::dispNodesForward()
{
    Node *temp = front;
    cout << "\n\nNodes in forward order:" << endl;
    while(temp != NULL)
    {
        cout <<"Student:" << temp -> student << " needs " << temp->value  << " minutes at a window at minute: " << temp -> time << endl;
        temp = temp->N;
    }
}
void doubleLinkedList::dispNodesReverse()
{
    Node *temp = back;
    cout << "\n\nNodes in reverse order :" << endl;
    while(temp != NULL)
    {
        cout <<"Student:" << temp -> student << " needs " << temp->value  << " minutes at a window at minute: " << temp -> time << endl;
        temp = temp->P;
    }
}
void doubleLinkedList::destroyList()
{
    Node *T = back;
    while(T != NULL)
    {
        Node *T2 = T;
        T = T->P;
        delete T2;
    }
    front = NULL;
    back = NULL;
}