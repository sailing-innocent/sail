#pragma once
#ifndef SAIL_COMMON
#define SAIL_COMMON

#define SAIL_NAMESPACE_BEGIN namespace sail {
#define SAIL_NAMESPACE_END }

#include <iostream>

SAIL_NAMESPACE_BEGIN

class ObjectBase {
public:
    ObjectBase() = default;
    virtual ~ObjectBase() {}
    ObjectBase& operator=() = delete;
    ObjectBase(const ObjectBase&) = delete;
    ObjectBase(ObjectBase&&) = delete;
    ObjectBase& operator=(ObjectBase&&) = delete;
};

class Object: public ObjectBase {};

class Comparable: public Object {
public:
    virtual bool operator<(const Comparable & rhs) const = delete;
};

SAIL_NAMESPACE_END

#endif