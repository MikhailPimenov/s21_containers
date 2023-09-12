#ifndef _S21_MULTIMAP_H_
#define _S21_MULTIMAP_H_


#include <list>
#include <utility>
#include <initializer_list>
#include "s21_list.h"
#include "s21_tree.h"
#include "s21_comparator.h"

#include <iostream>

namespace s21 {

template <typename TreeIterator, typename NodeIterator, typename Pointer, typename Reference>
class MultiTreeIteratorBase {

private:
    TreeIterator treeIterator_;
    TreeIterator treeBeforeBegin_;
    TreeIterator treeEnd_;
    NodeIterator nodeIterator_;

public:
    MultiTreeIteratorBase(TreeIterator treeIterator, 
                          TreeIterator treeBeforeBegin, 
                          TreeIterator treeEnd, 
                          NodeIterator nodeIterator) : 
                          treeIterator_{treeIterator}, 
                          treeBeforeBegin_{treeBeforeBegin}, 
                          treeEnd_{treeEnd}, 
                          nodeIterator_{nodeIterator} {}
    MultiTreeIteratorBase(const MultiTreeIteratorBase& other) : 
                          treeIterator_{other.treeIterator_}, 
                          treeBeforeBegin_{other.treeBeforeBegin_}, 
                          treeEnd_{other.treeEnd_}, 
                          nodeIterator_{other.nodeIterator_} {}
    
    MultiTreeIteratorBase& operator=(const MultiTreeIteratorBase& other) {
        treeIterator_ = other.treeIterator_;
        treeBeforeBegin_ = other.treeBeforeBegin_;
        treeEnd_ = other.treeEnd_;
        nodeIterator_ = other.nodeIterator_;
    }

    bool operator==(const MultiTreeIteratorBase& other) const noexcept {
        if (treeIterator_ == treeEnd_ && other.treeIterator_ == treeIterator_)
            return true;
        if (treeIterator_ == treeBeforeBegin_ && other.treeIterator_ == treeIterator_)
            return true;
            
        return other.treeIterator_ == treeIterator_ && 
               other.nodeIterator_ == nodeIterator_ &&
               other.treeBeforeBegin_ == treeBeforeBegin_ && 
               other.treeEnd_ == treeEnd_;
    }

    bool operator!=(const MultiTreeIteratorBase& other) const noexcept {
        return !(other == *this);
    }

    Pointer operator->() {
        return nodeIterator_.operator->();
    }
    Reference operator*() {
        return nodeIterator_.operator*();
    }

    MultiTreeIteratorBase& operator++() {
        if (treeIterator_ == treeBeforeBegin_ || nodeIterator_ == --(treeIterator_->second.end())) {
            ++treeIterator_;
            if (treeIterator_ != treeEnd_)
                nodeIterator_ = treeIterator_->second.begin();
            return *this;
        }
        ++nodeIterator_;
        return *this;
    }
    MultiTreeIteratorBase& operator--() {
        if (treeIterator_ == treeEnd_ || nodeIterator_ == treeIterator_->second.begin()) {
            --treeIterator_;
            if (treeIterator_ != treeBeforeBegin_)
                nodeIterator_ = --(treeIterator_->second.end());
            return *this;
        }
        --nodeIterator_;
        return *this;
    }
};

template <typename TreeIterator, typename NodeIterator, typename Pointer, typename Reference>
class MultiTreeIterator : public MultiTreeIteratorBase<TreeIterator, NodeIterator, Pointer, Reference> {

