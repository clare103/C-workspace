//
//  queue.h
//  we_shall_wait
//
//  Created by David Clare on 10/8/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef we_shall_wait_queue_h
#define we_shall_wait_queue_h


#include <iostream>
#include "wait.h"

using namespace std;


template<typename T>
class enqueue : public DList<int>
{
public:
    enqueue(T d);
public:
    ~enqueue();
    void add_back(T d);
    void delete_front();
private:
    DList<T> myQueue;
};

template <typename T>
enqueue<T>::enqueue(T d)
{
    d = 0;
}
template <typename T>
enqueue<T>::~enqueue()
{
    
}
template <typename T>
void enqueue<T>::add_back(T d)
{
    myQueue.addBack(d);
}
template <typename T>
void enqueue<T>::delete_front()
{
   // myQueue.deleteFront();
    cout << myQueue.deleteFront() << endl;
}


#endif
