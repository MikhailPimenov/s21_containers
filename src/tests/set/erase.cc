#include <gtest/gtest.h>

#include <stack>
#include <list>
#include <vector>
#include <deque>
#include <set>

#include "../../s21_set.h"
#include "../item.h"
#include "../set_helpers.h"
#include "../tree_helpers.h"

// GCOVR_EXCL_START

namespace
{


TEST(Set, T0EraseBegin)
{
    s21::Set<Item, ComparatorItem> s21_set;
    std::set<Item, ComparatorItem> set;

    s21_set.Insert(Item(4));
    s21_set.Insert(Item(3));
    s21_set.Insert(Item(7));

    // std::cout << s21_set << '\n';

    set.insert(Item(4));
    set.insert(Item(3));
    set.insert(Item(7));
    // std::cout << "Before erase: \n";
    // for (auto it = set.cbegin(); it != set.cend(); ++it)
        // std::cout << "{" << it->first << " : " << it->second << "}\n";


    s21::Set<Item, ComparatorItem>::iterator s21_it_result = s21_set.Erase(s21_set.cbegin());
    std::set<Item, ComparatorItem>::iterator it_result = set.erase(set.cbegin());

    EXPECT_EQ(*s21_it_result, *it_result);
    // std::cout << "After erase: \n";

    // for (auto it = s21_set.cbegin(); it != s21_set.cend(); ++it)
        // std::cout << "{" << it->first << " : " << it->second << "}\n";

    EXPECT_EQ(s21_set, set);
    EXPECT_TRUE(minimalHeightAVL(s21_set.Size(), s21_set.Height()));
    
    s21_set.Insert(Item());
    set.insert(Item());
    EXPECT_EQ(s21_set, set);
    EXPECT_TRUE(minimalHeightAVL(s21_set.Size(), s21_set.Height()));
}

TEST(Set, T1EraseRBegin)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21_set.Insert(Item(4));
    s21_set.Insert(Item(3));
    s21_set.Insert(Item(7));

    std::set<Item, ComparatorItem> set;
    set.insert(Item(4));
    set.insert(Item(3));
    set.insert(Item(7));

    s21::Set<Item, ComparatorItem>::const_iterator s21_it = s21_set.cbegin();
    std::set<Item, ComparatorItem>::const_iterator it = set.cbegin();
    for(int i = 0; i < 2; i++) {
        ++s21_it;
        ++it;
    }

    s21::Set<Item, ComparatorItem>::iterator s21_it_result = s21_set.Erase(s21_it);
    std::set<Item, ComparatorItem>::iterator it_result = set.erase(it);

    EXPECT_EQ(s21_it_result, s21_set.end());
    EXPECT_EQ(it_result, set.end());

    // std::cout << "After erase: \n";

    // for (auto it = s21_set.cbegin(); it != s21_set.cend(); ++it)
    //     std::cout << "{" << it->first << " : " << it->second << "}\n";


    EXPECT_EQ(s21_set, set);
}

TEST(Set, T2EraseRoot)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21_set.Insert(Item(4));
    s21_set.Insert(Item(3));
    s21_set.Insert(Item(7));

    std::set<Item, ComparatorItem> set;
    set.insert(Item(4));
    set.insert(Item(3));
    set.insert(Item(7));

    s21::Set<Item, ComparatorItem>::const_iterator s21_it = s21_set.cbegin();
    std::set<Item, ComparatorItem>::const_iterator it = set.cbegin();
    for(int i = 0; i < 1; i++) {
        ++s21_it;                    
        ++it;
    }

    s21::Set<Item, ComparatorItem>::iterator s21_it_result = s21_set.Erase(s21_it);
    std::set<Item, ComparatorItem>::iterator it_result = set.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    // std::cout << "After erase: \n";

    // for (auto it = s21_set.cbegin(); it != s21_set.cend(); ++it)
    //     std::cout << "{" << it->first << " : " << it->second << "}\n";


    EXPECT_EQ(s21_set, set);   
}

