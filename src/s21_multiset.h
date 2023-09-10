#ifndef _S21_MULTISET_H_
#define _S21_MULTISET_H_

#include "s21_tree.h"
#include "s21_comparator.h"

namespace s21
{

template <typename Type, 
          typename Comparator = ComparatorSet<Type>,
          typename Node = Tree::MultiNode<Type, std::ptrdiff_t>>
class MultiSet : public Tree::Tree<Type, Comparator, Node> {
public:
    using Base = Tree::Tree<Type, Comparator, Node>;

public:
    using Base::Base;

};

#endif  //  _S21_MULTISET_H_