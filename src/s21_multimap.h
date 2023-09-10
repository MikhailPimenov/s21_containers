#ifndef _S21_MULTIMAP_H_
#define _S21_MULTIMAP_H_

#include <utility>
#include "s21_tree.h"
#include "s21_comparator.h"

namespace s21 {


template <typename Key, 
          typename Type, 
          typename Comparator = ComparatorMap<std::pair<const Key, Type>>,
          typename Node = Tree::MultiNode<std::pair<const Key, Type>, std::ptrdiff_t>>
class MultiMap : public Tree::Tree<std::pair<const Key, Type>, 
                                   Comparator, 
                                   Node> 
{
public:
    using Base = Tree::Tree<std::pair<const Key, Type>, 
                            Comparator, 
                            Node>;
public:
    using value_type        = typename Base::value_type;
    using mapped_type       = Type;
    using key_type          = Key;
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
};

}
#endif  //  _S21_MULTIMAP_H_