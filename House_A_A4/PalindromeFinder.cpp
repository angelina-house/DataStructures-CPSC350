/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A4

Description: 
PalindromeFinder class. Contains methods for finding genetic palindromes.
*/
#include "PalindromeFinder.h"
#include "DnaSeq.h"
#include <iostream>

PalindromeFinder::PalindromeFinder(const std::string& sequence) : sequence(sequence) {} // constructor

bool PalindromeFinder::isNucleotide(char c) const { // checks if a character is a nucleotide
    return c == 'A' || c == 'C' || c == 'T' || c == 'G';
}

bool PalindromeFinder::isGeneticPalindrome() const { // checks if a DNA sequence is a genetic palindrome
    std::string complemented;

    for (char nucleotide : sequence) {
        if (!isNucleotide(nucleotide)) {
            std::cerr << "Invalid DNA sequence character: " << nucleotide << std::endl;
            return false;
        }

        switch (nucleotide) {
            case 'A':
                complemented += 'T';
                break;
            case 'T':
                complemented += 'A';
                break;
            case 'C':
                complemented += 'G';
                break;
            case 'G':
                complemented += 'C';
                break;
        }
    }


    std::string reversed = complemented;
    std::reverse(reversed.begin(), reversed.end());
    //reversed.findSubGeneticPalindromes();
    return sequence == reversed;
}

