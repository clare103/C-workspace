//
//  Practice1.cpp
//  Practice
//
//  Created by David Clare on 4/9/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//



#include "Practice1.h"

using namespace std;

template <class T>
void swapValues(T& variable1, T& variable2)
{
    T temp;
    
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}
/*
void execute()
{
    int integer1 = 1, integer2 = 2;
    cout << "Orginal integer values are " << integer1; << " " integer2 << endl;
    swapValues(integer1, integer2);
    cout << "Swapped integer values are " << integer1 << " " << integer2 << endl;
    
    char symbol1 = 'A', symbol2 = 'B';
    cout << "Original character values are: " << symbol1 << " " << symbol2 << endl;
    swapValues(symbol1, symbol2);
    cout << "Swapped character values are: " << symbol1 << " " << symbol2 << endl;
    
}
*/