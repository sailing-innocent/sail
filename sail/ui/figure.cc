#include <sail/ui/figure.h>

SAIL_NAMESPACE_BEGIN

void drawRect2D(VisNode& root, float l, float b, float width, float height) {
    std::cout << "Drawing Rect: " << l << ", " << b << ", " << width << ", " << height << std::endl;
    point lb(l, b);
    sail::Rect2D rec(lb, width, height);
    sail::VisNode vn;
    rec.visualize(vn);
    root.append(vn);
}

bool Histogram2D::draw(VisNode& root) {
    float left = mLB[0] + mPaddingL;
    float buttom = mLB[1] + mPaddingB;
    float top = mLB[1] + mRelHeight - mPaddingT;
    float right = mLB[0] + mRelWidth - mPaddingR;
    std::cout << "DRAW REGION: [" << left << ", " << buttom << ", " << right << ", " << top << "]" << std::endl;

    const float histoRelWidth = 0.8f;
    const float leftRelPad = (1 - histoRelWidth) / 2;
    float fwidth = (right - left) / mCount;
    float width = fwidth * histoRelWidth;
    for (auto i = 0; i < mCount; i++) {
        float height = heights[i] * (top - buttom);
        float l = left + i * fwidth + leftRelPad * fwidth;
        drawRect2D(root, l, buttom, width, height);
    }
    return true;
}

SAIL_NAMESPACE_END
