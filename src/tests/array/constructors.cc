#include <gtest/gtest.h>

#include <stack>
#include <list>
#include <array>
#include <deque>


#include "../../s21_array.h"
#include "../item.h"
#include "../array_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(Array, T1ConstructorInitializer)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array, array);
}

TEST(Array, T6ConstructorCopy)
{
    const s21::Array<Item, 3> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21::Array<Item, 3> s21_array(s21_source);
    std::array<Item, 3> array(source);

    EXPECT_EQ(s21_array, array);
}

TEST(Array, T8ConstructorCopy)
{
    const s21::Array<Item, 2> s21_source{Item(33, 'i', 0.3333), Item(33, 'c', 0.3333)};
    const std::array<Item, 2> source{Item(33, 'i', 0.3333), Item(33, 'c', 0.3333)};

    s21::Array<Item, 2> s21_array(s21_source);
    std::array<Item, 2> array(source);

    EXPECT_EQ(s21_array, array);
}

TEST(Array, T9ConstructorMove)
{
    s21::Array<Item, 3> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21::Array<Item, 3> s21_array(std::move(s21_source));
    std::array<Item, 3> array(std::move(source));

    EXPECT_EQ(s21_array, array);
    EXPECT_EQ(s21_source, source);
}

TEST(Array, T11OperatorCopy)
{
    const s21::Array<Item, 3> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21::Array<Item, 3> s21_array;
    s21_array = s21_source;
    std::array<Item, 3> array;
    array = source;

    EXPECT_EQ(s21_array, array);
}

TEST(Array, T13OperatorCopy)
{
    const s21::Array<Item, 3> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21::Array<Item, 3> s21_array{Item(1999), Item(22, 'h'), Item(33, 'c', 0.3333)};
    s21_array = s21_source ;
    std::array<Item, 3> array{Item(1999), Item(22, 'h'), Item(33, 'c', 0.3333)};
    array = source;

    EXPECT_EQ(s21_array, array);
}

TEST(Array, T15ConstructorCopySelf)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    auto &a = s21_array;
    s21_array = a;
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    auto &b = array;
    array = b;
    // array = array;

    EXPECT_EQ(s21_array, array);
}

TEST(Array, T16Constructor)
{
    s21::Array<Item, 5> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 5> s21_array_expected { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(), Item(), };

    EXPECT_EQ(s21_array, s21_array_expected);
}

}  // namespace

// GCOVR_EXCL_STOP
