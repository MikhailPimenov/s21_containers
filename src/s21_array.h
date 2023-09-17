#ifndef _S21_ARRAY_H_
#define _S21_ARRAY_H_

#include <cassert>
#include <initializer_list>
#include <iterator>
#include <new>
#include <cstring>

#include "s21_vector.h"

namespace s21
{

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
    using iterator = VectorIterator<Array<Type, N> >;
    using const_iterator = VectorIterator<Array<Type, N>, const_pointer, const_reference>;
    using reverse_iterator = VectorReverseIterator<Array<Type, N> >;
    using const_reverse_iterator = VectorReverseIterator<Array<Type, N>, const_pointer, const_reference>;


  private:
    value_type data_[N];

  public:
    Array() {
        for(std::size_t i = 0; i < N; i++)
            data_[i] = value_type();
    }

    Array(const Array& other) {
        for(std::size_t i = 0; i < N; i++)
            data_[i] = other.data_[i];
    }

    ~Array() {}

    Array(std::initializer_list<value_type> initializer) {
        assert(initializer.size() <= N && "wrong size");

        size_type i = 0ull;
        for (const auto& element : initializer) {
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
        if (this == &other)
            return *this;

        for (size_type i = 0; i < N; i++)
            data_[i] = other.data_[i];

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

    constexpr void Swap(Array& other) {
        for(std::size_t i = 0; i < N; i++) {
            const value_type copy = other.data_[i];
            other.data_[i] = data_[i];
            data_[i] = copy;
        }
    } 
};

template <typename Type, std::size_t N> 
bool operator==(const Array<Type, N> &left, const Array<Type, N> &right) {
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

template <typename Type, std::size_t N1, std::size_t N2> 
bool operator==(const Array<Type, N1>&, const Array<Type, N2>&) {
    return false;
}

template <typename Type, std::size_t N> 
bool operator!=(const Array<Type, N> &left, const Array<Type, N> &right) {
    return !(left == right);
}

template <typename Type, std::size_t N1, std::size_t N2> 
bool operator!=(const Array<Type, N1> &left, const Array<Type, N2> &right) {
    return !(left == right);
}

} // namespace s21

#endif //  _S21_ARRAY_H_
