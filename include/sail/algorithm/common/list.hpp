#pragma once
/**
 * FILE:include/sail/algorith/list.hpp
 * AUTHOR:sailing-innocent
 * CREATE:2022-10-15
 * DESP: the template linked list library for SAIL
 * DONE: //TODO: Finish SALI linked list library
*/

#ifndef SAIL_ALGORITHM_LIST_H_
#define SAIL_ALGORITHM_LIST_H_

#include <sail/algorithm.h>

SAIL_NAMESPACE_BEGIN

template <typename T>
class ListNode: public Node<T>
{
public:
    ListNode() {}
    explicit ListNode(T _content): Node(_content) {}
    const ListNode<T>& prev() const { return *mpPrev; }
    const ListNode<T>& next() const { return *mpNext; }
    bool setPrev(ListNode<T>& _prev) { mpPrev = &_prev; return true; }
    bool setNext(ListNode<T>& _next) { mpNext = &_next; return true; }
protected:
    ListNode<T>* mpPrev = nullptr;
    ListNode<T>* mpNext = nullptr;
};

template <typename T>
class LinkList: public Node<std::vector<ListNode<T>>>
{
public:
    LinkList() = default;
    explicit LinkList(std::vector<ListNode<T>>& vec)
    {
        setContent(vec);
    }
    inline size_t size() { return mSize; }
    bool setContent(std::vector<ListNode<T>>& vec);
    bool append(T val);
    ListNode<T>& operator[](size_t index){ return mContent[index]; }
    bool insert(size_t index, T val);
    bool del(size_t index);
    bool swap(size_t i, size_t j);
    LinkList<T>& sort(int type = 0) {
        switch(type) {
            case 0:
                return bubble_sort_ll(*this);
            case 1:
                return select_sort_ll(*this);
            default:
                return bubble_sort_ll(*this);
        }
    }
protected:
    size_t mSize = 0;
};

// ---------------------IMPLEMENTATIONS-------------------------//
#include <sail/algorithm/list/linklist.tpp>

SAIL_NAMESPACE_END

#endif // SAIL_ALGORITHM_LIST_H_
