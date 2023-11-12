Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A3

--- Description ---
This programs take in a file during run time which contains the heights of people at a speaker presentation.
The program then calculates the number of people who have an unobstructed view of the speaker from each row.
The program then outputs the number of people who have an unobstructed view from each row and their respective 
heights.

--- Program Components ---
main.cpp
- contains the main method which runs the program
- takes in a file during run time
- creates a speakerView object and calls the run method

monoStack.h
- creates the monostack data structue and its methods

speakerView.h
- creates the speakerView object 
- creates fileProcessor method

speakerView.cpp
- defines fileProcessor method
- determins the number of people who have an unobstructed view from each row
- outputs the number of people who have an unobstructed view from each row and their respective heights


--- Sources Used ---
https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
 used to read file input using istringstream

tutor: Bhuvan (idk his last name)

--- Running Code ---
g++ *.cpp -o test
./test sampleInput.txt