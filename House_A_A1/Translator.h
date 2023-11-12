/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A1

Description:
Creates translator class and constructors
*/
#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <string>

//public class that creates translateWord(input string), translateSentence(input string) and isvowel boolean (input char)
class Translator {
public:
    Translator(); 
    ~Translator(); 

    std::string translateWord(std::string word);
    std::string translateSentence(std::string sentence);
    
    bool isVowel(char c);
};

#endif
