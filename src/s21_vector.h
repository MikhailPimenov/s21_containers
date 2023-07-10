#ifndef _S21_VECTOR_H_
#define _S21_VECTOR_H_

#include <cassert>
#include <initializer_list>
#include <iterator>
#include <new>
#include <cstring>

namespace s21
{

template <typename Vector, typename Pointer, typename Reference, typename Difference_type,
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

    operator int() const = delete;

  protected:
    pointer pointer_;
};

template <typename Vector, typename Pointer = typename Vector::pointer, typename Reference = typename Vector::reference>
class VectorIterator : public VectorIteratorBase<Vector, Pointer, Reference, typename Vector::difference_type, typename Vector::value_type>
{
  private:
    using Base = VectorIteratorBase<Vector, Pointer, Reference, typename Vector::difference_type,
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

    
    operator int() const = delete;
};

template <typename Vector, 
          typename Pointer = typename Vector::pointer, 
          typename Reference = typename Vector::reference>
VectorIterator<Vector, Pointer, Reference> operator+(typename VectorIterator<Vector, Pointer, Reference>::difference_type n, 
                         const VectorIterator<Vector, Pointer, Reference>& it)
{
    return VectorIterator<Vector, Pointer, Reference>(it + n); 
}





template <typename Vector, typename Pointer = typename Vector::pointer, typename Reference = typename Vector::reference>
class VectorReverseIterator : public VectorIteratorBase<Vector, Pointer, Reference,
                                             typename Vector::difference_type, typename Vector::value_type>
{
  private:
    using Base = VectorIteratorBase<Vector, Pointer, Reference, typename Vector::difference_type,
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

    
    operator int() const = delete;
};






template <typename Type> class Vector
{
  public:
    using value_type = Type;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;

    using const_pointer = const value_type *;

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




    constexpr reference At( size_type pos )
    {
        if (pos >= size_)
            throw std::out_of_range("Index is out of range!");
        return operator[](pos);
    }
    constexpr const_reference At(size_type pos) const
    {
        if (pos >= size_)
            throw std::out_of_range("Index is out of range!");
        return operator[](pos);
    }

    reference operator[](size_type pos)
    {
        return data_[pos];
    }
    const_reference operator[](size_type pos) const
    {
        return data_[pos];
    }

    constexpr reference Front()
    {
        return data_[0];
    }
    constexpr const_reference Front() const
    {
        return data_[0];
    }

    constexpr reference Back()
    {
        return data_[size_ - 1];
    }
    constexpr const_reference Back() const
    {
        return data_[size_ - 1];
    }

    constexpr pointer Data() noexcept
    {
        return data_;
    }
    constexpr const_pointer Data() const noexcept
    {
        return data_;
    }

    size_type Size() const noexcept
    {
        return size_;
    }
    size_type Capacity() const noexcept
    {
        return capacity_;
    }

    constexpr void Reserve(size_type new_capacity)
    {
        if (new_capacity <= capacity_) 
            return;

        const size_type new_actual_capacity = calculate_capacity(new_capacity);
        reallocate(new_actual_capacity);
    }

    constexpr void Shrink_to_fit()
    {
        if (capacity_ > size_)
            reallocate(size_);
    }

    void Clear()
    {
        deallocate();
    }

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
        // return cbegin();
        return const_iterator(data_);
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





constexpr iterator Insert(const_iterator pos, const_reference value)
{
    const size_type new_size = size_ + 1;
    if (new_size > capacity_)
        reallocate(new_size);

    
    auto it = rbegin(); 
    while(it <= pos) 
    {
        *it = std::move(*(it + 1));
        ++it;
    } 

    ++it;
    *it = value;
}



// constexpr iterator insert( const_iterator pos, T&& value );
// (since C++20)
// (3)	
// constexpr iterator
//     insert( const_iterator pos, size_type count, const T& value );
// (since C++20)
// (4)	
// template< class InputIt >
// constexpr iterator insert( const_iterator pos, InputIt first, InputIt last );
// (since C++20)
// (5)	
// constexpr iterator insert( const_iterator pos,
//                            std::initializer_list<T> ilist );
// (since C++20)





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

    template<typename... Args>
    constexpr void Emplace_back(Args&&... args)
    {
        size_type old_size = size_;
        size_type new_size = size_ + 1;

        if (new_size > capacity_)
        {
            size_type new_capacity = calculate_capacity(new_size);
            reallocate(new_capacity);
        }
        data_[old_size] = value_type(std::forward<Args>(args)...);
        size_ = new_size;
    }
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
