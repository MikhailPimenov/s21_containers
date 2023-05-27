#ifndef _S21_LIST_H_
#define _S21_LIST_H_

#include <cassert>
#include <new>
#include <initializer_list>
#include <iterator>

namespace s21
{




template <typename List, 
          typename Pointer, 
          typename Reference,
          typename Node_pointer,
          typename Difference_type,
          typename Value_type
        //   typename Node_type
          >
class ListIteratorBase
{
    friend List;

public:
    using difference_type = Difference_type;
    using value_type = Value_type;
    using pointer = Pointer;
    using reference = Reference;
    using iterator_category = std::bidirectional_iterator_tag;

    // using node_type = Node_type;
    using node_pointer = Node_pointer;

  public:
    ListIteratorBase(node_pointer node_pointer) : node_pointer_{node_pointer} {};

    ListIteratorBase(const ListIteratorBase& other) : ListIteratorBase(other.node_pointer_) {};
    ListIteratorBase(ListIteratorBase&& other) : ListIteratorBase(other.node_pointer_) {
        other.node_pointer_ = nullptr;
    };

    friend void swap(ListIteratorBase& left, ListIteratorBase& right) {
        using namespace std;    // to enable ADL
        swap(left.node_pointer_, right.node_pointer_);
    };

    ListIteratorBase& operator=(const ListIteratorBase& other)
    {
        node_pointer_ = other->node_pointer_;
        return *this;
    };

    ListIteratorBase& operator=(ListIteratorBase&& other)
    {
        node_pointer_ = other->node_pointer_;
        other->node_pointer_ = nullptr;
        return *this;
    }

    reference operator*() const
    {
        return node_pointer_->data_;
    }

    pointer operator->() const
    {
        return &(node_pointer_->data_);
    }

    bool operator==(const ListIteratorBase &other) const
    {
        return node_pointer_ == other.node_pointer_;
    }

    bool operator!=(const ListIteratorBase &other) const
    {
        return !(*this == other);
    }

