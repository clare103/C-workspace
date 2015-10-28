//
//  Faculty.h
//  BST
//
//  Created by David Clare on 10/25/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef BST_Faculty_h
#define BST_Faculty_h

#include <iostream>
#include <string>

using namespace std;

class Faculty
{
public:
    Faculty(){
        faculty_id = 0;
        faculty_name = "";
        faculty_level = "";
        faculty_department= "";
    };
    
    Faculty(int _faculty_id, string _faculty_name, string _faculty_level, string _faculty_department){
        
        set_faculty_id(_faculty_id);
        set_faculty_name(_faculty_name);
        set_faculty_level(_faculty_level);
        set_faculty_department(_faculty_department);
    }
    
    ~Faculty(){};
    
    void set_faculty_id(int);
    void set_faculty_name(string);
    void set_faculty_level(string);
    void set_faculty_department(string);
    
    int get_faculty_id();
    string get_faculty_name();
    string get_faculty_level();
    string get_faculty_department();
    
    
    //add list of integers corresponding to all of the faculty member's advisees' ids
    
private:
    int faculty_id;
    string faculty_name;
    string faculty_level;
    string faculty_department;
};



void Faculty::set_faculty_id(int g)
{
    faculty_id = g;
}
int Faculty::get_faculty_id()
{
    return faculty_id;
}

void Faculty::set_faculty_name(string n)
{
    faculty_name = n;
}

string Faculty::get_faculty_name()
{
    return faculty_name;
}

void Faculty::set_faculty_level(string n)
{
    faculty_level = n;
}

string Faculty::get_faculty_level()
{
    return faculty_level;
}

void Faculty::set_faculty_department(string n)
{
    faculty_department = n;
}

string Faculty::get_faculty_department()
{
    return faculty_department;
}




#endif
