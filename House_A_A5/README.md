Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

--- Description ---
Student and Faculty Database using a BST and Doubly Linked List. Allows users to add, delete, and modify students and faculty. 
Prints out all students and faculty to readlog after program exits.

--- Program Components ---
main.cpp
- main function

LazyBST.h
- BST class
- defines tree node

DblList.h
- Doubly Linked List class

Menu.h
- Menu class for user interface

Menu.cpp
- Menu class implementation

Operations.h
- creates functions that run operations on database

Operations.cpp
- Operations class implementation

Database.h
- creates database structure

Database.cpp
- Database class implementation

Faculty.h
- creates faculty object

Faculty.cpp
- Faculty class implementation

FacultyTable.h
- creates faculty table

FacultyTable.cpp
- FacultyTable class implementation

Student.h
- creates student object

Student.cpp
- Student class implementation

StudentTable.h
- creates student table

StudentTable.cpp
- StudentTable class implementation

--- Sources Used ---

DblList.h taken from class

LazyBST.h based on BST.h taken from class

--- Running Code ---
g++ *.cpp -o test
./test 
