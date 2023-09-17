#ifndef _S21_LIST_H_
#define _S21_LIST_H_

#include <cassert>
#include <cmath>
#include <initializer_list>
#include <iterator>
#include <new>

#include "s21_utility.h"

namespace s21 {

template <typename List, typename Pointer, typename Reference,
          typename Node_pointer, typename Difference_type, typename Value_type>
class ListIteratorBase {
  friend List;

  template <typename OtherVector, typename OtherPointer,
            typename OtherReference, typename OtherNode_pointer,
            typename OtherDifference_type, typename OtherValue_type>
  friend class ListIteratorBase;  // to be able to compare iterator and
                                  // const_iterator

 public:
  using difference_type = Difference_type;
  using value_type = Value_type;
  using pointer = Pointer;
  using reference = Reference;
  using iterator_category = std::bidirectional_iterator_tag;

  using node_pointer = Node_pointer;

 public:
  ListIteratorBase(node_pointer node_pointer) : node_pointer_{node_pointer} {}

  template <
      typename OtherPointer, typename OtherReference,
      typename OtherNode_pointer>  // to be able to compare iterator and
                                   // const_iterator
                                   ListIteratorBase(
                                       const ListIteratorBase<
                                           List, OtherPointer, OtherReference,
                                           OtherNode_pointer, Difference_type,
                                           Value_type> &other) noexcept
      : ListIteratorBase(const_cast<node_pointer>(other.node_pointer_)) {}

  template <
      typename OtherPointer, typename OtherReference,
      typename OtherNode_pointer>  // to be able to compare iterator and
                                   // const_iterator
                                   ListIteratorBase(
                                       ListIteratorBase<
                                           List, OtherPointer, OtherReference,
                                           OtherNode_pointer, Difference_type,
                                           Value_type> &&other) noexcept
      : ListIteratorBase(const_cast<node_pointer>(other.node_pointer_)) {
    other.node_pointer_ = nullptr;
  }

  friend void swap(ListIteratorBase &left, ListIteratorBase &right) {
    using namespace std;  // to enable ADL
    swap(left.node_pointer_, right.node_pointer_);
  }

  template <
      typename OtherPointer, typename OtherReference,
      typename OtherNode_pointer>  // to be able to compare iterator and
                                   // const_iterator
                                   ListIteratorBase<
                                       List, OtherPointer, OtherReference,
                                       OtherNode_pointer, Difference_type,
                                       Value_type> &
                                   operator=(const ListIteratorBase<
                                             List, OtherPointer, OtherReference,
                                             OtherNode_pointer, Difference_type,
                                             Value_type> &other) noexcept {
    node_pointer_ = other.node_pointer_;
    return *this;
  }

  template <
      typename OtherPointer, typename OtherReference,
      typename OtherNode_pointer>  // to be able to compare iterator and
                                   // const_iterator
                                   ListIteratorBase<
                                       List, OtherPointer, OtherReference,
                                       OtherNode_pointer, Difference_type,
                                       Value_type> &
                                   operator=(ListIteratorBase<
                                             List, OtherPointer, OtherReference,
                                             OtherNode_pointer, Difference_type,
                                             Value_type> &&other) noexcept {
    node_pointer_ = other.node_pointer_;
    other.node_pointer_ = nullptr;
    return *this;
  }

  reference operator*() const { return node_pointer_->value_; }

  pointer operator->() const { return &(node_pointer_->value_); }

  template <
      typename OtherPointer, typename OtherReference,
      typename OtherNode_pointer>  // to be able to compare iterator and
                                   // const_iterator
                                   bool operator==(
                                       const ListIteratorBase<
                                           List, OtherPointer, OtherReference,
                                           OtherNode_pointer, Difference_type,
                                           Value_type> &other) const noexcept {
    return node_pointer_ == other.node_pointer_;
  }

