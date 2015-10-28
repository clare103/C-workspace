//
//  Menu.h
//  BST
//
//  Created by David Clare on 10/25/14.
//  Copyright (c) 2014 David Clare. All rights reserved.
//

#ifndef BST_Menu_h
#define BST_Menu_h


#include "BST_D.h"
#include "Faculty.h"
#include "Student.h"

class Menu
{
public:
    Menu(){};
    ~Menu(){};
    
    void execute();
    
};

void Menu::execute()
{
    BST_D<Student> student_tree;
    student_tree.create_student(Student(1, "Ross", "Senior","Computer Science", 3.987, 1));
    student_tree.create_student(Student(2, "Ani", "Senior","Computer Science", 3.987, 1));
    student_tree.create_student(Student(3, "Jared", "Junior", "Computer Science", 3.987, 1));
    student_tree.create_student(Student(4, "Katie", "Sophmore","Computer Science", 3.987, 1));
    student_tree.create_student(Student(5, "Meeshan", "Junior", "Computer Science", 1.987, 2));
    student_tree.create_student(Student(6, "Meghan", "Junior", "Math", 3.987, 1));

    student_tree.print_student();
    
    BST_D<Faculty> faculty_tree;
    faculty_tree.create_faculty(Faculty(1,"Eric Linstead","Super Hero","Computer Science"));
    faculty_tree.create_faculty(Faculty(2, " ","Tenure", "Math"));
    
   // student_tree.print_stud_fac(student_tree.root, faculty_tree.root);
    
    
    
    
}


#endif