TEST(Set, T2_1EraseRoot)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21_set.Insert(Item(3));
    s21_set.Insert(Item(4));

    std::set<Item, ComparatorItem> set;
    set.insert(Item(3));
    set.insert(Item(4));

    s21::Set<Item, ComparatorItem>::const_iterator s21_it = s21_set.cbegin();
    std::set<Item, ComparatorItem>::const_iterator it = set.cbegin();
    for(int i = 0; i < 1; i++) {
        ++s21_it;                    
        ++it;
    }

    s21::Set<Item, ComparatorItem>::iterator s21_it_result = s21_set.Erase(s21_it);
    std::set<Item, ComparatorItem>::iterator it_result = set.erase(it);

    EXPECT_EQ(s21_it_result, s21_set.end());
    EXPECT_EQ(it_result, set.end());

    EXPECT_EQ(s21_set, set);
}

TEST(Set, T3RandomErase)
{
    s21::Set<Item, ComparatorItem> s21_set;

    s21_set.Insert(Item(3));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(4));

    s21_set.Insert(Item(14));
    s21_set.Insert(Item(11));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-8));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(-18));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(3));
    s21_set.Insert(Item(29));
    s21_set.Insert(Item(30));
    s21_set.Insert(Item(31));
    s21_set.Insert(Item(34));
    s21_set.Insert(Item(37));


    std::set<Item, ComparatorItem> set;

    set.insert(Item(3));
    set.insert(Item(5));
    set.insert(Item(5));
    set.insert(Item(4));

   set.insert(Item(14));
   set.insert(Item(11));
   set.insert(Item(7));
   set.insert(Item(8));
   set.insert(Item(-8));
   set.insert(Item(7));
   set.insert(Item(-18));
   set.insert(Item(6));
   set.insert(Item(3));
   set.insert(Item(29));
   set.insert(Item(30));
   set.insert(Item(31));
   set.insert(Item(34));
   set.insert(Item(37));



    // std::cout << s21_set << "\n\n";
    s21::Set<Item, ComparatorItem>::const_iterator s21_it = s21_set.cbegin();
    std::set<Item, ComparatorItem>::const_iterator it = set.cbegin();
    for (int i = 0; i < 7; ++i) {
        ++s21_it;
        ++it;
    }

    s21::Set<Item, ComparatorItem>::iterator s21_it_result = s21_set.Erase(s21_it);
    std::set<Item, ComparatorItem>::iterator it_result = set.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_set, set);
    EXPECT_TRUE(minimalHeightAVL(s21_set.Size(), s21_set.Height()));    
}


TEST(Set, T4RandomErase)
{
    // return;
    s21::Set<Item, ComparatorItem> s21_set;

    s21_set.Insert(Item(3));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(4));

    s21_set.Insert(Item(14));
    s21_set.Insert(Item(11));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-8));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(-18));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(3));
    s21_set.Insert(Item(29));
    s21_set.Insert(Item(30));
    s21_set.Insert(Item(31));
    s21_set.Insert(Item(34));
    s21_set.Insert(Item(37));


    std::set<Item, ComparatorItem> set;

    set.insert(Item(3));
    set.insert(Item(5));
    set.insert(Item(5));
    set.insert(Item(4));

   set.insert(Item(14));
   set.insert(Item(11));
   set.insert(Item(7));
   set.insert(Item(8));
   set.insert(Item(-8));
   set.insert(Item(7));
   set.insert(Item(-18));
   set.insert(Item(6));
   set.insert(Item(3));
   set.insert(Item(29));
   set.insert(Item(30));
   set.insert(Item(31));
   set.insert(Item(34));
   set.insert(Item(37));



    // std::cout << s21_set << "\n\n";
    s21::Set<Item, ComparatorItem>::const_iterator s21_it = s21_set.cbegin();
    std::set<Item, ComparatorItem>::const_iterator it = set.cbegin();
    for (int i = 0; i < 11; ++i) {
        ++s21_it;
        ++it;
    }

    s21::Set<Item, ComparatorItem>::iterator s21_it_result = s21_set.Erase(s21_it);
    std::set<Item, ComparatorItem>::iterator it_result = set.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_set, set);
    EXPECT_TRUE(minimalHeightAVL(s21_set.Size(), s21_set.Height()));    
}

