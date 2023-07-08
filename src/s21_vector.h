#ifndef _S21_VECTOR_H_
#define _S21_VECTOR_H_

#include <cassert>
#include <initializer_list>
#include <iterator>
#include <new>
#include <cstring>

namespace s21
{

template <typename Vector, typename Pointer, typename Reference, typename Node_pointer, typename Difference_type,
          typename Value_type>
class VectorIteratorBase
{
    friend Vector;

  public:
    using difference_type = Difference_type;
    using value_type = Value_type;
    using pointer = Pointer;
    using reference = Reference;
    using iterator_category = std::bidirectional_iterator_tag;

    // using node_pointer = Node_pointer;

  public:
    VectorIteratorBase(pointer p) : pointer_{p} {};

    VectorIteratorBase(const VectorIteratorBase &other) : VectorIteratorBase(other.pointer_) {};
    VectorIteratorBase(VectorIteratorBase &&other) : VectorIteratorBase(other.pointer_)
    {
        other.pointer_ = nullptr;
    };

    friend void swap(VectorIteratorBase &left, VectorIteratorBase &right)
    {
        using namespace std; // to enable ADL
        swap(left.pointer_, right.pointer_);
    };

    VectorIteratorBase &operator=(const VectorIteratorBase &other)
    {
        pointer_ = other->pointer_;
        return *this;
    };

    VectorIteratorBase &operator=(VectorIteratorBase &&other)
    {
        pointer_ = other->pointer_;
        other->pointer_ = nullptr;
        return *this;
    }

    reference operator*() const
    {
        return *pointer_;
    }

    pointer operator->() const
    {
        return pointer_;
    }

    bool operator==(const VectorIteratorBase &other) const
    {
        return pointer_ == other.pointer_;
    }

    bool operator!=(const VectorIteratorBase &other) const
    {
        return !(*this == other);
    }

    operator bool() const
    {
        return pointer_;
    }

