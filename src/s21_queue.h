#ifndef _S21_QUEUE_H_
#define _S21_QUEUE_H_
#include "s21_list.h"

namespace s21 {

template <typename Type, typename Container = List<Type>>
class Queue {
private:
    using container_type = Container;
    using value_type = Container::value_type;
    using size_type	= Container::size_type;
    using reference	= Container::reference;
    using const_reference = Container::const_reference;

private:
    Container queue_;

public:
    Queue() : queue_(Container()) { };
    explicit Queue(const Container& cont) : queue_(cont) { };
    explicit Queue(Container&& cont) : queue_(std::move(cont)) { };
    Queue(const Queue& other) = default;
    Queue(Queue&& other) = default;
    ~Queue() = default;

    template< class InputIt >
    Queue(InputIt first, InputIt last) : queue_(first, last) { };

    Queue& operator=(const Queue& other) = default;
    reference Front() 
    { 
        return *(queue_.begin()); 
    };
    const_reference Front() const 
    { 
        return *(queue_.cbegin()); 
    };
    reference Back() 
    { 
        return *(queue_.rbegin()); 
    };
    const_reference Back() const 
    { 
        return *(queue_.crbegin()); 
    };
    bool Empty() const noexcept 
    { 
        return queue_.Empty(); 
    };
    size_type Size() const noexcept 
    { 
        return queue_.Size(); 
    };
    void Push(const value_type& value) 
    {
        queue_.Push_back(value);
    };
    void Push(value_type&& value) 
    {
        queue_.Push_back(std::move(value));
    };
    template<class... Args>
    decltype(auto) Emplace(Args&&... args) 
    {
        return queue_.Emplace_back(std::forward<Args>(args)...);
    };
    void Pop() noexcept 
    {
        queue_.Pop_front();
    };
    void Swap(Queue& other) 
    {
        queue_.Swap(other.queue_);
    };
};

};

#endif  //  _S21_QUEUE_H_