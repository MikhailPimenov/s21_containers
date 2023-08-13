#ifndef _S21_MAP_H_
#define _S21_MAP_H_

#include <cassert>
#include <initializer_list>
#include <iterator>
#include <new>
#include <cstring>
#include <iostream>

namespace s21
{

template <typename Map, typename Pointer, typename Reference, typename Node_pointer, typename Difference_type,
          typename Key_type, typename Value_type>
// template <typename Vector, typename Pointer, typename Reference, typename Difference_type,
        //   typename Value_type>
class MapIteratorBase
{
  public:
    using difference_type = Difference_type;
    using value_type = Value_type;
    using key_type = Key_type;
    using pointer = Pointer;
    using reference = Reference;
    using iterator_category = std::random_access_iterator_tag;
    using node_pointer = Node_pointer;


    // template <typename OtherVector, typename OtherPointer, typename OtherReference, typename OtherDifference_type, typename OtherValue_type>
    // friend class VectorIteratorBase;  // to be able to compare iterator and const_iterator


  public:
    MapIteratorBase(node_pointer p) noexcept : pointer_{p} {}

    
    // template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    // VectorIteratorBase(const VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &other) noexcept 
    //     : VectorIteratorBase(const_cast<Pointer>(other.pointer_)) 
    // {

    // }

    
    MapIteratorBase(const MapIteratorBase &other) noexcept 
        : MapIteratorBase(other.pointer_) 
    {

    }


    // template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    // VectorIteratorBase(VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &&other) noexcept 
    //     : VectorIteratorBase(const_cast<Pointer>(other.pointer_))
    // {
    //     other.pointer_ = nullptr;
    // }

    MapIteratorBase(MapIteratorBase &&other) noexcept 
        : MapIteratorBase(other.pointer_)
    {
        other.pointer_ = nullptr;
    }
    
    friend void swap(MapIteratorBase &left, MapIteratorBase &right) noexcept
    {
        using namespace std; // to enable ADL
        swap(left.pointer_, right.pointer_);
    }

    virtual MapIteratorBase &operator++() noexcept = 0;

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



    MapIteratorBase &operator=(const MapIteratorBase &other) noexcept
    {
        pointer_ = other.pointer_;
        return *this;
    }

    MapIteratorBase &operator=(MapIteratorBase &&other) noexcept
    {
        pointer_ = other.pointer_;
        other.pointer_ = nullptr;
        return *this;
    }



    reference operator*() const noexcept
    {
        return pointer_->value_;
    }

    pointer operator->() const noexcept
    {
        return &(pointer_->value_);
    }

    // template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    // bool operator==(const VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &other) const noexcept
    // {
    //     return pointer_ == other.pointer_;
    // }
    bool operator==(const MapIteratorBase &other) const noexcept
    {
        return pointer_ == other.pointer_;
    }

    // template <typename OtherPointer, typename OtherReference>
    // bool operator!=(const VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &other) const noexcept
    // {
    //     return !(*this == other);
    // }
    
    bool operator!=(const MapIteratorBase &other) const noexcept
    {
        return !(*this == other);
    }

    explicit operator bool() const noexcept
    {
        return pointer_;
    }

   

  protected:
    node_pointer pointer_;
};

template <typename Map, typename Pointer = typename Map::pointer, typename Reference = typename Map::reference>
class MapIterator : public MapIteratorBase<Map, Pointer, Reference, typename Map::node_pointer, typename Map::difference_type, typename Map::key_type, typename Map::value_type>
{
  private:
    using Base = MapIteratorBase<Map, Pointer, Reference, typename Map::node_pointer, typename Map::difference_type, typename Map::key_type,
                                  typename Map::value_type>;
  public:
    using typename Base::difference_type;   // otherwise everywhere in this class 'typename Base::difference_type' instead of 'difference_type'

    // template<typename VectorType, typename PointerType, typename ReferenceType>
    // friend class VectorIterator;  // to compare const_iterator with iterator

  public:
    using Base::Base;

    MapIterator &operator++() noexcept override  // ++i
    {
        // ++(this->pointer_);
        return *this;
    }

    MapIterator operator++(int) noexcept         // i++
    {
        MapIterator temporary(*this);
        // ++(this->pointer_);
        return temporary;
    }

