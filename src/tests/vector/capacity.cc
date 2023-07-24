#include <gtest/gtest.h>

#include <vector>
#include "../../s21_vector.h"

#include "../item.h"
#include "../vector_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(Vector, T0Capacity)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21_vector.Reserve(100);
    vector.reserve(100);

    EXPECT_EQ(s21_vector.Capacity(), vector.capacity());
}   

TEST(Vector, T1Capacity)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const auto s21_capacity_old = s21_vector.Capacity();
    s21_vector.Reserve(2);

    EXPECT_EQ(s21_vector.Capacity(), s21_capacity_old);
}

TEST(Vector, T2Size)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    EXPECT_EQ(s21_vector.Size(), 3);
}


}  // namespace

// GCOVR_EXCL_STOP
