#ifndef _S21_SET_H_
#define _S21_SET_H_

#include "s21_tree.h"
#include "s21_comparator.h"

namespace s21
{

template <typename Type, 
          typename Comparator = ComparatorSet<Type>,
          typename Node = Tree::SingleNode<Type, std::ptrdiff_t>>
class Set : public Tree::Tree<Type, Comparator, Node> {
public:
    using Base = Tree::Tree<Type, Comparator, Node>;


public:
    using value_type        = typename Base::value_type;
    using mapped_type       = typename Base::value_type;
    using key_type          = typename Base::value_type;
    using size_type         = typename Base::size_type;
    using difference_type   = typename Base::difference_type;
    using reference         = typename Base::reference;
    using const_reference   = typename Base::const_reference;
    using pointer           = typename Base::pointer;
    using const_pointer     = typename Base::const_pointer;

public:
    using iterator                  = typename Base::iterator;
    using const_iterator            = typename Base::const_iterator;
    using reverse_iterator          = typename Base::reverse_iterator;
    using const_reverse_iterator    = typename Base::const_reverse_iterator;


public:
    using Base::Base;



    iterator Find(const key_type& key) {
        return this->find(key);
    }
    const_iterator Find(const key_type& key) const {
        return this->find(key);
    }
    bool Contains(const key_type& key) const {
        return this->contains(key);
    }
    iterator Lower_bound(const key_type& key) {
        return this->lower_bound(key);
    }
    const_iterator Lower_bound(const key_type& key) const {
        return this->lower_bound(key);
    }
    iterator Upper_bound(const key_type& key) {
        return this->upper_bound(key);
    }
    const_iterator Upper_bound(const key_type& key) const {
        return this->upper_bound(key);
    }

    std::pair<iterator, iterator> Equal_range(const key_type& key) {
        return this->equal_range(key);
    }
    std::pair<const_iterator, const_iterator> Equal_range(const key_type& key) const {
        return this->equal_range(key);
    }

};

template<typename Type, typename Comperator>
bool operator==(const s21::Set<Type, Comperator>& left, const s21::Set<Type, Comperator>& right) {
    if(left.Size() != right.Size())
        return false;
    
    auto s21_it = left.cbegin();
    auto it = right.cbegin();


    while(s21_it != left.cend()) {
        if(*s21_it != *it) 
            return false;
        
        ++s21_it;
        ++it; 
    }

    return true;   
}

}   // namespace s21

#endif  //  _S21_SET_H_