  template <typename OtherPointer, typename OtherReference,
            typename OtherNode_pointer>
  bool operator!=(const ListIteratorBase<List, OtherPointer, OtherReference,
                                         OtherNode_pointer, Difference_type,
                                         Value_type> &other) const noexcept {
    return !(*this == other);
  }

  explicit operator bool() const { return node_pointer_; }

  template <typename OtherPointer, typename OtherReference,
            typename OtherNode_pointer>
  operator ListIteratorBase<List, OtherPointer, OtherReference,
                            OtherNode_pointer, Difference_type, Value_type>()
      const noexcept {
    return ListIteratorBase<List, OtherPointer, OtherReference,
                            OtherNode_pointer, Difference_type, Value_type>(
        node_pointer_);
  }

 private:
  node_pointer get() { return node_pointer_; }

 protected:
  node_pointer node_pointer_;
};

template <typename List, typename Pointer = typename List::pointer,
          typename Reference = typename List::reference>
class ListIterator
    : public ListIteratorBase<
          List, Pointer, Reference, typename List::node_pointer,
          typename List::difference_type, typename List::value_type> {
 private:
  using Base =
      ListIteratorBase<List, Pointer, Reference, typename List::node_pointer,
                       typename List::difference_type,
                       typename List::value_type>;

 public:
  using Base::Base;

  ListIterator &operator++() {
    this->node_pointer_ = this->node_pointer_->next_;
    return *this;
  }

  ListIterator operator++(int) {
    ListIterator temporary(*this);
    this->node_pointer_ = this->node_pointer_->next_;
    return temporary;
  }

  ListIterator &operator--() {
    this->node_pointer_ = this->node_pointer_->previous_;
    return *this;
  }

  ListIterator operator--(int) {
    ListIterator temporary(*this);
    this->node_pointer_ = this->node_pointer_->previous_;
    return temporary;
  }
};

template <typename List, typename Pointer = typename List::pointer,
          typename Reference = typename List::reference>
class ListReverseIterator
    : public ListIteratorBase<
          List, Pointer, Reference, typename List::node_pointer,
          typename List::difference_type, typename List::value_type> {
 private:
  using Base =
      ListIteratorBase<List, Pointer, Reference, typename List::node_pointer,
                       typename List::difference_type,
                       typename List::value_type>;

 public:
  using Base::Base;

  ListReverseIterator &operator++() {
    this->node_pointer_ = this->node_pointer_->previous_;
    return *this;
  }

  ListReverseIterator operator++(int) {
    ListReverseIterator temporary(*this);
    this->node_pointer_ = this->node_pointer_->previous_;
    return temporary;
  }

  ListReverseIterator &operator--() {
    this->node_pointer_ = this->node_pointer_->next_;
    return *this;
  }

  ListReverseIterator operator--(int) {
    ListReverseIterator temporary(*this);
    this->node_pointer_ = this->node_pointer_->next_;
    return temporary;
  }
};

template <typename Type>
class List {
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
  using node_type = Utility::Handler<node_pointer, reference>;

 public:
  friend class ListIterator<List<Type>>;
  friend class ListIterator<List<Type>, const_pointer, const_reference>;
  friend class ListReverseIterator<List<Type>>;
  friend class ListReverseIterator<List<Type>, const_pointer, const_reference>;

 public:
  using iterator = ListIterator<List<Type>>;
  using const_iterator =
      ListIterator<List<Type>, const_pointer, const_reference>;
  using reverse_iterator = ListReverseIterator<List<Type>>;
  using const_reverse_iterator =
      ListReverseIterator<List<Type>, const_pointer, const_reference>;

 private:
  struct Node {
   public:
    value_type value_;

    Node *next_;
    Node *previous_;

   public:
    Node() : value_{value_type()}, next_{nullptr}, previous_{nullptr} {}
    Node(const_reference value, Node *next = nullptr, Node *previous = nullptr)
        : value_{value}, next_{next}, previous_{previous} {}
    Node(value_type &&value, Node *next = nullptr, Node *previous = nullptr)
        : value_{std::move(value)}, next_{next}, previous_{previous} {}

