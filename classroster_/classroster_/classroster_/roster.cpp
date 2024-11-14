//
//  roster.cpp
//  classroster_
//
//  Created by Trayvonious Pendleton on 9/23/23.
//


#include "roster.hpp"
#include "student.hpp"
#include "degree.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
using namespace std;


    // Create an array of pointers to Student objects
    Student* classRosterArray[5];

    // Constructor
    Roster::Roster() {
        for (int i = 0; i < 5; i++) {
            classRosterArray[i] = nullptr;
        }
    }

        // Destructor
    Roster::~Roster() {
        for (int i = 0; i < 5; i++) {
            if (classRosterArray[i] != nullptr) {
                delete classRosterArray[i];
                classRosterArray[i] = nullptr;            }
            }
        }
    
        
    //add student to roster
    void Roster::add(string studentID, string firstname, string lastname, string email, int age, int days1, int days2, int days3, degree_program degreeprogram) {
        // Find an empty slot to add a new student
        for (int i = 0; i < 5; i++) {
            if (classRosterArray[i] == nullptr) {
                classRosterArray[i] = new Student(studentID, firstname, lastname, email, age, days1, days2, days3, degreeprogram);
                return;
            }
        }
        cout << "Error Message: Roster is full" << endl;
    }
    // remove student from roster by studentid
    void Roster::remove(string studentID) {
        for (int i = 0; i < 5; i++) {
            if (classRosterArray[i] != nullptr && classRosterArray[i]->getstudentID() == studentID) {
                delete classRosterArray[i];
                cout << "Removing "<< studentID<< endl<< endl;
                classRosterArray[i] = nullptr;
                return;
            }
        }
        cout << "Removing "<< studentID<< endl;
        cout << "Error Message: Student not found" << endl;
    }
    //print roster
    void Roster::printAll() {
        for (int i = 0; i < 5; i++) {
            if (classRosterArray[i] != nullptr) {
                classRosterArray[i]->print();{
                    cout<<endl;
                }
            }
        }
    }
    // average days in course
    void Roster::print_average_days_in_course(string studentID) {
        for (int i = 0; i < 5; i++) {
            if (classRosterArray[i] != nullptr && classRosterArray[i]->getstudentID() == studentID) {
                int* days = classRosterArray[i]->getdays_to_complete();
                int average_days = (days[0] + days[1] + days[2]) / 3;
                cout << "StudentID " << classRosterArray[i]->getstudentID() << " has an average of " << average_days << " days to complete a course." << endl;
            }
        }
    }
    //invalid email
    void Roster::printInvalidEmails() {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            string email = classRosterArray[i]->getemail();
            // Use regular expression to check for valid email format
            regex pattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
            if (!regex_match(email, pattern)) {
                cout << email << " is invalid" << endl;
            }
        }
    }
}

    //degree program
void Roster::printDegreeProgram(degree_program degreeprogram) {
    cout<< "Showing students in degree program: "<< degreeprogram << endl;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getdegreeprogram() == degreeprogram) {
            classRosterArray[i]->print();{
                cout<<endl;
            }
        }
    }
}
   
    void Roster::parseStudent(const string& studentData) {
        // Find an empty slot to add a new student
        for (int i = 0; i < 5; i++) {
            if (classRosterArray[i] == nullptr) {
                istringstream ss(studentData);
                string token;
                string studentID, firstname, lastname, email, degree_program_str;
                int age, days1, days2, days3;
                degree_program degreeprogram;

                getline(ss, studentID, ',');
                getline(ss, firstname, ',');
                getline(ss, lastname, ',');
                getline(ss, email, ',');
                ss >> age;
                ss.ignore(1);
                ss >> days1;
                ss.ignore(1);
                ss >> days2;
                ss.ignore(1);
                ss >> days3;
                ss.ignore(1);
                getline(ss, degree_program_str, ',');

                if (degree_program_str == "SECURITY") {
                    degreeprogram = security;
                } else if (degree_program_str == "NETWORK") {
                    degreeprogram = network;
                } else if (degree_program_str == "SOFTWARE") {
                    degreeprogram = software;
                } else {
                    cout << "Invalid degree program: " << degree_program_str << endl;
                    return;
                }

                // Create a new student object and add it to the roster
                classRosterArray[i] = new Student(studentID, firstname, lastname, email, age, days1, days2, days3, degreeprogram);
            
                return; 
            }
        }
        cout << "Error: Roster is full. Cannot add more students." << endl;
    }
