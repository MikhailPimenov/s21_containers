#include "item.h"

#include <iostream>

// GCOVR_EXCL_START

Item::Item(const Item &other) : array_{nullptr} {
        *this = other;
      }
Item::Item(Item &&other) : array_{nullptr} {
        *this = std::move(other);
      }
Item::Item(int number /* = 0*/, char symbol /* = 'a'*/,
           double fraction /* = 0.5*/)
    : number_{number}, symbol_{symbol}, fraction_{fraction}, array_{nullptr} {
        array_ = new long long[10]{};
    }

Item::~Item() {
    delete[] array_;
    array_ = nullptr;
}

Item &Item::operator=(const Item &other) {
  if (this == &other) return *this;

    delete[] array_;
    array_ = nullptr;
  number_ = other.number_;
  symbol_ = other.symbol_;
  fraction_ = other.fraction_;

    array_ = new long long[10];
    for (int i = 0; i < 10; ++i)
      array_[i] = other.array_[i];

  return *this;
}

Item &Item::operator=(Item &&other) {
  if (this == &other) return *this;

    delete[] array_;
    array_ = nullptr;
  number_ = other.number_;
  symbol_ = other.symbol_;
  fraction_ = other.fraction_;
  array_ = other.array_;
  other.array_ = nullptr;
  return *this;
}

bool Item::operator==(const Item &right) const {
  return number_ == right.number_ && symbol_ == right.symbol_ &&
         fraction_ == right.fraction_;
}
bool Item::operator!=(const Item &right) const { return !(*this == right); }

int Item::number() const { return number_; }

std::ostream &operator<<(std::ostream &out, const Item &object) {
  out << "Item(" << object.number_ << ", " << object.symbol_ << ", "
      << object.fraction_ << ')';
  return out;
}

// GCOVR_EXCL_STOP