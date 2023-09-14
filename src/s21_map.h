#ifndef _S21_MAP_H_
#define _S21_MAP_H_

// #include <cassert>
// #include <initializer_list>
// #include <iterator>
// #include <new>
// #include <cstring>
// #include <vector>

// #include "s21_list.h"
// #include "s21_vector.h"
// #include "tests/vector_helpers.h"   // TODO: remove from here and add everywhere map is printed

#include "s21_tree.h"
#include "s21_comparator.h"

namespace s21
{

template <typename Key, typename Pair, typename ComparatorKey>
class ComparatorMap {
private:
    ComparatorKey comparator_;
public:
    bool operator()(const Pair& left, const Pair& right) const {
        return comparator_(left.first, right.first);
    }
    bool operator()(const Key& left, const Pair& right) const {
        return comparator_(left, right.first);
    }
    bool operator()(const Pair& left, const Key& right) const {
        return comparator_(left.first, right);
    }
};

template <typename Key, 
          typename Value, 
          typename Comparator = Less<const Key>>
class Map : public Tree::Tree<Key,
                              std::pair<const Key, Value>, 
                              ComparatorMap<const Key, std::pair<const Key, Value>, Comparator>>
{
    using Base = Tree::Tree<Key,
                            std::pair<const Key, Value>, 
                            ComparatorMap<const Key, std::pair<const Key, Value>, Comparator>>;

public:
    using Base::Base;

    using node_type = Handler<typename Base::base_node_pointer, typename Base::reference>;

    node_type Extract(typename Base::const_iterator pos) {
        typename Base::base_node_pointer node = Base::Extract(pos);
        node_type result(node);
        return result;
    } 
};

template <typename Key, typename Type>
bool operator==(const s21::Map<Key, Type>& left, const s21::Map<Key, Type>& right) {
    if(left.Size() != right.Size())
        return false;

    auto it_left = left.cbegin();
    auto it_right = right.cbegin();


    while(it_left != left.cend()) {
        if(*it_left != *it_right)
            return false;

        ++it_left;
        ++it_right;

    }

    return true;
}



} // namespace s21


#endif //  _S21_MAP_H_
