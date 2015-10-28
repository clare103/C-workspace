//
//  Stack.h
//  Stack
//
//  Created by David Clare on 4/7/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef Stack_Stack_h
#define Stack_Stack_h


using namespace std;

template <typename T>
class Stack{
public:
	Stack();
	virtual ~Stack();
	void push(T d);
	T pop();
	T peek();
	
private:
	DList<T>* m_list;
	
};

template<typename T>
Stack<T>::Stack(){
	m_list = new DList<T>();
}

template<typename T>
Stack<T>::~Stack(){
	delete m_list;
}

template<typename T>
void Stack<T>::push(T d){
	m_list->addFront(d);
}

template<typename T>
T Stack<T>::pop(){
	return m_list->removeFront();
}

template<typename T>
T Stack<T>::peek(){
    std::cout << "peeking" << endl;
	return m_list->getFront();
}


#endif
