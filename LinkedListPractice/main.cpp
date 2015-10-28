//
//  main.cpp
//  LinkedListPractice
//
//  Created by David Clare on 4/13/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#include <iostream>
#include "Practice.cpp"
#include <math.h>

using namespace std;

struct node* AddAtHead()
{
    int a[] = {45,2,3,7,9};
    int size = sizeof(a)/sizeof(int);
    struct node* head = NULL;

    for(int i=0; i < size; i++)
    {
        //if(head != NULL)
        //cout << head -> data << endl;
        Push(head, a[i]);
        //cout << head -> data << endl;
    }
    return head;
}

struct node* AddAtTail()
{
    int a[] = {45,2,3,7,9};
    int size = sizeof(a)/sizeof(int);
    struct node* head = NULL;
    struct node* tail;
    
    Push(head, a[0]);
    tail = head;
    
    for (int i =0; i < size; i++)
    {
        Push((tail->next),a[i]);
        tail = tail-> next;
        cout << tail -> data << endl;
    }
    
    return tail;
};

void Pop_list(struct node* head)
{
    //int count =0;
    struct node* current = head;
    while(current != NULL)
    {
        cout << current->data << endl;
        current = current -> next;
    }
    
}

void Remove_list(struct node* head)
{
    struct node* current = head;
    struct node* tail = NULL;
    
    cout << "head:" << current -> data << endl;
    cout << "forward display" << endl;
    while(current != NULL)
    {
        cout << current -> data << endl;
            if(current -> next == NULL)
            {
                tail = current;
                //cout << "tail:" << tail -> data << endl;
                //delete current;
            }
            current = current -> next;
    }
    current = tail;
    cout << "backward display" << endl;
        while(current != NULL)
        {
            cout << current -> data << endl;
            current = current -> prev;
        }
    

};

void BuildWithSpecialCase()
{
    struct node* head= NULL;
    struct node* tail;
    int i;
    
    Push(head, 1);
    tail = head;
    
    for(int i =2; i < 6; i++)
    {
        Push((tail->next), i);
        tail = tail-> next;
        cout << tail -> data << endl;
    }
}


void PushTest()
{
    struct node* head = BuildOneTwoThree();
    Push(head, 0);
    Push(head, -1);
    Pop_list(head);
}



int main(int argc, const char * argv[])
{
    
    /*
    string answer;
    cout << "Please enter your string:";
    cin >> answer;
    
    isPalindrome(answer);
    
       return 0;
     */
    //LengthTest();
   // struct node* head = BuildOneTwoThree();
    struct node* add = AddAtHead();
    //Pop_list(add);
    //Remove_list(add);
    
    
    
    
    //cout << "this is it: " << endl;
    struct node* remove = AddAtTail();
    //Remove_list(add);
   // AddAtTail();
    //BuildWithSpecialCase();
    
    //PushTest();
    
    //PushTest(add);
   // GetNthTest();
   // CountTest();
   /*
    struct node* build = BuildOneTwoThree();
    cout << Pop(build) << endl;
    cout << Pop(build) << endl;
    cout << Pop(build) << endl;
    cout << Pop(build) << endl;
   */
    //InsertNthTest();
    
    /*
    DList<int> d;
    //ListNode<int> node = new ListNode<int> ;
   // d.addFront(5);
    d.add(6, 0);
    d.removeBack();
    */
    cout << endl;
    return 0;
}

