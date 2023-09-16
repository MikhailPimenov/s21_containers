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


TEST(Vector, T0InsertManyBack)
{
    s21::Vector<Item> s21_vector;
    s21::Vector<Item> vector_expected {Item(-33), Item(44), Item(-55), Item(66)};

    s21_vector.Insert_many_back(Item(-33), Item(44), Item(-55), Item(66));



    EXPECT_EQ(s21_vector, vector_expected);
}

TEST(Vector, T1InsertManyBack)
{
    s21::Vector<Item> s21_vector {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };

    s21::Vector<Item> s21_vector_expected {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777),
    };

    
    s21_vector.Insert_many_back(Item(666), Item(777));


    EXPECT_EQ(s21_vector, s21_vector_expected);
}

TEST(Vector, T2InsertManyEmptyBack)
{
    s21::Vector<Item> s21_vector;

    s21::Vector<Item> s21_vector_expected {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777),
    };

    
    s21_vector.Insert_many_back(Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777));


    EXPECT_EQ(s21_vector, s21_vector_expected);
}







TEST(Vector, T0InsertMany)
{
    s21::Vector<Item> s21_list;

    s21::Vector<Item> s21_list_expected {
       Item(11), 
       Item(22), 
       Item(33), 
       Item(44), 
       Item(55), 
       Item(66), 
       Item(666), 
       Item(777),
    };
  
    s21::Vector<Item>::iterator s21_result = s21_list.Insert_many(
        s21_list.end(), 
        Item(11), 
        Item(22), 
        Item(33), 
        Item(44), 
        Item(55), 
        Item(66), 
        Item(666), 
        Item(777)
    );

    EXPECT_EQ(s21_list, s21_list_expected);
    EXPECT_EQ(s21_result, s21_list.end());
}

TEST(Vector, T1InsertMany)
{
    s21::Vector<Item> s21_list { 
        Item(999, 'h', 0.777), 
        Item(888, 'i', 0.666),
        Item(999, 'q', 0.777), 
    };

    s21::Vector<Item> s21_list_expected {
       Item(999, 'h', 0.777), 
       Item(888, 'i', 0.666), 
       Item(999, 'q', 0.777), 
       Item(11), 
       Item(22), 
       Item(33), 
       Item(44), 
       Item(55), 
       Item(66), 
       Item(666), 
       Item(777),
    };
    
    s21::Vector<Item>::iterator s21_result = s21_list.Insert_many(
        s21_list.end(), 
        Item(11), 
        Item(22), 
        Item(33),
        Item(44), 
        Item(55), 
        Item(66), 
        Item(666), 
        Item(777)
    );

    EXPECT_EQ(s21_list, s21_list_expected);
    EXPECT_EQ(s21_result, s21_list.end());
}

TEST(Vector, T2InsertMany)
{
    s21::Vector<Item> s21_list { 
        Item(999, 'h', 0.777), 
        Item(888, 'i', 0.666), 
        Item(999, 'q', 0.777), 
    };

    s21::Vector<Item> s21_list_expected {
       Item(999, 'h', 0.777), 
       Item(888, 'i', 0.666), 
       Item(11), 
       Item(22), 
       Item(33), 
       Item(44), 
       Item(55), 
       Item(66), 
       Item(666), 
       Item(777), 
       Item(999, 'q', 0.777),
    };
    
    s21::Vector<Item>::iterator s21_result = s21_list.Insert_many(
        --s21_list.end(), 
        Item(11), 
        Item(22),
        Item(33), 
        Item(44),
        Item(55),
        Item(66), 
        Item(666), 
        Item(777)
    );


    EXPECT_EQ(s21_list, s21_list_expected);
    EXPECT_EQ(*s21_result, Item(999, 'q', 0.777));
}

TEST(Vector, T3InsertMany)
{
    s21::Vector<Item> s21_list { 
        Item(999, 'h', 0.777), 
        Item(888, 'i', 0.666), 
        Item(999, 'q', 0.777), 
        Item(555, 'j', 0.555), 
        Item(444, 'k', 0.333), 
    };

    s21::Vector<Item> s21_list_expected {
        Item(999, 'h', 0.777), 
        Item(888, 'i', 0.666), 
        Item(999, 'q', 0.777),
        Item(11), 
        Item(22), 
        Item(33), 
        Item(44), 
        Item(55), 
        Item(66), 
        Item(666), 
        Item(777), 
        Item(555, 'j', 0.555), 
        Item(444, 'k', 0.333), 
    };
    
    s21::Vector<Item>::iterator s21_result = s21_list.Insert_many(
        --(--s21_list.end()), 
        Item(11), 
        Item(22), 
        Item(33), 
        Item(44), 
        Item(55), 
        Item(66), 
        Item(666), 
        Item(777)
    );

    EXPECT_EQ(s21_list, s21_list_expected);
    EXPECT_EQ(*s21_result, Item(555, 'j', 0.555));
}

}  // namespace