    MapIterator &operator--() noexcept
    {
        // --(this->pointer_);
        return *this;
    }

    MapIterator operator--(int) noexcept
    {
        MapIterator temporary(*this);
        // --(this->pointer_);
        return temporary;
    }

    operator int() const = delete;

    // // to enable creating iterator from const_iterator via static_cast
    // template <typename OtherPointer, typename OtherReference>
    // explicit operator VectorIterator<Vector, OtherPointer, OtherReference>() const noexcept
    // {
    //     return VectorIterator<Vector, OtherPointer, OtherReference>(const_cast<OtherPointer>(this->pointer_));
    // }
};

template <typename Map, typename Pointer = typename Map::pointer, typename Reference = typename Map::reference>
class MapReverseIterator : public MapIteratorBase<Map, Pointer, Reference, typename Map::node_pointer, typename Map::difference_type, typename Map::key_type, typename Map::value_type>
{
  private:
    using Base = MapIteratorBase<Map, Pointer, Reference, typename Map::node_pointer, typename Map::difference_type, typename Map::key_type,
                                  typename Map::value_type>;
  public:
    using typename Base::difference_type;   // otherwise everywhere in this class 'typename Base::difference_type' instead of 'difference_type'

    // template<typename VectorType, typename PointerType, typename ReferenceType>
    // friend class VectorIterator;  // to compare const_iterator with iterator

  public:
    using Base::Base;

    MapReverseIterator &operator++() noexcept override  // ++i
    {
        // --(this->pointer_);
        return *this;
    }

    MapReverseIterator operator++(int) noexcept         // i++
    {
        MapReverseIterator temporary(*this);
        // --(this->pointer_);
        return temporary;
    }

    MapReverseIterator &operator--() noexcept
    {
        // ++(this->pointer_);
        return *this;
    }

    MapReverseIterator operator--(int) noexcept
    {
        MapReverseIterator temporary(*this);
        // ++(this->pointer_);
        return temporary;
    }

    operator int() const = delete;

