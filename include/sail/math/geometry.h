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
    GeoNode(const GeoNode& rhs) {
        mSubGeoCount = rhs.subsCount();
        mpSubGeos = rhs.subs();
    }
    GeoNode(std::vector<GeoNode*>& geos) {
        mSubGeoCount = geos.size();
        mpSubGeos = geos;
    }
    virtual ~GeoNode() {
        for (auto i = 0; i < mSubGeoCount; i++) {
            delete mpSubGeos[i];
        }
        mSubGeoCount = 0;
    }
    virtual GeoNode& operator=(const GeoNode& rhs) {
        mSubGeoCount = rhs.subsCount();
        mpSubGeos = rhs.subs();
        return *this;
    }
    virtual bool visualize(VisNode& root) {
        
        for (auto i = 0; i < mSubGeoCount; i++) {
            VisNode* pnewNode = new VisNode(); 
            mpSubGeos[i]->visualize(*pnewNode);
            root.append(*pnewNode);
        }
        return true;
    }
    size_t& subsCount() { return mSubGeoCount; }
    std::vector<GeoNode*>& subs() { return mpSubGeos; }
    const size_t subsCount() const { return mSubGeoCount; }
    const std::vector<GeoNode*> subs() const { return mpSubGeos; }
protected:
    size_t mSubGeoCount = 0;
    std::vector<GeoNode*> mpSubGeos;
};

/**
 * @class: Primitive
 * @desp: The Primitive class (and its derived class) has a 
 * float determine(point&)
 * method, which can determine a point is inside a primitive or not
*/

class Primitive: public GeoNode {
public:
    Primitive() = default;
    ~Primitive() {}
    virtual float determine() = 0;
protected:
    std::vector<float> mParams;
};

class Triangle: public GeoNode {
public:
    Triangle(point& p1, point& p2, point& p3): mPoints({p1, p2, p3}) {}
    ~Triangle() {}
    point& operator[](const size_t index) { return mPoints[index]; }
    const point operator[](const size_t index) const { return mPoints[index]; }
    bool visualize(VisNode& root);
protected: 
    std::array<point, 3> mPoints;
};

bool Triangle::visualize(VisNode& root) {
    VTriangle vtr(mPoints[0],mPoints[1],mPoints[2]);
    root.append(vtr);
    return true;
}

SAIL_NAMESPACE_END

#endif // SAIL_MATH_GEOMETRY_H_