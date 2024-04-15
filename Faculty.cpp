/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Defines faculty object and functions
*/

#include "Faculty.h"

Faculty::Faculty() : 
    mFacultyID(-1),
    mName(""),
    mLevel(""),
    mDepartment("")
{

}

//DESTRUCTOR
Faculty::~Faculty() {

}

//OVERLOADED CONSTRUCTOR
Faculty::Faculty(int facultyID, std::string name, std::string level, std::string department) :
    mFacultyID(facultyID),
    mName(name),
    mLevel(level),
    mDepartment(department)
{

}

//COPY CONSTRUCTOR
Faculty::Faculty(const Faculty& other) : 
    mFacultyID(other.mFacultyID),
    mName(other.mName),
    mLevel(other.mLevel),
    mDepartment(other.mDepartment),
    mStudentIDList(other.mStudentIDList)
{

}

//GET STUDENT ID LIST
LazyBST<int> Faculty::getStudentIDList() {
    return mStudentIDList;
}

//GET ID
int Faculty::getID() {
    return mFacultyID;
}

//ADD STUDENT ID
void Faculty::addStudentID(int studentID) {
    mStudentIDList.insert(studentID);
}

//DELETE STUDENT ID
void Faculty::deleteStudentID(int studentID) {
    mStudentIDList.deleteNode(studentID);
}

//PRINT
void Faculty::print() {
    std::cout << "Faculty ID: " << mFacultyID << std::endl;
    std::cout << "Name: " << mName << std::endl;
    std::cout << "Level: " << mLevel << std::endl;
    std::cout << "Department: " << mDepartment << std::endl;
    std::cout << "Student ID List: ";
    mStudentIDList.printTree();
    std::cout << std::endl;
    std::cout << std::endl;
}
