#include <sail/visualize.h>

SAIL_NAMESPACE_BEGIN

void VisNode::genING(std::vector<float>& fVertices, std::vector<uint16_t>& uIndices, uint16_t start)
{
    uint16_t shift = static_cast<uint16_t>(mData.size() / 8);
    // std::cout << "is generating node ING with " << shift << " items. " << std::endl;
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
    // std::cout << "Current verts: " << fVertices.size() << std::endl;

    VisRefine(fVertices, uIndices, start);
}

void indexCover(std::vector<uint16_t>& uIndicies, uint16_t _i, uint16_t _j)
{
    // make sure _i < _j
    for (auto i = 0; i < uIndicies.size(); i++) {
        if (uIndicies[i] == _j) {
            uIndicies[i] = _i;
        }
    }
}

void VisRefine(std::vector<float>& fVertices, std::vector<uint16_t>& uIndices, uint16_t start)
{
    const size_t stride = 8;
    const size_t shift = 3;
    const size_t nItems = fVertices.size() / stride;
    // std::cout << "IS REFINING MESH with: " << nItems << " Vertices" << std::endl;
    size_t validItems = nItems;
    for (auto i = 0; i < validItems-1; i++) {
        size_t j = i+1;

        while(j < validItems) {
            bool flag = true;
            for (auto s=0; s< shift; s++) {
                if (fVertices[i*stride+s] != fVertices[j*stride+s]) {
                    flag = false; break;
                }
            }
    
            // std::cout << "::IS COMPARING " << i << " and " << j << " with result: "<< flag <<std::endl;
        
            if (flag) {
                indexCover(uIndices, start+i, start+j);
                indexCover(uIndices, start+j, start+validItems-1);
                size_t swapI = j;
                size_t swapJ = validItems-1;
                float temp;
                for (auto t = 0; t < stride; t++) {
                    temp = fVertices[swapI*stride+t];
                    fVertices[swapI*stride+t] = fVertices[swapJ*stride+t];
                    fVertices[swapJ*stride+t] = temp;
                }
                validItems--;
                j--;
            }
            j++;
            // std::cout << "CURRENT VALIDATE ITEMS: " << validItems << std::endl;
        }
    }

    fVertices.resize(validItems * stride);
}




SAIL_NAMESPACE_END
