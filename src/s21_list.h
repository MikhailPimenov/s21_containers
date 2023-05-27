#ifndef _S21_LIST_H_
#define _S21_LIST_H_

#include <cassert>
#include <new>
#include <initializer_list>
#include <iterator>

namespace s21
{




template <typename List, 
          typename Pointer = typename List::pointer, 
          typename Reference = typename List::reference,
          typename Node_pointer = typename List::node_pointer> 
class ListIterator
{
public:
    using difference_type = typename List::difference_type;
    using value_type = typename List::value_type;
    using pointer = Pointer;
    using reference = Reference;
    using iterator_category = std::bidirectional_iterator_tag;

    using node_type = typename List::Node;
    using node_pointer = Node_pointer;

  public:
    ListIterator(node_pointer node_pointer) : node_pointer_{node_pointer} {};

    ListIterator(const ListIterator& other) : ListIterator(other.node_pointer_) {};
    ListIterator(ListIterator&& other) : ListIterator(other.node_pointer_) {
        other.node_pointer_ = nullptr;
    };

    friend void swap(ListIterator& left, ListIterator& right) {
        using namespace std;    // to enable ADL
        swap(left.node_pointer_, right.node_pointer_);
    };

    ListIterator& operator=(const ListIterator& other)
    {
        node_pointer_ = other->node_pointer_;
        return *this;
    };

    ListIterator& operator=(ListIterator&& other)
    {
        node_pointer_ = other->node_pointer_;
        other->node_pointer_ = nullptr;
        return *this;
    }

    ListIterator &operator++()
    {
        node_pointer_ = node_pointer_->next_;
        return *this;
    }

    ListIterator operator++(int)
    {
        ListIterator temporary(*this);
        node_pointer_ = node_pointer_->next_;
        return temporary;
    }

    ListIterator &operator--()
    {
        node_pointer_ = node_pointer_->previous_;
        return *this;
    }

    ListIterator operator--(int)
    {
        ListIterator temporary(*this);
        node_pointer_ = node_pointer_->previous_;
        return temporary;
    }

    reference operator*() const
    {
        return node_pointer_->data_;
    }

    pointer operator->() const
    {
        return &(node_pointer_->data_);
    }

    bool operator==(const ListIterator &other) const
    {
        return node_pointer_ == other.node_pointer_;
    }

    bool operator!=(const ListIterator &other) const
    {
        return !(*this == other);
    }

    operator bool() const
    {
        return node_pointer_;
    }
    
private:
    node_pointer node_pointer_;
};

template <typename Type> class List
{
    
    struct Node;
    using node_pointer = Node*;
    using const_node_pointer = const Node*;

  private:
    using value_type = Type;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;

public:
    friend class ListIterator<List<Type>>;
    friend class ListIterator<List<Type>, const_pointer, const_reference, const_node_pointer>; 

  public:
    using iterator = ListIterator<List<Type>>;
    using const_iterator = ListIterator<List<Type>, const_pointer, const_reference, const_node_pointer>;

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

    explicit List(size_type count) : List() {
        for (size_type i = 0ull; i < count; ++i)
            Push_back(value_type());
    }

    List(size_type count, const_reference value) : List() {
        for (size_type i = 0ull; i < count; ++i)
            Push_back(value);
    }

    template<typename IntupIterator>
    List(IntupIterator first, IntupIterator last) : List() {
        for (auto it = first; it != last; ++it)
            Push_back(*it);
    }

    // TODO: refactor rule of 5
    List(const List& other) : List() {
        for (auto it = other.cbegin(); it != other.cend(); ++it)
            Push_back(*it);
    }
    // TODO: refactor rule of 5
    List(List&& other) : 
    first_existing_{other.first_existing_}, 
    last_existing_{other.last_existing_},
    size_{other.size_}{
        last_existing_->next_ = &end_;

        other.first_existing_ = nullptr;
        other.last_existing_ = nullptr;
        other.size_ = 0ull;
    }

    // TODO: refactor rule of 5
    List& operator=(const List& other) {
        if (this == &other)
            return *this;

        List copy(other);
        *this = std::move(copy);   // operator=(List&&)
        return *this;
    }

    // TODO: refactor rule of 5
    List& operator=(List&& other) {
        if (this == &other) // TODO: remove??
            return *this;

        Clear();

        first_existing_ = other.first_existing_;
        last_existing_ = other.last_existing_;
        last_existing_->next_ = &end_;
        size_ = other.size_;

        other.first_existing_ = nullptr;
        other.last_existing_ = nullptr;
        other.size_ = 0ull;

        return *this;
    }

    List(const std::initializer_list<value_type>& list) : List() {
        for (const auto& element : list)
            Push_back(element);
    };


    ~List() 
    {
        Clear();
    }

    void Clear() 
    {
        while(!Empty())
            Pop_back();
    }

    bool Empty() const noexcept 
    {
        return size_ == 0ull;
    }

    size_type Size() const
    {
        return size_;
    }

    iterator begin()
    {
        return first_existing_ ? iterator(first_existing_) : iterator(&end_);
    }

    const_iterator cbegin() const
    {
        return first_existing_ ? const_iterator(first_existing_) : const_iterator(&end_);
    }

    iterator end() 
    {
        return iterator(&end_);
    }

    const_iterator cend() const
    {
        return const_iterator(&end_);
    }

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

    // Max_size()
    // Insert()
    // Assign()
    // Merge()
    // Push_front()
    void Push_front(const_reference data)
    {
        Node *new_node = new Node;
        new_node->data_ = data;

        new_node->previous_ = nullptr;
        new_node->next_ = first_existing_;

        if (size_) {
            assert(first_existing_ && "First existing node is nullptr!");
            first_existing_->previous_ = new_node;
        }
        else {
            last_existing_ = new_node;
        }

        first_existing_ = new_node;

        ++size_;
    };
    void Pop_front()
    {
        assert(size_ >= 1ull && "Pop_back() from empty list!");

        if (size_ == 1ull) {
            delete first_existing_;
            --size_;
            return;
        }

        assert(first_existing_->next_ && "Next pointer in first existing node is nullptr!");
        Node* next = first_existing_->next_;
        delete first_existing_;

        first_existing_ = next;

        --size_;
    }
    // Swap()
    // Rule of 5
    // Front()
    reference Front() 
    {
        assert(!Empty() && "Front() from empty list!");
        return *begin();
    }
    const_reference Front() const 
    {
        assert(!Empty() && "Front() from empty list!");
        return *cbegin();
    }
    // Back()
    reference Back() 
    {
        assert(!Empty() && "Back() from empty list!");
        return *(--end());
    }
    const_reference Back() const 
    {
        assert(!Empty() && "Back() from empty list!");
        return *(--cend());
    }

    // Erase()
    // Sort()
    // Unique()
    // Splice()
    // Emplace_back()
    // Emplace_front()
};

template<typename Type>
bool operator==(const List<Type>& left, const List<Type>& right) {
    if (left.Size() != right.Size())
        return false;


    auto left_iterator = left.cbegin();
    auto right_iterator = right.cbegin();

    while (left_iterator != left.cend()) {
        if (*left_iterator != *right_iterator)
            return false;
        ++left_iterator;
        ++right_iterator;
    }

    return true;
}


} // namespace s21

#endif //  _S21_LIST_H_
