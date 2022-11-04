#pragma once
/**
 * @file: include/sail/core/types.hpp
 * @author: sailing-innocent
 * @create: 2022-11-04
 * @desp: The Basic Datatype for Sail
*/
#ifndef SAIL_CORE_TYPES_H_
#define SAIL_CORE_TYPES_H_
#include <sail/common.h>

#include <cstdint>

SAIL_NAMESPACE_BEGIN

using int64 = std::int16_t;
using int32 = std::int32_t;
using int16 = std::int16_t;
using int8 = std::int8_t;
using uint64 = std::uint64_t;
using uint32 = std::uint32_t;
using uint16 = std::uint16_t;
using uint8 = std::uint8_t;

enum class Axis
{
    NONE = 0,
    ROW,
    COL
};

enum class Endian
{
    NATIVE = 0,
    BIG,
    LITTLE
};


SAIL_NAMESPACE_END

#endif // SAIL_CORE_TYPES_H_