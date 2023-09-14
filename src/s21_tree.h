#ifndef _TESTS_S21_TREE_H_
#define _TESTS_S21_TREE_H_

#include <cassert>

#include "s21_vector.h"

namespace s21 {

namespace Tree {

template <typename Value, typename size_type = std::size_t>
class Node {
public:
    Value value_;

    Node* root_;
    Node* left_;
    Node* right_;

    size_type lHeight_;
    size_type rHeight_;

public:
    Node(const Value& value = Value(), Node* root = nullptr, Node* left = nullptr, Node* right = nullptr, size_type lHeight = 0ull, size_type rHeight = 0ull)
        : value_{value}, root_{root}, left_{left}, right_{right}, lHeight_{lHeight}, rHeight_{rHeight} {}
    Node(Value&& value, Node* root = nullptr, Node* left = nullptr, Node* right = nullptr, size_type lHeight = 0ull, size_type rHeight = 0ull)
        : value_{std::move(value)}, root_{root}, left_{left}, right_{right}, lHeight_{lHeight}, rHeight_{rHeight} {}

    Node(const Node& other) : Node(other.value, other.root, other.left, other.right, other.lHeight, other.rHeight) {}
    Node(Node&& other) : Node(std::move(other.value), other.root, other.left, other.right, other.lHeight, other.rHeight) {}
    Node& operator=(const Node& other) {
        if (this == &other)
            return *this;

        Node temporary(other);
        *this = std::move(other);

        return *this;
    }
    Node& operator=(Node&& other) {
        if (this == &other)
            return *this;
        
        value_ = std::move(other.value_);
        lHeight_ = other.lHeight_;
        rHeight_ = other.rHeight_;
        root_ = other.root_;
        left_ = other.left_;
        right_ = other.right_;

        other.lHeight_ = 0ull;
        other.rHeight_ = 0ull;
        other.root_ = nullptr;
        other.left_ = nullptr;
        other.right_ = nullptr;

        return *this;
    } 
};






template <typename Tree, typename Pointer, typename Reference, typename Node_pointer, typename Difference_type>
class TreeIteratorBase
{
  public:
    using difference_type = Difference_type;
    // using value_type = Value_type;
    //using key_type = Key_type;
    using pointer = Pointer;
    using reference = Reference;
    using size_type = typename Tree::size_type;
    using iterator_category = std::bidirectional_iterator_tag;
    using node_pointer = Node_pointer;

private:



    // template <typename OtherVector, typename OtherPointer, typename OtherReference, typename OtherDifference_type, typename OtherValue_type>
    // friend class VectorIteratorBase;  // to be able to compare iterator and const_iterator


  public:
    TreeIteratorBase(node_pointer p) noexcept : pointer_{p} {}


    // template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    // VectorIteratorBase(const VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &other) noexcept
    //     : VectorIteratorBase(const_cast<Pointer>(other.pointer_))
    // {

    // }


    TreeIteratorBase(const TreeIteratorBase &other) noexcept
        : TreeIteratorBase(other.pointer_) {
    }


    // template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    // VectorIteratorBase(VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &&other) noexcept
    //     : VectorIteratorBase(const_cast<Pointer>(other.pointer_))
    // {
    //     other.pointer_ = nullptr;
    // }

    TreeIteratorBase(TreeIteratorBase &&other) noexcept
        : TreeIteratorBase(other.pointer_) {
        other.pointer_ = nullptr;
    }

    friend void swap(TreeIteratorBase &left, TreeIteratorBase &right) noexcept
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



    TreeIteratorBase &operator=(const TreeIteratorBase &other) noexcept
    {
        pointer_ = other.pointer_;
        return *this;
    }

