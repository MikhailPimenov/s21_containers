#ifndef _S21_LIST_H_
#define _S21_LIST_H_

#include <cassert>
#include <new>
#include <initializer_list>
#include <iterator>

namespace s21
{




template <typename List> class ConstListIterator
{
public:
        // using std::iterator_traits<ConstListIterator>::difference_type = typename List::difference_type;
        // using std::iterator_traits<ConstListIterator>::value_type = typename List::value_type;
        // using std::iterator_traits<ConstListIterator>::pointer = typename List::const_pointer;
        // using std::iterator_traits<ConstListIterator>::reference = typename List::const_reference;
        // using std::iterator_traits<ConstListIterator>::iterator_category = bidirectional_iterator_tag;

        using difference_type = typename List::difference_type;
        using value_type = typename List::value_type;
        using pointer = typename List::const_pointer;
        using reference = typename List::const_reference;
        using iterator_category = std::bidirectional_iterator_tag;

    // std::iterator_traits<It>::reference

  public:
    // using iterator_category = std::bidirectional_iterator_tag;
//   private:
    using Value_type = typename List::value_type;
    // using value_type = Value_type;
    // using Reference = typename List::reference;
    using Const_reference = typename List::const_reference;
    using const_reference = Const_reference;
    // using Pointer = typename List::pointer;
    using Const_pointer = typename List::const_pointer;
    using const_pointer = Const_pointer;
    using Node_type = typename List::Node;
    // using Node_pointer = Node_type *;
    using Const_node_pointer = const Node_type *;
    using Node_reference = Node_type &;

  public:
    ConstListIterator(Const_node_pointer node_pointer) : node_pointer_{node_pointer} {};

    ConstListIterator(const ConstListIterator& other) : ConstListIterator(other.node_pointer_) {};
    ConstListIterator(ConstListIterator&& other) : ConstListIterator(other.node_pointer_) {
        other.node_pointer_ = nullptr;
    };
    friend void swap(ConstListIterator& left, ConstListIterator& right) {
        using namespace std;    // to enable ADL
        swap(left.node_pointer_, right.node_pointer_);
    };

    ConstListIterator& operator=(const ConstListIterator& other)
    {
        node_pointer_ = other->node_pointer_;
        return *this;
    };

    ConstListIterator& operator=(ConstListIterator&& other)
    {
        node_pointer_ = other->node_pointer_;
        other->node_pointer_ = nullptr;
        return *this;
    }


    ConstListIterator &operator++()
    {
        node_pointer_ = node_pointer_->next_;
        return *this;
    }

    ConstListIterator operator++(int)
    {
        ConstListIterator temporary(*this);
        node_pointer_ = node_pointer_->next_;
        return temporary;
    }

    ConstListIterator &operator--()
    {
        node_pointer_ = node_pointer_->previous_;
        return *this;
    }

    ConstListIterator operator--(int)
    {
        ConstListIterator temporary(*this);
        node_pointer_ = node_pointer_->previous_;
        return temporary;
    }

    Const_reference operator*() const
    {
        return node_pointer_->data_;
    }

    Const_pointer operator->() const
    {
        return &(node_pointer_->data_);
    }

    bool operator==(const ConstListIterator &other) const
    {
        return node_pointer_ == other.node_pointer_;
    }

    bool operator!=(const ConstListIterator &other) const
    {
        return !(*this == other);
    }

    operator bool() const
    {
        return node_pointer_;
    }
    
  private:
    Const_node_pointer node_pointer_;
};


template <typename List> class ListIterator
{
  private:
    using Value_type = typename List::value_type;
    using Reference = typename List::reference;
    // using Const_reference = typename List::const_reference;
    using Pointer = typename List::pointer;
    // using Const_pointer = typename List::const_pointer;
    using Node_type = typename List::Node;
    using Node_pointer = Node_type *;
    // using Const_node_pointer = const Node_pointer;
    using Node_reference = Node_type &;

  public:
    ListIterator(Node_pointer node_pointer) : node_pointer_{node_pointer}{};

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

    Reference operator*()
    {
        return node_pointer_->data_;
    }

    // Const_reference operator*() const
    // {
    //     return node_pointer_->data_;
    // }

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
    friend class ConstListIterator<List<Type>>;

  private:
    using value_type = Type;
    // allocator_type	Allocator
    using size_type = std::size_t; //	Unsigned integer type (usually
                                   // std::size_t)
    using difference_type = std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    // Allocator::pointer	(until C++11)
    // std::allocator_traits<Allocator>::pointer	(since C++11)

    using const_pointer = const value_type *;
    // Allocator::const_pointer	(until C++11)
    // std::allocator_traits<Allocator>::const_pointer	(since C++11)

  public:
    using iterator = ListIterator<List<Type>>;
    using const_iterator = ConstListIterator<List<Type>>;
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
