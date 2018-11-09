#include <iostream>
#include <sstream>
#include <fstream>
#include "verification.h"

int main(int argc, char *argv[]) {
    std::string file = argv[1]; // opens the given text file containing html
    Verification content;
    content.createStack(file); // create a stack containing all the tags in file
    content.verify(); // verifies the contents of the file
}
