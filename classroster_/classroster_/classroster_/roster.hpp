//
//  roster.hpp
//  classroster_
//
//  Created by Trayvonious Pendleton on 9/23/23.
//

#ifndef roster_hpp
#define roster_hpp

#include <stdio.h>
#pragma once
#include <string>
#include "student.hpp"
#include "degree.hpp"

class Roster {
public:
    //parse
    void parseStudent(const string& studentData);
    //add student to roster
    void add(string studentID, string firstname, string lastname, string email, int age, int days1, int days2, int days3, degree_program degreeprogram);
    // remove sudent to roster
    void remove(string studentID);
    // print all student data
    void printAll();
    // Print average days in course for a student
    void print_average_days_in_course(string studentID);
    // Print invalid emails
    void printInvalidEmails();
    // Print students by degree program
    void printDegreeProgram(degree_program degreeprogram);
    //constructor
    Roster();
    //destructor
    ~Roster();
    //
    Student* classRosterArray[5];
    
};
#endif /* roster_hpp */
