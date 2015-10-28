//
//  queue.h
//  new_queue
//
//  Created by David Clare on 4/28/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef __new_queue__queue__
#define __new_queue__queue__

#include <iostream>


struct Node
{
    double value;
    int time;
    char student;
    Node *N,*P;
    Node(char student_letter, double y, int time_)
    {
        time = time_;
        student = student_letter;
        value = y;
        N = P = NULL;
    }
};

class doubleLinkedList
{
    Node *front;
    Node *back;
public:
    doubleLinkedList()
    {  front = NULL; back = NULL; }
    ~doubleLinkedList(){ destroyList();}
    void appendNodeFront(char a, double x, int z);
    void appendNodeBack(char a, double x, int z);
    void dispNodesForward();
    void dispNodesReverse();
    void destroyList();
    void decrement_windows();
    void increment_windows();
    int windows = 5;
    int mean_student=0;
    int median_student=0;
    int longest_student=0;
    int students_over_ten=0;
    int mean_idle_window_time=0;
    int longest_idle_window_time=0;
    int num_of_idle_windows_over_5=0;
    //void menu();
};

#endif /* defined(__new_queue__queue__) */