    using Base = MultiTreeIteratorBase<TreeIterator, NodeIterator, Pointer, Reference>;
public:
    using Base::Base;

public:
    MultiTreeIterator& operator++() {
        Base::operator++();
        return *this;
    }
    MultiTreeIterator& operator--() {
        Base::operator--();
        return *this;
    }
    MultiTreeIterator operator++(int) {
        const MultiTreeIterator temporary(*this);
        Base::operator++();
        return temporary;
    }
    MultiTreeIterator operator--(int) {
        const MultiTreeIterator temporary(*this);
        Base::operator--();
        return temporary;
    }
};
template <typename TreeIterator, typename NodeIterator, typename Pointer, typename Reference>
class MultiTreeReverseIterator : public MultiTreeIteratorBase<TreeIterator, NodeIterator, Pointer, Reference> {
    using Base = MultiTreeIteratorBase<TreeIterator, NodeIterator, Pointer, Reference>;
public:
    using Base::Base;

public:
    MultiTreeReverseIterator& operator++() {
        Base::operator--();
        return *this;
    }
    MultiTreeReverseIterator& operator--() {
        Base::operator++();
        return *this;
    }
    MultiTreeReverseIterator operator++(int) {
        const MultiTreeReverseIterator temporary(*this);
        Base::operator--();
        return temporary;
    }
    MultiTreeReverseIterator operator--(int) {
        const MultiTreeReverseIterator temporary(*this);
        Base::operator++();
        return temporary;
    }
};

template <typename Key, 
          typename Type, 
          typename Comparator = Less<const Key>>
class MultiMap
{



public:
    using value_type        = std::pair<const Key, Type>;
    using mapped_type       = Type;
    using key_type          = Key;
    using size_type         = std::size_t;
    using difference_type   = std::ptrdiff_t;
    using reference         = value_type&;
    using const_reference   = const value_type&;
    using pointer           = value_type*;
    using const_pointer     = const value_type*;

private:
    using aggregator_type   = std::list<value_type>;

private:
    template <typename KeyComparator>
    class TreeComparator {
    private:
        KeyComparator comparator_;
    public:
        bool operator()(const key_type& left, const std::pair<const Key, aggregator_type>& right) const {
            return comparator_(left, right.first);
        }
        bool operator()(const std::pair<const Key, aggregator_type>& left, const key_type& right) const {
            return comparator_(left.first, right);
        }
        bool operator()(const std::pair<const Key, aggregator_type>& left, const std::pair<const Key, aggregator_type>& right) const {
            return comparator_(left.first, right.first);
        }
    };


private:
    using tree_type         = Tree::Tree<const Key, std::pair<const Key, aggregator_type>, TreeComparator<Comparator>>;

public:
    using iterator                  = MultiTreeIterator<typename tree_type::iterator, typename aggregator_type::iterator, pointer, reference>;
    using const_iterator            = MultiTreeIterator<typename tree_type::const_iterator, typename aggregator_type::const_iterator, const_pointer, const_reference>;
    using reverse_iterator          = MultiTreeReverseIterator<typename tree_type::iterator, typename aggregator_type::iterator, pointer, reference>;
    using const_reverse_iterator    = MultiTreeReverseIterator<typename tree_type::const_iterator, typename aggregator_type::const_iterator, const_pointer, const_reference>;

private:
    tree_type tree_;
    size_type size_;

public:
    MultiMap() : size_{0ull} {}
    MultiMap(std::initializer_list<value_type> list) : MultiMap() {
        for (const auto& element : list) 
            Insert(element);
    }

    MultiMap(const MultiMap& other) : tree_{other.tree_}, size_{other.size_} {}
    MultiMap(MultiMap&& other) : MultiMap() {
        *this = std::move(other);
    }
    MultiMap& operator=(const MultiMap& other) {
        if (this == &other)
            return *this;
        MultiMap temporary(other);
        *this = std::move(temporary);
        return *this;
    }
    MultiMap& operator=(MultiMap&& other) {
        if (this == &other)
            return *this;
        size_ = other.size_;
        tree_ = std::move(other.tree_);

        other.size_ = 0ull;
        return *this;
    }

    std::pair<iterator, bool> Insert(const_reference value) {
        typename tree_type::iterator it = tree_.find(value.first);
        ++size_;

        if (it == tree_.end()) {
            aggregator_type list;
            list.push_back(value);
            auto [added_it, _] = tree_.Insert(std::make_pair(value.first, list));
            return {iterator(added_it, --(tree_.begin()), tree_.end(), added_it->second.begin()), true};
        }

        it->second.push_back(value);
        return {iterator(it, --(tree_.begin()), tree_.end(), --(it->second.end())), true};
    }



    size_type Size() const noexcept {
        return size_;
    }

    iterator begin() {
        typename tree_type::iterator treeIt = tree_.begin();
        typename aggregator_type::iterator aggregatorIt = treeIt->second.begin();
        return iterator(treeIt, --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_iterator begin() const {
        typename tree_type::const_iterator treeIt = tree_.begin();
        typename aggregator_type::const_iterator aggregatorIt = treeIt->second.begin();
        return const_iterator(treeIt, --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_iterator cbegin() const {
        return begin();
    }
    iterator end() {
        typename tree_type::iterator treeIt = --(tree_.end());
        typename aggregator_type::iterator aggregatorIt = treeIt->second.end();
        return iterator(tree_.end(), --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_iterator end() const {
        typename tree_type::const_iterator treeIt = --(tree_.end());
        typename aggregator_type::const_iterator aggregatorIt = treeIt->second.end();
        return const_iterator(tree_.end(), --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_iterator cend() const {
        return end();
    }

    reverse_iterator rbegin() {
        typename tree_type::iterator treeIt = --(tree_.end());
        typename aggregator_type::iterator aggregatorIt = --(treeIt->second.end());
        return reverse_iterator(treeIt, --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_reverse_iterator rbegin() const {
        typename tree_type::const_iterator treeIt = --(tree_.end());
        typename aggregator_type::const_iterator aggregatorIt = --(treeIt->second.end());
        return const_reverse_iterator(treeIt, --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_reverse_iterator crbegin() const {
        return rbegin();
    }
    reverse_iterator rend() {
        typename tree_type::iterator treeIt = tree_.begin();
        typename aggregator_type::iterator aggregatorIt = --(treeIt->second.begin());
        return reverse_iterator(--treeIt, --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_reverse_iterator rend() const {
        typename tree_type::const_iterator treeIt = tree_.begin();
        typename aggregator_type::const_iterator aggregatorIt = --(treeIt->second.begin());
        return const_reverse_iterator(--treeIt, --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_reverse_iterator crend() const {
        return rend();
    }
};










template <typename Key, typename Type>
bool operator==(const s21::MultiMap<Key, Type>& left, const s21::MultiMap<Key, Type>& right) {
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

}
#endif  //  _S21_MULTIMAP_H_