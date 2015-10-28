//
//  convert.h
//  NFAtoDFA
//
//  Created by David Clare on 2/21/15.
//  Copyright (c) 2015 David Clare. All rights reserved.
//

#ifndef __NFAtoDFA__convert__
#define __NFAtoDFA__convert__

#include <stdio.h>
#include <iostream>


using namespace std;

class NFA
{
public:
    NFA();
    ~NFA();
    
    void set_grid();
    
    void set_num_of_states(int a);
    
    void set_num_of_transitions(int a);
    
    void set_num_of_eps(int a);
    
    void convert_to_DFA(char **b);
    
    void menu();
    
    
private:
    int num_of_states, num_of_transitions, num_of_eps;
    int accept_state;
    char **NFA_array, **DFA_array;
    
    
};


#endif /* defined(__NFAtoDFA__convert__) */
