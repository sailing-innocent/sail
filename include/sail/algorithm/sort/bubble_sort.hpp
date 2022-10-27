#pragma once 
#ifndef SAIL_ALGORITHM_BUBBLE_SORT_H_
#define SAIL_ALGORITHM_BUBBLE_SORT_H_

#include <sail/algorithm.h>

SAIL_NAMESPACE_BEGIN

void bubble_sort_d(std::vector<double>& arr);

template <typename T>
LinkList<T>& bubble_sort_ll(LinkList<T>& lst) {
    for (auto j = lst.size()-1; j > 1; j--) {
        for (auto i = 0; i < j; i++) {
            if (lst[i].content() > lst[j].content()) {
                lst.swap(i, j);
            }
        }
    }
    return lst;
}

SAIL_NAMESPACE_END

#endif // SAIL_ALGORITHM_SELECT_KMAX_H_
