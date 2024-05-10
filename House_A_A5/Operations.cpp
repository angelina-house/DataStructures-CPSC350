/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Defines functions for the Operations class
*/

#include "Operations.h"

//CONSTRUCTOR
Operations::Operations() {

}

//DESTRUCTOR
Operations::~Operations() {

}

//PRINT ALL STUDENTS
void Operations::printAllStudents(Database d) {
    d.getStudentTable().print();
}

//PRINT ALL FACULTY
void Operations::printAllFaculty(Database d) {
    d.getFacultyTable().print();
}

//PRINT STUDENT
void Operations::printStudent(Database d, int studentID) {
    d.getStudentTable().find(studentID).print();
}

//PRINT FACULTY
void Operations::printFaculty(Database d, int facultyID) {
    d.getFacultyTable().find(facultyID).print();
}

//ADD NEW STUDENT
void Operations::addNewStudent(Database& d, Student s) {
    d.addStudent(s);
}

//ADD NEW FACULTY
void Operations::addNewFaculty(Database& d, Faculty f) {
    d.addFaculty(f);
}

//DELETE STUDENT
void Operations::deleteStudent(Database& d, int studentID) {
    d.deleteStudent(studentID);
}

//DELETE FACULTY
void Operations::deleteFaculty(Database& d, int facultyID) {
    d.deleteFaculty(facultyID);
}

//CHANGE ADVISOR
void Operations::changeAdvisor(Database& d, int studentID, int facultyID) {
    d.changeAdvisor(studentID, facultyID);
}

//DELETE STUDENT ID
void Operations::deleteStudentID(Database& d, int studentID, int facultyID) {
    d.deleteStudentID(studentID, facultyID);
}