  protected:
    pointer pointer_;
};

template <typename Vector, typename Pointer = typename Vector::pointer, typename Reference = typename Vector::reference>
class VectorIterator : public VectorIteratorBase<Vector, Pointer, Reference, typename Vector::node_pointer,
                                             typename Vector::difference_type, typename Vector::value_type>
{
  private:
    using Base = VectorIteratorBase<Vector, Pointer, Reference, typename Vector::node_pointer, typename Vector::difference_type,
                                  typename Vector::value_type>;
    using typename Base::difference_type;   // otherwise everywhere in this class 'typename Base::difference_type' instead of 'difference_type'
    using typename Base::reference;

  public:
    using Base::Base;

    VectorIterator &operator++()
    {
        ++(this->pointer_);
        return *this;
    }

    VectorIterator operator++(int)
    {
        VectorIterator temporary(*this);
        ++(this->pointer_);
        return temporary;
    }

    VectorIterator &operator--()
    {
        --(this->pointer_);
        return *this;
    }

    VectorIterator operator--(int)
    {
        VectorIterator temporary(*this);
        --(this->node_pointer_);
        return temporary;
    }

    
    VectorIterator& operator+=(difference_type n) 
    {
        this->pointer_ += n;
        return *this;
    }
    VectorIterator& operator-=(difference_type n) 
    {
        this->pointer_ -= n;
        return *this;
    }
    VectorIterator operator+(difference_type n)
    {
        return VectorIterator(this->pointer_ + n);
    }
    VectorIterator operator-(difference_type n)
    {
        return VectorIterator(this->pointer_ - n);
    }
    difference_type operator-(const VectorIterator& other)
    {
        return this->poiner_ - other.pointer_;
    }
    reference operator[](difference_type n)
    {
        return this->operator*(n);
    }
    bool operator<(const VectorIterator& other)
    {
        return this->pointer_ - other->pointer_ < 0;
    }
    bool operator>(const VectorIterator& other)
    {
        return other < *this;
    }
    bool operator<=(const VectorIterator& other)
    {
        return !(*this > other);
    }
    bool operator>=(const VectorIterator& other)
    {
        return !(*this < other);
    }

};

// template <typename Vector, typename Pointer = typename Vector::pointer, typename Reference = typename Vector::reference>
// VectorIterator operator+(template VectorIterator::difference_type n, const VectorIterator& it)
// {
//     return 
// }





template <typename Vector, typename Pointer = typename Vector::pointer, typename Reference = typename Vector::reference>
class VectorReverseIterator : public VectorIteratorBase<Vector, Pointer, Reference, typename Vector::node_pointer,
                                             typename Vector::difference_type, typename Vector::value_type>
{
  private:
    using Base = VectorIteratorBase<Vector, Pointer, Reference, typename Vector::node_pointer, typename Vector::difference_type,
                                  typename Vector::value_type>;
    using typename Base::difference_type;
    using typename Base::reference;

  public:
    using Base::Base;

    VectorReverseIterator &operator++()
    {
        --(this->pointer_);
        return *this;
    }

    VectorReverseIterator operator++(int)
    {
        VectorReverseIterator temporary(*this);
        --(this->pointer_);
        return temporary;
    }

    VectorReverseIterator &operator--()
    {
        ++(this->pointer_);
        return *this;
    }

    VectorReverseIterator operator--(int)
    {
        VectorReverseIterator temporary(*this);
        ++(this->node_pointer_);
        return temporary;
    }

    
    VectorReverseIterator& operator+=(difference_type n) 
    {
        this->pointer_ -= n;
        return *this;
    }
    VectorReverseIterator& operator-=(difference_type n) 
    {
        this->pointer_ += n;
        return *this;
    }
    VectorReverseIterator operator+(difference_type n)
    {
        return VectorReverseIterator(this->pointer_ - n);
    }
    VectorReverseIterator operator-(difference_type n)
    {
        return VectorReverseIterator(this->pointer_ + n);
    }
    difference_type operator-(const VectorReverseIterator& other)
    {
        return other.pointer_ - this->poiner_;
    }
    reference operator[](difference_type n)
    {
        return this->operator*(n);
    }
    bool operator<(const VectorReverseIterator& other)
    {
        return other->pointer_ - this->pointer_ < 0;
    }
    bool operator>(const VectorReverseIterator& other)
    {
        return other < *this;
    }
    bool operator<=(const VectorReverseIterator& other)
    {
        return !(*this > other);
    }
    bool operator>=(const VectorReverseIterator& other)
    {
        return !(*this < other);
    }
};














// template <typename Vector, typename Pointer = typename Vector::pointer, typename Reference = typename Vector::reference>
// class VectorReverseIterator : public VectorIteratorBase<Vector, Pointer, Reference, typename Vector::node_pointer,
//                                                     typename Vector::difference_type, typename Vector::value_type>
// {
//   private:
//     using Base = VectorIteratorBase<Vector, Pointer, Reference, typename Vector::node_pointer, typename Vector::difference_type,
//                                   typename Vector::value_type>;

//   public:
//     using Base::Base;

//     VectorReverseIterator &operator++()
//     {
//         this->node_pointer_ = this->node_pointer_->previous_;
//         return *this;
//     }

//     VectorReverseIterator operator++(int)
//     {
//         VectorReverseIterator temporary(*this);
//         this->node_pointer_ = this->node_pointer_->previous_;
//         return temporary;
//     }

//     VectorReverseIterator &operator--()
//     {
//         this->node_pointer_ = this->node_pointer_->next_;
//         return *this;
//     }

//     VectorReverseIterator operator--(int)
//     {
//         VectorReverseIterator temporary(*this);
//         this->node_pointer_ = this->node_pointer_->next_;
//         return temporary;
//     }
// };

template <typename Type> class Vector
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
    using node_pointer = Node *;

  public:
    friend class VectorIterator<Vector<Type> >;
    friend class VectorIterator<Vector<Type>, const_pointer, const_reference>;
    friend class VectorReverseIterator<Vector<Type> >;
    friend class VectorReverseIterator<Vector<Type>, const_pointer, const_reference>;

  public:
    using iterator = VectorIterator<Vector<Type> >;
    using const_iterator = VectorIterator<Vector<Type>, const_pointer, const_reference>;
    using reverse_iterator = VectorReverseIterator<Vector<Type> >;
    using const_reverse_iterator = VectorReverseIterator<Vector<Type>, const_pointer, const_reference>;

  private:
    size_type capacity_;
    size_type size_;
    pointer data_;

    // value_type end_;
    // value_type rend_;

    private:
        static size_type calculate_capacity(size_type count) {
            size_type result = 1;
            while (result <= count)
                result <<= 1;
            return result - 1;
        }

