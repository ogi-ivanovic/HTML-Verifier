#ifndef VERIFY_VERIFICATION_H
#define VERIFY_VERIFICATION_H
#include "stack.h"
#include <iostream>
#include <sstream>
#include <fstream>

class Verification {
    Stack first;
    Stack second;
    bool isTag( std::string s ) ; // determines if the given string s is an html tag
    bool isClosingTag( std::string tag ); // determines if the given tag is a closing tag
public:
    void createStack( std::string file ); // creates a stack containing all the tags in the html file
    bool verify(); // verifies that the tags in the html file are correct
};


#endif
