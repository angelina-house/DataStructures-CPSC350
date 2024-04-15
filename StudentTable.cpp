/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Defines student table object and functions
*/

#include "StudentTable.h"
#include "LazyBST.h"

//CONSTRUCTOR
StudentTable::StudentTable() {

}

//DESTRUCTOR
StudentTable::~StudentTable() {

}

//FIND
Student StudentTable::find(int studentID) {
    if(studentList.searchByID(studentID) == NULL) {
        return Student();
    }
    return studentList.searchByID(studentID)->getValue();
}

//ADD
void StudentTable::add(Student student) {
    studentList.insert(student);
}

//DELETE
void StudentTable::del(int studentID) {
    studentList.deleteNode(studentList.searchByID(studentID)->getValue());
}

//UPDATE
void StudentTable::update(Student oldStudent, Student student) {
    studentList.replace(oldStudent, student);
}

//PRINT
void StudentTable::print() {
    studentList.studentPrinter();
}

//CHANGE ADVISOR
void StudentTable::changeAdvisor(int studentID, int facultyID) {
    Student s = find(studentID);
    s.setFacultyID(facultyID);
    update(s, s);
}

//CONTAINS
bool StudentTable::contains(int studentID) {
    Student s = find(studentID);
    return studentList.contains(s);
}


