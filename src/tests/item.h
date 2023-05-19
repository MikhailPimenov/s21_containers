#ifndef _TESTS_ITEM_H_
#define _TESTS_ITEM_H_

#include <iostream>


class Item {
private:
    int number_;

public:
    Item(int number = 0);
    Item(const Item& other);

    Item& operator=(const Item& other);
    bool operator==(const Item& right) const;
    bool operator!=(const Item& right) const;

    friend std::ostream& operator<<(std::ostream& out, const Item& object);
};

// class ItemArray {
// private:
//     int length_;
//     double* array_;

// public:
//     ItemArray
// };

#endif  //  _TESTS_ITEM_H_