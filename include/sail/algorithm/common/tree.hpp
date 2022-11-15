#pragma once
#ifndef SAIL_ALGORITHM_COMMON_TREE_H_
#define SAIL_ALGORITHM_COMMON_TREE_H_

/**
 * @file: include/sail/algorithm/common/tree.hpp
 * @author: sailing-innocent
 * @create: 2022-11-15
 * @desp: My Sail Tree header
*/

#include <sail/algorithm.h>

SAIL_NAMESPACE_BEGIN

template <typename T>
class TreeNode: public Node<T>
{
public:
    TreeNode() = default;
    explicit TreeNode(T _content): Node<T>(_content) {}
    const TreeNode<T>& firstChild() const { return *mpFirstChild; }
    const TreeNode<T>& nextSibling() const { return *mpNextSibling; }
    bool setFirstChild(TreeNode<T>& _node) { mpFirstChild = &_node; return true; }
    bool setNextSibling(TreeNode<T>& _node) { mpNextSibling = &_node; return true; }
protected:
    TreeNode<T>* mpFirstChild;
    TreeNode<T>* mpNextSibling;
};

template <typename T>
class Tree: public Node<TreeNode<T>>
{
public:
    Tree() = default;
    Tree(TreeNode<T>& _node): Node<TreeNode<T>>(_node) {}
    TreeNode<T>& root() { return mContent; }
};


SAIL_NAMESPACE_END

#endif // SAIL_ALGORITHM_COMMON_TREE_H_
