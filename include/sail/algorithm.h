#pragma once
#ifndef SAIL_ALGORITHM
#define SAIL_ALGORITHM

/**
 * @file: include/sail/algorithm
 * @author: sailing-innocent
 * @create: 2022-10-21
 * @desp: The Header and Center file for sail algorithm
*/

#include "sail/common.h"

SAIL_NAMESPACE_BEGIN

#define SAIL_ARRAY_MAX 256

class Object: public Base {};

class Comparable: public Object {
public:
    virtual bool operator<(const Comparable & rhs) const = delete;
};

SAIL_NAMESPACE_END

#include <sail/algorithm/common/node.hpp>
#include <sail/algorithm/common/list.hpp>
#include <sail/algorithm/common/stack.hpp>
#include <sail/algorithm/common/queue.hpp>
#include <sail/algorithm/sort.hpp>
// #include <sail/algorithm/common/array.hpp>

#endif