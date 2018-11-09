#ifndef VERIFY_TAG_H
#define VERIFY_TAG_H
#include <iostream>
#include <string>

class Tag {
    int lineNumber;
    std::string htmlTag;

public:
    Tag( int lineNumber, std::string tag );
    int line(); // returns the line number of the tag
    std::string tag(); // returns the tag as a string
};

std::ostream & operator<<( std::ostream & out, Tag tag );


#endif