    TreeIteratorBase &operator=(TreeIteratorBase &&other) noexcept
    {
        pointer_ = other.pointer_;
        other.pointer_ = nullptr;
        return *this;
    }










 
    //          0 1 2
    // 6 7 8            2 1 0
    TreeIteratorBase& operator++() noexcept  // ++i
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
                    this->pointer_ = root;
                    return *this;
                }
                this->pointer_ = this->pointer_->root_;
            }
        }

        if (!this->pointer_->right_)
            return *this;

        this->pointer_ = this->pointer_->right_;

        while (true) {
            if (this->pointer_->left_)
                this->pointer_ = this->pointer_->left_;
            else
                return *this;
        }

        return *this;
    }
    //                4
    //      2                   8
    //                       6
    //                      5       
    //                                         

    TreeIteratorBase& operator--() noexcept  // ++i
    {
        if (!this->pointer_->left_) {
            node_pointer temp = this->pointer_; 
            while (true) {
                // find lower root
                if (!this->pointer_->root_) {
                    this->pointer_ = temp->left_;       // not existing rend_
                    return *this;
                }
                node_pointer root = this->pointer_->root_;
                // // if we are in left subtree - root is greater
                if (root->right_ && root->right_ == this->pointer_) { // root is lower
                    this->pointer_ = root;
                    return *this;
                }
                this->pointer_ = root;               
            }
        }

        if (!this->pointer_->left_) {
            return *this;
        }

        this->pointer_ = this->pointer_->left_;

        while (true) {
            if (this->pointer_->right_)
                this->pointer_ = this->pointer_->right_;
            else {
                return *this;
            }
        }

        return *this;
    }


    // reference operator*() noexcept
    // {
    //     return pointer_->Get(shift_);
    // }
    reference operator*() const noexcept
    {
        return pointer_->value_;
    }

    pointer operator->() noexcept
    {
        return &(pointer_->value_);
    }

    //pointer operator->() const noexcept
    //{
    //    return &(pointer_->Get(shift_));
    //}

    size_type LeftHeight() const noexcept
    {
        return pointer_->lHeight_;
    }

    size_type RightHeight() const noexcept
    {
        return pointer_->rHeight_;
    }


    // template <typename OtherPointer, typename OtherReference> // to be able to compare iterator and const_iterator
    // bool operator==(const VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &other) const noexcept
    // {
    //     return pointer_ == other.pointer_;
    // }
    bool operator==(const TreeIteratorBase &other) const noexcept
    {
        return pointer_ == other.pointer_;
    }

    // template <typename OtherPointer, typename OtherReference>
    // bool operator!=(const VectorIteratorBase<Vector, OtherPointer, OtherReference, Difference_type, Value_type> &other) const noexcept
    // {
    //     return !(*this == other);
    // }

    bool operator!=(const TreeIteratorBase &other) const noexcept
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

template <typename Tree,
          typename Pointer = typename Tree::pointer, 
          typename Reference = typename Tree::reference, 
          typename Node_pointer = typename Tree::base_node_pointer>
class TreeIterator : public TreeIteratorBase<Tree, 
                                             Pointer, 
                                             Reference, 
                                             Node_pointer, 
                                             typename Tree::difference_type>
{
    // template<typename K, typename V, typename C>
    // friend class Map;  // to compare const_iterator with iterator

    // template<typename V, typename C, typename N>
    friend Tree;  // to compare const_iterator with iterator


  private:
    using Base = TreeIteratorBase<Tree, Pointer, Reference, Node_pointer, typename Tree::difference_type>;
  public:
    using typename Base::difference_type;   // otherwise everywhere in this class 'typename Base::difference_type' instead of 'difference_type'
    using typename Base::node_pointer;
    using typename Base::reference;

    // template<typename VectorType, typename PointerType, typename ReferenceType>
    // friend class VectorIterator;  // to compare const_iterator with iterator

  public:
    using Base::Base;

    TreeIterator& operator++() noexcept  // ++i
    {
        Base::operator++();
        return *this;
    }
    TreeIterator& operator--() noexcept  // --i
    {
        Base::operator--();
        return *this;
    }
    // TODO: postfix form ++ -- + tests

    TreeIterator operator++(int) noexcept {
        TreeIterator temp = *this;
        Base::operator++();

        return temp;
    }

    TreeIterator operator--(int) noexcept {
        TreeIterator temp = *this;
        Base::operator--();

        return temp;
    }


    operator int() const = delete;

    // to enable creating iterator from const_iterator via static_cast
private:
    template <typename OtherPointer, typename OtherReference, typename OtherNode_pointer>
    explicit operator TreeIterator<Tree, OtherPointer, OtherReference, OtherNode_pointer>() const noexcept
    {
        return TreeIterator<Tree, OtherPointer, OtherReference, OtherNode_pointer>(const_cast<OtherNode_pointer>(this->pointer_));
    }
};

template <typename Tree, 
          typename Pointer = typename Tree::pointer, 
          typename Reference = typename Tree::reference, 
          typename Node_pointer = typename Tree::base_node_pointer>
