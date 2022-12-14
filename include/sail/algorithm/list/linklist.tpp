#ifndef SAIL_ALGORITHM_LINKLIST_TPP_
#define SAIL_ALGORITHM_LINKLIST_TPP_

#include <sail/common.h>

SAIL_NAMESPACE_BEGIN

template<typename T>
bool LinkList<T>::setContent(std::vector<ListNode<T>>& vec) {
    mSize = vec.size();
    mContent.resize(mSize);
    if (mSize < 2) { 
        return true; 
    }
    for (auto i = 0; i < mSize; i++) {
        mContent[i].setContent(vec[i].content());
    }
    for (auto i = 0; i < mSize; i++) {
        if ( i == 0 ) {
            mContent[i].setNext(mContent[i+1]);
        } else if ( i == mSize-1 ) {
            mContent[i].setPrev(mContent[i-1]);
        } else {
            mContent[i].setNext(mContent[i+1]);
            mContent[i].setPrev(mContent[i-1]);
        }
    }
    return true;
}

template <typename T>
bool LinkList<T>::append(T val) {

    ListNode<T> ln(val);
    
    mContent.push_back(ln);
    
    if (mSize == 0) {
        mSize++;
        return true;    
    }
    mContent[mSize-1].setNext(mContent[mSize]);
    mContent[mSize].setPrev(mContent[mSize-1]);
    mSize++;
    return true;
}

template <typename T>
bool LinkList<T>::insert(size_t index, T val) {
    if (mSize == 0 || index >= mSize) {
        return append(val);
    }
    ListNode<T> ln(val);

    if (index <= 0) {
        ln.setNext(mContent[0]);
        mContent[0].setPrev(ln);
        mContent.insert(mContent.begin(), ln);
    } else {
        ln.setNext(mContent[index]);
        ln.setPrev(mContent[index-1]);
        mContent[index-1].setNext(ln);
        mContent[index].setPrev(ln);
        mContent.insert(mContent.begin()+index-1, ln);
    }
    mSize++;
    return true;
}


template <typename T>
bool LinkList<T>::del(size_t index)
{
    if (mSize == 0 || mSize <= index || index < 0) {
        return false;
    }
    if (mSize == 1) {
        mContent.erase(mContent.begin());
        mSize--;
        return true;
    }
    if (index == 0 || index == mSize-1) {} else {
        mContent[index-1].setNext(mContent[index+1]);
        mContent[index+1].setPrev(mContent[index-1]);
    }
    mContent.erase(mContent.begin()+index-1);
    mSize--;
    return true;
}

template <typename T>
bool LinkList<T>::swap(size_t i, size_t j)
{
    const T datai = mContent[i].content();
    const T dataj = mContent[j].content();
    mContent[i].setContent(dataj);
    mContent[j].setContent(datai);
    return true;
}

SAIL_NAMESPACE_END

#endif // SAIL_ALGORITHM_LINKLIST_TPP_