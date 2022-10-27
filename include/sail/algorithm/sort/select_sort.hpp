#pragma once
#ifndef SAIL_ALGORITHM_SELECT_SORT_H_
#define SAIL_ALGORITHM_SELECT_SORT_H_

#include <sail/algorithm.h>

SAIL_NAMESPACE_BEGIN

template <typename T>
LinkList<T>& select_sort_ll(LinkList<T>& lst) {
    for (auto i = 1; i < lst.size() - 1; i ++ ) {
        for (auto j = 0; j < i; j++) {
            if (lst[i].content() < lst[j].content()) {
                lst.swap(i, j);
            }
        }
    }
    return lst;
}

SAIL_NAMESPACE_END

#endif // SAIL_ALGORITHM_SELECT_SORT_H_