class TreeReverseIterator : public TreeIteratorBase<Tree, 
                                                    Pointer, 
                                                    Reference, 
                                                    Node_pointer,
                                                    typename Tree::difference_type>
{
  private:
    using Base = TreeIteratorBase<Tree, Pointer, Reference, Node_pointer, typename Tree::difference_type>;
  public:
    using typename Base::difference_type;   // otherwise everywhere in this class 'typename Base::difference_type' instead of 'difference_type'
    using typename Base::node_pointer;
    using typename Base::reference;
//     // template<typename VectorType, typename PointerType, typename ReferenceType>
//     // friend class VectorIterator;  // to compare const_iterator with iterator

  public:
    using Base::Base;

    TreeReverseIterator& operator++() noexcept  // ++i
    {
        Base::operator--();
        return *this;
    }
    TreeReverseIterator& operator--() noexcept  // --i
    {
        Base::operator++();
        return *this;
    }

    TreeReverseIterator operator++(int) noexcept {
        TreeReverseIterator temp = *this;
        Base::operator--();

        return temp;
    }

    TreeReverseIterator operator--(int) noexcept {
        TreeReverseIterator temp = *this;
        Base::operator++();

        return temp;
    }


    operator int() const = delete;

private:
    template <typename OtherPointer, typename OtherReference, typename OtherNode_pointer>
    explicit operator TreeReverseIterator<Tree, OtherPointer, OtherReference, OtherNode_pointer>() const noexcept
    {
        return TreeReverseIterator<Tree, OtherPointer, OtherReference, OtherNode_pointer>(const_cast<OtherNode_pointer>(this->pointer_));
    }
};








template <typename Key,
          typename Value, 
          typename Comparator> 

// template <typename Value, 
//           typename Comparator> 
class Tree
{

public:
    using key_type = Key;
    using value_type = Value;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;

    using node_type = Node<value_type, size_type>;
    using base_node_type = Node<value_type, size_type>;
    using node_pointer = Node<value_type, size_type>*;
    using base_node_pointer = Node<value_type, size_type>*;
    using const_node_pointer = const Node<value_type, size_type>*;
    using const_base_node_pointer = const Node<value_type, size_type>*;
    using comparator = Comparator;
  private:
    size_type size_; 

private:
    
private:
    base_node_pointer root_;
    mutable node_type end_;      // non-existing element, element after last existing element
    mutable node_type rend_;     // non-existing element, element before begin

private:
    comparator comparator_;

  public:
    using iterator = TreeIterator<Tree<Key, Value, Comparator> >;
    using const_iterator = TreeIterator<Tree<Key, Value, Comparator>, const_pointer, const_reference, const_base_node_pointer>;
    using reverse_iterator = TreeReverseIterator<Tree<Key, Value, Comparator> >;
    using const_reverse_iterator = TreeReverseIterator<Tree<Key, Value, Comparator>, const_pointer, const_reference, const_base_node_pointer>;

public:
    Tree() : size_{0},  end_{}, rend_{}, root_{nullptr} {}
    Tree(std::initializer_list<value_type> list) : Tree()
    {
        for (auto&& element : list)
            Insert(std::move(element));
    }

private:
    base_node_pointer copy_recursive(base_node_pointer source, base_node_pointer destination_root, node_pointer rend, node_pointer end) {
        assert(source && "source should exist");
        base_node_pointer destination = create_node(destination_root, source->value_);

        if (source->left_ && source->left_ != rend) {
            base_node_pointer left = copy_recursive(source->left_, destination, rend, end);
            destination->left_ = left;
        }
        if (source->right_ && source->right_ != end) {
            base_node_pointer right = copy_recursive(source->right_, destination, rend, end);
            destination->right_ = right;
        }

        return destination;
    }

public:
    Tree(const Tree& other) : Tree() {
        if (!other.root_)
            return;
       
        root_ = copy_recursive(other.root_, nullptr, &(other.rend_), &(other.end_));
        updateEnd();
        updateReverseEnd();
    }
    Tree(Tree&& other) noexcept : Tree() {  
        *this = std::move(other);
    }
    Tree& operator=(const Tree& other) {
        if (this == &other)
            return *this;

        Tree temporary(other);
        *this = std::move(temporary);
        return *this;
    }
    Tree& operator=(Tree&& other) noexcept {
        if (this == &other)
            return *this;

        Clear();

        root_ = other.root_;
        size_ = other.size_;
        
        if (other.root_) {
            if (other.root_->left_ != &(other.rend_)) {
                other.root_->left_->root_ = root_;
                root_->left_ = other.root_->left_;
            }
            if (other.root_->right_ != &(other.end_)) {
                other.root_->right_->root_ = root_;
                root_->right_ = other.root_->right_;
            }
        }

        if (other.rend_.root_) {
            other.rend_.root_->left_ = &rend_;
        }
        rend_.root_ = other.rend_.root_;

        if (other.end_.root_) {
            other.end_.root_->right_ = &end_;
        }
        end_.root_ = other.end_.root_;


        other.rend_.root_ = nullptr;
        other.end_.root_ = nullptr;
        other.root_ = nullptr;
        other.size_ = 0ull;

        return *this;
    }


private:
    void deallocate(base_node_pointer* node) {
        if((*node)->left_ && (*node)->left_ != &rend_)
            deallocate(&(*node)->left_);

        if((*node)->right_ && (*node)->right_ != &end_)
            deallocate(&(*node)->right_);

        delete *node;
        *node = nullptr;
    }

public:
    ~Tree() {
        Clear();
    }
    bool Empty() const noexcept {
        return size_ == 0ull;
    }
    size_type Size() const noexcept {
        return size_;
    }
    size_type Height() const noexcept {
        if (!root_)
            return 0ull;
        return root_->lHeight_ > root_->rHeight_ ? root_->lHeight_ : root_->rHeight_;
    }

