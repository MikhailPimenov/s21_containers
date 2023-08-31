#include <gtest/gtest.h>

#include <array>
#include "../../s21_array.h"

#include "../item.h"
#include "../array_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(Array, T0Operator)
{
    s21::Array<int, 3> s21_array { 3, 5, 7 };
    std::array<int, 3> array { 3, 5, 7 };

    EXPECT_EQ(s21_array[0], array[0]);
}

TEST(Array, T1Operator)
{
    s21::Array<double, 4> s21_array { 3.5, 8.77, 9.65, 8.08 };
    std::array<double, 4> array { 3.5, 8.77, 9.65, 8.08 };

    EXPECT_EQ(s21_array[1], array[1]);
}

TEST(Array, T2Operator)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array[2], array[2]);
}

TEST(Vector, T3Operator)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item item(666, 'h', 0.666666);
    s21_array[0]   = item;
    array[0]       = item;
    EXPECT_EQ(s21_array, array);
}

TEST(Array, T4Operator)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item item(666, 'h', 0.666666);
    s21_array[1]   = item;
    array[1]       = item;
    EXPECT_EQ(s21_array, array);
}

TEST(Array, T5Operator)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item item(666, 'h', 0.666666);
    s21_array[2]   = item;
    array[2]       = item;
    EXPECT_EQ(s21_array, array);
}







TEST(Array, T6Operator)
{
    const s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array[0], array[0]);
}

TEST(Array, T7Operator)
{
    const s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array[1], array[1]);
}

TEST(Array, T8Operator)
{
    const s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array[2], array[2]);
}






TEST(Array, T9At)
{
    const s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array.At(0), array.at(0));
}

TEST(Array, T10At)
{
    const s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array.At(1), array.at(1));
}

TEST(Array, T11At)
{
    const s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array.At(2), array.at(2));
}

TEST(Array, T12AtOutOfRange)
{
    const s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_THROW(s21_array.At(99), std::out_of_range);
}




TEST(Array, T13At)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item item0(6666, 'h', 0.666666);
    const Item item1(7777, 'j', 0.777777);
    const Item item2(8888, 'k', 0.888888);
    s21_array.At(0) = item0;
    s21_array.At(1) = item1;
    s21_array.At(2) = item2;
    array.at(0) = item0;
    array.at(1) = item1;
    array.at(2) = item2;

    EXPECT_EQ(s21_array.At(0), array.at(0));
    EXPECT_EQ(s21_array, array);
}

TEST(Array, T14AtOutOfRange)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item item0(6666, 'h', 0.666666);
    EXPECT_THROW(s21_array.At(99) = item0, std::out_of_range);
}

TEST(Array, T15AtOutOfRange)
{
    const s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_THROW(s21_array.At(99), std::out_of_range);
}









TEST(Array, T16At)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array.At(0), array.at(0));
}

TEST(Array, T17At)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array.At(1), array.at(1));
}

TEST(Array, T18At)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array.At(2), array.at(2));
}

TEST(Array, T19AtOutOfRange)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    EXPECT_THROW(s21_array.At(10), std::out_of_range);
}

TEST(Array, T20AtOutOfRange)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    EXPECT_THROW(s21_array.At(-1), std::out_of_range);
}

TEST(Array, T21AtOutOfRange)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    EXPECT_THROW(s21_array.At(123), std::out_of_range);
}











TEST(Array, T22Front)
{
    const s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array.Front(), array.front());
}

TEST(Array, T23Front)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21_array.Front() = Item(666);
    array.front() = Item(666);

    EXPECT_EQ(s21_array, array);
}









TEST(Array, T24Back)
{
    const s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array.Back(), array.back());
}   

TEST(Array, T25Back)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21_array.Back() = Item(666);
    array.back() = Item(666);

    EXPECT_EQ(s21_array, array);
}









TEST(Array, T26Data)
{
    const s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item* s21_data = s21_array.Data();
    const Item* data = array.data();

    EXPECT_EQ(s21_data[0], data[0]);
    EXPECT_EQ(s21_data[1], data[1]);
    EXPECT_EQ(s21_data[2], data[2]);
}   

TEST(Array, T27Data)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    Item* s21_data = s21_array.Data();
    Item* data = array.data();

    s21_data[1] = Item(666);
    data[1] = Item(666);

    EXPECT_EQ(s21_data[0], data[0]);
    EXPECT_EQ(s21_data[1], data[1]);
    EXPECT_EQ(s21_data[2], data[2]);
}   



}  // namespace

// GCOVR_EXCL_STOP
