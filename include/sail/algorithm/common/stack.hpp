#pragma once

/**
 * @file: include/sail/algorithm/common/stack.hpp
 * @author: sailing-innocent
 * @create: 2022-11-15
 * @desp: the stack header file
*/

#ifndef SAIL_ALGORITHM_STACK_H_
#define SAIL_ALGORITHM_STACK_H_

#include <sail/algorithm.h>

SAIL_NAMESPACE_BEGIN

template <typename T>
class Stack: public Node<std::vector<Node<T>>>
{
public:
    Stack() = default;
    bool isEmpty() const { return mSize == 0; }
    size_t size() const { return mSize; }
    bool push(Node<T>& n) {
        mContent.push_back(n);
        mSize = mSize + 1;
        return true;
    }
    bool push(T& nt) {
        Node<T> n(nt);
        push(n);
    }
    Node<T> pop() { 
        Node<T> n = mContent[mSize-1];
        mSize = mSize - 1;
        mContent.resize(mSize);
        return n; 
    }
protected:
    size_t mSize = 0;
};

// stack.push
// stack.pop

SAIL_NAMESPACE_END

#endif 
