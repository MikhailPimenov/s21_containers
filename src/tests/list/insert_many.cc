#include <gtest/gtest.h>

#include <list>

#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

//  GCOVR_EXCL_START

namespace
{
TEST(List, T0InsertManyBack)
{
    s21::List<Item> s21_list {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };

    s21::List<Item> s21_list_expected {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777),
    };

    
    s21_list.Insert_many_back(Item(666), Item(777));


    EXPECT_EQ(s21_list, s21_list_expected);
}

TEST(List, T1InsertManyEmptyBack)
{
    s21::List<Item> s21_list;

    s21::List<Item> s21_list_expected {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777),
    };

    
    s21_list.Insert_many_back(Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777));


    EXPECT_EQ(s21_list, s21_list_expected);
}


TEST(List, T0InsertManyFront)
{
    s21::List<Item> s21_list {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };

    s21::List<Item> s21_list_expected {
        Item(666), Item(777), Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };

    
    s21_list.Insert_many_front(Item(666), Item(777));


    EXPECT_EQ(s21_list, s21_list_expected);
}

TEST(List, T1InsertManyEmptyFront)
{
    s21::List<Item> s21_list;

    s21::List<Item> s21_list_expected {
       Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777),
    };

    
    s21_list.Insert_many_front(Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777));


    EXPECT_EQ(s21_list, s21_list_expected);
}

TEST(List, T0InsertMany)
{
    s21::List<Item> s21_list;

    s21::List<Item> s21_list_expected {
       Item(11), 
       Item(22), 
       Item(33), 
       Item(44), 
       Item(55), 
       Item(66), 
       Item(666), 
       Item(777),
    };
  
    s21::List<Item>::iterator s21_result = s21_list.Insert_many(
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

TEST(List, T1InsertMany)
{
    s21::List<Item> s21_list { 
        Item(999, 'h', 0.777), 
        Item(888, 'i', 0.666),
        Item(999, 'q', 0.777), 
    };

    s21::List<Item> s21_list_expected {
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
    
    s21::List<Item>::iterator s21_result = s21_list.Insert_many(
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

TEST(List, T2InsertMany)
{
    s21::List<Item> s21_list { 
        Item(999, 'h', 0.777), 
        Item(888, 'i', 0.666), 
        Item(999, 'q', 0.777), 
    };

    s21::List<Item> s21_list_expected {
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
    
    s21::List<Item>::iterator s21_result = s21_list.Insert_many(
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

TEST(List, T3InsertMany)
{
    s21::List<Item> s21_list { 
        Item(999, 'h', 0.777), 
        Item(888, 'i', 0.666), 
        Item(999, 'q', 0.777), 
        Item(555, 'j', 0.555), 
        Item(444, 'k', 0.333), 
    };

    s21::List<Item> s21_list_expected {
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
    
    s21::List<Item>::iterator s21_result = s21_list.Insert_many(
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

} // namespace

//  GCOVR_EXCL_STOP