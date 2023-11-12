Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A4

--- Description ---
This program takes in a text file of dna sequences and checks if they are valid or not. If they are valid, it outputs the longest common subsequence between the two sequences. If they are not valid, it outputs an error message. The program also checks if
substrings of the sequence are palindromes.

--- Program Components ---
main.cpp
- contains the main method which runs the program
- takes in a file during run time
- creates a DnaSeq object and calls the run method

DnaSeq.h
- header file for DnaSeq.cpp

DnaSeq.cpp
- checks if dna sequences are valid
- checks if substrings of the sequence are palindromes

PalindromeFinder.h
- header file for PalindromeFinder.cpp

PalindromeFinder.cpp
- finds compiment of a dna sequence
- checks if compliment is a palindrome

DblList.h
- creates a doubly linked list and its methods

ListNode.h
- creates a node for the doubly linked list and its methods


--- Sources Used ---
https://stackoverflow.com/questions/10363646/compiling-c11-with-g
used to figure out how to compile with c++11

DblList.h and ListNode.h were taken from class

--- Running Code ---
g++ -std=c++11 *.cpp -o test
./test dna_sequences.txt
