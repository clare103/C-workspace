//
//  main.cpp
//  queue
//
//  Created by David Clare on 4/6/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include <iostream>
//#include <conio.h>
//#include <malloc.h>
//#include <process.h>
#include "queue.cpp"

using namespace std;

int display_menu()
{
    int ch;
   // clrscr();
    cout<<"[ 1 ] : Insert at First"<<endl;
    cout<<"[ 2 ] : Insert at Last"<<endl;
    cout<<"[ 3 ] : Delete From First"<<endl;
    cout<<"[ 4 ] : Delete From Last"<<endl;
    cout<<"[ 5 ] : Display"<<endl;
    cout<<"[ 6 ] : Exit"<<endl;
    cout<<"Enter your choice :";
    cin>>ch;
    return(ch);
};


int main(int argc, const char * argv[])
{
    dqueue dq1;
    //clrscr();
    
    
    dq1.insert_from_front();
    dq1.display();
    
    /*
    while(1)
    {
        cout << endl;
        switch(display_menu())
        {
            case 1 : dq1.insert_first();
                dq1.display();
                //getch();
                break;
            case 2 : dq1.insert_last();
                dq1.display();
                //getch();
                break;
            case 3 : dq1.delete_first();
                dq1.display();
                //getch();
                break;
            case 4 : dq1.delete_last();
                dq1.display();
                //getch();
                break;
            case 5 : dq1.display();
                //getch();
                break;
            case 6 : exit(0);
        }
    }
     */
     return 0;
}

