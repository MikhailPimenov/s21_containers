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


TEST(array, T0DefaultConstructor)
{
    s21::Array<Item, 0> s21_array;
    std::array<Item, 0> array;



    EXPECT_EQ(s21_array, array);
}





TEST(array, T1ConstructorInitializer)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array, array);
}

TEST(array, T2ConstructorInitializerEmpty)
{
    s21::Array<Item, 0> s21_array {};
    std::array<Item, 0> array {};

    EXPECT_EQ(s21_array, array);
}





TEST(array, T6ConstructorCopy)
{
    const s21::Array<Item, 3> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21::Array<Item, 3> s21_array(s21_source);
    std::array<Item, 3> array(source);

    EXPECT_EQ(s21_array, array);
}

TEST(array, T7ConstructorCopyEmpty)
{
    s21::Array<Item, 0> s21_source;
    std::array<Item, 0> source;

    s21::Array<Item, 0> s21_array(s21_source);
    std::array<Item, 0> array(source);

    EXPECT_EQ(s21_array, array);
}

TEST(array, T8ConstructorCopy)
{
    const s21::Array<Item, 2> s21_source{Item(33, 'i', 0.3333), Item(33, 'c', 0.3333)};
    const std::array<Item, 2> source{Item(33, 'i', 0.3333), Item(33, 'c', 0.3333)};

    s21::Array<Item, 2> s21_array(s21_source);
    std::array<Item, 2> array(source);

    EXPECT_EQ(s21_array, array);
}





TEST(array, T9ConstructorMove)
{
    s21::Array<Item, 3> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21::Array<Item, 3> s21_array(std::move(s21_source));
    std::array<Item, 3> array(std::move(source));

    EXPECT_EQ(s21_array, array);
    EXPECT_EQ(s21_source, source);
}






TEST(array, T11OperatorCopy)
{
    const s21::Array<Item, 3> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21::Array<Item, 3> s21_array;
    s21_array = s21_source;
    std::array<Item, 3> array;
    array = source;

    EXPECT_EQ(s21_array, array);
}

TEST(array, T12ConstructorCopyEmpty)
{
    s21::Array<Item, 0> s21_source;
    std::array<Item, 0> source;

    s21::Array<Item, 0> s21_array;
    s21_array = s21_source;
    std::array<Item, 0> array;
    array = source;

    EXPECT_EQ(s21_array, array);
}

TEST(array, T13OperatorCopy)
{
    const s21::Array<Item, 3> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21::Array<Item, 3> s21_array{Item(1999), Item(22, 'h'), Item(33, 'c', 0.3333)};
    s21_array = s21_source ;
    std::array<Item, 3> array{Item(1999), Item(22, 'h'), Item(33, 'c', 0.3333)};
    array = source;

    EXPECT_EQ(s21_array, array);
}

TEST(array, T14ConstructorCopyEmpty)
{
    s21::Array<Item, 0> s21_source;
    std::array<Item, 0> source;

    s21::Array<Item, 0> s21_array;
    s21_array = s21_source;
    std::array<Item, 0> array;
    array = source;

    EXPECT_EQ(s21_array, array);
}

TEST(array, T15ConstructorCopySelf)
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


}  // namespace

// GCOVR_EXCL_STOP
