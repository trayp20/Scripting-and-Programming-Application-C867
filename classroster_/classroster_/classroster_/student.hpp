//
//  student.hpp
//  classroster_
//
//  Created by Trayvonious Pendleton on 9/23/23.
//

#ifndef student_hpp
#define student_hpp
#include <iostream>
#include <stdio.h>
#include <string>
#include "degree.hpp"

using namespace std;


class Student {
   
private:
    
    string studentID;
    string firstname;
    string lastname;
    string email;
    int age;
    int days_to_complete[3];
    degree_program degreeprogram;
    
    
public:
    
    //const
    Student(string studentID,string firstname,string lastname,string email,int age,int days1, int days2, int days3, degree_program degreeprogram);
    //getters
    string getstudentID();
    string getfirstname();
    string getlastname();
    string getemail();
    int getage();
    int* getdays_to_complete();
    enum degree_program getdegreeprogram();
    
    //setters
    void setstudentID(string ID);
    void setfirstname(string first);
    void setlastname(string last);
    void setemail(string mail);
    void setage(int a);
    void setdegreeprogram(enum degree_program degreeprogram);
    void setdays_to_complete(int days1, int days2, int days3);
//print student data
    void print();
};


#endif /* student_hpp */
