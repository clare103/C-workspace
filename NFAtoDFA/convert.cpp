//
//  convert.cpp
//  NFAtoDFA
//
//  Created by David Clare on 2/21/15.
//  Copyright (c) 2015 David Clare. All rights reserved.
//

#include "convert.h"


NFA::NFA()
{
    
}

NFA::~NFA()
{
    
}

void NFA::menu()
{
    
    cout << "Converting an NFA to a DFA." << endl;
    cout << "Theorem: Every NFA has an equivalent DFA" << endl;
    cout << "5-tuple (Q, Sigma, Qo, Delta, F)" << endl;
    
    int num_states;
    cout << "Q represents a finite set of states and will be reprsented as integers."  << endl;
    cout << "How many states are there in your NFA?" << endl;
    cin >> num_states;
    
    cout << endl;
    
    int alphabet;
    cout << "Sigma represents a finite alphabet" << endl;
    cout << "For simplicity, a standard 26 letter alphabet will be used." << endl;
    cout << "How many different transition letters are there?" << endl;
    cin >> alphabet;
    
    cout << endl;
    
    cout << "q Sigma Q represents a start state and will be denoted with '>'." << endl;
    cout << "For simplicity, '1' will be the integer of the start state. " << endl;
    
    cout << endl;
    
    
    string transition;
    cout << "Delta represents the transition of one state to another. A state may transition directly to another state through Sigma or it may be transitioned to through an Epsilon transition." << endl;
    cout << "For each state, please enter how a function transitions to another state" << endl;
    cout << "Each state will have an epsilon transition to itself by default." << endl;
    cout << "The transition will be contained within a string as such '1a2'. " << endl;
    cout << "The string '1a2' means that there is a transition from 1 to 2 through delta a." << endl;
    cin >> transition;
    
    cout << endl;
    
    
    int accept_state;
    cout << "F represents the final accept state. There can only be one accept state." << endl;
    cout << "The accept state is one of the states that was entered in your states represented by Q and can not be '1' because that is the start state." << endl;
    cin >> accept_state;
    
}

void NFA::set_grid()
{
    string** NFA_array = 0;
    NFA_array = new string*[4];
    for(unsigned int x=0; x < 4; x++)
    {
        NFA_array[x] = new string[4];
    }
    
    
    NFA_array[0][0] = "2";
    NFA_array[0][1] = "-";
    NFA_array[0][2] = "4";
    NFA_array[0][3] = "1";
    NFA_array[1][0] = "-";
    NFA_array[1][1] = "3";
    NFA_array[1][2] = "-";
    NFA_array[1][3] = "2,1";
    NFA_array[2][0] = "2";
    NFA_array[2][1] = "-";
    NFA_array[2][2] = "-";
    NFA_array[2][3] = "3";
    NFA_array[3][0] = "-";
    NFA_array[3][1] = "-";
    NFA_array[3][2] = "3";
    NFA_array[3][3] = "4,3";
    
    
    cout << " NFA ARRAY" << endl;
    cout << endl;
    cout << "    a |b |c |EPS " << endl;
    cout << "    _____________" << endl;
    cout << ">";
    
    for(int i =0; i < 4; i++)
    {
        if(i+1 == 1)
        {
            cout << i+1 << " |";
        }
        else
        {
        cout <<" "<< i+1 << " |";
        }
        for(int g=0; g < 4; g++)
        {
            if(g+1 != 4)
            {
            cout << NFA_array[i][g] << " |";
            }
            else
            {
                cout << NFA_array[i][g];
            }
        }
        cout << endl;
        
    }
    
      string** DFA_array = 0;
    DFA_array = new string*[3];
    for(unsigned int x=0; x < 4; x++)
    {
        DFA_array[x] = new string[3];
    }
    
    
    DFA_array[0][0] = "2,1";
    DFA_array[0][1] = "-";
    DFA_array[0][2] = "4,3";
    DFA_array[1][0] = "2,1";
    DFA_array[1][1] = "3";
    DFA_array[1][2] = "4,3";
    DFA_array[2][0] = "2,1";
    DFA_array[2][1] = "-";
    DFA_array[2][2] = "3";
    DFA_array[3][0] = "2,1";
    DFA_array[3][1] = "-";
    DFA_array[3][2] = "-";
    
    
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    
    cout << "DFA ARRAY" << endl;
    cout << endl;
    cout << "       a,EPS|b,EPS|c,EPS" << endl;
    cout << "       _________________" << endl;
    cout << ">";

    for(int i =0; i < 4; ++i)
    {
        if(i + 1 == 1)
        {
            cout << "1" << "    |";
        }
        else if(i + 1 == 2)
        {
            cout << " " << DFA_array[0][0] << "  |";
        }
        else if(i + 1 == 3)
        {
            cout << " " << DFA_array[0][2] << "  |";
        }
        else if(i + 1 == 4)
        {
            cout << " " << DFA_array[1][1] << "    |";
        }
        for(int g =0; g < 3; g++)
        {
            if(g+1 ==1)
            {
                cout << DFA_array[i][g] << "  |";
            }
            else if(g+1 == 2)
            {
                cout << DFA_array[i][g] << "    |";
            }
            else
            {
                cout << DFA_array[i][g];
            }
        }
        cout << endl;
    }

}