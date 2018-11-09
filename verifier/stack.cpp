#include "stack.h"

Stack::Stack() :
    stackHeight{0}, stackCapacity{1} {
    stack = new Tag*[stackCapacity];
}


Stack::~Stack() {
    for (int i = 0; i < stackHeight; ++i) {
        delete stack[i];
    }
    delete[] stack;
}


// returns the number of tags in the stack
int Stack::height() {
    return stackHeight;
}


// returns true if the stack contains no tags
bool Stack::isEmpty() {
    return (stackHeight == 0);
}


// doubles the size of the stack in order to add more tags
void Stack::doubleStack() {
    Tag ** tmp = new Tag*[stackCapacity];
    for (int i = 0; i < stackHeight; ++i) {
        tmp[i] = stack[i];
    }
    delete[] stack;
    stack = tmp;
}


// adds a tag to the top of the stack
void Stack::push( Tag * tag ) {
    if (stackHeight == stackCapacity) {
        stackCapacity *= 2;
        doubleStack();
    }
    stack[stackHeight] = tag;
    stackHeight += 1;
}


// returns the tag at the top of the stack
Tag Stack::top() {
    return *stack[stackHeight - 1];
}

// returns the tag at the top of the stack and
//  takes it off the stack
// requires: stack must have at least one item
Tag * Stack::pop() {
    Tag * item = stack[stackHeight - 1];
    //stack[stackHeight] = nullptr;
    stackHeight -= 1;
    return item;
}