        void allocate(size_type exact_count) 
        {
            assert(!data_ && "Possible memory leak!");
            // assert(capacity_ == 0 && "Possible memory leak!");
            // assert(size_ == 0 && "Possible memory leak!");
            data_ = new value_type[exact_count];
            capacity_ = exact_count;
        }
        void reallocate(size_type exact_count)
        {
            pointer new_data = new Type[exact_count];
            size_type new_size = size_;
            for (size_type i = 0; i < size_; ++i)
                new_data[i] = data_[i];
            
            deallocate();
            data_ = new_data;
            size_ = new_size;
            capacity_ = exact_count;
        }
        void deallocate() noexcept
        {
            delete[] data_;
            data_ = nullptr;
            capacity_ = 0;
            size_ = 0;
        }

  public:
    Vector() : data_{nullptr}, size_{0ull}, capacity_{0ull}
    {
    };

    explicit Vector(size_type count, const_reference value) 
        : capacity_{calculate_capacity(count)}, size_{count}, data_{nullptr}
    {      
        allocate(capacity_);

        for (size_type i = 0; i < count; ++i)
            data_[i] = value;
    }
    ~Vector() 
    {
        delete[] data_;
        capacity_ = 0;
        size_ = 0;
    }

    Vector(std::initializer_list<value_type> initializer) 
        : capacity_{calculate_capacity(initializer.size())}, size_{initializer.size()}, data_{nullptr}
    {
        allocate(capacity_);


        size_type i = 0;
        for (const auto& element : initializer)
        {
            data_[i] = element;
            ++i;
        }            
    }




    reference operator[](size_type pos)
    {
        return data_[pos];
    }
    const_reference operator[](size_type pos) const
    {
        return data_[pos];
    }

    size_type Size() const noexcept
    {
        return size_;
    }
    size_type Capacity() const noexcept
    {
        return capacity_;
    }

    // List(size_type count, const_reference value) : List()
    // {
    //     for (size_type i = 0ull; i < count; ++i)
    //         Push_back(value);
    // }

    // template <typename InputIterator> List(InputIterator first, InputIterator last) : List()
    // {
    //     for (auto it = first; it != last; ++it)
    //         Push_back(*it);
    // }

    // // TODO: refactor rule of 5
    // List(const List &other) : List()
    // {
    //     for (auto it = other.cbegin(); it != other.cend(); ++it)
    //         Push_back(*it);
    // }
    // // TODO: refactor rule of 5
    // List(List &&other) : size_{other.size_}
    // {
    //     Node *other_first = nextOf(&(other.rend_));
    //     Node *other_last = previousOf(&(other.end_));

    //     connect(&rend_, other_first);
    //     connect(other_last, &end_);

    //     connect(&(other.rend_), &(other.end_));
    //     other.size_ = 0ull;
    // }

    // // TODO: refactor rule of 5
    // List &operator=(const List &other)
    // {
    //     if (this == &other)
    //         return *this;

    //     List copy(other);
    //     *this = std::move(copy); // operator=(List&&)
    //     return *this;
    // }

    // // TODO: refactor rule of 5
    // List &operator=(List &&other)
    // {
    //     if (this == &other) // TODO: remove??
    //         return *this;

    //     Clear();

    //     size_ = other.size_;

    //     Node *other_first = nextOf(&(other.rend_));
    //     Node *other_last = previousOf(&(other.end_));

    //     connect(&rend_, other_first);
    //     connect(other_last, &end_);

    //     connect(&(other.rend_), &(other.end_));
    //     other.size_ = 0ull;

    //     return *this;
    // }

    // List(const std::initializer_list<value_type> &list) : List()
    // {
    //     for (const auto &element : list)
    //         Push_back(element);
    // };

    // ~List()
    // {
    //     Clear();
    // }

    // void Clear()
    // {
    //     while (!Empty())
    //         Pop_back();
    // }

    bool Empty() const noexcept
    {
        return size_ == 0ull;
    }


    iterator begin()
    {
        return iterator(data_);
    }
    const_iterator begin() const
    {
        return cbegin();
    }
    const_iterator cbegin() const
    {
        return const_iterator(data_);
    }


    reverse_iterator rbegin()
    {
        return reverse_iterator(data_ + size_ - 1);
    }
    const_reverse_iterator rbegin() const
    {
        return crbegin();
    }
    const_reverse_iterator crbegin() const
    {
        return const_reverse_iterator(data_ + size_ - 1);
    }


