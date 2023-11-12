/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A4

Description: 
PalindromeFinder class. Create methods for finding genetic palindromes.
*/
#ifndef PALINDROME_FINDER_H
#define PALINDROME_FINDER_H

#include <string>

class PalindromeFinder {
public:
    PalindromeFinder(const std::string& sequence);

    bool isGeneticPalindrome() const;
    //void findSubGeneticPalindromes(std::string substring) const;

private:
    std::string sequence;

    bool isNucleotide(char c) const;
};

#endif
