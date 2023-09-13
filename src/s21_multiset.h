#ifndef _S21_MULTISET_H_
#define _S21_MULTISET_H_

#include "s21_multitree.h"
#include "s21_comparator.h"

namespace s21
{

template <typename Type, 
          typename Comparator = Less<Type>>
class MultiSet : public MultiTree<Type, Type, Comparator> {
public:
    using Base = MultiTree<Type, Type, Comparator>;

public:
    using Base::Base;

};

#endif  //  _S21_MULTISET_H_