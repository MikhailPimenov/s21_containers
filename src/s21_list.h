#ifndef _S21_LIST_H_
#define _S21_LIST_H_

namespace s21 {

    class SequentionalBase {
    public:
        virtual void Push_back() = 0;
        virtual void Pop_back() = 0;
    };

    using Type = double;

    template <typename Type>
    // class List : public SequentionalBase<Type> {
    // class List : public SequentionalBase {
    class List {
    private:
        using value_type = Type;
        // using size_type = std::size_t;
        using size_type = int;
        // using reference = value_type&;

    private:
        value_type data_;
        List* next_ = nullptr;
        List* previous_ = nullptr;

    public:
        List() = default;



    };

}  // namespace s21

#endif  //  _S21_LIST_H_
