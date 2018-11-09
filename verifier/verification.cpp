#include "verification.h"

bool Verification::isTag( std::string s ) {
    int round = 1;
    while (round <= 2) {
        if (s == "<html>") return true;
        if (s =="<body>") return true;
        if (s == "<div>") return true;
        if (s == "<h1>") return true;
        if (s == "<h2>") return true;
        if (s == "<h3>") return true;
        if (s == "<h4>") return true;
        if (s == "<h5>") return true;
        if (s == "<h6>") return true;
        if (s == "<p>") return true;
        if (s == "<script>") return true;
        if (s == "<ol>") return true;
        if (s == "<ul>") return true;

        // if s is a closing tag, then remove the '/' and go through the while loop again
        s.erase(1,1);
        round++;
    }
    return false;
}


// determines if the given tag is a closing tag
bool Verification::isClosingTag( std::string tag ) {
    if ((tag[1] == '/') && (isTag(tag))) return true;
    return false;
}


// creates a new stack containing the tags
void Verification::createStack( std::string file ) {
    int lineNumber = 1;
    std::ifstream infile(file);
    std::string line;
    while (getline(infile, line)) {
        std::istringstream ss(line);
        std::string word;
        while (ss >> word) {
            if (isTag(word)) {
                Tag * newTag = new Tag{lineNumber, word};
                first.push(newTag);
            }
        }
        lineNumber++;
    }
}


// returns true if the tags in the file are all correct
bool Verification::verify() {
    while ((! first.isEmpty()) && (isClosingTag(first.top().tag()) || (! second.isEmpty()))) {
        Tag * tag = first.pop();

        if (isClosingTag(tag->tag())) {
            second.push(tag);
        } else {
            Tag * secondTag = second.pop();
            if (tag->tag() == secondTag->tag().erase(1,1)) { // tags match
                delete tag;
                delete secondTag;
            } else { // tags do not match
                std::cerr << "Error: " << tag->tag() << ", line " << tag->line() << std::endl;
                delete tag;
                delete secondTag;
                return false;
            }
        }
    }
    
    if (! first.isEmpty()) {
        Tag * tag = first.pop();
        std::cerr << "Error: " << tag->tag() << ", line " << tag->line() << std::endl;
        delete tag;
        while (! first.isEmpty()) {
            delete first.pop();
        }
        return false;
    } else if (! second.isEmpty()) {
        Tag * tag = second.pop();
        std::cerr << "Error: " << tag->tag() << ", line " << tag->line() << std::endl;
        delete tag;
        while (! second.isEmpty()) {
            delete second.pop();
        }
        return false;
    }
    std::cout << "HTML tags are correct." << std::endl;
    return true;
}
