//
//  main.cpp
//  new_queue
//
//  Created by David Clare on 4/28/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include <iostream>
#include "queue.cpp"


using namespace std;

void execute()
{
    doubleLinkedList *list = new doubleLinkedList();
    //append nodes to front of the list
    //for( int i = 1 ; i < 4 ; i++)
      //  list->appendNodeFront(i*1.1);
    
    
    cout << "5 available windows for students" << endl;
    
    
    list -> appendNodeFront('A', 5, 1);
    list -> appendNodeFront('B', 10, 1);
    list -> appendNodeFront('C', 4, 3);
    
    
    list->dispNodesForward();
    list->dispNodesReverse();
    
    //append nodes to back of the list
   // for( int i = 1 ; i < 4 ; i++)
     //   list->appendNodeBack(11.0 - (1.1 * i));
    cout << endl << endl;
    list->dispNodesForward();
    list->dispNodesReverse();
    
    cout << endl << endl;
    delete list;
    
    cout << "1. The mean student wait time: " << mean_student << endl;
    cout << "2. The median student wait time: " << endl;
    cout << "3. The longest student wait time: " << endl;
    cout << "4. The number of students waiting over 10 minutes: " << endl;
    cout << "5. The mean window idle time: " << endl;
    cout << "6. The longest window idle time: " << endl;
    cout << "7. Number of windows idle for over 5 minutes: " << endl;
}

int main(int argc, const char * argv[])
{
    execute();
    return 0;
}