TEST(Set, T5RandomErase)
{
    s21::Set<Item, ComparatorItem> s21_set;

    s21_set.Insert(Item(3));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(4));

    s21_set.Insert(Item(14));
    s21_set.Insert(Item(11));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-8));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(-18));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(3));
    s21_set.Insert(Item(29));
    s21_set.Insert(Item(30));
    s21_set.Insert(Item(31));
    s21_set.Insert(Item(34));
    s21_set.Insert(Item(37));


    std::set<Item, ComparatorItem> set;

    set.insert(Item(3));
    set.insert(Item(5));
    set.insert(Item(5));
    set.insert(Item(4));

   set.insert(Item(14));
   set.insert(Item(11));
   set.insert(Item(7));
   set.insert(Item(8));
   set.insert(Item(-8));
   set.insert(Item(7));
   set.insert(Item(-18));
   set.insert(Item(6));
   set.insert(Item(3));
   set.insert(Item(29));
   set.insert(Item(30));
   set.insert(Item(31));
   set.insert(Item(34));
   set.insert(Item(37));



    // std::cout << s21_set << "\n\n";
    s21::Set<Item, ComparatorItem>::const_iterator s21_it = s21_set.cbegin();
    std::set<Item, ComparatorItem>::const_iterator it = set.cbegin();
    for (int i = 0; i < 3; ++i) {
        ++s21_it;
        ++it;
    }

    s21::Set<Item, ComparatorItem>::iterator s21_it_result = s21_set.Erase(s21_it);
    std::set<Item, ComparatorItem>::iterator it_result = set.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_set, set);
    EXPECT_TRUE(minimalHeightAVL(s21_set.Size(), s21_set.Height()));    
}

TEST(Set, T6RandomErase)
{
    s21::Set<Item, ComparatorItem> s21_set;

    s21_set.Insert(Item(3));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(4));

    s21_set.Insert(Item(14));
    s21_set.Insert(Item(11));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-8));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(-18));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(3));
    s21_set.Insert(Item(29));
    s21_set.Insert(Item(30));
    s21_set.Insert(Item(31));
    s21_set.Insert(Item(34));
    s21_set.Insert(Item(37));


    std::set<Item, ComparatorItem> set;

    set.insert(Item(3));
    set.insert(Item(5));
    set.insert(Item(5));
    set.insert(Item(4));

   set.insert(Item(14));
   set.insert(Item(11));
   set.insert(Item(7));
   set.insert(Item(8));
   set.insert(Item(-8));
   set.insert(Item(7));
   set.insert(Item(-18));
   set.insert(Item(6));
   set.insert(Item(3));
   set.insert(Item(29));
   set.insert(Item(30));
   set.insert(Item(31));
   set.insert(Item(34));
   set.insert(Item(37));



    // std::cout << s21_set << "\n\n";
    s21::Set<Item, ComparatorItem>::const_iterator s21_it = s21_set.cbegin();
    std::set<Item, ComparatorItem>::const_iterator it = set.cbegin();
    for (int i = 0; i < 5; ++i) {
        ++s21_it;
        ++it;
    }

    EXPECT_EQ(s21_set, set);
    
    s21::Set<Item, ComparatorItem>::iterator s21_it_result = s21_set.Erase(s21_it);
    std::set<Item, ComparatorItem>::iterator it_result = set.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_set, set);
    EXPECT_TRUE(minimalHeightAVL(s21_set.Size(), s21_set.Height()));    
}

TEST(Set, T7RandomEraseRoot)
{
    s21::Set<Item, ComparatorItem> s21_set;

    s21_set.Insert(Item(3));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(4));

    s21_set.Insert(Item(14));
    s21_set.Insert(Item(11));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-8));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(-18));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(3));
    s21_set.Insert(Item(29));
    s21_set.Insert(Item(30));
    s21_set.Insert(Item(31));
    s21_set.Insert(Item(34));
    s21_set.Insert(Item(37));


    std::set<Item, ComparatorItem> set;

    set.insert(Item(3));
    set.insert(Item(5));
    set.insert(Item(5));
    set.insert(Item(4));

   set.insert(Item(14));
   set.insert(Item(11));
   set.insert(Item(7));
   set.insert(Item(8));
   set.insert(Item(-8));
   set.insert(Item(7));
   set.insert(Item(-18));
   set.insert(Item(6));
   set.insert(Item(3));
   set.insert(Item(29));
   set.insert(Item(30));
   set.insert(Item(31));
   set.insert(Item(34));
   set.insert(Item(37));


    EXPECT_EQ(s21_set, set);
    // std::cout << s21_set << "\n\n";
    s21::Set<Item, ComparatorItem>::const_iterator s21_it = s21_set.cbegin();
    std::set<Item, ComparatorItem>::const_iterator it = set.cbegin();
    for (int i = 0; i < 10; ++i) {
        ++s21_it;
        ++it;
    }

    s21::Set<Item, ComparatorItem>::iterator s21_it_result = s21_set.Erase(s21_it);
    std::set<Item, ComparatorItem>::iterator it_result = set.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_set, set);
    EXPECT_TRUE(minimalHeightAVL(s21_set.Size(), s21_set.Height()));    
}

