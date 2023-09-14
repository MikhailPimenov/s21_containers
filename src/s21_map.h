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

    class Handler;

    using node_type = Handler;

    class Handler {
    private:
        typename Base::base_node_pointer pointer_;
    
    public:
        Handler(typename Base::base_node_pointer pointer) : pointer_{pointer} {}

        Handler(const Handler& other) = delete; // запретили создавать копированием

        Handler& operator=(const Handler& other) = delete; // запретили копировать 

        Handler(Handler&& other) noexcept : pointer_{other.pointer_} {
            other.pointer_ = nullptr;
        }

        typename Base::base_node_pointer operator->() {
            return pointer_;
        }
        typename Base::base_node_pointer operator->() const {
            return pointer_;
        }

        typename Base::reference Get() {
            return pointer_->value_;
        }
        typename Base::const_reference Get() const {
            return pointer_->value_;
        }

        Handler& operator=(Handler&& other) noexcept {
            if(this == &other)
                return *this;

            this->~Handler();
            pointer_ = other.pointer_;
            other.pointer_ = nullptr;
            return *this;
        }

        ~Handler() {
            delete pointer_;
        }
    }; /// smart ass

    Handler Extract(typename Base::const_iterator pos) {
        typename Base::base_node_pointer node = Base::Extract(pos);
        Handler result(node);
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
