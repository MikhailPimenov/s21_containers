#ifndef _S21_MAP_H_
#define _S21_MAP_H_

#include <cassert>
#include <initializer_list>
#include <iterator>
#include <new>
#include <cstring>

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

    // MapIteratorBase &operator++() noexcept
    // {
    //     pointer_;
    //     ++
    // }

    // MapIteratorBase &operator--() noexcept
    // {
    //     --
    // }


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
    using typename Base::node_pointer;

    // template<typename VectorType, typename PointerType, typename ReferenceType>
    // friend class VectorIterator;  // to compare const_iterator with iterator

  public:
    using Base::Base;

    //          1
    //              4
    //                  6
    //                      7

    //          4
    //     1        6
    //                  7

    //                          
    //                4
    //          2               6
    //        1   3       5          7
    //     re         4.5  5.5
    /*
    Tree* next(Tree* node) {
    // if no children -> go up
    // if right exists -> go right
    if (!node->_left && !node->_right) {
        while (1) {
            // find greater root
            if (!node->_root)
                return NULL;
            Tree* root = node->_root;
            if (root->_data > node->_data)
                return root;
            node = node->_root; 
        }
    }

    if (!node->_right)
        return node;
        
    node = node->_right;
    
    while(1) {
        if (node->_left)
            node = node->_left;
        else
            return node;
    }
    
    return node;
}
    */

    // MapIterator &operator++() noexcept override  // ++i
    MapIterator &operator++() noexcept  // ++i
    {
        if (!this->pointer_->right_) {
            node_pointer temp = this->pointer_;
            while (true) {
                // find greater root
                if (!this->pointer_->root_) {
                    this->pointer_ = temp->right_;  // temp->right_ may be nullptr
                    return *this;
                }
                node_pointer root = this->pointer_->root_;
                // if we are in left subtree - root is greater
                if (root->left_ && root->left_ == this->pointer_) {
                // if (root->value_.first > temp->value_.first) {
                    this->pointer_ = root;
                    return *this;
                }
                this->pointer_ = this->pointer_->root_; 
            }
        }

        if (!this->pointer_->right_)
            return *this;
        
        this->pointer_ = this->pointer_->right_;
    
        while(true) {
            if (this->pointer_->left_)
                this->pointer_ = this->pointer_->left_;
            else
                return *this;
        }
    
        return *this;
    }

    MapIterator operator++(int) noexcept         // i++
    {
        MapIterator temporary(*this);
        // ++(this->pointer_);
        return temporary;
    }


    //                          
    //                    4
    //             2                 6
    //        1      3         5          7
    //     re  1.5    3.5   4.5  5.5        e
    MapIterator &operator--() noexcept
    {
        if (!this->pointer_->left_) {
            node_pointer temp = this->pointer_;
            while (true) {
                // find lower root
                if (!this->pointer_->root_) {
                    this->pointer_ = temp->left_;       // temp->left_ may be nullptr
                    return *this;
                }
                node_pointer root = this->pointer_->root_;
                // if we are in left subtree - root is greater
                if (root->right_ && root->right_ == this->pointer_) { // root is lower

                // if (root->value_.first < temp->value_.first) {  // TODO: sign of comparison
                    this->pointer_ = root;
                    return *this;
                }
                this->pointer_ = this->pointer_->root_; 
            }
        }

        if (!this->pointer_->left_)
            return *this;
        
        this->pointer_ = this->pointer_->left_;
    
        while(true) {
            if (this->pointer_->right_)
                this->pointer_ = this->pointer_->right_;
            else
                return *this;
        }
    
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

    // MapReverseIterator &operator++() noexcept override  // ++i
    MapReverseIterator &operator++() noexcept  // ++i
    { 
        // --(this->pointer_);
        if (!this->pointer_->left_) {
            typename Map::node_pointer temp = this->pointer_;   // очень странная херь!! проверить===============
            while (true) {
                // find lower root
                if (!this->pointer_->root_) {
                    this->pointer_ = temp->left_;       // temp->left_ may be nullptr
                    return *this;
                }
                typename Map::node_pointer root = this->pointer_->root_;
                // if we are in left subtree - root is greater
                if (root->right_ && root->right_ == this->pointer_) { // root is lower

                // if (root->value_.first < temp->value_.first) {  // TODO: sign of comparison
                    this->pointer_ = root;
                    return *this;
                }
                this->pointer_ = this->pointer_->root_; 
            }
        }

        if (!this->pointer_->left_)
            return *this;
        
        this->pointer_ = this->pointer_->left_;
    
        while(true) {
            if (this->pointer_->right_)
                this->pointer_ = this->pointer_->right_;
            else
                return *this;
        }

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
        if (!this->pointer_->right_) {
            typename Map::node_pointer temp = this->pointer_;
            while (true) {
                // find greater root
                if (!this->pointer_->root_) {
                    this->pointer_ = temp->right_;  // temp->right_ may be nullptr
                    return *this;
                }
                typename Map::node_pointer root = this->pointer_->root_;
                // if we are in left subtree - root is greater
                if (root->left_ && root->left_ == this->pointer_) {
                // if (root->value_.first > temp->value_.first) {
                    this->pointer_ = root;
                    return *this;
                }
                this->pointer_ = this->pointer_->root_; 
            }
        }

        if (!this->pointer_->right_)
            return *this;
        
        this->pointer_ = this->pointer_->right_;
    
        while(true) {
            if (this->pointer_->left_)
                this->pointer_ = this->pointer_->left_;
            else
                return *this;
        }
    
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
    using reverse_iterator = MapReverseIterator<Map<Key, Type> >;
    using const_reverse_iterator = MapReverseIterator<Map<Key, Type>, const_pointer, const_reference>;

  private:
    size_type size_;

private:
    struct Node {
        value_type value_;  // key + value

        Node* root_;
        Node* left_;
        Node* right_;

        // Map& owner_;

        Node() : value_{key_type(), mapped_type()}, root_{nullptr}, left_{nullptr}, right_{nullptr} {}
        
        Node(const_reference value, Node* root = nullptr, Node* left = nullptr, Node* right = nullptr)
         : value_{value}, root_{root}, left_{left}, right_{right} {

        }
        Node(value_type&& value, Node* root = nullptr, Node* left = nullptr, Node* right = nullptr)
         : value_{std::move(value)}, root_{root}, left_{left}, right_{right} {
 
        }

    };
    Node* root_;
    mutable Node end_;      // non-existing element, element after last existing element
    mutable Node rend_;     // non-existing element, element before begin
    // pointer data_;


public:
    Map() : size_{0},  end_{}, rend_{}, root_{nullptr}
    {
        rend_.root_ = &end_;
        end_.root_ = &rend_;
    }

    size_type Size() const {
        return size_;
    } 

    // Map<int, float> m1;
    // Map<int, float>::iterator azaza = m1.begin();
    // ++azaza;
    // iterators============================================================

    iterator begin() {          // existing beginning
        return size_ ? iterator(rend_.root_) : end();
    }

    reverse_iterator rbegin() {          
        return size_ ? reverse_iterator(end_.root_) : rend();
    }

    const_iterator begin() const {    // existing beginning
        return cbegin();
    }

    const_reverse_iterator rbegin() const {    
        return rbegin();
    }

    const_iterator cbegin() const {
        return size_ ? const_iterator(rend_.root_) : cend();
    }

    iterator end() {        // non-existing end
        return iterator(&end_);
    }

    reverse_iterator rend() {        // non-existing begin
        return reverse_iterator(&rend_);
    }

    const_iterator end() const {
        return cend();
    }

    const_reverse_iterator rend() const {
        return crend();
    }

    const_iterator cend() const {
        return const_iterator(&end_);
    }

    const_reverse_iterator crend() const {
        return const_iterator(&rend_);
    }


    

private:
    //modifiers==============================================================
    //         4
    //    2           6
    //  1   3       5    7
    //                      8
    Node* create_node(Node* root, const_reference value) {
        Node* new_node = new Node(value, root);
        ++size_;
        return new_node;
    }

    void updateEnd() {
        assert(root_ && "Root should always exist!");
        Node* new_end = root_;
        while (new_end->right_ != nullptr && new_end->right_ != &end_) {
            new_end = new_end->right_;
        }
        end_.root_ = new_end;
        new_end->right_ = &end_;     // otherwise it will not stop when if (new_end->right_)
    }

    void updateReverseEnd() {
        assert(root_ && "Root should always exist!");
        Node* new_end = root_;
        while (new_end->left_ && new_end->left_ != &rend_) {
            new_end = new_end->left_;
        }
        rend_.root_ = new_end;
        new_end->left_ = &rend_;     // otherwise it will not stop when if (new_end->left_)
    }

    //       4

    std::pair<iterator, bool> insert_recursive(Node* root, const_reference value) {
        assert(root && "Root should always exist!");
        // root always exists
        if (value.first < root->value_.first) {
            if (root->left_ != nullptr && root->left_ != &rend_) {
                return insert_recursive(root->left_, value);
            } else {
                root->left_ = create_node(root, value);
                updateReverseEnd();
                return std::make_pair(iterator(root->left_), true);
            }
        } else if (root->value_.first < value.first) {
            if (root->right_ != nullptr && root->right_ != &end_) {
                return insert_recursive(root->right_, value);
            } else {
                root->right_ = create_node(root, value);
                updateEnd();
                return std::make_pair(iterator(root->right_), true);
            }
        }
        // equal
        return std::make_pair(iterator(root), false);
    }

public:
    std::pair<iterator, bool> Insert(const_reference value) {
        if (!root_) {
            root_ = create_node(nullptr, value);
            updateReverseEnd();
            updateEnd();
            return std::make_pair(iterator(root_), true);
        }
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


// int main() {
//     s21::Map<int, double> m;
//     m.Insert(std::make_pair(1, 1.1));
//     m.Insert(std::make_pair(1, 4.4));
//     m.Insert(std::make_pair(2, 2.2));
//     m.Insert(std::make_pair(3, 3.3));
    
//     std::cout << m;
//     return 0;
// }
#endif //  _S21_MAP_H_
