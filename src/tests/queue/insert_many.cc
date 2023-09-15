#include <gtest/gtest.h>

#include <list>
#include <queue>

#include "../../s21_queue.h"
#include "../item.h"
#include "../queue_helpers.h"

//  GCOVR_EXCL_START

namespace
{
TEST(Queue, T0InsertMany)
{
    s21::List<Item> s21_list { Item(11), Item(22), Item(33) };
    s21::Queue<Item> s21_queue(s21_list);

    s21::List<Item> s21_list2 { Item(11), Item(22), Item(33), Item(666), Item(777), Item(-33) };
    s21::Queue<Item> s21_queue_expected(s21_list2);

    
    s21_queue.Insert_many_back(Item(666), Item(777), Item(-33));


    EXPECT_EQ(s21_queue, s21_queue_expected);
}

TEST(Queue, T1InsertManyEmpty)
{
    s21::List<Item> s21_queue;

    s21::List<Item> s21_queue_expected {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777),
    };

    
    s21_queue.Insert_many_back(Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777));


    EXPECT_EQ(s21_queue, s21_queue_expected);
}

} // namespace

//  GCOVR_EXCL_STOP