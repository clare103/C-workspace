//
//  main.cpp
//  uppercase
//
//  Created by David Clare on 12/4/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;


void swap()
{
    
    int a = 4;
    int b = 7;
    
    int temp;
    temp = a;
    a = b;
    b = temp;
    
    cout << "b=" << b << endl;
    cout << "a=" << a << endl;
}


void uppercase()
{
    bool check = true;
    
    while(check)
    {
        char c;
        // cin.ignore();
        cout << "Please enter a small case letter: " << endl;
        c = getchar();
        
        if( c>= 'a' && c<='z')
        {
            cout << "The upper case of " << c << " is ";
            printf("%c \n" , c  - ('a' - 'A'));
        }
        c = getchar();
        
    }

}


int main(int argc, const char * argv[]) {

//    swap();
//    uppercase();
    return 0;
}
