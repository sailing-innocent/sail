#pragma once
#ifndef SAIL_VISUALIZE_H_
#define SAIL_VISUALIZE_H_

/**
 * @file: include/sail/visualize.h
 * @author: sailing-innocent
 * @create: 2022-10-28
 * @desp: the visialization part of SAIL
*/

#include <sail/common.h>
#include <sail/math/vec4.hpp>

SAIL_NAMESPACE_BEGIN

class VisNode: public Base {
public:
    VisNode() = default;
    virtual ~VisNode() {}
    virtual void genING(std::vector<float>& fVertices, std::vector<uint16_t>& uIndices);
    const size_t subNodeCount() const { return mSubNodeCount; }

protected:
    size_t mSubNodeCount = 0;
    std::vector<VisNode*> mpSubNodes;
};

void VisNode::genING(std::vector<float>& fVertices, std::vector<uint16_t>& uIndices)
{
    for (auto i = 0; i < mSubNodeCount; i++) {
        std::vector<float> vf;
        std::vector<uint16_t> iu;
        mpSubNodes[i]->genING(vf, iu);
        for (auto j = 0; j < vf.size(); j++) {
            fVertices.push_back(vf[j]);
        }
        for (auto j = 0; j < iu.size(); j++) {
            uIndices.push_back(iu[j]);
        }
    }
}

class VTriangle : public VisNode {
public:
    VTriangle() = default;
    VTriangle(point& _p1, point& _p2, point& _p3): mP1(_p1), mP2(_p2), mP3(_p3) {}
    ~VTriangle() {}
    bool setP1(point& p) { mP1 = p; return true;}
    bool setP2(point& p) { mP2 = p; return true;}
    bool setP3(point& p) { mP3 = p; return true;}
    void genING(std::vector<float>& fVertices, std::vector<uint16_t>& uIndices)
    {
        fVertices.push_back(mP1[0]);
        fVertices.push_back(mP1[1]);
        fVertices.push_back(mP1[2]);
        fVertices.push_back(1.0f);
        fVertices.push_back(mC1[0]);
        fVertices.push_back(mC1[1]);
        fVertices.push_back(mC1[2]);
        fVertices.push_back(mC1[3]);

        fVertices.push_back(mP2[0]);
        fVertices.push_back(mP2[1]);
        fVertices.push_back(mP2[2]);
        fVertices.push_back(1.0f);
        fVertices.push_back(mC2[0]);
        fVertices.push_back(mC2[1]);
        fVertices.push_back(mC2[2]);
        fVertices.push_back(mC2[3]);

        fVertices.push_back(mP3[0]);
        fVertices.push_back(mP3[1]);
        fVertices.push_back(mP3[2]);
        fVertices.push_back(1.0f);
        fVertices.push_back(mC3[0]);
        fVertices.push_back(mC3[1]);
        fVertices.push_back(mC3[2]);
        fVertices.push_back(mC3[3]);

        uIndices.push_back(0);
        uIndices.push_back(1);
        uIndices.push_back(2);
    }
protected:
    point mP1;
    point mP2;
    point mP3;
    color mC1 = {1.0f, 0.0f, 0.0f, 1.0f}; 
    color mC2 = {0.0f, 1.0f, 0.0f, 1.0f}; 
    color mC3 = {0.0f, 0.0f, 1.0f, 1.0f};
};

SAIL_NAMESPACE_END

#endif // SAIL_VISUALIZE_H_