    template <class... Args>
    Node(Args &&...args)
        : value_{std::forward<Args>(args)...},
          next_{nullptr},
          previous_{nullptr} {}
  };

  mutable Node end_;
  mutable Node rend_;
  size_type size_;

 public:
  List() : end_{}, rend_{}, size_{0ull} { connect(&rend_, &end_); };

  explicit List(size_type count) : List(count, value_type()) {}

  List(size_type count, const_reference value) : List() {
    for (size_type i = 0ull; i < count; ++i) Push_back(value);
  }

  template <typename InputIterator>
  List(InputIterator first, InputIterator last) : List() {
    for (auto it = first; it != last; ++it) Push_back(*it);
  }

  List(const List &other) : List() {
    for (auto it = other.cbegin(); it != other.cend(); ++it) Push_back(*it);
  }

  List(List &&other) : size_{other.size_} {
    Node *other_first = nextOf(&(other.rend_));
    Node *other_last = previousOf(&(other.end_));

    connect(&rend_, other_first);
    connect(other_last, &end_);

    connect(&(other.rend_), &(other.end_));
    other.size_ = 0ull;
  }

  List &operator=(const List &other) {
    if (this == &other) return *this;

    List copy(other);
    *this = std::move(copy);
    return *this;
  }

  List &operator=(List &&other) {
    if (this == &other) return *this;

    Clear();

    size_ = other.size_;

    Node *other_first = nextOf(&(other.rend_));
    Node *other_last = previousOf(&(other.end_));

    connect(&rend_, other_first);
    connect(other_last, &end_);

    connect(&(other.rend_), &(other.end_));
    other.size_ = 0ull;

    return *this;
  }

  List(const std::initializer_list<value_type> &list) : List() {
    for (const auto &element : list) Push_back(element);
  };

  ~List() { Clear(); }

  void Clear() {
    while (!Empty()) Pop_back();
  }

  bool Empty() const noexcept { return size_ == 0ull; }

  size_type Size() const { return size_; }

  iterator begin() { return ++iterator(&rend_); }

  reverse_iterator rbegin() { return ++reverse_iterator(&end_); }

  const_iterator begin() const { return ++const_iterator(&rend_); }

  const_iterator cbegin() const { return begin(); }

  const_reverse_iterator crbegin() const {
    return ++const_reverse_iterator(&end_);
  }

  iterator end() { return iterator(&end_); }

  reverse_iterator rend() { return reverse_iterator(&rend_); }

  const_iterator end() const { return const_iterator(&end_); }

  const_iterator cend() const { return end(); }

  const_reverse_iterator crend() const {
    return const_reverse_iterator(&rend_);
  }

  void Push_back(const_reference data) {
    Node *old_last = previousOf(&end_);
    Node *new_last = create_node(data);

    connect(old_last, new_last);
    connect(new_last, &end_);

    ++size_;
  };

  void Push_back(value_type &&data) {
    Node *old_last = previousOf(&end_);
    Node *new_last = create_node(std::move(data));

    connect(old_last, new_last);
    connect(new_last, &end_);

    ++size_;
  };

  void Pop_back() {
    assert(size_ >= 1ull && "Pop_back() from empty list!");

    Node *old_last = previousOf(&end_);
    Node *new_last = previousOf(old_last);

    delete old_last;
    connect(new_last, &end_);

    --size_;
  }

  size_type Max_size() const noexcept {
#if defined(__APPLE__) || defined(__MACH__)
    if constexpr (sizeof(void *) == 4)
      return (std::pow(2.0, 31.0) / sizeof(Node) - 2.0) * 2.0;
    return (std::pow(2.0, 63.0) / sizeof(Node) - 2.0) * 2.0;
#else
    if constexpr (sizeof(void *) == 4)
      return std::pow(2.0, 31.0) / sizeof(Node) - 2.0;
    return std::pow(2.0, 63.0) / sizeof(Node) - 2.0;
#endif  // defined(__APPLE__) || defined(__MACH__)
  }

