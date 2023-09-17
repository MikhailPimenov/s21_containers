#ifndef _S21_MULTISET_H_
#define _S21_MULTISET_H_

#include <initializer_list>
#include "s21_multitree.h"
#include "s21_utility.h"

namespace s21
{

template <typename Value, 
          typename Comparator = Utility::Less<Value>>
class MultiSet : public MultiTree<Value,
                                  Value, 
                                  Comparator,
                                  Utility::KeyGetterSet<Value>>
{
    using Base = MultiTree<Value,
                           Value, 
                           Comparator,
                           Utility::KeyGetterSet<Value>>;
public:
    MultiSet() : Base() {}
    MultiSet(std::initializer_list<Value> list) : Base(list) {}

};

}   // namespase s21

#endif  //  _S21_MULTISET_H_