TEST(Set, T8RandomEraseRoot)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21_set.Insert(Item(60));
    s21_set.Insert(Item(50));
    s21_set.Insert(Item(70));
    s21_set.Insert(Item(45));
    s21_set.Insert(Item(55));
    s21_set.Insert(Item(65));
    s21_set.Insert(Item(80));
    s21_set.Insert(Item(41));
    s21_set.Insert(Item(54));
    s21_set.Insert(Item(58));
    s21_set.Insert(Item(61));
    s21_set.Insert(Item(75));
    s21_set.Insert(Item(85));
    s21_set.Insert(Item(57));
    s21_set.Insert(Item(88));
    s21_set.Insert(Item(90)); 
   
    std::set<Item, ComparatorItem> set;
    set.insert(Item(60));
    set.insert(Item(50));
    set.insert(Item(70));
    set.insert(Item(45));
    set.insert(Item(55));
    set.insert(Item(65));
    set.insert(Item(80));
    set.insert(Item(41));
    set.insert(Item(54));
    set.insert(Item(58));
    set.insert(Item(61));
    set.insert(Item(75));
    set.insert(Item(85));
    set.insert(Item(57));
    set.insert(Item(88));
    set.insert(Item(90)); 


    EXPECT_EQ(s21_set, set);
    // std::cout << s21_set << "\n\n";
    s21::Set<Item, ComparatorItem>::const_iterator s21_it = s21_set.cbegin();
    std::set<Item, ComparatorItem>::const_iterator it = set.cbegin();
    for (int i = 0; i < 7; ++i) {
        ++s21_it;
        ++it;
    }

    // std::cout << "Erase: " << s21_it->first << '\n';
    s21::Set<Item, ComparatorItem>::iterator s21_it_result = s21_set.Erase(s21_it);
    std::set<Item, ComparatorItem>::iterator it_result = set.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_set, set);
    EXPECT_TRUE(minimalHeightAVL(s21_set.Size(), s21_set.Height()));    
}

TEST(Set, T9RandomErase)
{
    s21::Set<Item, ComparatorItem> s21_set;

    s21_set.Insert(Item(3));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(4));

    s21_set.Insert(Item(14));
    s21_set.Insert(Item(11));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-8));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(-18));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(3));
    s21_set.Insert(Item(29));
    s21_set.Insert(Item(30));
    s21_set.Insert(Item(31));
    s21_set.Insert(Item(34));
    s21_set.Insert(Item(37));


    std::set<Item, ComparatorItem> set;

    set.insert(Item(3));
    set.insert(Item(5));
    set.insert(Item(5));
    set.insert(Item(4));

    set.insert(Item(14));
    set.insert(Item(11));
    set.insert(Item(7));
    set.insert(Item(8));
    set.insert(Item(-8));
    set.insert(Item(7));
    set.insert(Item(-18));
    set.insert(Item(6));
    set.insert(Item(3));
    set.insert(Item(29));
    set.insert(Item(30));
    set.insert(Item(31));
    set.insert(Item(34));
    set.insert(Item(37));



    // std::cout << s21_set << "\n\n";
    s21::Set<Item, ComparatorItem>::const_iterator s21_it = s21_set.cbegin();
    std::set<Item, ComparatorItem>::const_iterator it = set.cbegin();
    for (int i = 0; i < 8; ++i) {
        ++s21_it;
        ++it;
    }

    s21::Set<Item, ComparatorItem>::iterator s21_it_result = s21_set.Erase(s21_it);
    std::set<Item, ComparatorItem>::iterator it_result = set.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_set, set);
    EXPECT_TRUE(minimalHeightAVL(s21_set.Size(), s21_set.Height()));    
}
























