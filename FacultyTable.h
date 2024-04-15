/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Creates faculty table object and functions
*/

#ifndef FACULTYTABLE_H
#define FACULTYTABLE_H
#include "Faculty.h"
#include "LazyBST.h"

class FacultyTable {
    public:
        FacultyTable();
        ~FacultyTable();
        Faculty find(int facultyID);
        void del(int facultyID);
        void update(Faculty oldFaculty, Faculty Faculty);
        void add(Faculty Faculty);
        void addStudentID(int studentID, int facultyID);
        void deleteStudentID(int studentID, int facultyID);
        void print();
        bool contains(int ID);
    private:
        LazyBST<Faculty> facultyList;
};

#endif 