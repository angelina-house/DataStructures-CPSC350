/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Creates a database object that allows the user to interact with the database.
*/

#ifndef DATABASE_H
#define DATABASE_H
#include "StudentTable.h"
#include "FacultyTable.h"
#include "Student.h"
#include "Faculty.h"

class Database {
    public: 
        Database();
        ~Database();
        StudentTable getStudentTable();
        FacultyTable getFacultyTable();
        void addStudent(Student s);
        void addFaculty(Faculty f);
        void deleteStudent(int studentID);
        void deleteFaculty(int studentID);
        void addStudentID(int studentID, int facultyID);
        void deleteStudentID(int studentID, int facultyID);
        void changeAdvisor(int studentID, int facultyID);

    private:
        FacultyTable facultyTable;
        StudentTable studentTable;
};

#endif