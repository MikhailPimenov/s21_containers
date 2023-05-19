#ifndef _S21_LIST_H_
#define _S21_LIST_H_

#include <cassert>
#include <new>

namespace s21
{





template <typename List> class ListIterator
{
  private:
    using Value_type = typename List::value_type;
    using Reference = typename List::reference;
    using Const_reference = typename List::const_reference;
    using Pointer = typename List::pointer;
    using Const_pointer = typename List::const_pointer;
    using Node_type = typename List::Node;
    using Node_pointer = Node_type *;
    using Const_node_pointer = const Node_pointer;  // the wrong place of * after expanding: should be const List::Node* but actually List::Node* const
    using Node_reference = Node_type &;

  public:
    ListIterator(Node_pointer node_pointer) : node_pointer_{node_pointer}{};

    ListIterator &operator++()
    {
        // TODO: check if the next node exists?
        node_pointer_ = node_pointer_->next_;
        return *this;
    }

    ListIterator operator++(int)
    {
        ListIterator temporary(*this);
        // TODO: check if the next node exists?
        node_pointer_ = node_pointer_->next_;
        return temporary;
    }

    ListIterator &operator--()
    {
        // TODO: check if the previous node exists?
        node_pointer_ = node_pointer_->previous_;
        return *this;
    }

    ListIterator operator--(int)
    {
        ListIterator temporary(*this);
        // TODO: check if the previous node exists?
        node_pointer_ = node_pointer_->previous_;
        return temporary;
    }

    Reference operator*()
    {
        return node_pointer_->data_;
    }

    Const_reference operator*() const
    {
        return node_pointer_->data_;
    }

    // Pointer operator->()
    // {
    //     return &(node_pointer_->data_);
    // }

    // Const_pointer operator->() const
    // {
    //     return &(node_pointer_->data_);
    // }

    bool operator==(const ListIterator &iterator) const
    {
        return node_pointer_ == iterator.node_pointer_;
    }

    bool operator!=(const ListIterator &iterator) const
    {
        return !(*this == iterator);
    }

  private:
    Node_pointer node_pointer_;
};

template <typename Type> class List
{
    friend class ListIterator<List<Type>>;

  private:
    using value_type = Type;
    // allocator_type	Allocator
    using size_type = std::size_t; //	Unsigned integer type (usually
                                   // std::size_t)
    // difference_type	Signed integer type (usually std::ptrdiff_t)
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    // Allocator::pointer	(until C++11)
    // std::allocator_traits<Allocator>::pointer	(since C++11)

    using const_pointer = const value_type *;
    // Allocator::const_pointer	(until C++11)
    // std::allocator_traits<Allocator>::const_pointer	(since C++11)

    using iterator = ListIterator<List<Type>>;
    // iterator	LegacyBidirectionalIterator to value_type
    // const_iterator	LegacyBidirectionalIterator to const value_type
    // reverse_iterator	std::reverse_iterator<iterator>
    // const_reverse_iterator	std::reverse_iterator<const_iterator>

  private:
    struct Node
    {
        value_type data_;
        Node *next_;
        Node *previous_;
    };

    Node *first_existing_;
    Node *last_existing_;
    Node end_;

    size_type size_;

  public:
    List() 
        : first_existing_{nullptr}, 
          last_existing_{nullptr}, 
          end_{}, 
          size_{0ull} {

    };

    ~List() {
        Clear();
    }

    void Clear() {
        while(!Empty())
            Pop_back();
    }

    bool Empty() const noexcept {
        return size_ == 0ull;
    }

    size_type Size() const
    {
        return size_;
    }

    iterator begin()
    {
        return iterator(first_existing_);
    }

    // iterator cbegin() const
    // {
    //     return const_iterator(first_existing_);
    // }

    iterator end() 
    {
        return iterator(&end_);
    }

    // iterator cend() const
    // {
    //     return const_iterator(&end_);
    // }

    void Push_back(const_reference data)
    {
        Node *new_node = new Node;
        new_node->data_ = data;

        new_node->previous_ = last_existing_;
        new_node->next_ = nullptr;

        if (size_) {
            assert(last_existing_ && "Last existing node is nullptr!");
            last_existing_->next_ = new_node;
        }
        else {
            first_existing_ = new_node;
        }

        last_existing_ = new_node;

        last_existing_->next_ = &end_;
        end_.previous_ = last_existing_;

        ++size_;
    };

    void Pop_back()
    {
        // std::cout << "Pop_back(): size_ is " << size_ << '\n';
        assert(size_ >= 1ull && "Pop_back() from empty list!");

        if (size_ == 1ull) {
            delete last_existing_;
            --size_;
            return;
        }

        assert(last_existing_->previous_ && "Previous pointer in last existing node is nullptr!");
        Node* previous = last_existing_->previous_;
        delete last_existing_;

        previous->next_ = &end_;
        last_existing_ = previous;

        --size_;
    }
};

} // namespace s21

#endif //  _S21_LIST_H_