    iterator end()
    {
        return iterator(data_ + size_);
    }
    const_iterator end() const
    {
        return cend();
    }
    const_iterator cend() const
    {
        return const_iterator(data_ + size_);
    }


    reverse_iterator rend()
    {
        return reverse_iterator(data_ - 1);
    }
    const_reverse_iterator rend() const
    {
        return crend();
    }
    const_reverse_iterator crend() const
    {
        return const_reverse_iterator(data_ - 1);
    }

    constexpr void Push_back(const_reference element)
    {
        size_type old_size = size_;
        size_type new_size = size_ + 1;

        if (new_size > capacity_)
        {
            size_type new_capacity = calculate_capacity(new_size);
            reallocate(new_capacity);
        }
        data_[old_size] = element;
        size_ = new_size;
    };

    constexpr void Push_back(value_type&& element)
    {
        size_type old_size = size_;
        size_type new_size = size_ + 1;

        if (new_size > capacity_)
        {
            size_type new_capacity = calculate_capacity(new_size);
            reallocate(new_capacity);
        }
        data_[old_size] = std::move(element);
        size_ = new_size;
    };

    // void Pop_back()
    // {
    //     assert(size_ >= 1ull && "Pop_back() from empty list!");

    //     Node *old_last = previousOf(&end_);
    //     Node *new_last = previousOf(old_last);
    //     delete old_last;

    //     connect(new_last, &end_);

    //     --size_;
    // }

    // // Max_size()
    // size_type Max_size() const noexcept {
    //     return std::numeric_limits<difference_type>::max();
    // }
    // // Resize()
    // void Resize(size_type count, const_reference value)
    // {
    //     assert(static_cast<signed long long>(count) >= 0 && "Probably negative number of elements!");

    //     if (count == size_)
    //         return;

    //     if (count < size_)
    //         for (size_type i = 0ull; i < size_ - count; ++i)
    //             Pop_back();
    //     else
    //         for (size_type i = 0ull; i < count - size_; ++i)
    //             Push_back(value);
    // }
    // void Resize(size_type count)
    // {
    //     Resize(count, value_type());
    // }

    // // Insert()
    // iterator Insert(const_iterator pos, const_reference value)
    // {
    //     Node *new_node = new Node;
    //     new_node->data_ = value;

    //     Node *next = pos.get();
    //     Node *previous = previousOf(next);
    //     connect(previous, new_node);
    //     connect(new_node, next);

    //     ++size_;
    //     return iterator(new_node);
    // }
    // iterator Insert(const_iterator pos, size_type count, const_reference value)
    // {
    //     assert(static_cast<signed long long>(count) >= 0 && "Probably negative number of elements!");
    //     for (size_type i = 0ull; i < count; ++i)
    //         Insert(pos, value);

    //     iterator result(pos.get());
    //     for (size_type i = 0ull; i < count; ++i)
    //         --result;

    //     return result;
    // }
    // template <typename InputIterator> iterator Insert(const_iterator pos, InputIterator first, InputIterator last)
    // {
    //     size_type count = 0ull;
    //     for (InputIterator it = first; it != last; ++it)
    //     {
    //         Insert(pos, *it);
    //         ++count;
    //     }

    //     iterator result(pos.get());
    //     for (size_type i = 0ull; i < count; ++i)
    //         --result;

    //     return result;
    // }
    // iterator Insert(const_iterator pos, const std::initializer_list<Type> &list)
    // {
    //     for (const auto &element : list)
    //         Insert(pos, element);

    //     iterator result(pos.get());
    //     for (size_type i = 0ull; i < list.size(); ++i)
    //         --result;

    //     return result;
    // }

    // void Assign(size_type count, const_reference value)
    // {
    //     List temporary(count, value);
    //     *this = temporary; // operator=(List&&)
    // }

    // template <typename InputIterator> void Assign(InputIterator first, InputIterator last)
    // {
    //     List temporary(first, last);
    //     *this = temporary; // operator=(List&&)
    // }

    // void Assign(const std::initializer_list<value_type> &list)
    // {
    //     List temporary(list);
    //     *this = temporary; // operator=(List&&)
    // };

    // // Merge()
    // // Push_front()
    // void Push_front(const_reference data)
    // {
    //     Node *old_first = nextOf(&rend_);

