#pragma once
#ifndef SAIL_COMMON
#define SAIL_COMMON

#define SAIL_NAMESPACE_BEGIN namespace sail {
#define SAIL_NAMESPACE_END }

#include <iostream>
#include <vector>

SAIL_NAMESPACE_BEGIN

class Base {
public:
    Base() = default;
    virtual ~Base() {}
};

SAIL_NAMESPACE_END

#endif