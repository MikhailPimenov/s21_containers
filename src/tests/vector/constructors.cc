#include <gtest/gtest.h>

#include <stack>
#include <list>
#include <vector>
#include <deque>


#include "../../s21_vector.h"
#include "../item.h"
#include "../vector_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(Vector, T0DefaultConstructor)
{
    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;



    EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T1ConstructorInitializer)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector, vector);
}


}  // namespace

// GCOVR_EXCL_STOP
