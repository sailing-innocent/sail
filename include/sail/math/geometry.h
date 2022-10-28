#pragma once
#ifndef SAIL_MATH_GEOMETRY_H_
#define SAIL_MATH_GEOMETRY_H_

/**
 * @file: include/sail/math/geometry.h
 * @author: sailing-innocent
 * @create: 2022-10-28
 * @desp: The SAIL MATH GEOMETRY LIB Header
*/

#include <sail/math.h>
#include <sail/visualize.h>

SAIL_NAMESPACE_BEGIN

class GeoNode: public Base {
public:
    GeoNode() = default;
    virtual ~GeoNode() {}
    virtual bool visualize(VisNode& root) {
        // TODO: NOT CLEAR
        return true;
    }
protected:
    size_t mSubGeoCount = 0;
    std::vector<GeoNode*> mpSubGeos;
};

class Triangle: public GeoNode {
public:
    Triangle(point& p1, point& p2, point& p3): mPoints({p1, p2, p3}) {}
    ~Triangle() {}
    point& operator[](const size_t index) { return mPoints[index]; }
    const point operator[](const size_t index) const { return mPoints[index]; }
    bool visualize(VTriangle& vtr);
protected: 
    std::array<point, 3> mPoints;
};

bool Triangle::visualize(VTriangle& vtr) {
    vtr.setP1(mPoints[0]);
    vtr.setP2(mPoints[1]);
    vtr.setP3(mPoints[2]);
    return true;
}

SAIL_NAMESPACE_END

#endif // SAIL_MATH_GEOMETRY_H_