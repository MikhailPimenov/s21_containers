#ifndef _S21_MULTITREE_H_
#define _S21_MULTITREE_H_


#include <utility>
#include <initializer_list>
#include "s21_list.h"
#include "s21_tree.h"
#include "s21_comparator.h"

#include <iostream> // TODO: remove

namespace s21 {

template <typename TreeIterator, typename NodeIterator, typename Pointer, typename Reference>
class MultiTreeIteratorBase {

protected:
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
    Pointer operator->() const {
        return nodeIterator_.operator->();
    }
    Reference operator*() {
        return nodeIterator_.operator*();
    }
    Reference operator*() const {
        return nodeIterator_.operator*();
    }

    MultiTreeIteratorBase& operator++() {
        if (treeIterator_ == treeBeforeBegin_ || nodeIterator_ == --(treeIterator_->end())) {
            ++treeIterator_;
            if (treeIterator_ != treeEnd_)
                nodeIterator_ = treeIterator_->begin();
            return *this;
        }
        ++nodeIterator_;
        return *this;
    }
    MultiTreeIteratorBase& operator--() {
        if (treeIterator_ == treeEnd_ || nodeIterator_ == treeIterator_->begin()) {
            --treeIterator_;
            if (treeIterator_ != treeBeforeBegin_)
                nodeIterator_ = --(treeIterator_->end());
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

    template <typename OtherTreeIterator, typename OtherNodeIterator, typename OtherPointer, typename OtherReference>
    explicit operator MultiTreeIterator<OtherTreeIterator, OtherNodeIterator, OtherPointer, OtherReference>() {
        return MultiTreeIterator<OtherTreeIterator, OtherNodeIterator, OtherPointer, OtherReference>(static_cast<OtherTreeIterator>(this->treeIterator_),
                                                                                                     static_cast<OtherTreeIterator>(this->treeBeforeBegin_),
                                                                                                     static_cast<OtherTreeIterator>(this->treeEnd_),
                                                                                                     static_cast<OtherNodeIterator>(this->nodeIterator_));
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


    template <typename OtherTreeIterator, typename OtherNodeIterator, typename OtherPointer, typename OtherReference>
    explicit operator MultiTreeReverseIterator<OtherTreeIterator, OtherNodeIterator, OtherPointer, OtherReference>() {
        return MultiTreeReverseIterator<OtherTreeIterator, OtherNodeIterator, OtherPointer, OtherReference>(static_cast<OtherTreeIterator>(this->treeIterator_),
                                                                                                            static_cast<OtherTreeIterator>(this->treeBeforeBegin_),
                                                                                                            static_cast<OtherTreeIterator>(this->treeEnd_),
                                                                                                            static_cast<OtherNodeIterator>(this->nodeIterator_));
    }

};


template <typename Key, 
          typename Value, 
          typename Comparator,
          typename KeyGetter>
class MultiTree
{



public:
    using value_type        = Value;
    using mapped_type       = value_type;
    using key_type          = Key;
    using size_type         = std::size_t;
    using difference_type   = std::ptrdiff_t;
    using reference         = value_type&;
    using const_reference   = const value_type&;
    using pointer           = value_type*;
    using const_pointer     = const value_type*;

private:
    using aggregator_type   = List<value_type>;

private:

    class ComparatorTree {
    private:
        Comparator comparator_;
        KeyGetter keyGetter_;
    public:
        bool operator()(const Key& left, const aggregator_type& right) const {
            return comparator_(left, keyGetter_(*(right.begin())));
        }
        bool operator()(const aggregator_type& left, const Key& right) const {
            return comparator_(keyGetter_(*(left.begin())), right);
        }
        bool operator()(const aggregator_type& left, const aggregator_type& right) const {
            return comparator_(keyGetter_(*(left.begin())), keyGetter_(*(right.begin())));
        }
    };



private:
    using tree_type         = Tree::Tree<const Key, aggregator_type, ComparatorTree>;

public:
    using node_type         = typename aggregator_type::node_type;  // handler which forbids copying and is responsible for destruction 

public:
    using iterator                  = MultiTreeIterator<typename tree_type::iterator, typename aggregator_type::iterator, pointer, reference>;
    using const_iterator            = MultiTreeIterator<typename tree_type::const_iterator, typename aggregator_type::const_iterator, const_pointer, const_reference>;
    using reverse_iterator          = MultiTreeReverseIterator<typename tree_type::iterator, typename aggregator_type::iterator, pointer, reference>;
    using const_reverse_iterator    = MultiTreeReverseIterator<typename tree_type::const_iterator, typename aggregator_type::const_iterator, const_pointer, const_reference>;

private:
    tree_type tree_;
    size_type size_;

private:
    KeyGetter keyGetter_;

public:
    MultiTree() : size_{0ull} {}
    MultiTree(std::initializer_list<value_type> list) : MultiTree() {
        for (const auto& element : list) 
            Insert(element);
    }

    MultiTree(const MultiTree& other) : tree_{other.tree_}, size_{other.size_} {}
    MultiTree(MultiTree&& other) : MultiTree() {
        *this = std::move(other);
    }
    MultiTree& operator=(const MultiTree& other) {
        if (this == &other)
            return *this;
        MultiTree temporary(other);
        *this = std::move(temporary);
        return *this;
    }
    MultiTree& operator=(MultiTree&& other) {
        if (this == &other)
            return *this;
        size_ = other.size_;
        tree_ = std::move(other.tree_);

        other.size_ = 0ull;
        return *this;
    }

    std::pair<iterator, bool> Insert(const_reference value) {
        typename tree_type::iterator it = tree_.Find(keyGetter_(value));
        ++size_;

        if (it == tree_.end()) {
            aggregator_type list;
            list.Push_back(std::move(value));
            auto [added_it, _] = tree_.Insert(list);
            return {iterator(added_it, --(tree_.begin()), tree_.end(), added_it->begin()), true};
        }

        it->Push_back(value);
        return {iterator(it, --(tree_.begin()), tree_.end(), --(it->end())), true};
    }

    iterator Erase(const_iterator pos) {
        typename tree_type::iterator it = tree_.Find(keyGetter_(*pos));
        assert(it != tree_.end() && "Tried to erase not existing element!");
        --size_;
        if (it->Size() > 1ull) {
            typename aggregator_type::iterator next_it = it->Erase(it->begin());
            return iterator(it, --(tree_.begin()), tree_.end(), next_it);

        }
        typename tree_type::iterator next_it = tree_.Erase(it);
        return iterator(next_it, --(tree_.begin()), tree_.end(), next_it->begin());
    }

    node_type Extract(const_iterator pos) {
        typename tree_type::iterator it = tree_.Find(keyGetter_(*pos));
        --size_;
        if(it->Size() > 1ull) {
            for(auto nodeIt = it->begin(); nodeIt != it->end(); ++nodeIt) {
                if(*nodeIt == *pos)
                    return it->Extract(nodeIt);
            }
        }

        typename tree_type::node_pointer node = tree_.Extract(it); 
        node_type result(node->value_.Extract(node->value_.begin()));
        delete node;
        node = nullptr;
        return result;
    }

    node_type Extract(iterator pos) {
        auto it = static_cast<const_iterator>(pos);
        return Extract(it);
    }


    size_type Size() const noexcept {
        return size_;
    }
    size_type Height() const noexcept {
        return tree_.Height();
    }

    iterator Find(const key_type& key) {
        typename tree_type::iterator it =  tree_.Find(key);
        return iterator(it, --(tree_.begin()), tree_.end(), it->begin());
    }
    const_iterator Find(const key_type& key) const {
        typename tree_type::const_iterator it =  tree_.Find(key);
        return const_iterator(it, --(tree_.begin()), tree_.end(), it->begin());
    }

    bool Contains(const key_type& key) const {
        return tree_.Contains(key);
    }

    iterator Lower_bound(const key_type& key) {
        typename tree_type::iterator it =  tree_.Lower_bound(key);
        return iterator(it, --(tree_.begin()), tree_.end(), it->begin());
    }

    const_iterator Lower_bound(const key_type& key) const {
        typename tree_type::const_iterator it =  tree_.Lower_bound(key);
        return const_iterator(it, --(tree_.begin()), tree_.end(), it->begin());
    }

    iterator Upper_bound(const key_type& key) {
        typename tree_type::iterator it =  tree_.Upper_bound(key);
        return iterator(it, --(tree_.begin()), tree_.end(), it->begin());
    }
    const_iterator Upper_bound(const key_type& key) const {
        typename tree_type::const_iterator it =  tree_.Upper_bound(key);
        return const_iterator(it, --(tree_.begin()), tree_.end(), it->begin());
    }

    std::pair<iterator, iterator> Equal_range(const key_type& key) {
        std::pair<typename tree_type::iterator, typename tree_type::iterator> pair = tree_.Equal_range(key);
        return std::make_pair(iterator(pair.first, --(tree_.begin()), tree_.end(), pair.first->begin()), iterator(pair.second, --(tree_.begin()), tree_.end(), pair.second->begin()));
    }
    std::pair<const_iterator, const_iterator> Equal_range(const key_type& key) const {
        std::pair<typename tree_type::const_iterator, typename tree_type::const_iterator> pair = tree_.Equal_range(key);
        return std::make_pair(const_iterator(pair.first, --(tree_.begin()), tree_.end(), pair.first->begin()), const_iterator(pair.second, --(tree_.begin()), tree_.end(), pair.second->begin()));
    }

    bool Empty() const noexcept {
        assert(((tree_.Empty() && !size_) || (!tree_.Empty() && size_)) && "Size should be 0 when and only when tree is empty");
        return tree_.Empty();
    }

    void Clear() noexcept {
        tree_.Clear();
        size_ = 0ull;
    }

    iterator begin() {
        typename tree_type::iterator treeIt = tree_.begin();
        typename aggregator_type::iterator aggregatorIt = treeIt->begin();
        return iterator(treeIt, --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_iterator begin() const {
        typename tree_type::const_iterator treeIt = tree_.begin();
        typename aggregator_type::const_iterator aggregatorIt = treeIt->begin();
        return const_iterator(treeIt, --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_iterator cbegin() const {
        return begin();
    }
    iterator end() {
        typename tree_type::iterator treeIt = --(tree_.end());
        typename aggregator_type::iterator aggregatorIt = treeIt->end();
        return iterator(tree_.end(), --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_iterator end() const {
        typename tree_type::const_iterator treeIt = --(tree_.end());
        typename aggregator_type::const_iterator aggregatorIt = treeIt->end();
        return const_iterator(tree_.end(), --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_iterator cend() const {
        return end();
    }

    reverse_iterator rbegin() {
        typename tree_type::iterator treeIt = --(tree_.end());
        typename aggregator_type::iterator aggregatorIt = --(treeIt->end());
        return reverse_iterator(treeIt, --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_reverse_iterator rbegin() const {
        typename tree_type::const_iterator treeIt = --(tree_.end());
        typename aggregator_type::const_iterator aggregatorIt = --(treeIt->end());
        return const_reverse_iterator(treeIt, --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_reverse_iterator crbegin() const {
        return rbegin();
    }
    reverse_iterator rend() {
        typename tree_type::iterator treeIt = tree_.begin();
        typename aggregator_type::iterator aggregatorIt = --(treeIt->begin());
        return reverse_iterator(--treeIt, --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_reverse_iterator rend() const {
        typename tree_type::const_iterator treeIt = tree_.begin();
        typename aggregator_type::const_iterator aggregatorIt = --(treeIt->begin());
        return const_reverse_iterator(--treeIt, --(tree_.begin()), tree_.end(), aggregatorIt);
    }
    const_reverse_iterator crend() const {
        return rend();
    }
};










template <typename Key, typename Type, typename Comparator, typename GetKey>
bool operator==(const s21::MultiTree<Key, Type, Comparator, GetKey>& left, const s21::MultiTree<Key, Type, Comparator, GetKey>& right) {
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
#endif  //  _S21_MULTITREE_H_