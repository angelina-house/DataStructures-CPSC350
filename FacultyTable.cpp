/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Defines the functions for the FacultyTable class.
*/

#include "FacultyTable.h"
#include "LazyBST.h"

//CONSTRUCTOR
FacultyTable::FacultyTable() {

}

//DESTRUCTOR
FacultyTable::~FacultyTable() {

}

//FIND
Faculty FacultyTable::find(int facultyID) {
    if(facultyList.searchByID(facultyID) == NULL) {
        return Faculty();
    }
    return facultyList.searchByID(facultyID)->getValue();
}

//ADD
void FacultyTable::add(Faculty faculty) {
    facultyList.insert(faculty);
}

//DELETE
void FacultyTable::del(int facultyID) {
    facultyList.deleteNode(facultyList.searchByID(facultyID)->getValue());
}

//UPDATE
void FacultyTable::update(Faculty oldFaculty, Faculty faculty) {
    facultyList.replace(oldFaculty, faculty);
}

//ADD STUDENT ID
void FacultyTable::addStudentID(int studentID, int facultyID) {
    Faculty faculty = find(facultyID);
    faculty.addStudentID(studentID);
    update(faculty, faculty);
}

//PRINT
void FacultyTable::print() {
    facultyList.studentPrinter();
}

//DELETE STUDENT ID
void FacultyTable::deleteStudentID(int studentID, int facultyID) {
    Faculty faculty = find(facultyID);
    faculty.deleteStudentID(studentID);
    update(faculty, faculty);
}

//CONTAINS
bool FacultyTable::contains(int ID) {
    Faculty f = find(ID);
    return facultyList.contains(f);
}