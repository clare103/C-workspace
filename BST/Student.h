//
//  Student.h
//  BST
//
//  Created by David Clare on 10/25/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef BST_Student_h
#define BST_Student_h


#include <string>
#include <iostream>

using namespace std;

class Student
{
public:
    Student(){
    
        student_id =0;
        student_name = "";
        student_level = "";
        student_major = "";
        student_GPA = 0.0;
        student_advisor_id = 0;
        
    };
    
    Student(int _student_id, string _student_name, string _student_level, string _student_major, double _student_GPA, int _student_advisor_id)
    {
        set_student_id(_student_id);
        set_student_name(_student_name);
        set_student_level(_student_level);
        set_student_major(_student_major);
        set_student_GPA(_student_GPA);
        set_student_advisor_id(_student_advisor_id);
        
    }
    
    ~Student(){};
    
    void set_student_id(int g);
    int get_student_id();
    
    void set_student_name(string n);
    string get_student_name();
    
    void set_student_level(string n);
    string get_student_level();
    
    void set_student_major(string n);
    string get_student_major();
    
    void set_student_GPA(double n);
    double get_student_GPA();
    
    void set_student_advisor_id(int n);
    int get_student_advisor_id();
    
    void print();
    
private:
    int student_id;
    string student_name;
    string student_level;
    string student_major;
    double student_GPA;
    int student_advisor_id;
    
};


void Student::set_student_id(int g)
{
    student_id= g;
}
void Student::set_student_name(string g)
{
    student_name= g;
}
void Student::set_student_level(string g)
{
    student_level= g;
}
void Student::set_student_major(string g)
{
    student_major= g;
}
void Student::set_student_GPA(double g)
{
    student_GPA= g;
}
void Student::set_student_advisor_id(int g)
{
    student_advisor_id= g;
}


int Student::get_student_id()
{
    return student_id;
}
string Student::get_student_name()
{
    return student_name;
}
string Student::get_student_level()
{
    return student_level;
}
string Student::get_student_major()
{
    return student_major;
}
double Student::get_student_GPA()
{
    return student_GPA;
}
int Student::get_student_advisor_id()
{
    return student_advisor_id;
}


#endif
