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

};




// template <typename Key, 
//           typename Type, 
//           typename Comparator = ComparatorMap<std::pair<const Key, Type>>,
//           typename Node = Tree::SingleNode<std::pair<const Key, Type>, std::ptrdiff_t>>
// class Map : public Tree::Tree<std::pair<const Key, Type>, 
//                               Comparator, 
//                               Node> {

// public:
//     using Base = Tree::Tree<std::pair<const Key, Type>, 
//                             Comparator, 
//                             Node>;

// public:
//     using value_type        = typename Base::value_type;
//     using mapped_type       = Type;
//     using key_type          = Key;
//     using size_type         = typename Base::size_type;
//     using difference_type   = typename Base::difference_type;
//     using reference         = typename Base::reference;
//     using const_reference   = typename Base::const_reference;
//     using pointer           = typename Base::pointer;
//     using const_pointer     = typename Base::const_pointer;

// public:
//     using iterator                  = typename Base::iterator;
//     using const_iterator            = typename Base::const_iterator;
//     using reverse_iterator          = typename Base::reverse_iterator;
//     using const_reverse_iterator    = typename Base::const_reverse_iterator;

// public:
//     using Base::Base;





//     iterator Find(const key_type& key) {
//         return this->find(value_type(key, mapped_type()));
//     }
//     const_iterator Find(const key_type& key) const {
//         return this->find(value_type(key, mapped_type()));
//     }
//     bool Contains(const key_type& key) const {
//         return this->contains(value_type(key, mapped_type()));
//     }
//     iterator Lower_bound(const Key& key) {
//         return this->lower_bound(value_type(key, mapped_type()));
//     }
//     const_iterator Lower_bound(const Key& key) const {
//         return this->lower_bound(value_type(key, mapped_type()));
//     }
//     iterator Upper_bound(const Key& key) {
//         return this->upper_bound(value_type(key, mapped_type()));
//     }
//     const_iterator Upper_bound(const Key& key) const {
//         return this->upper_bound(value_type(key, mapped_type()));
//     }

//     std::pair<iterator, iterator> Equal_range(const Key& key) {
//         return this->equal_range(value_type(key, mapped_type()));
//     }
//     std::pair<const_iterator, const_iterator> Equal_range(const Key& key) const {
//         return this->equal_range(value_type(key, mapped_type()));
//     }
// };


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
