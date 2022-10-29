/**
 * @file: sail/math/geometry_primitive.c
 * @author: sailing-innocent
 * @desp: the implementation for geoemtry Primitive Class
 * @create: 2022-10-29
*/

#include <sail/math/geometry.h>

SAIL_NAMESPACE_BEGIN


bool Triangle::visualize(VisNode& root) {
    VTriangle vtr(mPoints[0],mPoints[1],mPoints[2]);
    root.append(vtr);
    return true;
}

float Triangle::determinate(point& p) {
    // positive outside, negative inside
    return 1.0;
}

float Line::determinate(point& p) {
    // we can define a line by two points
    point p1 = mPoints[0];
    point p2 = mPoints[1];
    vec4f p1p2 = p2 - p1;
    vec4f p1p = p - p1;
    float det = (p1p - (p1p2 * p1p)/(p1p2 * p1p2) * p1p2).norm();
    return det;
}

bool Rect2D::visualize(VisNode& root) {
    VTriangle vtr1(mPoints[0], mPoints[1], mPoints[2]);
    VTriangle vtr2(mPoints[2], mPoints[1], mPoints[3]);
    root.append(vtr1);
    root.append(vtr2);
    return true;
}

float Rect2D::determinate(point& p) {
    return 1.0f;
}

SAIL_NAMESPACE_END

