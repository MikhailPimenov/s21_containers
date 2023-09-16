#ifndef _S21_ARRAY_H_
#define _S21_ARRAY_H_

#include <cassert>
#include <initializer_list>
#include <iterator>
#include <new>
#include <cstring>

namespace s21
{

template <typename Array, typename Pointer, typename Reference, typename Difference_type,
          typename Value_type>
class ArrayIteratorBase
{
  public:
    using difference_type = Difference_type;
    using value_type = Value_type;
    using pointer = Pointer;
    using reference = Reference;
    using iterator_category = std::random_access_iterator_tag;

    template <typename OtherArray, typename OtherPointer, typename OtherReference, typename OtherDifference_type, typename OtherValue_type>
    friend class ArrayIteratorBase;  // to be able to compare iterator and const_iterator


  public:
    ArrayIteratorBase(pointer p) noexcept : pointer_{p} {}

    
    // template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    // ArrayIteratorBase(const ArrayIteratorBase<Array, OtherPointer, OtherReference, Difference_type, Value_type> &other) noexcept 
    //     : ArrayIteratorBase(const_cast<Pointer>(other.pointer_)) 
    // {

    // }

    
    ArrayIteratorBase(const ArrayIteratorBase &other) noexcept 
        : ArrayIteratorBase(other.pointer_) 
    {

    }


    // template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    // ArrayIteratorBase(ArrayIteratorBase<Array, OtherPointer, OtherReference, Difference_type, Value_type> &&other) noexcept 
    //     : ArrayIteratorBase(const_cast<Pointer>(other.pointer_))
    // {
    //     other.pointer_ = nullptr;
    // }

    ArrayIteratorBase(ArrayIteratorBase &&other) noexcept 
        : ArrayIteratorBase(other.pointer_)
    {
        other.pointer_ = nullptr;
    }
    
    friend void swap(ArrayIteratorBase &left, ArrayIteratorBase &right) noexcept
    {
        using namespace std; // to enable ADL
        swap(left.pointer_, right.pointer_);
    }

    virtual ArrayIteratorBase &operator++() noexcept = 0;

    // template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    // ArrayIteratorBase<Array, OtherPointer, OtherReference, Difference_type, Value_type> &operator=(const ArrayIteratorBase<Array, OtherPointer, OtherReference, Difference_type, Value_type> &other) noexcept
    // {
    //     pointer_ = other.pointer_;
    //     return *this;
    // }

    // template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    // ArrayIteratorBase<Array, OtherPointer, OtherReference, Difference_type, Value_type> &operator=(ArrayIteratorBase<Array, OtherPointer, OtherReference, Difference_type, Value_type> &&other) noexcept
    // {
    //     pointer_ = other.pointer_;
    //     other.pointer_ = nullptr;
    //     return *this;
    // }



    ArrayIteratorBase &operator=(const ArrayIteratorBase &other) noexcept
    {
        pointer_ = other.pointer_;
        return *this;
    }

    ArrayIteratorBase &operator=(ArrayIteratorBase &&other) noexcept
    {
        pointer_ = other.pointer_;
        other.pointer_ = nullptr;
        return *this;
    }



    reference operator*() const noexcept
    {
        return *pointer_;
    }

    pointer operator->() const noexcept
    {
        return pointer_;
    }

    template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    bool operator==(const ArrayIteratorBase<Array, OtherPointer, OtherReference, Difference_type, Value_type> &other) const noexcept
    {
        return pointer_ == other.pointer_;
    }

    template <typename OtherPointer, typename OtherReference>
    bool operator!=(const ArrayIteratorBase<Array, OtherPointer, OtherReference, Difference_type, Value_type> &other) const noexcept
    {
        return !(*this == other);
    }

    explicit operator bool() const noexcept
    {
        return pointer_;
    }

  protected:
    pointer pointer_;
};

template <typename Array, typename Pointer = typename Array::pointer, typename Reference = typename Array::reference>
class ArrayIterator : public ArrayIteratorBase<Array, Pointer, Reference, typename Array::difference_type, typename Array::value_type>
{
  private:
    using Base = ArrayIteratorBase<Array, Pointer, Reference, typename Array::difference_type,
                                  typename Array::value_type>;
  public:
    using typename Base::difference_type;   // otherwise everywhere in this class 'typename Base::difference_type' instead of 'difference_type'
    using typename Base::reference;

    template<typename ArrayType, typename PointerType, typename ReferenceType>
    friend class ArrayIterator;  // to compare const_iterator with iterator

