/**
 * @file: include/sail/algorith/double/dlist.hpp
 * @author: sailing-innocent
 * @create: 2022-10-26
 * @desp: Header File for Double List
*/

#pragma once
#ifndef SAIL_ALGORITHM_DLIST_H_
#define SAIL_ALGORITHM_DLIST_H_

#include <sail/algorithm.h>

SAIL_NAMESPACE_BEGIN

class DListNode: public ListNode<double> {
public:
    DListNode() = default;
    DListNode(double _content): ListNode<double>(_content) {} 
};

class DLinkList: public LinkList<double> {
public:
    DLinkList() = default;
    DLinkList(std::vector<DListNode>& _dvec) {
        std::vector<ListNode<double>> _vec;
        for (auto dnode : _dvec ) {
            _vec.push_back(ListNode<double>(dnode.content()));
        }
        LinkList<double>::setContent(_vec);
    }
};

SAIL_NAMESPACE_END

#endif // SAIL_ALGORITHM_DLIST_H_
