#ifndef _S21_LIST_H_
#define _S21_LIST_H_

#include <new>  // new

namespace s21 {

    template <typename List>
    class ListIterator {
    private:
        using Value_type = typename List::value_type;
        using Reference = typename List::reference;
        using Const_reference = typename List::const_reference;
        using Pointer = typename List::pointer;
        using Const_pointer = typename List::const_pointer;
        using Node_type = typename List::Node;
        using Node_pointer = Node_type*;
        using Node_reference = Node_type&;
    
    public:
        ListIterator(Node_pointer pointer) :  pointer_(pointer) {};

        ListIterator& operator++() {
            // TODO: check if the next node exists?
            pointer_ = pointer_->next_;
            return *this;
        }

        ListIterator operator++(int) {
            ListIterator temporary(*this);
            // TODO: check if the next node exists?
            pointer_ = pointer_->next_;
            return temporary;
        }

        ListIterator& operator--() {
            // TODO: check if the previous node exists?
            pointer_ = pointer_->previous_;
            return *this;
        }

        ListIterator operator--(int) {
            ListIterator temporary(*this);
            // TODO: check if the previous node exists?
            pointer_ = pointer_->previous_;
            return temporary;
        }

        Reference operator*() {
            return pointer_->data_;
        }

        Const_reference operator*() const{
            return pointer_->data_;
        }

        Pointer operator->() {
            return &(pointer_->data_);
        }

        Const_pointer operator->() const {
            return &(pointer_->data_);
        }

        bool operator==(const ListIterator& iterator) const {
            return pointer_ == iterator->pointer_;
        }

        bool operator!=(const ListIterator& iterator) const {
            return !(*this == iterator);
        }

    private:
        Node_pointer pointer_;
    };


    template <typename Type>
    class List {
        friend class ListIterator<List<Type>>;
    private:
        using value_type = Type;
        // allocator_type	Allocator
        using size_type = std::size_t;  //	Unsigned integer type (usually std::size_t)
        // difference_type	Signed integer type (usually std::ptrdiff_t)
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*; 
        // Allocator::pointer	(until C++11)
        // std::allocator_traits<Allocator>::pointer	(since C++11)
        
        using const_pointer = const value_type*;	 
        // Allocator::const_pointer	(until C++11)
        // std::allocator_traits<Allocator>::const_pointer	(since C++11)
        
        using iterator = ListIterator<List<Type>>;
        // iterator	LegacyBidirectionalIterator to value_type
        // const_iterator	LegacyBidirectionalIterator to const value_type
        // reverse_iterator	std::reverse_iterator<iterator>
        // const_reverse_iterator	std::reverse_iterator<const_iterator>


    private:
        class Node {
            friend class ListIterator<List<Type>>;

            value_type data_;
            List* next_ = nullptr;
            List* previous_ = nullptr;
        } node_;

        size_type size_ = 0;

        Node* begin_ = nullptr;
        Node* end_ = nullptr;
        
    public:
        List() {};


        size_type Size() const {
            return size_;
        }

        iterator begin() {
            return iterator(begin_);
        }

        iterator cbegin() const {
            return iterator(begin_);
        }
    };

}  // namespace s21

#endif  //  _S21_LIST_H_
