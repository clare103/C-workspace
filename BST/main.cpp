//
//  main.cpp
//  BST
//
//  Created by David Clare on 10/9/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include <iostream>
#include "BST.h"
#include "Menu.h"
#include "Student.h"
#include "Faculty.h"


int main(int argc, const char * argv[])
{
    
    
    BST<int> tree;
    
    tree.recAdd(1);
    tree.recAdd(4);
    tree.recAdd(3);
    tree.recAdd(5);
    tree.recAdd(15);
    tree.recAdd(18);
    tree.recAdd(20);
    
    tree.print();
    
    //tree.mirror();
    
    
   // cout<<"mirror tree" << endl;
    
   // tree.print();
    
    
   // Menu m;
  //  m.execute();
    
    return 0;
}

