#include "item.h"

#include <iostream>

// GCOVR_EXCL_START

Item::Item(const Item &other) : number_{other.number_}, symbol_{other.symbol_}, fraction_{other.fraction_}
{
}
Item::Item(Item &&other) : number_{other.number_}, symbol_{other.symbol_}, fraction_{other.fraction_}
{
}
Item::Item(int number /* = 0*/, char symbol /* = 'a'*/, double fraction /* = 0.5*/) : number_{number}, symbol_{symbol}, fraction_{fraction}  
{
}
    

Item &Item::operator=(const Item &other)
{
    if (this == &other)
        return *this;

    number_ = other.number_;
    symbol_ = other.symbol_;
    fraction_ = other.fraction_;
    return *this;
}

Item &Item::operator=(Item &&other)
{
    if (this == &other)
        return *this;

    number_ = other.number_;
    symbol_ = other.symbol_;
    fraction_ = other.fraction_;
    return *this;
}

bool Item::operator==(const Item &right) const
{
    return number_ == right.number_ &&
           symbol_ == right.symbol_ &&
           fraction_ == right.fraction_;
}
bool Item::operator!=(const Item &right) const
{
    return !(*this == right);
}

std::ostream &operator<<(std::ostream &out, const Item &object)
{
    out << "Item(" << object.number_ << ", " << object.symbol_ << ", " << object.fraction_ << ')';
    return out;
}

ItemMove::ItemMove(int number) : Item(number)
{
}
ItemMove::ItemMove(ItemMove &&other) : Item(other.number_)
{
}

ItemMove &ItemMove::operator=(ItemMove &&other)
{
    Item::operator=(other);
    return *this;
}

std::ostream &operator<<(std::ostream &out, const ItemMove &object)
{
    out << "ItemMove(" << object.number_ << ')';
    return out;
}

// GCOVR_EXCL_STOP