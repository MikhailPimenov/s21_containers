#include <iostream>
#include "item.h"

// GCOVR_EXCL_START

Item::Item(int number /* = 0*/) : number_{number} {}
Item::Item(const Item& other) : number_{other.number_} {}

Item& Item::operator=(const Item& other){
    if (this == &other)
        return *this;

    number_ = other.number_;
    return *this;
}

bool Item::operator==(const Item& right) const {
    return number_ == right.number_;
}
bool Item::operator!=(const Item& right) const {
    return !(*this == right);
}

std::ostream& operator<<(std::ostream& out, const Item& object) {
    out << "Item(" << object.number_ << ')';
    return out;
}


ItemMove::ItemMove(int number) : Item(number) {};
ItemMove::ItemMove(ItemMove&& other) : Item(other.number_) {}; 

ItemMove& ItemMove::operator=(ItemMove&& other){
    Item::operator=(other);
    return *this;
}

std::ostream& operator<<(std::ostream& out, const ItemMove& object) {
    out << "ItemMove(" << object.number_ << ')';
    return out;
}

// GCOVR_EXCL_STOP