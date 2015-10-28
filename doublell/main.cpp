//
//  main.cpp
//  doublell
//
//  Created by David Clare on 9/23/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <thread>
#include <stdio.h>
#include "LL.h"

using namespace std;


int main(int argc, const char * argv[])
{

    chrono::seconds interval( 10 ) ;
    
    for( int i = 0 ; i < 10 ; ++i )
    {
        std::cout << "tick!\n" << std::flush ;
        this_thread::sleep_for(interval) ;
    }
    int second1 = 1;
    int second3 = 3;
    
    //time(0);
    
    //cout << timeInSeconds;
    
/*
    DList<int> mylist;
    cout << mylist.isEmpty() << endl;
    for(int i=0; i < 10; ++i)
    {
        mylist.addFront(i);
    }
    
    cout << mylist.getSize() << endl;
    
    cout << mylist.getFront() << endl;
    cout << mylist.getBack() << endl;
    cout << mylist.contains(10) << endl;
    cout << mylist.contains(9) << endl;
  */
    
    
    
    return 0;
}

