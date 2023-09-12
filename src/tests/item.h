#ifndef _TESTS_ITEM_H_
#define _TESTS_ITEM_H_

#include <iostream>
// namespace std {
//   class ostream;
// }

class Item
{
  protected:
    int number_;
    char symbol_;
    double fraction_;

  public:
    explicit Item(int number = 0, char symbol = 'a', double fraction = 0.5);        // just to test emplace-functions which take variadic number of arguments
    Item(const Item &other);
    Item(Item &&other);

    Item &operator=(const Item &other);
    Item &operator=(Item &&other);
    bool operator==(const Item &right) const;
    bool operator!=(const Item &right) const;

    int number() const;

    friend std::ostream &operator<<(std::ostream &out, const Item &object);
};

class ComparatorItem {
public:
  bool operator()(const Item& left, const Item& right) const {
    return left.number() < right.number();
  }
};

#endif //  _TESTS_ITEM_H_