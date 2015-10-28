//
//  main.cpp
//  practice_again
//
//  Created by David Clare on 4/23/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include <iostream>
#include "practice_again.cpp"

int main(int argc, const char * argv[])
{
    DoublyLinkedList_h a;
    struct node* head = NULL;
    head =(struct node*) malloc(sizeof(struct node));
    //head -> data =1;
    a.addFront(head, 5);
    return 0;
}

