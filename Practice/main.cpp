//
//  main.cpp
//  Practice
//
//  Created by David Clare on 4/9/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

struct Box
{
    string name;
    int number;
    Box *next;
};

typedef Box* BoxPtr;


int main(int argc, const char * argv[])
{

    BoxPtr head;
    head = new Box;
    head -> name = "Sally";
    head -> number = 18;
    cout << (*head).name << endl;
    cout << head -> name << endl;
    cout << (*head).number << endl;
    cout << head -> number << endl;
    
    
     return 0;
}

