/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Create operations object and functions
*/

#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "Database.h"
#include "FacultyTable.h"
#include "Student.h"
#include "StudentTable.h"
#include "Faculty.h"

//OPERATIONS CLASS
class Operations {
    public:
        Operations();
        ~Operations();
        void printAllStudents(Database d); 
        void printAllFaculty(Database d);
        void printStudent(Database d, int studentID);
        void printFaculty(Database d, int facultyID);
        void addNewStudent(Database& d, Student s);
        void addNewFaculty(Database& d, Faculty f);
        void deleteStudent(Database& d, int studentID);
        void deleteFaculty(Database& d, int facultyID);
        void changeAdvisor(Database& d, int studentID, int facultyID);
        void deleteStudentID(Database& d, int studentID, int facultyID);
    private:

};

#endif