  void Resize(size_type count, const_reference value) {
    assert(static_cast<signed long long>(count) >= 0 &&
           "Probably negative number of elements!");

    if (count == size_) return;

    if (count < size_)
      for (size_type i = 0ull; i < size_ - count; ++i) Pop_back();
    else
      for (size_type i = 0ull; i < count - size_; ++i) Push_back(value);
  }

  void Resize(size_type count) { Resize(count, value_type()); }

  iterator Insert(const_iterator pos, const_reference value) {
    Node *new_node = create_node(value);

    Node *next = pos.get();
    Node *previous = previousOf(next);
    connect(previous, new_node);
    connect(new_node, next);

    ++size_;
    return iterator(new_node);
  }

  iterator Insert(const_iterator pos, size_type count, const_reference value) {
    assert(static_cast<signed long long>(count) >= 0 &&
           "Probably negative number of elements!");
    for (size_type i = 0ull; i < count; ++i) Insert(pos, value);

    iterator result(pos.get());
    for (size_type i = 0ull; i < count; ++i) --result;

    return result;
  }

  template <typename InputIterator>
  iterator Insert(const_iterator pos, InputIterator first, InputIterator last) {
    size_type count = 0ull;
    for (InputIterator it = first; it != last; ++it) {
      Insert(pos, *it);
      ++count;
    }

    iterator result(pos.get());
    for (size_type i = 0ull; i < count; ++i) --result;

    return result;
  }

  iterator Insert(const_iterator pos, const std::initializer_list<Type> &list) {
    for (const auto &element : list) Insert(pos, element);

    iterator result(pos.get());
    for (size_type i = 0ull; i < list.size(); ++i) --result;

    return result;
  }

  template <class... Args>
  void Insert_many_back(Args &&...args) {
    return insert_many_back(std::forward<Args>(args)...);
  }

  template <typename... Args>
  void Insert_many_front(Args &&...args) {
    return insert_many_front(std::forward<Args>(args)...);
  }

  template <typename... Args>
  iterator Insert_many(const_iterator pos, Args &&...args) {
    insert_many(pos, std::forward<Args>(args)...);
    return static_cast<const_iterator>(pos);
  }

  void Assign(size_type count, const_reference value) {
    List temporary(count, value);
    *this = std::move(temporary);
  }

  template <typename InputIterator>
  void Assign(InputIterator first, InputIterator last) {
    List temporary(first, last);
    *this = std::move(temporary);
  }

  void Assign(const std::initializer_list<value_type> &list) {
    List temporary(list);
    *this = std::move(temporary);
  };

  void Push_front(const_reference data) {
    Node *old_first = nextOf(&rend_);

    Node *new_first = create_node(data);

    connect(&rend_, new_first);
    connect(new_first, old_first);

    ++size_;
  };

  void Push_front(value_type &&data) {
    Node *old_first = nextOf(&rend_);

    Node *new_first = create_node(std::move(data));

    connect(&rend_, new_first);
    connect(new_first, old_first);

    ++size_;
  };

  void Pop_front() {
    assert(size_ >= 1ull && "Pop_back() from empty list!");

    Node *old_first = nextOf(&rend_);
    Node *new_first = nextOf(old_first);

    delete old_first;

    connect(&rend_, new_first);

    --size_;
  }

  void Swap(List &other) noexcept {
    Node *other_first = nextOf(&(other.rend_));
    Node *other_last = previousOf(&(other.end_));

    Node *first = nextOf(&rend_);
    Node *last = previousOf(&end_);

    if (size_) {
      connect(&(other.rend_), first);
      connect(last, &(other.end_));
    } else {
      connect(&(other.rend_), &(other.end_));
    }

    if (other.size_) {
      connect(other_last, &end_);
      connect(&rend_, other_first);
    } else {
      connect(&rend_, &end_);
    }

    std::swap(size_, other.size_);
  }

