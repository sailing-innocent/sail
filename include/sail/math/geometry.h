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
            VisNode newNode; 
            mpSubGeos[i]->visualize(newNode);
            root.append(newNode);
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
 * float determinate(point&)
 * method, which can determine a point is inside a primitive or not
*/
class Primitive: public GeoNode {
public:
    Primitive() = default;
    ~Primitive() {}
    virtual float determinate(point& p) = 0;
protected:
    std::vector<point> mPoints;
    std::vector<float> mParams;
};


class Triangle: public Primitive {
public:
    Triangle(point& p1, point& p2, point& p3): mPoints({p1, p2, p3}) {}
    ~Triangle() {}
    point& operator[](const size_t index) { return mPoints[index]; }
    const point operator[](const size_t index) const { return mPoints[index]; }
    bool visualize(VisNode& root);
    float determinate(point& p) override;
protected: 
    std::vector<point> mPoints;
};

class Rect2D: public Primitive {
public:
    Rect2D() = default;
    Rect2D(point& lb = point(), float width = 0.2f, float height=0.1f) {
        point lt(lb[0], lb[1] + height);
        point rb(lb[0]+width, lb[1]);
        point rt(lb[0]+width, lb[1]+height); 
        mPoints.push_back(lb);
        mPoints.push_back(rb);
        mPoints.push_back(lt);
        mPoints.push_back(rt);
    }
    bool visualize(VisNode& root);
    float determinate(point& p) override;
    ~Rect2D() {
        std::cout << "is desctructing rect2d" << std::endl;
    }
};

class Line: public Primitive {
public:
    Line() = default;
    ~Line() {}
    float determinate(point& p) override;
protected:
    std::vector<point> mPoints;
    std::vector<float> mParams;
};


SAIL_NAMESPACE_END

#endif // SAIL_MATH_GEOMETRY_H_