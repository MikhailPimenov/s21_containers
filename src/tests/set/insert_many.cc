#include <gtest/gtest.h>

#include "../../s21_set.h"
#include "../../s21_vector.h"
#include "../item.h"
#include "../set_helpers.h"


//  GCOVR_EXCL_START

namespace
{
TEST(Set, T0InsertMany)
{
    s21::Set<Item, ComparatorItem> s21_set {
        Item(11), 
        Item(22), 
        Item(33), 
        Item(44), 
        Item(55), 
        Item(66),
    };

    s21::Set<Item, ComparatorItem> s21_set_expected {
        Item(11), 
        Item(22), 
        Item(33), 
        Item(44), 
        Item(55), 
        Item(66),
        Item(666), 
        Item(777),
    };

    
    s21_set.Insert_many(Item(666), Item(777));


    EXPECT_EQ(s21_set, s21_set_expected);
}

TEST(Set, T1InsertManyEmpty)
{
    s21::Set<Item, ComparatorItem> s21_set;

    s21::Set<Item, ComparatorItem> s21_set_expected {
        Item(11) , 
        Item(22) , 
        Item(33) , 
        Item(44) , 
        Item(55) , 
        Item(66) ,
        Item(666) , 
        Item(777) ,
    };

    
    s21::Vector<std::pair<s21::Set<Item, ComparatorItem>::iterator,bool>> s21_result = s21_set.Insert_many(
        Item(11),
        Item(22),
        Item(33),
        Item(44),
        Item(55),
        Item(66),
        Item(666), 
        Item(777)
    );


    EXPECT_EQ(s21_set, s21_set_expected);
}



TEST(Set, T2InsertMany)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21::Set<Item, ComparatorItem> s21_set2 = s21_set;

    s21::Set<Item, ComparatorItem> s21_set_expected {
        Item(11), 
        Item(22), 
        Item(33), 
        Item(44), 
        Item(55), 
        Item(66),
        Item(666), 
        Item(777),
    };

    s21::Vector<std::pair<s21::Set<Item, ComparatorItem>::iterator,bool>> s21_result_expected;
    s21_result_expected.Push_back(s21_set2.Insert(Item(11)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(22)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(33)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(44)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(55)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(66)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(666)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(777)));
  
    s21::Vector<std::pair<s21::Set<Item, ComparatorItem>::iterator,bool>> s21_result = s21_set.Insert_many(
        Item(11), 
        Item(22), 
        Item(33), 
        Item(44), 
        Item(55), 
        Item(66),
        Item(666), 
        Item(777)
    );


    EXPECT_EQ(s21_set, s21_set_expected);
    EXPECT_EQ(s21_set2, s21_set_expected);

    EXPECT_EQ(s21_result.Size(), s21_result_expected.Size());
    auto it = s21_result.begin();
    auto it_expected = s21_result_expected.begin();

    while (it != s21_result.end() && it_expected != s21_result_expected.end()) {
        EXPECT_EQ(*(it->first), *(it_expected->first));
        EXPECT_EQ(it->second, it_expected->second);
        ++it;
        ++it_expected;
    }
}

TEST(Set, T3InsertMany)
{
    s21::Set<Item, ComparatorItem> s21_set { 
        Item(44, 'a'), 
        Item(55), 
    };
    s21::Set<Item, ComparatorItem> s21_set2 = s21_set;

    s21::Set<Item, ComparatorItem> s21_set_expected {
        Item(11), 
        Item(22), 
        Item(33), 
        Item(44, 'a'), 
        Item(55), 
        Item(66),
        Item(666), 
        Item(777),
    };

    s21::Vector<std::pair<s21::Set<Item, ComparatorItem>::iterator,bool>> s21_result_expected;
    s21_result_expected.Push_back(s21_set2.Insert(Item(11)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(22)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(33)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(44)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(55)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(66)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(666)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(777)));
  
    s21::Vector<std::pair<s21::Set<Item, ComparatorItem>::iterator,bool>> s21_result = s21_set.Insert_many(
        Item(11), 
        Item(22), 
        Item(33), 
        Item(44), 
        Item(55), 
        Item(66),
        Item(666), 
        Item(777)
    );


    EXPECT_EQ(s21_set, s21_set_expected);
    EXPECT_EQ(s21_set2, s21_set_expected);

    EXPECT_EQ(s21_result.Size(), s21_result_expected.Size());
    auto it = s21_result.begin();
    auto it_expected = s21_result_expected.begin();

    while (it != s21_result.end() && it_expected != s21_result_expected.end()) {
        EXPECT_EQ(*(it->first), *(it_expected->first));
        EXPECT_EQ(it->second, it_expected->second);
        ++it;
        ++it_expected;
    }
}


TEST(Set, T4InsertMany)
{
    s21::Set<Item, ComparatorItem> s21_set { 
        Item(111, 's', 0.111), 
        Item(44, 'a'), 
        Item(55), 
    };
    s21::Set<Item, ComparatorItem> s21_set2 = s21_set;

    s21::Set<Item, ComparatorItem> s21_set_expected {
        Item(111, 's', 0.111),
        Item(11), 
        Item(22), 
        Item(33), 
        Item(44, 'a'),
        Item(55),
        Item(66),
        Item(666), 
        Item(777),
    };

    s21::Vector<std::pair<s21::Set<Item, ComparatorItem>::iterator,bool>> s21_result_expected;
    s21_result_expected.Push_back(s21_set2.Insert(Item(11)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(22)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(33)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(44)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(55)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(66)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(666)));
    s21_result_expected.Push_back(s21_set2.Insert(Item(777)));
  
    s21::Vector<std::pair<s21::Set<Item, ComparatorItem>::iterator,bool>> s21_result = s21_set.Insert_many(
        Item(11), 
        Item(22), 
        Item(33), 
        Item(44), 
        Item(55), 
        Item(66),
        Item(666), 
        Item(777)
    );


    EXPECT_EQ(s21_set, s21_set_expected);
    EXPECT_EQ(s21_set2, s21_set_expected);

    EXPECT_EQ(s21_result.Size(), s21_result_expected.Size());
    auto it = s21_result.begin();
    auto it_expected = s21_result_expected.begin();

    while (it != s21_result.end() && it_expected != s21_result_expected.end()) {
        EXPECT_EQ(*(it->first), *(it_expected->first));
        EXPECT_EQ(it->second, it_expected->second);
        ++it;
        ++it_expected;
    }
}

} // namespace

//  GCOVR_EXCL_STOP