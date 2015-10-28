//
//  main.cpp
//  Node
//
//  Created by David Clare on 4/8/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include <iostream>
#include "Node.cpp"

using namespace std;

int main(int argc, const char * argv[])
{

    Node<char> *p,*q,*r;
    // Link the nodes with each other
    q = new Node<char>('B'); // here nxtptr is passed by a nullptr by default
    p = new Node<char>('A',q);
    r = new Node<char>('C');
    
    // modify the list
    q->InsertAfter(r);
    /*
     Call the InsertAfter method that belongs to the object pointed by q, as
     paramater, pass to it the address contained in r.
     */
    
    cout << "p:" << p->data << endl;                 // "A" will be printed out
    cout << "p_next:" << p->NextNode()->data << endl;  // "B" will be printed out
    cout << "q:" << q->data << endl;                 // "B" will be printed out
    cout << "q_next:" << q->NextNode()->data << endl;  // "C" will be printed out
    cout << "r:" << r->data << endl;                 // "C" will be printed out
    
    p = p->NextNode(); // p now points to the node coming after the node it was
    // previously pointing to.
    cout << endl;
    cout << "p:" << p->data << endl;                 // "B" will be printed out
    
    r = q->DeleteAfter();        // copy to r the address of the node pointed by
    //the node pointed by the node pointed by q, and remove that node from the list
    
    Node<char> *head;
    head = GetNode('A',GetNode('B',GetNode('C')));
    /*
     Here above method, creates a list which has nodes having data A,B,C and each
     node pointing to the next one respectively.
     */
   // delete q;
    delete p;
    delete r;
    return 0;
    
    return 0;
}