  reference Front() {
    assert(!Empty() && "Front() from empty list!");
    return *begin();
  }
  const_reference Front() const {
    assert(!Empty() && "Front() from empty list!");
    return *cbegin();
  }
  reference Back() {
    assert(!Empty() && "Back() from empty list!");
    return *(--end());
  }
  const_reference Back() const {
    assert(!Empty() && "Back() from empty list!");
    return *(--cend());
  }

  iterator Erase(const_iterator pos) {
    Node *previous = previousOf(pos.get());
    Node *next = nextOf(pos.get());

    delete pos.get();
    --size_;

    connect(previous, next);
    return iterator(next);
  }
  iterator Erase(const_iterator first, const_iterator last) {
    while (first != last) first = Erase(first);

    return last;
  }

  node_type Extract(const_iterator pos) {
    Node *previous = previousOf(pos.get());
    Node *next = nextOf(pos.get());

    connect(previous, next);
    --size_;
    return node_type(pos.get());
  }

  template <class... Args>
  iterator Emplace(const_iterator pos, Args &&...args) {
    Node *new_node = create_node(std::forward<Args>(args)...);

    Node *next = pos.get();
    Node *previous = previousOf(next);

    connect(previous, new_node);
    connect(new_node, next);
    ++size_;

    return iterator(new_node);
  }

  template <class... Args>
  reference Emplace_back(Args &&...args) {
    Node *new_last = create_node(std::forward<Args>(args)...);
    Node *old_last = previousOf(&end_);

    connect(old_last, new_last);
    connect(new_last, &end_);
    ++size_;

    return new_last->value_;
  }

  template <class... Args>
  reference Emplace_front(Args &&...args) {
    Node *new_first = create_node(std::forward<Args>(args)...);
    Node *old_first = nextOf(&rend_);

    connect(&rend_, new_first);
    connect(new_first, old_first);
    ++size_;

    return new_first->value_;
  }

 private:
  void connect(Node *node, Node *next_node) {
    assert(node && "node was nullptr!");
    assert(next_node && "next_node was nullptr!");
    node->next_ = next_node;
    next_node->previous_ = node;
  }
  Node *previousOf(Node *node) {
    assert(node && "node was nullptr!");
    return node->previous_;
  }
  Node *nextOf(Node *node) {
    assert(node && "node was nullptr!");
    return node->next_;
  }

  Node *create_node(const_reference data) { return new Node(data); }

  Node *create_node(value_type &&data) { return new Node(std::move(data)); }
  template <class... Args>
  Node *create_node(Args &&...args) {
    return new Node(std::forward<Args>(args)...);
  }

  template <typename Last>
  void insert_many_back(Last last) {
    Push_back(std::forward<Last>(last));
  }
  template <typename First, class... Args>
  void insert_many_back(First first, Args &&...args) {
    Push_back(std::forward<First>(first));
    insert_many_back(std::forward<Args>(args)...);
  }

  template <typename Last>
  void insert_many_front(Last last) {
    Push_front(std::forward<Last>(last));
  }
  template <typename First, class... Args>
  void insert_many_front(First first, Args &&...args) {
    insert_many_front(std::forward<Args>(args)...);
    Push_front(std::forward<First>(first));
  }

  template <typename Last>
  iterator insert_many(const_iterator pos, Last last) {
    return Insert(pos, last);
  }
  template <typename First, class... Args>
  iterator insert_many(const_iterator pos, First first, Args &&...args) {
    iterator it = insert_many(pos, std::forward<Args>(args)...);
    return Insert(it, first);
  }
};

template <typename Type>
bool operator==(const List<Type> &left, const List<Type> &right) {
  if (left.Size() != right.Size()) return false;

  auto left_iterator = left.cbegin();
  auto right_iterator = right.cbegin();

  while (left_iterator != left.cend()) {
    if (*left_iterator != *right_iterator) return false;
    ++left_iterator;
    ++right_iterator;
  }

  return true;
}

}  // namespace s21

#endif  //  _S21_LIST_H_
