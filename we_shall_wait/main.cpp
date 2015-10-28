//
//  main.cpp
//  we_shall_wait
//
//  Created by David Clare on 10/8/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include <iostream>
#include "queue.h"


using namespace std;

int main(int argc, const char * argv[])
{

    enqueue<int> e(0);
    e.add_back(5);
    e.add_back(10);
    e.add_back(12);
    e.delete_front();
    e.delete_front();
    e.delete_front();
    //e.add_back(7);
    //e.delete_front();

    

    return 0;
}

