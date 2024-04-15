/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Defines the database class and its functions.
*/

#include "Database.h"

//Default constructor
Database::Database() {

}

//Default destructor
Database::~Database() {

}

//GET STUDENT TABLE
StudentTable Database::getStudentTable() {
    return studentTable;
}

//GET FACULTY TABLE
FacultyTable Database::getFacultyTable() {
    return facultyTable;
}

//ADD STUDENT
void Database::addStudent(Student s) {
    studentTable.add(s);
}

//ADD FACULTY
void Database::addFaculty(Faculty f) {
    facultyTable.add(f);
}

//DELETE FACULTY
void Database::deleteFaculty(int facultyID) {
    facultyTable.del(facultyID);
}

//DELETE STUDENT
void Database::deleteStudent(int studentID) {
    studentTable.del(studentID);
}

//ADD STUDENT ID
void Database::addStudentID(int studentID, int facultyID) {
    facultyTable.addStudentID(studentID, facultyID);
}

//DELETE STUDENT ID
void Database::deleteStudentID(int studentID, int facultyID) {
    facultyTable.deleteStudentID(studentID, facultyID);
}

//CHANGE ADVISOR
void Database::changeAdvisor(int studentID, int facultyID) {
    studentTable.changeAdvisor(studentID, facultyID);
}