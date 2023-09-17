#ifndef _S21_STACK_H_
#define _S21_STACK_H_
#include "s21_list.h"

namespace s21 {

template <typename Type, typename Container = List<Type>>
class Stack {
 private:
  using container_type = Container;
  using value_type = typename Container::value_type;
  using size_type = typename Container::size_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;

 private:
  Container stack_;

 public:
  Stack() : stack_(Container()) {}
  explicit Stack(const Container& cont) : stack_(cont) {}
  explicit Stack(Container&& cont) : stack_(std::move(cont)) {}
  Stack(const Stack& other) = default;
  Stack(Stack&& other) = default;
  ~Stack() = default;

  template <class InputIt>
  Stack(InputIt first, InputIt last) : stack_(first, last) {}
  // template< class Alloc >
  // explicit stack( const Alloc& alloc );
  // template< class Alloc >
  // stack( const Container& cont, const Alloc& alloc );
  // template< class Alloc >
  // stack( Container&& cont, const Alloc& alloc );
  // template< class Alloc >
  // stack( const stack& other, const Alloc& alloc );
  // template< class Alloc >
  // stack( stack&& other, const Alloc& alloc );
  // template< class InputIt, class Alloc >
  // stack( InputIt first, InputIt last, const Alloc& alloc );

  Stack& operator=(const Stack& other) = default;
  reference Top() { return *(stack_.rbegin()); }
  const_reference Top() const { return *(stack_.crbegin()); }
  bool Empty() const noexcept { return stack_.Empty(); }
  size_type Size() const noexcept { return stack_.Size(); }
  void Push(const value_type& value) { stack_.Push_back(value); }
  void Push(value_type&& value) { stack_.Push_back(std::move(value)); }
  template <class... Args>
  decltype(auto) Emplace(Args&&... args) {
    return stack_.Emplace_back(std::forward<Args>(args)...);
  }
  template <class... Args>
  void Insert_many_front(Args&&... args) {
    return stack_.Insert_many_back(std::forward<Args>(args)...);
  }
  void Pop() noexcept { stack_.Pop_back(); }
  void Swap(Stack& other) { stack_.Swap(other.stack_); }
};
}  // namespace s21

#endif  //  _S21_STACK_H_