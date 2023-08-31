#ifndef _TESTS_ITEM_H_
#define _TESTS_ITEM_H_

#include <iostream>

class Item
{
  protected:
    int number_;
    char symbol_;
    double fraction_;

  public:
    Item(int number = 0, char symbol = 'a', double fraction = 0.5);        // just to test emplace-functions which take variadic number of arguments
    Item(const Item &other);
    Item(Item &&other);

    Item &operator=(const Item &other);
    Item &operator=(Item &&other);
    bool operator==(const Item &right) const;
    bool operator!=(const Item &right) const;

    int number() const;

    friend std::ostream &operator<<(std::ostream &out, const Item &object);
};

class ItemMove : public Item
{
  public:
    ItemMove(int number);
    ItemMove(const ItemMove &) = delete;
    ItemMove(ItemMove &&);

    ItemMove &operator=(const ItemMove &) = delete;
    ItemMove &operator=(ItemMove &&other);

    bool operator==(const ItemMove &right) const;
    bool operator!=(const ItemMove &right) const;

    friend std::ostream &operator<<(std::ostream &out, const ItemMove &object);
};
// class ItemArray {
// private:
//     int length_;
//     double* array_;

// public:
//     ItemArray
// };

#endif //  _TESTS_ITEM_H_