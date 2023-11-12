/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A4

Description: 
DnaSeq class. creates methods for finding genetic palindromes and sub-genetic palindromes.
*/
#ifndef DNASEQ_H
#define DNASEQ_H

#include <string>

class DnaSeq {
public:
    DnaSeq();
    DnaSeq(const std::string& str);
    ~DnaSeq();

    DnaSeq complement() const;
    //void findSubGeneticPalindromes() const;
    DnaSeq substring(int s, int e) const;
    bool isSubGeneticPalindrome(const std::string& sequence) const;
    static bool isGeneticPalindrome(const std::string& sequence);
    void print() const;
    bool isEmpty() const;

    const std::string& getSequence() const;
    int getLength() const;

private:
    std::string sequence;
    int length;

    bool isNucleotide(char c) const;
};

#endif
