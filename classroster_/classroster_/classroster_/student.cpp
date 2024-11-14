//
//  student.cpp
//  classroster_
//
//  Created by Trayvonious Pendleton on 9/23/23.
//

#include "student.hpp"
#include <string>
#include <iostream>
#include "degree.hpp"

using namespace std;

    //setter
    void Student::setstudentID(string ID) {
        studentID = ID;
    }
   // getter
    string Student::getstudentID(){
       return studentID;
   }
    //setter
    void Student::setfirstname(string first) {
        firstname = first;
    }
    //getter
    string Student::getfirstname(){
        return firstname;
    }
    //setter
    void Student::setlastname(string last) {
        lastname = last;
    }
    //getter
    string Student::getlastname(){
        return lastname;
    }
    //setter
    void Student::setemail(string mail) {
        mail = email;
    }
    //getter
    string Student::getemail(){
        return email;
    }
    //setter
    void Student::setage(int a) {
        age = a;
    }
    //getter
    int Student::getage(){
        return age;
    }
    //setter
    void Student::setdays_to_complete(int days1, int days2, int days3) {
        days_to_complete[0] = days1;
        days_to_complete[1] = days2;
        days_to_complete[2] = days3;
    }

    //getter
   int* Student::getdays_to_complete(){
       return days_to_complete;
       ;
    }
    //setter
    void Student::setdegreeprogram( enum degree_program degreeprogram){
            
    }
    //getter
enum degree_program  Student::getdegreeprogram(){
        return degreeprogram;
    }
  
    //implement the student function
    Student::Student(string studentID, string firstname,string lastname,string email, int age,int days1, int days2, int days3, degree_program degreeprogram){
        // Initialize member variables in the constructor
        this->studentID = studentID;
        this->firstname = firstname;
        this->lastname = lastname;
        this->email = email;
        this->age = age;
        this->days_to_complete[0] = days1;
        this->days_to_complete[1] = days2;
        this->days_to_complete[2] = days3;
        this->degreeprogram = degreeprogram;
    }
        // print student
        void Student::print() {
        cout << "StudentID: " << getstudentID() <<" First Name: " << getfirstname()<< " Last Name: " << getlastname()<< " Email: " << getemail()<< " Age: " << getage()<< " Days to Complete: " << getdays_to_complete()[0] << ", " << getdays_to_complete()[1] << ", " << getdays_to_complete()[2] << " Degree Program: ";
        if (getdegreeprogram() == security) {
            cout << "security";
        } else if (getdegreeprogram() == network) {
            cout << "network";
        } else if (getdegreeprogram() == software) {
            cout << "software";
        }
        cout << endl;
    }

