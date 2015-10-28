//
//  main.cpp
//  Stack
//
//  Created by David Clare on 4/7/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include <iostream>
#include "Stack.h"

using namespace std;

int main(int argc, const char * argv[])
{
	Stack<int> s;
	s.push(10);
	s.push(20);
	cout << s.peek() << endl;
	//cout << s.pop() << endl;
	//cout << s.pop() << endl;
	cout << s.pop() << "\t" << s.pop() << endl;

    return 0;
}