    // Map<int, float> m1;
    // Map<int, float>::iterator azaza = m1.begin();
    // ++azaza;
    // iterators============================================================
    iterator begin() {                                          // existing beginning
        return size_ ? iterator(rend_.root_) : end();
    }
    reverse_iterator rbegin() {
        return size_ ? reverse_iterator(end_.root_) : rend();
    }
    const_reverse_iterator crbegin() const {
        return size_ ? const_reverse_iterator(end_.root_) : rend();
    }
    const_iterator begin() const {                              // existing beginning
        return cbegin();
    }
    const_reverse_iterator rbegin() const {
        return crbegin();
    }
    const_iterator cbegin() const {
        return size_ ? const_iterator(rend_.root_) : cend();
    }
    iterator end() {                                            // non-existing end
        return iterator(&end_);
    }
    reverse_iterator rend() {                                   // non-existing begin
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
    base_node_pointer create_node(base_node_pointer root, value_type&& value) {
        base_node_pointer new_node = new Node(std::move(value), root);
        ++size_;
        return new_node;
    }
    base_node_pointer create_node(base_node_pointer root, const_reference value) {
        base_node_pointer new_node = new Node(value, root);
        ++size_;
        return new_node;
    }
    void updateEnd() {
        assert(root_ && "Root should always exist!");
        base_node_pointer new_end = root_;
        while (new_end->right_ != nullptr && new_end->right_ != &end_) {
            new_end = new_end->right_;
        }
        end_.root_ = new_end;
        new_end->right_ = &end_;     // otherwise it will not stop when if (new_end->right_)
    }
    void updateReverseEnd() {
        assert(root_ && "Root should always exist!");
        base_node_pointer new_end = root_;
        while (new_end->left_ && new_end->left_ != &rend_) {
            new_end = new_end->left_;
        }
        rend_.root_ = new_end;
        new_end->left_ = &rend_;     // otherwise it will not stop when if (new_end->left_)
    }
    bool leftLeftCase(base_node_pointer root) const noexcept {
        if (root->lHeight_ - root->rHeight_ != 2ull)
            return false;
        if (!root->left_)
            return false;
        if (root->left_->lHeight_ - root->left_->rHeight_ != 1ull)
            return false;
        return true;
    }
    bool rightRightCase(base_node_pointer root) const noexcept {
        if (root->rHeight_ - root->lHeight_ != 2ull)
            return false;
        if (!root->right_)
            return false;
        if (root->right_->rHeight_ - root->right_->lHeight_ != 1ull)
            return false;
        return true;
    }
    bool leftRightCase(base_node_pointer root) const noexcept {
        if (root->lHeight_ - root->rHeight_ != 2ull)
            return false;
        if (!root->left_)
            return false;
        if (root->left_->rHeight_ - root->left_->lHeight_ != 1ull)
            return false;
        return true;
    }
    bool rightLeftCase(base_node_pointer root) const noexcept {
        if (root->rHeight_ - root->lHeight_ != 2ull)
            return false;
        if (!root->right_)
            return false;
        if (root->right_->lHeight_ - root->right_->rHeight_ != 1ull)
            return false;

        return true;
    }
    void leftLeftBalance(base_node_pointer root) {
        assert(root->left_ && "left_ should exist!");
        base_node_pointer root_root = root->root_;
        base_node_pointer pivot = root->left_;
        base_node_pointer b = pivot->right_;

        pivot->right_ = root;
        root->root_ = pivot;

        root->left_ = b;
        if (b)
            b->root_ = root;

        pivot->root_ = root_root;
        if (root_root) {
            if (root_root->left_ == root)
                root_root->left_ = pivot;
            else
                root_root->right_ = pivot;
        } else {
            root_ = pivot;
        }

        updateLeftHeight(root);         // order matters
        updateRightHeight(pivot);       // order matters
    }
    void rightRightBalance(base_node_pointer root) {
        assert(root->right_ && "right_ should exist!");
        base_node_pointer root_root = root->root_;
        base_node_pointer pivot = root->right_;
        base_node_pointer b = pivot->left_;

        pivot->left_ = root;
        root->root_ = pivot;

        root->right_ = b;
        if (b)
            b->root_ = root;

        pivot->root_ = root_root;
        if (root_root) {
            if (root_root->left_ == root)
                root_root->left_ = pivot;
            else
                root_root->right_ = pivot;
        } else {
            root_ = pivot;
        }

        updateRightHeight(root);        // order matters
        updateLeftHeight(pivot);        // order matters
    }
    void leftRightBalance(base_node_pointer root) {
        assert(root->left_ && "left_ should exist!");       
        assert(root->left_->right_ && "left_->right_ should exist!");

        base_node_pointer child = root->left_;
        base_node_pointer pivot = child->right_;
        base_node_pointer c = pivot->left_;

        pivot->left_ = child;
        child->root_ = pivot;

        child->right_ = c;
        if (c)
            c->root_ = child;

        root->left_ = pivot;
        pivot->root_ = root;

        updateRightHeight(child);       // order matters
        updateLeftHeight(pivot);        // order matters

        leftLeftBalance(root);
    }
    void rightLeftBalance(base_node_pointer root) {
        assert(root->right_ && "right_ should exist!");
        assert(root->right_->left_ && "right_->left_ should exist!");

        base_node_pointer child = root->right_;
        base_node_pointer pivot = child->left_;
        base_node_pointer c = pivot->right_;

        pivot->right_ = child;
        child->root_ = pivot;

        child->left_ = c;
        if (c)
            c->root_ = child;

        root->right_ = pivot;
        pivot->root_ = root;

        updateLeftHeight(child);        // order matters
        updateRightHeight(pivot);       // order matters

        rightRightBalance(root);
    }
    void balance(base_node_pointer root) noexcept {
        if (leftRightCase(root))
            leftRightBalance(root);
        else if (rightLeftCase(root))
            rightLeftBalance(root);
        else if (leftLeftCase(root))
            leftLeftBalance(root);
        else if (rightRightCase(root))
            rightRightBalance(root);
        else
            assert(0 && "Unknown type of unbalanced case!");
    }
    void updateLeftHeight(base_node_pointer node) {
        assert(node && "Node should exist!");
        if (!node->left_ || node->left_ == &rend_) {
            node->lHeight_ = 0ull;
            return;
        }

        if (node->left_->lHeight_ > node->left_->rHeight_)
            node->lHeight_ = 1ull + node->left_->lHeight_;
        else
            node->lHeight_ = 1ull + node->left_->rHeight_;
    }
    void updateRightHeight(base_node_pointer node) {
        assert(node && "Node should exist!");
        if (!node->right_ || node->right_ == &end_) {
            node->rHeight_ = 0ull;
            return;
        }
        if (node->right_) 
            if (node->right_->lHeight_ > node->right_->rHeight_)
                node->rHeight_ = 1ull + node->right_->lHeight_;
            else
                node->rHeight_ = 1ull + node->right_->rHeight_;
    }

    std::pair<iterator, bool> insert_recursive(base_node_pointer root, const_reference value) {
        assert(root && "Root should always exist!");
        // root always exists
        if (comparator_(value, root->value_)) {
            if (root->left_ && root->left_ != &rend_) {
                const auto [_, created] = insert_recursive(root->left_, value);
                if (created) {
                    updateLeftHeight(root);
                    if (unbalanced(root))
                        balance(root);
                }
                return {_, created};
            } else {
                root->left_ = create_node(root, value);
                root->lHeight_ = 1ull;
                updateReverseEnd();
                return std::make_pair(iterator(root->left_), true);
            }
        } else if (comparator_(root->value_, value)) {
            if (root->right_ && root->right_ != &end_) {
                const auto [_, created] = insert_recursive(root->right_, value);
                if (created) {
                    updateRightHeight(root);
                    if (unbalanced(root))
                        balance(root);
                }
                return {_, created};
            } else {
                root->right_ = create_node(root, value);
                root->rHeight_ = 1ull;
                updateEnd();
                return std::make_pair(iterator(root->right_), true);
            }
        }
        // equal
        // size_ += root->Push_back(value);
        return std::make_pair(iterator(root), false);
    }
    std::pair<iterator, bool> insert_recursive(base_node_pointer root, value_type&& value) {
        assert(root && "Root should always exist!");
        // root always exists
        if (comparator_(value, root->value_)) {
            if (root->left_ && root->left_ != &rend_) {
                const auto [_, created] = insert_recursive(root->left_, std::move(value));
                if (created) {
                    updateLeftHeight(root);
                    if (unbalanced(root))
                        balance(root);
                }
                return {_, created};
            } else {
                root->left_ = create_node(root, std::move(value));
                root->lHeight_ = 1ull;
                updateReverseEnd();
                return std::make_pair(iterator(root->left_), true);
            }
        } else if (comparator_(root->value_, value)) {
            if (root->right_ && root->right_ != &end_) {
                const auto [_, created] = insert_recursive(root->right_, std::move(value));
                if (created) {
                    updateRightHeight(root);
                    if (unbalanced(root))
                        balance(root);
                }
                return {_, created};
            } else {
                root->right_ = create_node(root, std::move(value));
                root->rHeight_ = 1ull;
                updateEnd();
                return std::make_pair(iterator(root->right_), true);
            }
        }
        // equal
        // size_ += root->Push_back(value);
        return std::make_pair(iterator(root), false);
    }
public:
    bool unbalanced(base_node_pointer node) const noexcept {
        const auto difference = node->lHeight_ > node->rHeight_ ? (node->lHeight_ - node->rHeight_) : (node->rHeight_ - node->lHeight_);
        assert(difference <= 2 && "Critical disbalance!");
        return difference > 1;
    }

public:

    void Clear() noexcept {
        if(root_)
            deallocate(&root_);
        size_ = 0;
    }

    std::pair<iterator, bool> Insert(const_reference value) {
        if (!root_) {
            root_ = create_node(nullptr, value);
            updateReverseEnd();
            updateEnd();
            return std::make_pair(iterator(root_), true);
        }
        const auto [_, created] = insert_recursive(root_, value);
        if (created) {
            updateLeftHeight(root_);
            updateRightHeight(root_);
            if (unbalanced(root_))
                balance(root_);
        }
        return {_, created};
    }
    std::pair<iterator, bool> Insert(value_type&& value) {
        if (!root_) {
            root_ = create_node(nullptr, std::move(value));
            updateReverseEnd();
            updateEnd();
            return std::make_pair(iterator(root_), true);
        }
        const auto [_, created] = insert_recursive(root_, std::move(value));
        if (created) {
            updateLeftHeight(root_);
            updateRightHeight(root_);
            if (unbalanced(root_))
                balance(root_);
        }
        return {_, created};
    }
private:
    //modifiers==============================================================
    //                      4
    //         2                                          6
    //  1           3                  5                              7
    //   1.5                   4.5             5.5               6.5         8
    //    1.6               4.1           5.4        5.8      6.1         7.5          8.5
    //          1.8                               5.7                             8.2        9
    //       1.7                                                                8.1

    // std::pair<iterator, base_node_pointer> extract_recursive(base_node_pointer root, const key_type& key) {
    std::pair<iterator, base_node_pointer> extract_recursive(base_node_pointer root, const_reference value) {
        assert(root && "root should exist!");

        if (comparator_(value, root->value_)) {  // pos < root->value_
            if ((root)->left_ && (root)->left_ != &rend_) {
                const std::pair<iterator, base_node_pointer> result = extract_recursive(root->left_, value);
                updateLeftHeight(root);
                if (unbalanced(root))
                    balance(root);
                return result;
            } else {
                // not found
                assert(0 && "Element should exist!");
            }

        } else if (comparator_(root->value_, value)) {
            if ((root)->right_ && (root)->right_ != &end_) {
                const std::pair<iterator, base_node_pointer> result = extract_recursive(root->right_, value);
                updateRightHeight(root);
                if (unbalanced(root))
                    balance(root);
                return result;
            } else {
                // not found
                assert(0 && "Element should exist!");
            }
        }

        // found
        iterator it_result(root);
        ++it_result;
        base_node_pointer result = root;

        base_node_pointer new_node = nullptr;
        bool no_replace = true;

        if ((root)->left_ && (root)->left_ != &rend_) {

            no_replace = false;
            new_node = (root)->left_;

            if (!new_node->right_) {

                new_node->right_ = (root)->right_;
                if ((root)->right_)
                    (root)->right_->root_ = new_node;
                updateRightHeight(new_node);

                if ((root)->root_)
                    if ((root)->root_->right_ == (root))
                        (root)->root_->right_ = new_node;
                    else
                        (root)->root_->left_ = new_node;
                new_node->root_ = (root)->root_;

                if (unbalanced(new_node))
                    balance(new_node);

            } else {

                while (new_node->right_)
                    new_node = new_node->right_;

                new_node->right_ = (root)->right_;
                if ((root)->right_)
                    (root)->right_ = new_node;
                updateRightHeight(new_node);

                new_node->root_->right_ = new_node->left_;
                if (new_node->left_)
                    new_node->left_->root_ = new_node->root_;

                base_node_pointer temp = new_node->root_;
                while (temp != (root)->left_) {
                    updateRightHeight(temp);
                    temp = temp->root_;
                }

                new_node->left_ = (root)->left_;
                (root)->left_->root_ = new_node;
                updateLeftHeight(new_node);

                if ((root)->root_)
                    if ((root)->root_->right_ == (root))
                        (root)->root_->right_ = new_node;
                    else
                        (root)->root_->left_ = new_node;
                new_node->root_ = (root)->root_;

                if (unbalanced(new_node))
                    balance(new_node);

            }


        } else if ((root)->right_ && (root)->right_ != &end_) {

            no_replace = false;
            new_node = (root)->right_;

            if (!new_node->left_) {

                new_node->left_ = (root)->left_;
                if ((root)->left_)
                    (root)->left_->root_ = new_node;
                updateLeftHeight(new_node);


                if ((root)->root_)
                    if ((root)->root_->left_ == (root))
                        (root)->root_->left_ = new_node;
                    else
                        (root)->root_->right_ = new_node;
                new_node->root_ = (root)->root_;

                if (unbalanced(new_node))
                    balance(new_node);

            } else {

                while (new_node->left_)
                    new_node = new_node->left_;

                new_node->left_ = (root)->left_;
                if ((root)->left_)
                    (root)->left_ = new_node;
                updateLeftHeight(new_node);

                new_node->root_->left_ = new_node->right_;
                if (new_node->right_)
                    new_node->right_->root_ = new_node->root_;

                base_node_pointer temp = new_node->root_;
                while (temp != (root)->right_) {
                    updateLeftHeight(temp);
                    temp = temp->root_;
                }

                new_node->right_ = (root)->right_;
                (root)->right_->root_ = new_node;
                updateRightHeight(new_node);

                if ((root)->root_)
                    if ((root)->root_->left_ == (root))
                        (root)->root_->left_ = new_node;
                    else
                        (root)->root_->right_ = new_node;
                new_node->root_ = (root)->root_;

                if (unbalanced(new_node))
                    balance(new_node);

            }

        }

        if (no_replace && root->root_)
            if (root->root_->left_ == root)
                root->root_->left_ = nullptr;
            else
                root->root_->right_ = nullptr;

        --size_;

        if (new_node && !new_node->root_)
            root_ = new_node;

        if (root_) {
            updateEnd();
            updateReverseEnd();
        }

        return std::make_pair(it_result, result);
    }

public:
    iterator Erase(iterator pos) {
        return Erase(static_cast<const_iterator>(pos));
    }
    iterator Erase(const_iterator pos) {
        return Erase(*pos); 
    }
    iterator Erase(const_reference value) {
        if (!root_)
            assert(0 && "Trying to erase from empty tree!");

        std::pair<iterator, base_node_pointer> result = extract_recursive(root_, value);
        delete result.second;
        result.second = nullptr;

        return result.first;
    }
    base_node_pointer Extract(const_iterator pos) {
        if (!root_)
            assert(0 && "Trying to extract from empty tree!");
        const auto& [_, node] = extract_recursive(root_, *pos);
        return node;
    }
    // base_node_pointer Extract(const key_type& key) {
    base_node_pointer Extract(const_reference key) {
        if (!root_)
            assert(0 && "Trying to extract from empty tree!");
        const auto& [_, node] = extract_recursive(root_, key);
        return node;
    }

    // node_type Extract(const_iterator position );
// (1)	(since C++17)
// node_type extract( const Key& k );



protected:
    const_iterator find_recursive(base_node_pointer root, const key_type& key, bool lowerBound = false, bool upperBound = false, base_node_pointer bound = nullptr) const {
    // const_iterator find_recursive(base_node_pointer root, const_reference key, bool lowerBound = false, bool upperBound = false, base_node_pointer bound = nullptr) const {
        assert(root && "root should exist!");

        if (comparator_(key, root->value_)) {  // key < root->value_
            if (root->left_ && root->left_ != &rend_) {
                bound = root;
                return find_recursive(root->left_, key, lowerBound, upperBound, bound);
            } else {
                // not found
                // or return root if lowerBound or upperBound
                if (lowerBound || upperBound)
                    return const_iterator(root);
                return end();
            }
        } else if (comparator_(root->value_, key)) {
            if (root->right_ && root->right_ != &end_) {
                return find_recursive(root->right_, key, lowerBound, upperBound, bound);
            } else {
                // not found
                // or if lowerBound or upperBound return the last time we took left subtree
                if (lowerBound || upperBound)
                    return const_iterator(bound);
                return end();
            }
        } else {
            // found
            // or return next if upperBound
            if (upperBound)
                return ++const_iterator(root);
            return const_iterator(root);
        }
    }

public:
    // iterator find(const_reference value) {
    //     if (!root_)
    //         return end();
    //     return static_cast<iterator>(find_recursive(root_, value));
    // }
    iterator Find(const key_type& key) {
        if (!root_)
            return end();
        return static_cast<iterator>(find_recursive(root_, key));
    }
    const_iterator Find(const key_type& key) const {
        if (!root_)
            return end();
        return find_recursive(root_, key);
    }

    // template< class K > iterator find( const K& x );
    // template< class K > const_iterator find( const K& x ) const;

    bool Contains(const key_type& key) const {
        return Find(key) != end();
    }
    iterator Lower_bound(const key_type& key) {
        if (!root_)
            return end();
        return static_cast<iterator>(find_recursive(root_, key, true, false, &end_));
    }
    const_iterator Lower_bound(const key_type& key) const {
        if (!root_)
            return end();
        return find_recursive(root_, key, true, false, &end_);
    }
    iterator Upper_bound(const key_type& key) {
        if (!root_)
            return end();
        return static_cast<iterator>(find_recursive(root_, key, false, true, &end_));
    }
    const_iterator Upper_bound(const key_type& key) const {
        if (!root_)
            return end();
        return find_recursive(root_, key, false, true, &end_);
    }

    // template< class K > bool contains( const K& x ) const;
    std::pair<iterator, iterator> Equal_range(const key_type& key) {
        if (!root_)
            return std::make_pair(end(), end());

        iterator lower = Lower_bound(key);
        iterator upper = Upper_bound(key);
        return std::make_pair(lower, upper);
    }
    std::pair<const_iterator, const_iterator> Equal_range(const key_type& key) const {
        if (!root_)
            return std::make_pair(end(), end());

        const_iterator lower = static_cast<const_iterator>(Lower_bound(key));
        const_iterator upper = static_cast<const_iterator>(Upper_bound(key));
        return std::make_pair(lower, upper);
    }
    //template< class K >
    //std::pair<iterator,iterator> equal_range( const K& x );
    //template< class K >
    //std::pair<const_iterator,const_iterator> equal_range( const K& x ) const;

};

};  // namespace Tree

};  // namespace s21

#endif //  _TESTS_S21_TREE_H_