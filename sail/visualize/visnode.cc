#include <sail/visualize.h>

SAIL_NAMESPACE_BEGIN

void VisNode::genING(std::vector<float>& fVertices, std::vector<uint16_t>& uIndices, uint16_t start)
{
    uint16_t shift = static_cast<uint16_t>(mData.size() / 8);
    std::cout << "is generating node ING with " << shift << " items. " << std::endl;
    for (auto i = 0; i < mData.size(); i++) {
        fVertices.push_back(mData[i]);
    }
    
    for (auto i = 0; i < shift; i++) {
        uIndices.push_back(i + start);
    }
    
    for (auto i = 0; i < mSubNodeCount; i++) {
        std::vector<float> vf;
        std::vector<uint16_t> iu;
        mSubNodes[i].genING(vf, iu, start+shift);
        for (auto j = 0; j < vf.size(); j++) {
            fVertices.push_back(vf[j]);
        }
        for (auto j = 0; j < iu.size(); j++) {
            uIndices.push_back(iu[j]);
        }
        shift += static_cast<uint16_t>(vf.size() / 8);
    }
}

SAIL_NAMESPACE_END
