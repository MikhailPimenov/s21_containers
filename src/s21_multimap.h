#ifndef _S21_MULTIMAP_H_
#define _S21_MULTIMAP_H_


#include <initializer_list>
#include "s21_multitree.h"
#include "s21_utility.h"

namespace s21 {

template <typename Key, 
          typename Value, 
          typename Comparator = Utility::Less<const Key>>
class MultiMap : public MultiTree<Key,
                                  std::pair<const Key, Value>, 
                                  Comparator,
                                  Utility::KeyGetterMap<Key, std::pair<const Key, Value>>>
{
    using Base = MultiTree<Key,
                           std::pair<const Key, Value>, 
                           Comparator,
                           Utility::KeyGetterMap<Key, std::pair<const Key, Value>>>;
public:
    MultiMap() : Base() {}
    MultiMap(std::initializer_list<std::pair<const Key, Value>> list) : Base(list) {}

};

}   // namespace s21

#endif  //  _S21_MULTIMAP_H_