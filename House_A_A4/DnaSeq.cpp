/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A4

Description: 
DnaSeq class. Contains methods for finding genetic palindromes and sub-genetic palindromes.
*/
#include "DnaSeq.h"
#include "PalindromeFinder.h"
#include "DblList.h"
#include <iostream>

DnaSeq::DnaSeq() : sequence(""), length(0) {} // default constructor

DnaSeq::DnaSeq(const std::string& str) : sequence(str), length(str.length()) {} // overloaded constructor

DnaSeq::~DnaSeq() {} // destructor

bool DnaSeq::isNucleotide(char c) const { // checks if a character is a nucleotide
    return c == 'A' || c == 'C' || c == 'T' || c == 'G';
}

DnaSeq DnaSeq::complement() const { // returns the complement of a DNA sequence
    DnaSeq complemented;
    for (char nucleotide : sequence) {
        if (!isNucleotide(nucleotide)) {
            //std::cerr << "Invalid DNA sequence character: " << nucleotide << std::endl;
            return DnaSeq();
        }

        switch (nucleotide) {
            case 'A':
                complemented.sequence += 'T';
                break;
            case 'T':
                complemented.sequence += 'A';
                break;
            case 'C':
                complemented.sequence += 'G';
                break;
            case 'G':
                complemented.sequence += 'C';
                break;
        }
    }
    complemented.length = sequence.length();
    //complemented.findSubGeneticPalindromes();
    return complemented;
}

DnaSeq DnaSeq::substring(int s, int e) const { // returns a substring of a DNA sequence
    if (s < 0 || e < 0 || s >= length || e > length || s >= e) {
        // Invalid indices, return an empty sequence or handle it as appropriate.
        return DnaSeq();
    }

    std::string subSequence = sequence.substr(s, e - s);
    return DnaSeq(subSequence);
}


bool DnaSeq::isGeneticPalindrome(const std::string& sequence) { // checks if a DNA sequence is a genetic palindrome
    PalindromeFinder finder(sequence);
    return finder.isGeneticPalindrome();
}

bool DnaSeq::isSubGeneticPalindrome(const std::string& sequence) const { // checks if a DNA sequence is a sub-genetic palindrome
    DnaSeq currSeq = sequence;
    if (sequence.length() < 5 || !isNucleotide(sequence[0])) {
        return false;
    } else {
    DnaSeq complemented = complement();
    int max = sequence.length()-1;
    int range = 5;
    while (range <= max) {
        for (int i = 0; i <= max - range; i++) {
            DnaSeq subComp = currSeq.substring(i, i + range);
            subComp = subComp.getSequence();
            //std::cout << "Subsequence: " << subComp.getSequence() << std::endl;
            if (DnaSeq::isGeneticPalindrome(subComp.getSequence())) {
                std::cout << "Subsequence: " << subComp.getSequence() << " is a palindrome" << std::endl;
            }
        }
        range++;
    }
}
    
    return true;
}

void DnaSeq::print() const { // prints a DNA sequence
    //PalindromeFinder.isGeneticPalindrome();
    std::cout << sequence << " - ";

    if (isEmpty()) {
        std::cout << "INVALID";
    } else if (DnaSeq::isGeneticPalindrome(sequence)) {
        std::cout << "Genetic Palindrome" <<  std::endl;
        
    } else {
        std::cout << "Not a Genetic Palindrome" << std::endl;
    }

    isSubGeneticPalindrome(sequence);


    std::cout << std::endl;
}

    

bool DnaSeq::isEmpty() const { // checks if a DNA sequence is empty
    return sequence.empty();
}

const std::string& DnaSeq::getSequence() const { // returns a DNA sequence
    return sequence;
}

int DnaSeq::getLength() const { // returns the length of a DNA sequence
    return length;
}