    // // to enable creating iterator from const_iterator via static_cast
    // template <typename OtherPointer, typename OtherReference>
    // explicit operator VectorIterator<Vector, OtherPointer, OtherReference>() const noexcept
    // {
    //     return VectorIterator<Vector, OtherPointer, OtherReference>(const_cast<OtherPointer>(this->pointer_));
    // }
};









template <typename Key, typename Type> class Map
{
    struct Node;
  public:
    using value_type = std::pair<const Key, Type>;
    using mapped_type = Type;
    using key_type = Key;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;

    using node_pointer = Node*;

  public:
    using iterator = MapIterator<Map<Key, Type>>;
    using const_iterator = MapIterator<Map<Key, Type>, const_pointer, const_reference>;
    // using reverse_iterator = VectorReverseIterator<Vector<Type> >;
    // using const_reverse_iterator = VectorReverseIterator<Vector<Type>, const_pointer, const_reference>;

  private:
    size_type size_;

    struct Node {
        value_type value_;  // key + value

        Node* root_;
        Node* left_;
        Node* right_;

        Node() : value_{key_type(), mapped_type()}, root_{nullptr}, left_{nullptr}, right_{nullptr} {}
        
        Node(const_reference value, Node* root = nullptr, Node* left = nullptr, Node* right = nullptr)
         : value_{value}, root_{root}, left_{left}, right_{right} {

        }
        Node(value_type&& value, Node* root = nullptr, Node* left = nullptr, Node* right = nullptr)
         : value_{std::move(value)}, root_{root}, left_{left}, right_{right} {

        }

    };
    Node* root_;
    mutable Node end_;
    mutable Node rend_;
    // pointer data_;


public:
    Map() : size_{0},  end_{}, rend_{}, root_{nullptr}
    {
        rend_.right_ = &end_;
        end_.left_ = &rend_;
    }

    size_type Size() const {
        return size_;
    } 


    // iterators============================================================

    iterator begin() {      // existing beginning
        return size_ ? iterator(rend_.root_) : end();
    }

    const_iterator cbegin() const {
        return size_ ? const_iterator(rend_.root_) : cend();
    }

    iterator end() {        // non-existing end
        return iterator(&end_);
    }

    const_iterator cend() const {
        return const_iterator(&end_);
    }


    

private:
    //modifiers==============================================================
    //         4
    //    2           6
    //  1   3       5    7
    Node* create_node(Node* root, const_reference value) {
        Node* new_node = new Node(value, root);
        ++size_;
        return new_node;
    }
    std::pair<iterator, bool> create_left_node(Node* root, const_reference value) {
        assert(root && "Root should always exist!");
        root->left_ = create_node(root, value);
        return std::make_pair(iterator(root->left_), true);
    }
    std::pair<iterator, bool> create_right_node(Node* root, const_reference value) {
        assert(root && "Root should always exist!");
        root->right_ = create_node(root, value);
        return std::make_pair(iterator(root->right_), true);
    }
    std::pair<iterator, bool> insert_recursive(Node* root, const_reference value) {
        assert(root && "Root should always exist!");
        // root always exists
        if (value.first < root->value_.first) {
            if (root->left_)
                return insert_recursive(root->left_, value);
            else
                return create_left_node(root, value);
        } else if (root->value_.first < value.first) {
            if (root->right_)
                return insert_recursive(root->right_, value);
            else 
                return create_right_node(root, value);
        }
        // equal
        return std::make_pair(iterator(root), false);
    }

public:
    std::pair<iterator, bool> Insert(const_reference value) {
        if (!root_)
            return std::make_pair(iterator(create_node(nullptr, value)), true);
        return insert_recursive(root_, value);
    }
    // template< class P >
    // std::pair<iterator, bool> insert( P&& value );
// (2)	(since C++11)
// std::pair<iterator, bool> insert( value_type&& value );
// (3)	(since C++17)
// (4)	

// iterator insert( const_iterator pos, const value_type& value );
// (since C++11)
// template< class P >
// iterator insert( const_iterator pos, P&& value );
// (5)	(since C++11)
// iterator insert( const_iterator pos, value_type&& value );
// (6)	(since C++17)
// template< class InputIt >
// void insert( InputIt first, InputIt last );
// (7)	
// void insert( std::initializer_list<value_type> ilist );
// (8)	(since C++11)
// insert_return_type insert( node_type&& nh );
// (9)	(since C++17)
// iterator insert( const_iterator pos, node_type&& nh );
// (10)	(since C++17)




//     private:
//         static size_type calculate_capacity(size_type count) {
//             size_type result = 1;
//             while (result <= count)
//                 result <<= 1;
//             return result - 1;
//         }

//         void allocate(size_type exact_count) 
//         {
//             assert(!data_ && "Possible memory leak!");
//             data_ = new value_type[exact_count];
//             capacity_ = exact_count;
//         }
//         void reallocate(size_type exact_count)
//         {
//             pointer new_data = new Type[exact_count];
//             size_type new_size = size_;
//             for (size_type i = 0; i < size_; ++i)
//                 new_data[i] = data_[i];
            
//             deallocate();
//             data_ = new_data;
//             size_ = new_size;
//             capacity_ = exact_count;
//         }
//         void deallocate() noexcept
//         {
//             delete[] data_;
//             data_ = nullptr;
//             capacity_ = 0;
//             size_ = 0;
//         }

//   public:
//     Vector() : capacity_{0ull}, size_{0ull}, data_{nullptr} 
//     {
//     }

//     explicit Vector(size_type count, const_reference value) 
//         : capacity_{calculate_capacity(count)}, size_{count}, data_{nullptr}
//     {      
//         allocate(capacity_);

//         for (size_type i = 0; i < count; ++i)
//             data_[i] = value;
//     }
//     ~Vector() 
//     {
//         deallocate();
//     }

//     Vector(std::initializer_list<value_type> initializer) 
//         : capacity_{calculate_capacity(initializer.size())}, size_{initializer.size()}, data_{nullptr}
//     {
//         allocate(capacity_);


//         size_type i = 0;
//         for (const auto& element : initializer)
//         {
//             data_[i] = element;
//             ++i;
//         }            
//     }

//     Vector(Vector&& other) noexcept : capacity_{other.capacity_}, size_{other.size_}, data_{other.data_}
//     {
//         other.data_ = nullptr;
//         other.size_ = 0;
//         other.capacity_ = 0;
//     }

//     Vector(const Vector& other) : Vector()  
//     {
//         pointer new_data = new value_type[other.size_];
//         for (size_type i = 0; i < other.size_; ++i)
//             new_data[i] = other.data_[i];
        
//         data_ = new_data;
//         size_ = other.size_;
//         capacity_ = size_;
//     }

//     template<typename InputIt>
//     constexpr Vector(InputIt first, InputIt last) : Vector()
//     {
//         const size_type count = getDistance(first, last);
//         capacity_ = calculate_capacity(count);
//         allocate(capacity_);

//         size_type i = 0;
//         while (first != last)        
//         {
//             data_[i] = *first;
//             ++i;
//             ++first;
//         }
//         size_ = count;
//     }

//     // Vector& operator

//     Vector& operator=(const Vector& other)
//     {
//         // using namespace std;    // to enable ADL
//         if (this == &other)
//             return *this;

//         Vector temporary(other);
//         *this = std::move(temporary);
//         return *this;
//     }

//     Vector& operator=(Vector&& other) noexcept
//     {
//         if (this == &other)
//             return *this;

//         deallocate();

//         data_ = other.data_;
//         size_ = other.size_;
//         capacity_ = other.capacity_;

//         other.data_ = nullptr;
//         other.size_ = 0;
//         other.capacity_ = 0;

//         return *this;
//     }
    
//     constexpr void Assign(size_type count, const_reference value)
//     {
//         Vector temporary(count, value);
//         *this = std::move(temporary);
//     }

//     template<typename InputIt>
//     constexpr void Assign(InputIt first, InputIt last)
//     {
//         Vector temporary(first, last);
//         *this = std::move(temporary);
//     }

//     constexpr void Assign(std::initializer_list<value_type> list)
//     {
//         Vector temporary(std::move(list));
//         *this = std::move(temporary);
//     }
    
//     constexpr reference At(size_type pos)
//     {
//         if (pos >= size_ || pos < 0)
//             throw std::out_of_range("Index is out of range!");
//         return operator[](pos);
//     }
//     constexpr const_reference At(size_type pos) const
//     {
//         if (pos >= size_ || pos < 0)
//             throw std::out_of_range("Index is out of range!");
//         return operator[](pos);
//     }

//     reference operator[](size_type pos)
//     {
//         return data_[pos];
//     }
//     const_reference operator[](size_type pos) const
//     {
//         return data_[pos];
//     }

//     constexpr reference Front()
//     {
//         return data_[0];
//     }
//     constexpr const_reference Front() const
//     {
//         return data_[0];
//     }

//     constexpr reference Back()
//     {
//         return data_[size_ - 1];
//     }
//     constexpr const_reference Back() const
//     {
//         return data_[size_ - 1];
//     }

//     constexpr pointer Data() noexcept
//     {
//         return data_;
//     }
//     constexpr const_pointer Data() const noexcept
//     {
//         return data_;
//     }

//     size_type Size() const noexcept
//     {
//         return size_;
//     }
//     size_type Capacity() const noexcept
//     {
//         return capacity_;
//     }

//     constexpr void Reserve(size_type new_capacity)
//     {
//         if (new_capacity <= capacity_) 
//             return;

//         // const size_type new_actual_capacity = calculate_capacity(new_capacity);
//         const size_type new_actual_capacity = new_capacity;
//         reallocate(new_actual_capacity);
//     }

//     constexpr void Shrink_to_fit()
//     {
//         if (capacity_ > size_)
//             reallocate(size_);
//     }

//     void Clear()
//     {
//         deallocate();
//     }

//     bool Empty() const noexcept
//     {
//         return size_ == 0ull;
//     }


//     iterator begin()
//     {
//         return iterator(data_);
//     }
//     const_iterator begin() const
//     {
//         // return cbegin();
//         return const_iterator(data_);
//     }
 
//     const_iterator cbegin() const
//     {
//         return const_iterator(data_);
//     }


//     reverse_iterator rbegin()
//     {
//         return reverse_iterator(data_ + size_ - 1);
//     }
//     const_reverse_iterator rbegin() const
//     {
//         return crbegin();
//     }
//     const_reverse_iterator crbegin() const
//     {
//         return const_reverse_iterator(data_ + size_ - 1);
//     }


//     iterator end()
//     {
//         return iterator(data_ + size_);
//     }
//     const_iterator end() const
//     {
//         return cend();
//     }
//     const_iterator cend() const
//     {
//         return const_iterator(data_ + size_);
//     }


//     reverse_iterator rend()
//     {
//         return reverse_iterator(data_ - 1);
//     }
//     const_reverse_iterator rend() const
//     {
//         return crend();
//     }
//     const_reverse_iterator crend() const
//     {
//         return const_reverse_iterator(data_ - 1);
//     }


// private:
// void checkReallocateUpdatingIterator(size_type new_size, const_iterator& pos)
// {
//     if (new_size > capacity_) {
//         const size_type pos_index = pos - cbegin();
//         reallocate(calculate_capacity(new_size));
//         pos = cbegin() + pos_index;
//     }
// }
// iterator shiftBack(size_type shift, const_iterator pos_untill)
// {
//     assert(size_ + shift <= capacity_ && "Shifting is out of range!");
//     size_ += shift;
//     auto it = end() - 1;
//     while (it - shift + 1 > pos_untill)
//     {
//         *it = *(it - shift);
//         --it;
//     }
//     it -= (shift - 1);
//     return it;
// }

// public:
//     constexpr iterator Insert(const_iterator pos, const_reference value)
//     {
//         return Insert(pos, 1, value);
//     }

//     constexpr iterator Insert(const_iterator pos, value_type&& value)
//     {
//         const size_type new_size = size_ + 1;
//         checkReallocateUpdatingIterator(new_size, pos);
//         auto it = shiftBack(1, pos);
//         *it = std::move(value);
//         return it;
//     }

//     constexpr iterator Insert(const_iterator pos, size_type count, const_reference value)
//     {
//         const size_type new_size = size_ + count;
//         checkReallocateUpdatingIterator(new_size, pos);
//         auto it = shiftBack(count, pos);
//         const auto it_result = it;
//         for (size_type i = 0; i < count; ++i)
//         {
//             *it = value;
//             ++it;
//         }

//         return it_result;
//     }

//     private:
//     template<class InputIt>
//     static size_type getDistance(InputIt first, InputIt last) noexcept
//     {
//         size_type count = 0;
//         if constexpr(std::is_same_v<typename InputIt::iterator_category, std::random_access_iterator_tag>)
//         {
//             count = last - first;
//         } 
//         else 
//         {
//             while (first != last)
//             {
//                 ++count;
//                 ++first;
//             }
//         }
//         return count;
//     }

//     public:
//     template<class InputIt>
//     constexpr iterator Insert(const_iterator pos, InputIt first, InputIt last)
//     {
//         const size_type count = getDistance(first, last);
//         const size_type new_size = size_ + count;
//         checkReallocateUpdatingIterator(new_size, pos);
//         auto it = shiftBack(count, pos);
//         const auto it_result = it;

//         while (first != last) {
//             *it = *first;
//             ++it;
//             ++first;
//         }

//         return it_result;
//     }

//     constexpr iterator Insert(const_iterator pos, std::initializer_list<value_type> list)
//     {
//         const size_type new_size = size_ + list.size();
//         checkReallocateUpdatingIterator(new_size, pos);
//         auto it = shiftBack(list.size(), pos);
//         const auto it_result = it;
//         for (auto& element: list)
//         {
//             *it = std::move(element);
//             ++it;
//         }

//         return it_result;
//     }




//     template<class... Args>
//     constexpr iterator Emplace(const_iterator pos, Args&&... args)
//     {
//         const size_type new_size = size_ + 1;
//         checkReallocateUpdatingIterator(new_size, pos);
//         auto it = shiftBack(1, pos);
//         *it = value_type(std::forward<Args>(args)...);
//         return it;
//     }

//     private:
//         iterator shiftForward(size_type shift, const_iterator pos_untill)
//         {
//             iterator it(static_cast<iterator>(pos_untill));
//             assert(it - 2 < end() && "Shifting is out of range!");
//             const iterator result = it - shift;
//             while (it < end())
//             {
//                 *(it - shift) = *it;
//                 ++it;
//             }
//             size_ -= shift;
//             return result;
//         }
//     public:
//         constexpr iterator Erase(const_iterator pos)
//         {
//             return shiftForward(1, pos + 1);
//         }

//         constexpr iterator Erase(const_iterator first, const_iterator last)
//         {
//             return shiftForward(last - first, last);
//         }









//     constexpr void Push_back(const_reference element)
//     {
//         size_type old_size = size_;
//         size_type new_size = size_ + 1;

//         if (new_size > capacity_)
//         {
//             size_type new_capacity = calculate_capacity(new_size);
//             reallocate(new_capacity);
//         }
//         data_[old_size] = element;
//         size_ = new_size;
//     };

//     constexpr void Push_back(value_type&& element)
//     {
//         size_type old_size = size_;
//         size_type new_size = size_ + 1;

//         if (new_size > capacity_)
//         {
//             size_type new_capacity = calculate_capacity(new_size);
//             reallocate(new_capacity);
//         }
//         data_[old_size] = std::move(element);
//         size_ = new_size;
//     };

//     constexpr void Pop_back()
//     {
//         --size_;
//     }

//     constexpr void Resize(size_type count)
//     {
//         Resize(count, value_type());
//     }
//     constexpr void Resize(size_type count, const_reference value)
//     {
//         if (count == size_)
//             return;

//         if (count < size_) {
//             size_ = count;
//             return;
//         }

//         Reserve(count);

//         for (size_type i = size_; i < count; ++i)
//             Push_back(value);

//         size_ = count;
//     }

//     template<typename... Args>
//     constexpr void Emplace_back(Args&&... args)
//     {
//         size_type old_size = size_;
//         size_type new_size = size_ + 1;

//         if (new_size > capacity_)
//         {
//             size_type new_capacity = calculate_capacity(new_size);
//             reallocate(new_capacity);
//         }
//         data_[old_size] = value_type(std::forward<Args>(args)...);
//         size_ = new_size;
//     }

//     constexpr void Swap(Vector& other) 
//     {
//         using namespace std;                    // to enable ADL
//         swap(data_, other.data_);
//         swap(size_, other.size_);
//         swap(capacity_, other.capacity_);
//     }

    // template<typename Key2, typename Type2>
    friend std::ostream& operator<<(std::ostream& out, const Node& root);


    // template<typename Key2, typename Type2>
    friend std::ostream& operator<<(std::ostream& out, const Map& s21_map);


};

template <typename Key, typename Type>
bool operator==(const s21::Map<Key, Type>& left, const s21::Map<Key, Type>& right) {
    if(left.Size() != right.Size())
        return false;
    
    auto it_left = left.cbegin();
    auto it_right = right.cbegin();


    while(it_left != left.cend()) {
        // assert(0 && "Azaza");
        if(*it_left != *it_right) 
            return false;
        
        it_left++;
        it_right++;
        
    }

    return true;   
}


// int* p = 0x00000001;
// std::cout << p;
// operator<<(std::ostream& ,  int*)

template<typename Key, typename Type>
std::ostream& operator<<(std::ostream& out, const typename s21::Map<Key, Type>::Node& root) {
    assert(0 && "print");
    if (!root.left_) {
        out << "{" << root.value_->first << " : " << root.value_->second << "}, ";
        return out;
    }

    out << root.left_;
    out << "{" << root.value_->first << " : " << root.value_->second << "}, ";
    if (!root.right_)
        out << root.right_;

    return out;
}



template<typename Key, typename Type>
std::ostream& operator<<(std::ostream& out, const s21::Map<Key, Type>& s21_map) {
    out << "Map " << s21_map.size_ << "\n";
    out << (*(s21_map.root_));
    return out;
}
// template <typename Type> bool operator==(const Vector<Type> &left, const Vector<Type> &right)
// {
//     if (left.Size() != right.Size())
//         return false;

//     auto left_iterator = left.cbegin();
//     auto right_iterator = right.cbegin();

//     while (left_iterator != left.cend())
//     {
//         if (*left_iterator != *right_iterator)
//             return false;
//         ++left_iterator;
//         ++right_iterator;
//     }

//     return true;
// }

// template <typename Type> bool operator!=(const Vector<Type> &left, const Vector<Type> &right)
// {
//     return !(left == right);
// }

} // namespace s21

#endif //  _S21_MAP_H_
