#include <gtest/gtest.h>

#include <vector>
#include "../../s21_vector.h"

#include "../item.h"
#include "../vector_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(Array, T0Size)
{
    s21::Array<Item, 13> s21_array { 
        Item(11), 
        Item(22, 'b'), 
        Item(33, 'c', 0.3333), 
        Item(11), 
        Item(22, 'b'), 
        Item(33, 'c', 0.3333), 
        Item(11), 
        Item(22, 'b'), 
        Item(11), 
        Item(22, 'b'), 
        Item(33, 'c', 0.3333), 
        Item(11),
        Item(33, 'c', 0.3333), 
    };
    EXPECT_EQ(s21_array.Size(), 13ull);
}

TEST(Array, T1Size)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    EXPECT_EQ(s21_array.Size(), 3ull);
}

}  // namespace

// GCOVR_EXCL_STOP
