#pragma once
#ifndef SAIL_ALGORITHM_COMMON_QUEUE_H_
#define SAIL_ALGORITHM_COMMON_QUEUE_H_
/**
 * @file: include/sail/algorithm/common/queue.hpp
 * @author: sailing-innocent
 * @create: 2022-11-15
 * @desp: sail queue header
*/

#include <sail/algorithm.h>
#include <queue>

SAIL_NAMESPACE_BEGIN

// first in ; first out

template <typename T>
class Queue: public Node<std::queue<Node<T>>>
{
public:
    Queue() = default;
    bool isEnpty() const { return mSize == 0; }
    size_t size() const { return mSize; }
    bool enqueue(Node<T>& n) {
        mContent.push(n);
        mSize++;
        return true;
    }
    Node<T> dequeue() {
        if (mSize == 0) {
            Node<T> n;
            return n;
        }
        Node<T> n = mContent.front();
        mContent.pop();
        mSize--;
        return n;
    }
protected:
    size_t mSize = 0;
};

SAIL_NAMESPACE_END

#endif // SAIL_ALGORITHM_COMMON_QUEUE_H_