    //     Node *new_first = new Node;
    //     new_first->data_ = data;

    //     connect(&rend_, new_first);
    //     connect(new_first, old_first);

    //     ++size_;
    // };

    // void Push_front(value_type&& data)
    // {
    //     Node *old_first = nextOf(&rend_);

    //     Node *new_first = new Node;
    //     new_first->data_ = std::move(data);

    //     connect(&rend_, new_first);
    //     connect(new_first, old_first);

    //     ++size_;
    // };

    // void Pop_front()
    // {
    //     assert(size_ >= 1ull && "Pop_back() from empty list!");

    //     Node *old_first = nextOf(&rend_);
    //     Node *new_first = nextOf(old_first);

    //     delete old_first;

    //     connect(&rend_, new_first);

    //     --size_;
    // }
    // // Swap()
    // void Swap(List& other) noexcept 
    // {
    //     Node* other_first = nextOf(&(other.rend_));
    //     Node* other_last = previousOf(&(other.end_));

    //     Node* first = nextOf(&rend_);
    //     Node* last = previousOf(&end_);

    //     if (size_) {
    //         connect(&(other.rend_), first);
    //         connect(last, &(other.end_));
    //     } else {
    //         connect(&(other.rend_), &(other.end_));
    //     }

    //     if (other.size_) {
    //         connect(other_last, &end_);
    //         connect(&rend_, other_first);
    //     } else {
    //         connect(&rend_, &end_);
    //     }
        
    //     std::swap(size_, other.size_);
    // }

   
    // // Front()
    // reference Front()
    // {
    //     assert(!Empty() && "Front() from empty list!");
    //     return *begin();
    // }
    // const_reference Front() const
    // {
    //     assert(!Empty() && "Front() from empty list!");
    //     return *cbegin();
    // }
    // // Back()
    // reference Back()
    // {
    //     assert(!Empty() && "Back() from empty list!");
    //     return *(--end());
    // }
    // const_reference Back() const
    // {
    //     assert(!Empty() && "Back() from empty list!");
    //     return *(--cend());
    // }

    // // Erase()
    // iterator Erase(const_iterator pos)
    // {
    //     Node* previous = previousOf(pos.get());
    //     Node* next = nextOf(pos.get());

    //     delete pos.get();
    //     --size_;

    //     connect(previous, next);
    //     return iterator(next);
    // }
    // iterator Erase(const_iterator first, const_iterator last)
    // {
    //     for (const_iterator it = first; it != last; ++it)
    //         Erase(it);

    //     return iterator(last.get());
    // }
    // // Sort()
    // // Unique()
    // // Splice()
    // // Emplace()
    // template <class... Args> iterator Emplace(const_iterator pos, Args &&...args)
    // {
    //     Node *new_node = new Node;
    //     new_node->data_ = value_type(std::forward<Args>(args)...);

    //     Node *next = pos.get();
    //     Node *previous = previousOf(next);

    //     connect(previous, new_node);
    //     connect(new_node, next);
    //     ++size_;

    //     return iterator(new_node);
    // }

    // // Emplace_back()
    // template <class... Args> reference Emplace_back(Args &&...args)
    // {
    //     Node *new_last = new Node;
    //     new_last->data_ = value_type(std::forward<Args>(args)...);

    //     Node *old_last = previousOf(&end_);

    //     connect(old_last, new_last);
    //     connect(new_last, &end_);
    //     ++size_;

    //     return new_last->data_;
    // }
    // // Emplace_front()
    // template <class... Args> reference Emplace_front(Args &&...args)
    // {
    //     Node *new_first = new Node;
    //     new_first->data_ = value_type(std::forward<Args>(args)...);

    //     Node *old_first = nextOf(&rend_);

    //     connect(&rend_, new_first);
    //     connect(new_first, old_first);
    //     ++size_;

    //     return new_first->data_;
    // }
};

template <typename Type> bool operator==(const Vector<Type> &left, const Vector<Type> &right)
{
    if (left.Size() != right.Size())
        return false;

    auto left_iterator = left.cbegin();
    auto right_iterator = right.cbegin();

    while (left_iterator != left.cend())
    {
        if (*left_iterator != *right_iterator)
            return false;
        ++left_iterator;
        ++right_iterator;
    }

    return true;
}

} // namespace s21

#endif //  _S21_VECTOR_H_
