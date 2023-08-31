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
    // VectorIteratorBase(const VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &other) noexcept 
    //     : VectorIteratorBase(const_cast<Pointer>(other.pointer_)) 
    // {

    // }

    
    ArrayIteratorBase(const ArrayIteratorBase &other) noexcept 
        : ArrayIteratorBase(other.pointer_) 
    {

    }


    // template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    // VectorIteratorBase(VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &&other) noexcept 
    //     : VectorIteratorBase(const_cast<Pointer>(other.pointer_))
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
    // VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &operator=(const VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &other) noexcept
    // {
    //     pointer_ = other.pointer_;
    //     return *this;
    // }

    // template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    // VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &operator=(VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &&other) noexcept
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






template <typename Type> class Array
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
    using iterator = ArrayIterator<Array<Type> >;
    using const_iterator = ArrayIterator<Array<Type>, const_pointer, const_reference>;
    using reverse_iterator = ArrayReverseIterator<Array<Type> >;
    using const_reverse_iterator = ArrayReverseIterator<Array<Type>, const_pointer, const_reference>;

  private:
    size_type capacity_;
    size_type size_;
    pointer data_;


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
    Array() : capacity_{0ull}, size_{0ull}, data_{nullptr} 
    {
    }

    explicit Array(size_type count, const_reference value) 
        : capacity_{calculate_capacity(count)}, size_{count}, data_{nullptr}
    {      
        allocate(capacity_);

        for (size_type i = 0; i < count; ++i)
            data_[i] = value;
    }
    ~Array() 
    {
        deallocate();
    }

    Array(std::initializer_list<value_type> initializer) 
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

    Array(Array&& other) noexcept : capacity_{other.capacity_}, size_{other.size_}, data_{other.data_}
    {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    Array(const Array& other) : Array()  
    {
        pointer new_data = new value_type[other.size_];
        for (size_type i = 0; i < other.size_; ++i)
            new_data[i] = other.data_[i];
        
        data_ = new_data;
        size_ = other.size_;
        capacity_ = size_;
    }

    template<typename InputIt>
    constexpr Array(InputIt first, InputIt last) : Array()
    {
        const size_type count = getDistance(first, last);
        capacity_ = calculate_capacity(count);
        allocate(capacity_);

        size_type i = 0;
        while (first != last)        
        {
            data_[i] = *first;
            ++i;
            ++first;
        }
        size_ = count;
    }

    // Array& operator

    Array& operator=(const Array& other)
    {
        // using namespace std;    // to enable ADL
        if (this == &other)
            return *this;

        Array temporary(other);
        *this = std::move(temporary);
        return *this;
    }

    Array& operator=(Array&& other) noexcept
    {
        if (this == &other)
            return *this;

        deallocate();

        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;

        return *this;
    }
    
    constexpr void Assign(size_type count, const_reference value)
    {
        Array temporary(count, value);
        *this = std::move(temporary);
    }

    template<typename InputIt>
    constexpr void Assign(InputIt first, InputIt last)
    {
        Array temporary(first, last);
        *this = std::move(temporary);
    }

    constexpr void Assign(std::initializer_list<value_type> list)
    {
        Array temporary(std::move(list));
        *this = std::move(temporary);
    }
    
    constexpr reference At(size_type pos)
    {
        if (pos >= size_ || pos < 0)
            throw std::out_of_range("Index is out of range!");
        return operator[](pos);
    }
    constexpr const_reference At(size_type pos) const
    {
        if (pos >= size_ || pos < 0)
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

        // const size_type new_actual_capacity = calculate_capacity(new_capacity);
        const size_type new_actual_capacity = new_capacity;
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


private:
void checkReallocateUpdatingIterator(size_type new_size, const_iterator& pos)
{
    if (new_size > capacity_) {
        const size_type pos_index = pos - cbegin();
        reallocate(calculate_capacity(new_size));
        pos = cbegin() + pos_index;
    }
}
iterator shiftBack(size_type shift, const_iterator pos_untill)
{
    assert(size_ + shift <= capacity_ && "Shifting is out of range!");
    size_ += shift;
    auto it = end() - 1;
    while (it - shift + 1 > pos_untill)
    {
        *it = *(it - shift);
        --it;
    }
    it -= (shift - 1);
    return it;
}

public:
    constexpr iterator Insert(const_iterator pos, const_reference value)
    {
        return Insert(pos, 1, value);
    }

    constexpr iterator Insert(const_iterator pos, value_type&& value)
    {
        const size_type new_size = size_ + 1;
        checkReallocateUpdatingIterator(new_size, pos);
        auto it = shiftBack(1, pos);
        *it = std::move(value);
        return it;
    }

    constexpr iterator Insert(const_iterator pos, size_type count, const_reference value)
    {
        const size_type new_size = size_ + count;
        checkReallocateUpdatingIterator(new_size, pos);
        auto it = shiftBack(count, pos);
        const auto it_result = it;
        for (size_type i = 0; i < count; ++i)
        {
            *it = value;
            ++it;
        }

        return it_result;
    }

    private:
    template<class InputIt>
    static size_type getDistance(InputIt first, InputIt last) noexcept
    {
        size_type count = 0;
        if constexpr(std::is_same_v<typename InputIt::iterator_category, std::random_access_iterator_tag>)
        {
            count = last - first;
        } 
        else 
        {
            while (first != last)
            {
                ++count;
                ++first;
            }
        }
        return count;
    }

    public:
    template<class InputIt>
    constexpr iterator Insert(const_iterator pos, InputIt first, InputIt last)
    {
        const size_type count = getDistance(first, last);
        const size_type new_size = size_ + count;
        checkReallocateUpdatingIterator(new_size, pos);
        auto it = shiftBack(count, pos);
        const auto it_result = it;

        while (first != last) {
            *it = *first;
            ++it;
            ++first;
        }

        return it_result;
    }

    constexpr iterator Insert(const_iterator pos, std::initializer_list<value_type> list)
    {
        const size_type new_size = size_ + list.size();
        checkReallocateUpdatingIterator(new_size, pos);
        auto it = shiftBack(list.size(), pos);
        const auto it_result = it;
        for (auto& element: list)
        {
            *it = std::move(element);
            ++it;
        }

        return it_result;
    }




    template<class... Args>
    constexpr iterator Emplace(const_iterator pos, Args&&... args)
    {
        const size_type new_size = size_ + 1;
        checkReallocateUpdatingIterator(new_size, pos);
        auto it = shiftBack(1, pos);
        *it = value_type(std::forward<Args>(args)...);
        return it;
    }

    private:
        iterator shiftForward(size_type shift, const_iterator pos_untill)
        {
            iterator it(static_cast<iterator>(pos_untill));
            assert(it - 2 < end() && "Shifting is out of range!");
            const iterator result = it - shift;
            while (it < end())
            {
                *(it - shift) = *it;
                ++it;
            }
            size_ -= shift;
            return result;
        }
    public:
        constexpr iterator Erase(const_iterator pos)
        {
            return shiftForward(1, pos + 1);
        }

        constexpr iterator Erase(const_iterator first, const_iterator last)
        {
            return shiftForward(last - first, last);
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

    constexpr void Pop_back()
    {
        --size_;
    }

    constexpr void Resize(size_type count)
    {
        Resize(count, value_type());
    }
    constexpr void Resize(size_type count, const_reference value)
    {
        if (count == size_)
            return;

        if (count < size_) {
            size_ = count;
            return;
        }

        Reserve(count);

        for (size_type i = size_; i < count; ++i)
            Push_back(value);

        size_ = count;
    }

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

    constexpr void Swap(Array& other) 
    {
        using namespace std;                    // to enable ADL
        swap(data_, other.data_);
        swap(size_, other.size_);
        swap(capacity_, other.capacity_);
    }
};

template <typename Type> bool operator==(const Array<Type> &left, const Array<Type> &right)
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

template <typename Type> bool operator!=(const Array<Type> &left, const Array<Type> &right)
{
    return !(left == right);
}

} // namespace s21

#endif //  _S21_ARRAY_H_
