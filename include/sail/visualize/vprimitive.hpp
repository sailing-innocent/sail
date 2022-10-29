#pragma once
#ifndef SAIL_VISUALIZE_VPRIMITIVE_H_
#define SAIL_VISUALIZE_VPRIMITIVE_H_
/**
 * @file: include/sail/visualize.hpp
 * @author: sailing-innocent
 * @create: 2022-10-29
 * @desp: the 
*/

#include <sail/visualize.h>

SAIL_NAMESPACE_BEGIN

/**
 * @class VMesh: Its subgeo should be triangles
*/

class VTriangle : public VisNode {
public:
    VTriangle() = default;
    VTriangle(point& _p1, point& _p2, point& _p3){
        std::cout << "Constucting Triangle ..." << std::endl;
        // generate colors
        point mP1 = _p1;
        point mP2 = _p2;
        point mP3 = _p3;
        color mC1 = {1.0f, 0.0f, 0.0f, 1.0f}; 
        color mC2 = {0.0f, 1.0f, 0.0f, 1.0f}; 
        color mC3 = {0.0f, 0.0f, 1.0f, 1.0f};
        mP1.out(mData);
        mC1.out(mData);
        mP2.out(mData);
        mC2.out(mData);
        mP3.out(mData);
        mC3.out(mData);
    }
    ~VTriangle() {
        std::cout << "Is desctructing Triangle" << std::endl;
    }
};

class VMesh: public VisNode {
public:
    VMesh() = default;
    ~VMesh() {}
protected:
};

class VQuatrangle: public VMesh {};
class VCube: public VMesh {};
class VCircle: public VMesh {};
class VSphere: public VMesh {};
class VPoint: public VMesh {};
class VLine: public VMesh {};

class VRectangle: public VQuatrangle{};


SAIL_NAMESPACE_END

#endif // SAIL_VISUALIZE_VPRIMITIVE_H_
