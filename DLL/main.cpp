//
//  main.cpp
//  DLL
//
//  Created by David Clare on 4/7/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include <iostream>
#include "DLL.h"

using namespace std;

int main(int argc, const char * argv[])
{

    DList<int> myList;
	
	//for(int i = 0; i < 10; ++i)
	//	myList.addFront(i);
	myList.addBack(50);
	myList.addBack(100);
	
	cout << myList.getFront() << endl;
	cout << myList.getBack() << endl;
	
	while(!myList.isEmpty())
		cout << myList.removeFront() << endl;
	
	cout << myList.getSize() << endl;

    
    return 0;
}

