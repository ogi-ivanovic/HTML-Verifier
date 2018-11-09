#ifndef VERIFY_STACK_H
#define VERIFY_STACK_H
#include "tag.h"

class Stack {
    int stackHeight, stackCapacity;
    Tag **stack;
    void doubleStack(); // doubles the size of the stack

public:
    Stack();
    ~Stack();
    int height(); // height of the stack
    bool isEmpty(); // determines if stack is empty
    void push( Tag * tag ); // adds tag to the top of the stack
    Tag top(); // returns tag at the top of the stack
    Tag * pop(); // removes teh tag at the top of the stack
};


#endif
