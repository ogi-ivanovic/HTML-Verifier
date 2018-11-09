#include "tag.h"

Tag::Tag( int lineNumber, std::string tag ) :
        lineNumber{lineNumber}, htmlTag{tag} {
}


// returns the line number of the tag
int Tag::line() {
    return lineNumber;
}


// returns the html tag
std::string Tag::tag() {
    return htmlTag;
}


std::ostream & operator<<( std::ostream & out, Tag tag ) {
    out << "Tag: " << tag.tag() << ", line: " << tag.line();
    return out;
}
