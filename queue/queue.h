//
//  queue.h
//  queue
//
//  Created by David Clare on 4/6/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef __queue__queue__
#define __queue__queue__

#include <iostream>
#include <stdlib.h>

using namespace std;

struct link_list
{
    int data;
    struct link_list *next;
    struct link_list *prev;
};

class dqueue
{
public:
    link_list *list, *head;
    dqueue()
    {
        head = NULL;
    }
   // ~dqueue();
    void insert_from_front();
    void insert_last();
    void delete_first();
    void delete_last();
    void display();
};


#endif /* defined(__queue__queue__) */
