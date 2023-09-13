#ifndef _S21_MULTIMAP_H_
#define _S21_MULTIMAP_H_


// #include <utility>
#include <initializer_list>
// #include "s21_list.h"
#include "s21_multitree.h"
// #include "s21_comparator.h"

// #include <iostream> // TODO: remove

namespace s21 {

// template<typename Pair, typename ComparatorKey>
// class ComparatorMap 
// {
// private:
//     ComparatorKey comparator_;
// public:
//     bool operator()(const Pair& left, const Pair& right) const noexcept {
//         return comparator_(left.first, right.first);
//     }
// };

template<typename Key, typename Pair>
class KeyGetterMap {
public:
    const Key& operator()(const Pair& pair) const {
        return pair.first;
    }
};



template <typename Key, 
          typename Value, 
          typename Comparator = Less<const Key>>
class MultiMap : public MultiTree<Key,
                                  std::pair<const Key, Value>, 
                                  Comparator,
                                  KeyGetterMap<Key, std::pair<const Key, Value>>>
{
    using Base = MultiTree<Key,
                           std::pair<const Key, Value>, 
                           Comparator,
                           KeyGetterMap<Key, std::pair<const Key, Value>>>;
public:
    // using Base::Base;
    MultiMap() : Base() {}
    MultiMap(std::initializer_list<std::pair<const Key, Value>> list) : Base(list) {}

};

}   // namespace s21

#endif  //  _S21_MULTIMAP_H_