    operator bool() const
    {
        return node_pointer_;
    }

private:
    node_pointer get() 
    {
        return node_pointer_;
    }
    
protected:
    node_pointer node_pointer_;
};

template <typename List, 
          typename Pointer = typename List::pointer, 
          typename Reference = typename List::reference> 
class ListIterator : 
public ListIteratorBase <List,
                         Pointer, 
                         Reference, 
                         typename List::node_pointer, 
                         typename List::difference_type, 
                         typename List::value_type> {

private:
    using Base = ListIteratorBase <List, Pointer, Reference, typename List::node_pointer, typename List::difference_type, typename List::value_type>;

public:
    using Base::Base;

    ListIterator &operator++()
    {
        this->node_pointer_ = this->node_pointer_->next_;
        return *this;
    }

    ListIterator operator++(int)
    {
        ListIterator temporary(*this);
        this->node_pointer_ = this->node_pointer_->next_;
        return temporary;
    }

    ListIterator &operator--()
    {
        this->node_pointer_ = this->node_pointer_->previous_;
        return *this;
    }

    ListIterator operator--(int)
    {
        ListIterator temporary(*this);
        this->node_pointer_ = this->node_pointer_->previous_;
        return temporary;
    }
};

template <typename List, 
          typename Pointer = typename List::pointer, 
          typename Reference = typename List::reference> 
class ListReverseIterator : 
public ListIteratorBase <List,
                         Pointer, 
                         Reference, 
                         typename List::node_pointer, 
                         typename List::difference_type, 
                         typename List::value_type> {

private:
    using Base = ListIteratorBase <List, Pointer, Reference, typename List::node_pointer, typename List::difference_type, typename List::value_type>;

public:
    using Base::Base;

    ListReverseIterator &operator++()
    {
        this->node_pointer_ = this->node_pointer_->previous_;
        return *this;
    }

    ListReverseIterator operator++(int)
    {
        ListReverseIterator temporary(*this);
        this->node_pointer_ = this->node_pointer_->previous_;
        return temporary;
    }

    ListReverseIterator &operator--()
    {
        this->node_pointer_ = this->node_pointer_->next_;
        return *this;
    }

    ListReverseIterator operator--(int)
    {
        ListReverseIterator temporary(*this);
        this->node_pointer_ = this->node_pointer_->next_;
        return temporary;
    }
};

template <typename Type> class List
{
    
    struct Node;

  public:
    using value_type = Type;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;

    using const_pointer = const value_type *;

    using node_pointer = Node*;
    // using const_node_pointer = const Node*;
public:
    // friend class ListIteratorBase<List<Type>>;
    friend class ListIterator<List<Type>>;
    // friend class ListIterator<List<Type>, const_pointer, const_reference, const_node_pointer>;
    friend class ListIterator<List<Type>, const_pointer, const_reference>;
    friend class ListReverseIterator<List<Type>>;
    // friend class ListReverseIterator<List<Type>, const_pointer, const_reference, const_node_pointer>; 
    friend class ListReverseIterator<List<Type>, const_pointer, const_reference>; 

  public:
    using iterator = ListIterator<List<Type>>;
    // using const_iterator = ListIterator<List<Type>, const_pointer, const_reference, const_node_pointer>;
    using const_iterator = ListIterator<List<Type>, const_pointer, const_reference>;
    using reverse_iterator = ListReverseIterator<List<Type>>;
    // using const_reverse_iterator = ListReverseIterator<List<Type>, const_pointer, const_reference, const_node_pointer>;
    using const_reverse_iterator = ListReverseIterator<List<Type>, const_pointer, const_reference>;


  private:
    struct Node
    {
        template<typename T>
        friend void List<T>::connect(typename List<T>::Node*, typename List<T>::Node*);

        template<typename T>
        friend typename List<T>::Node* List<T>::previousOf(typename List<T>::Node*);
        
        template<typename T>
        friend typename List<T>::Node* List<T>::nextOf(typename List<T>::Node*);

        friend iterator;
        friend const_iterator;
        friend reverse_iterator;
        friend const_reverse_iterator;

    public:
        value_type data_;

    private:
        Node *next_;
        Node *previous_;
    };





    // Node *first_existing_;
    // Node *last_existing_;
    mutable Node end_;
    mutable Node rend_;
    size_type size_;

  public:
    List() 
        : 
        // first_existing_{nullptr}, 
        //   last_existing_{nullptr}, 
          end_{},
          rend_{},
          size_{0ull} {
        connect(&rend_, &end_);
    };

    explicit List(size_type count) : List() {
        for (size_type i = 0ull; i < count; ++i)
            Push_back(value_type());
    }

    List(size_type count, const_reference value) : List() {
        for (size_type i = 0ull; i < count; ++i)
            Push_back(value);
    }

    template<typename InputIterator>
    List(InputIterator first, InputIterator last) : List() {
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
    // first_existing_{other.first_existing_}, 
    // last_existing_{other.last_existing_},
    size_{other.size_}{

        Node* other_first = nextOf(&(other.rend_));
        Node* other_last = previousOf(&(other.end_));

        connect(&rend_, other_first);
        connect(other_last, &end_);
        // connect(last_existing_, &end_);
        // connect(&rend_, first_existing_);

        // other.first_existing_ = nullptr;
        // other.last_existing_ = nullptr;
        connect(&(other.rend_), &(other.end_));
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


        size_ = other.size_;

        Node* other_first = nextOf(&(other.rend_));
        Node* other_last = previousOf(&(other.end_));
        // if (size_) {
        connect(&rend_, other_first);
        connect(other_last, &end_);
            // first_existing_ = other.first_existing_;
            // last_existing_ = other.last_existing_;
            // connect(last_existing_, &end_);
            // connect(&rend_, first_existing_);
        // }

        // other.first_existing_ = nullptr;
        // other.last_existing_ = nullptr;
        connect(&(other.rend_), &(other.end_));
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
        // return first_existing_ ? iterator(first_existing_) : iterator(&end_);
        // return nextOf(&rend_) ? iterator(nextOf(&rend_)) : iterator(&end_);
        // return iterator(nextOf(&rend_));
        return ++iterator(&rend_);
    }

    reverse_iterator rbegin()
    {
        // return last_existing_ ? reverse_iterator(last_existing_) : reverse_iterator(&rend_);
        // return previousOf(&end_) ? reverse_iterator(previousOf(&end_)) : reverse_iterator(&rend_);
        // return reverse_iterator(previousOf(&end_));
        return ++reverse_iterator(&end_);
    }

    const_iterator cbegin() const
    {
        // return first_existing_ ? const_iterator(first_existing_) : const_iterator(&end_);
        return ++const_iterator(&rend_);
    }

    const_reverse_iterator crbegin() const
    {
        // return last_existing_ ? const_reverse_iterator(last_existing_) : const_reverse_iterator(&rend_);
        return ++const_reverse_iterator(&end_);
    }

    iterator end() 
    {
        return iterator(&end_);
    }

    reverse_iterator rend() 
    {
        return reverse_iterator(&rend_);
    }

    const_iterator cend() const
    {
        return const_iterator(&end_);
    }

    const_reverse_iterator crend() const
    {
        return const_reverse_iterator(&rend_);
    }

    void Push_back(const_reference data)
    {
        Node* old_last = previousOf(&end_);

        Node *new_last = new Node;
        new_last->data_ = data;

        connect(old_last, new_last);
        connect(new_last, &end_);
        
        // if (size_) {
            // assert(last_existing_ && "Last existing node is nullptr!");
            // connect(last_existing_, new_node);
        // } else {
            // connect(&rend_, new_node);
            // first_existing_ = new_node;
        // }

        // last_existing_ = new_node;
        ++size_;
    };

    void Pop_back()
    {
        assert(size_ >= 1ull && "Pop_back() from empty list!");

        Node* old_last = previousOf(&end_);
        Node* new_last = previousOf(old_last);
        delete old_last;

        connect(new_last, &end_);

        // if (size_ == 1ull) {
        //     delete last_existing_;
        //     last_existing_ = nullptr;
        //     first_existing_ = nullptr;
        //     connect(&rend_, &end_);
        //     --size_;
        //     return;
        // }

        // assert(previousOf(last_existing_) && "Previous pointer in last existing node is nullptr!");
        // Node* previous = previousOf(last_existing_);
        // delete last_existing_;

        // connect(previous, &end_);
        // last_existing_ = previous;
        --size_;
    }

    // Max_size()
    // Insert()
    iterator Insert(const_iterator pos, const_reference value) {
        Node* new_node = new Node;
        new_node->data_ = value;

        Node* next = pos.get();
        Node* previous = previousOf(next);
        connect(previous, new_node); 
        connect(new_node, next);

        ++size_;
        return iterator(new_node);
    }

    void Assign(size_type count, const_reference value) 
    {
        List temporary(count, value);
        *this = temporary;  // operator=(List&&)
    }

    template<typename InputIterator>
    void Assign(InputIterator first, InputIterator last) 
    {
        List temporary(first, last);
        *this = temporary;  // operator=(List&&)
    }

    void Assign(const std::initializer_list<value_type>& list) 
    {
        List temporary(list);
        *this = temporary;  // operator=(List&&)
    };

    // Merge()
    // Push_front()
    void Push_front(const_reference data)
    {
        Node* old_first = nextOf(&rend_);
        
        Node *new_first = new Node;
        new_first->data_ = data;

        connect(&rend_, new_first);
        connect(new_first, old_first);
        

        // if (size_) {
        //     assert(first_existing_ && "First existing node is nullptr!");
        //     connect(new_node, first_existing_);
        // } else {
        //     connect(new_node, &end_);
        //     last_existing_ = new_node;
        // }

        // first_existing_ = new_node;        
        ++size_;
    };
    void Pop_front()
    {
        assert(size_ >= 1ull && "Pop_back() from empty list!");

        Node* old_first = nextOf(&rend_);
        Node* new_first = nextOf(old_first);

        delete old_first;

        connect(&rend_, new_first);

        // if (size_ == 1ull) {
        //     delete first_existing_;
        //     first_existing_ = nullptr;
        //     last_existing_ = nullptr;
        //     connect(&rend_, &end_);
        //     --size_;
        //     return;
        // }

        // assert(nextOf(first_existing_) && "Next pointer in first existing node is nullptr!");
        // Node* next = nextOf(first_existing_);
        // delete first_existing_;

        // connect(&rend_, next);
        // first_existing_ = next;
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

    private:
        void connect(Node* node, Node* next_node) {
            node->next_ = next_node;
            next_node->previous_ = node;
        }
        Node* previousOf(Node* node) {
            return node->previous_;
        }
        Node* nextOf(Node* node) {
            return node->next_;
        }


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