  public:
    using Base::Base;

    ArrayIterator &operator++() noexcept override
    {
        ++(this->pointer_);
        return *this;
    }

    ArrayIterator operator++(int) noexcept
    {
        ArrayIterator temporary(*this);
        ++(this->pointer_);
        return temporary;
    }

    ArrayIterator &operator--() noexcept
    {
        --(this->pointer_);
        return *this;
    }

    ArrayIterator operator--(int) noexcept
    {
        ArrayIterator temporary(*this);
        --(this->pointer_);
        return temporary;
    }

    template<typename IntegralType> 
    ArrayIterator& operator+=(IntegralType n) noexcept 
    {
        this->pointer_ += n;
        return *this;
    }
    template<typename IntegralType>
    ArrayIterator& operator-=(IntegralType n) noexcept
    {
        this->pointer_ -= n;
        return *this;
    }
    template<typename IntegralType> // otherwise for iterator + 1  operator+(int, int) is called
    ArrayIterator operator+(IntegralType n) const noexcept
    {
        return ArrayIterator(this->pointer_ + n);
    }
    template<typename IntegralType>
    ArrayIterator operator-(IntegralType n) const noexcept
    {
        return ArrayIterator(this->pointer_ - n);
    }
    template<typename PointerType, typename ReferenceType> // to compare const_iterator with iterator
    difference_type operator-(const ArrayIterator<Array, PointerType, ReferenceType>& other) const noexcept
    {
        return this->pointer_ - other.pointer_;
    }
    reference operator[](difference_type n) const noexcept
    {
        return ArrayIterator(this->pointer_ + n).operator*();
    }
    template<typename PointerType, typename ReferenceType>
    bool operator<(const ArrayIterator<Array, PointerType, ReferenceType>& other) const noexcept
    {
        return this->pointer_ - other.pointer_ < 0;
    }
    template<typename PointerType, typename ReferenceType>
    bool operator>(const ArrayIterator<Array, PointerType, ReferenceType>& other) const noexcept
    {
        return other.operator<(*this);
    }
    template<typename PointerType, typename ReferenceType>
    bool operator<=(const ArrayIterator<Array, PointerType, ReferenceType>& other) const noexcept
    {
        return !(this->operator>(other));
    }
    template<typename PointerType, typename ReferenceType>
    bool operator>=(const ArrayIterator<Array, PointerType, ReferenceType>& other) const noexcept
    {
        return !(this->operator<(other));
    }

    operator int() const = delete;