TEST(Set, T0RandomExtract)
{
    // return;
    s21::Set<Item, ComparatorItem> s21_set;

    s21_set.Insert(Item(3));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(4));

    s21_set.Insert(Item(14));
    s21_set.Insert(Item(11));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-8));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(-18));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(3));
    s21_set.Insert(Item(29));
    s21_set.Insert(Item(30));
    s21_set.Insert(Item(31));
    s21_set.Insert(Item(34));
    s21_set.Insert(Item(37));


    std::set<Item, ComparatorItem> set;

    set.insert(Item(3));
    set.insert(Item(5));
    set.insert(Item(5));
    set.insert(Item(4));

    set.insert(Item(14));
    set.insert(Item(11));
    set.insert(Item(7));
    set.insert(Item(8));
    set.insert(Item(-8));
    set.insert(Item(7));
    set.insert(Item(-18));
    set.insert(Item(6));
    set.insert(Item(3));
    set.insert(Item(29));
    set.insert(Item(30));
    set.insert(Item(31));
    set.insert(Item(34));
    set.insert(Item(37));



    // std::cout << s21_set << "\n\n";
    s21::Set<Item, ComparatorItem>::const_iterator s21_it = s21_set.cbegin();
    std::set<Item, ComparatorItem>::const_iterator it = set.cbegin();
    for (int i = 0; i < 8; ++i) {
        ++s21_it;
        ++it;
    }

    s21::Set<Item, ComparatorItem>::node_type s21_it_result = s21_set.Extract(s21_it);
    std::set<Item, ComparatorItem>::node_type it_result = set.extract(it);

    EXPECT_EQ(it_result.value(), s21_it_result.Get());

    EXPECT_EQ(s21_set, set);
    EXPECT_TRUE(minimalHeightAVL(s21_set.Size(), s21_set.Height()));    

// TODO: leaks?
//    delete &s21_it_result;
//    delete &it_result;

}






TEST(Set, T1RandomExtract)
{
    // return;
    s21::Set<Item, ComparatorItem> s21_set;

    s21_set.Insert(Item(3));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(5));
    s21_set.Insert(Item(4));

    s21_set.Insert(Item(14));
    s21_set.Insert(Item(11));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-8));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(-18));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(3));
    s21_set.Insert(Item(29));
    s21_set.Insert(Item(30));
    s21_set.Insert(Item(31));
    s21_set.Insert(Item(34));
    s21_set.Insert(Item(37));


    std::set<Item, ComparatorItem> set;

    set.insert(Item(3));
    set.insert(Item(5));
    set.insert(Item(5));
    set.insert(Item(4));

    set.insert(Item(14));
    set.insert(Item(11));
    set.insert(Item(7));
    set.insert(Item(8));
    set.insert(Item(-8));
    set.insert(Item(7));
    set.insert(Item(-18));
    set.insert(Item(6));
    set.insert(Item(3));
    set.insert(Item(29));
    set.insert(Item(30));
    set.insert(Item(31));
    set.insert(Item(34));
    set.insert(Item(37));



    // std::cout << s21_set << "\n\n";
    s21::Set<Item, ComparatorItem>::const_iterator s21_it = s21_set.cbegin();
    std::set<Item, ComparatorItem>::const_iterator it = set.cbegin();
    for (int i = 0; i < 4; ++i) {
        ++s21_it;
        ++it;
    }

    s21::Set<Item, ComparatorItem>::node_type s21_it_result = s21_set.Extract(s21_it);
    std::set<Item, ComparatorItem>::node_type it_result = set.extract(it);

    EXPECT_EQ(it_result.value(), s21_it_result.Get());

    EXPECT_EQ(s21_set, set);
    EXPECT_TRUE(minimalHeightAVL(s21_set.Size(), s21_set.Height()));    
}


}  // namespace

// GCOVR_EXCL_STOP
