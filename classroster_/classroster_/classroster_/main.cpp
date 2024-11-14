//
//  main.cpp
//  classroster_
//
//  Created by Trayvonious Pendleton on 9/23/23.
//

#include <iostream>
#include "roster.hpp"
#include "degree.hpp"
#include "student.hpp"
#include <string>

using namespace std;
//enum security[]
//enum network[]
//enum software[]

int main() {
    
    //Print your info
    cout << "Xcode " << "Scripting and Programming Application-C867 "<< endl;
    cout <<"Programming C++ "<< endl;
    cout << "Student ID: 011205284 "<< endl;
    cout  << "Trayvonious Pendleton"<< endl<<endl;
    const string studentData[] =
    {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Trayvonious,Pendleton,tpend32@wgu.edu,32,4,10,15,SOFTWARE",
    };
    //An instance
    Roster classRoster;
    // parse
    for (const string& data : studentData) {
        classRoster.parseStudent(data);
    }
    
    // Print all students
    cout<<"Displaying all students:"<<endl;
    classRoster.printAll();
    
    // Print students with invalid emails
    cout<<"Displaying invalid emails:"<<endl;
    classRoster.printInvalidEmails();
    cout<<endl;
   
    //average days in course
    for (int i = 0; i < 5; i++) { // Use the size of classRosterArray
        if (classRoster.classRosterArray[i] != nullptr) {
            string studentId = classRoster.classRosterArray[i]->getstudentID();
            classRoster.print_average_days_in_course(studentId);
        }
    }
    cout<<endl;
    
    // Print students in a specific degree program
    classRoster.printDegreeProgram(software);
    
    // Remove a3 student by ID
    classRoster.remove("A3");
    
    //Print all student
    classRoster.printAll();
    
    //try to remove a3 again
    classRoster.remove("A3");
    
    //destructor to release memory
    classRoster.~Roster();
    
    return 0;
    
    
}
