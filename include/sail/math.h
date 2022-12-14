#pragma once
/**
 * @file: include/sail/math.h
 * @author: sailing-innocent
 * @desp: The Math Header Library
 * @create: 2022-10-15
*/

// originally I will use double for most precisions

#ifndef SAIL_MATH_H_
#define SAIL_MATH_H_

#include <sail/common.h>

SAIL_NAMESPACE_BEGIN

#define MAX_ARRAY_BUFSZ 10000

SAIL_NAMESPACE_END

#include <sail/math/arithmetic.h>
#include <sail/math/geometry.h>
#include <sail/math/statistic.h>

#endif // SAIL_MATH_H