    // to enable creating iterator from const_iterator via static_cast
    template <typename OtherPointer, typename OtherReference>
    explicit operator ArrayIterator<Array, OtherPointer, OtherReference>() const noexcept
    {
        return ArrayIterator<Array, OtherPointer, OtherReference>(const_cast<OtherPointer>(this->pointer_));
    }
};


template <typename Array, typename Pointer = typename Array::pointer, typename Reference = typename Array::reference>
class ArrayReverseIterator : public ArrayIteratorBase<Array, Pointer, Reference,
                                             typename Array::difference_type, typename Array::value_type>
{
  private:
    using Base = ArrayIteratorBase<Array, Pointer, Reference, typename Array::difference_type,
                                  typename Array::value_type>;
  public:
    using typename Base::difference_type;
    using typename Base::reference;

    template<typename ArrayType, typename PointerType, typename ReferenceType>
    friend class ArrayReverseIterator;

  public:
    using Base::Base;

    ArrayReverseIterator &operator++() noexcept override
    {
        --(this->pointer_);
        return *this;
    }

    ArrayReverseIterator operator++(int) noexcept
    {
        ArrayReverseIterator temporary(*this);
        --(this->pointer_);
        return temporary;
    }

    ArrayReverseIterator &operator--() noexcept
    {
        ++(this->pointer_);
        return *this;
    }

    ArrayReverseIterator operator--(int) noexcept
    {
        ArrayReverseIterator temporary(*this);
        ++(this->pointer_);
        return temporary;
    }

    template<typename IntegralType>
    ArrayReverseIterator& operator+=(IntegralType n) noexcept
    {
        this->pointer_ -= n;
        return *this;
    }
    template<typename IntegralType>
    ArrayReverseIterator& operator-=(IntegralType n) noexcept
    {
        this->pointer_ += n;
        return *this;
    }
    template<typename IntegralType>
    ArrayReverseIterator operator+(IntegralType n) const noexcept
    {
        return ArrayReverseIterator(this->pointer_ - n);
    }
    template<typename IntegralType>
    ArrayReverseIterator operator-(IntegralType n) const noexcept
    {
        return ArrayReverseIterator(this->pointer_ + n);
    }
    template<typename PointerType, typename ReferenceType>
    difference_type operator-(const ArrayReverseIterator<Array, PointerType, ReferenceType>& other) const noexcept
    {
        return other.pointer_ - this->pointer_;
    }
    reference operator[](difference_type n) const noexcept
    {
        return ArrayReverseIterator(this->pointer_ - n).operator*();
    }
    template<typename PointerType, typename ReferenceType>
    bool operator<(const ArrayReverseIterator<Array, PointerType, ReferenceType>& other) const noexcept
    {
        return other.pointer_ - this->pointer_ < 0;
    }
    template<typename PointerType, typename ReferenceType>
    bool operator>(const ArrayReverseIterator<Array, PointerType, ReferenceType>& other) const noexcept
    {
        return other.operator<(*this);
    }
    template<typename PointerType, typename ReferenceType>
    bool operator<=(const ArrayReverseIterator<Array, PointerType, ReferenceType>& other) const noexcept
    {
        return !(this->operator>(other));
    }
    template<typename PointerType, typename ReferenceType>
    bool operator>=(const ArrayReverseIterator<Array, PointerType, ReferenceType>& other) const noexcept
    {
        return !(this->operator<(other));
    }

    operator int() const = delete;

    // to enable creating iterator from const_iterator via static_cast
    template <typename OtherPointer, typename OtherReference>
    explicit operator ArrayReverseIterator<Array, OtherPointer, OtherReference>() const noexcept
    {
        return ArrayReverseIterator<Array, OtherPointer, OtherReference>(const_cast<OtherPointer>(this->pointer_));
    }
};






template <typename Type, std::size_t N> class Array
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
    using iterator = ArrayIterator<Array<Type, N> >;
    using const_iterator = ArrayIterator<Array<Type, N>, const_pointer, const_reference>;
    using reverse_iterator = ArrayReverseIterator<Array<Type, N> >;
    using const_reverse_iterator = ArrayReverseIterator<Array<Type, N>, const_pointer, const_reference>;

  private:
    size_type size_;
    value_type data_[N];



  public:
    Array() : size_{N}
    {
        // for(std::size_t i = 0; i < N; i++) {
        //     data_[i] = value_type();
        // }
    }

    Array(const Array& other) {
        for(std::size_t i = 0; i < N; i++) {
            data_[i] = other.data_[i];
        }
    }

    ~Array() 
    {
    }

    Array(std::initializer_list<value_type> initializer) 
    {
        assert(initializer.size() <= N && "wrong size");


        size_type i = 0;
        for (const auto& element : initializer)
        {
            data_[i] = element;
            ++i;
        }

        while(i < N) {
            data_[i] = value_type();
            ++i;
        }            
    }

    

    // Array& operator

    Array& operator=(const Array& other)
    {
       
        for(std::size_t i = 0; i < N; i++) {
            data_[i] = other.data_[i];
        }
        return *this;
    }

    
    constexpr reference At(size_type pos)
    {
        if (pos >= N)
            throw std::out_of_range("Index is out of range!");
        return operator[](pos);
    }
    constexpr const_reference At(size_type pos) const
    {
        if (pos >= N)
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
        return data_[N - 1];
    }
    constexpr const_reference Back() const
    {
        return data_[N - 1];
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
        return N;
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
        return reverse_iterator(data_ + N - 1);
    }
    const_reverse_iterator rbegin() const
    {
        return crbegin();
    }
    const_reverse_iterator crbegin() const
    {
        return const_reverse_iterator(data_ + N - 1);
    }


    iterator end()
    {
        return iterator(data_ + N);
    }
    const_iterator end() const
    {
        return cend();
    }
    const_iterator cend() const
    {
        return const_iterator(data_ + N);
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


private:



public:
    constexpr void Swap(Array& other) {
        for(std::size_t i = 0; i < N; i++) {
            const value_type copy = other.data_[i];
            other.data_[i] = data_[i];
            data_[i] = copy;
        }
    } 
};

template <typename Type, std::size_t N> bool operator==(const Array<Type, N> &left, const Array<Type, N> &right)
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

template <typename Type, std::size_t N> bool operator!=(const Array<Type, N> &left, const Array<Type, N> &right)
{
    return !(left == right);
}

} // namespace s21

#endif //  _S21_ARRAY_H_
