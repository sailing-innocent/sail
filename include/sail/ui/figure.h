#pragma once
#ifndef SAIL_UI_FIGURE_H_
#define SAIL_UI_FIGURE_H_

/**
 * @file: include/sail/ui/figure
 * @author: sailing-innocent
 * @create: 2022-10-30
 * @desp: The ui-figure header file
*/

#include <sail/common.h>
#include <sail/math/geometry.h>

SAIL_NAMESPACE_BEGIN

class Figure: public Base {
public:
    Figure(
        point& _lb = point(), 
        float _width = 0.9f,
        float _height= 0.9f
    ):
        mRelWidth(_width),
        mRelHeight(_height),
        mLB(_lb),
        mBackground(Rect2D(_lb, _width, _height))
    {
        std::cout << "Figure is constructing..." << std::endl;
    };
    ~Figure() {
        std::cout << "Figure is destructed" << std::endl;
    }
    virtual bool draw(VisNode& root) { mBackground.visualize(root); return true; }
protected:
    float mRelWidth = 0.9f;
    float mRelHeight = 0.9f;
    point mLB = point();
    Rect2D mBackground;
};

class Histogram2D: public Figure {
public:
    Histogram2D(): Figure() {};
    Histogram2D(std::vector<float>& _listofdata, float _max, float _min) {
        mCount = _listofdata.size();
        for (auto data: _listofdata) {
            heights.push_back((data-_min)/(_max-_min));
        }
    }
    ~Histogram2D() {}
    bool draw(VisNode& root);
protected:
    size_t mCount = 0;
    std::vector<float> heights;
    float mPaddingL = 0.1f;
    float mPaddingR = 0.1f;
    float mPaddingT = 0.1f;
    float mPaddingB = 0.1f;
};

SAIL_NAMESPACE_END

#endif // SAIL_UI_FIGURE_H_
