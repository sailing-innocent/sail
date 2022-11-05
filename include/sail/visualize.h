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
#include <sail/math/arithmetic.h>

SAIL_NAMESPACE_BEGIN

class VisNode: public Base {
public:
    VisNode() {
        // std::cout << "Constructing VisNode" << std::endl;
    };
    VisNode(const VisNode& node) {
        // std::cout << "Constructing VisNode with " << node.subNodeCount() << " subnodes" << std::endl;
        mSubNodeCount = node.subNodeCount();
        std::vector<float> _data = node.data();
        for (auto i = 0; i < _data.size(); i++) {
            mData.push_back(_data[i]);
        }
        for (auto i = 0; i < node.subNodeCount(); i++) {
            mSubNodes.push_back(node[i]);
        }
    }
    virtual ~VisNode() {
        // std::cout << "Destructing VisNode with "<< mSubNodeCount << " subnodes." << std::endl;
        for (auto i = 0; i < mSubNodeCount; i++) {
            // delete mSubNodes[i];
        }
    }
    virtual const VisNode operator[](size_t index) const { return mSubNodes[index]; }
    virtual VisNode& operator[](size_t index) { return mSubNodes[index]; }

    virtual void genING(std::vector<float>& fVertices, std::vector<uint16_t>& uIndices, uint16_t start = 0);
    const size_t subNodeCount() const { return mSubNodeCount; }
    virtual bool append(VisNode& node) {
        // std::cout << "is appending node with " << node.subNodeCount() << " subnodes" << std::endl;
        mSubNodes.push_back(node);
        mSubNodeCount++;
        return true;
    }
    virtual std::vector<float>& data() { return mData; }
    virtual const std::vector<float> data() const { return mData; }
protected:
    size_t mSubNodeCount = 0;
    std::vector<VisNode> mSubNodes;
    std::vector<float> mData;
};


void VisRefine(std::vector<float>& fVertices, std::vector<uint16_t>& uIndices, uint16_t start);

SAIL_NAMESPACE_END

#include <sail/visualize/vprimitive.hpp>

#endif // SAIL_VISUALIZE_H_
