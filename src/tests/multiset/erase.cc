#include <gtest/gtest.h>

#include <set>

#include "../../s21_multiset.h"
#include "../item.h"
#include "../multiset_helpers.h"
#include "../tree_helpers.h"

// GCOVR_EXCL_START

namespace
{


TEST(MultiSet, T0EraseBegin)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset;
    std::multiset<Item, ComparatorItem> multiset;

    s21_multiset.Insert(Item(4));
    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(7));

    std::cout << s21_multiset << '\n';

    multiset.insert(Item(4));
    multiset.insert(Item(3));
    multiset.insert(Item(7));
    std::cout << "Before erase: \n";
    // for (auto it = multiset.cbegin(); it != multiset.cend(); ++it)
        // std::cout << "{" << it->first << " : " << it->second << "}\n";


    s21::MultiSet<Item, ComparatorItem>::iterator s21_it_result = s21_multiset.Erase(s21_multiset.cbegin());
    std::multiset<Item, ComparatorItem>::iterator it_result = multiset.erase(multiset.cbegin());

    EXPECT_EQ(*s21_it_result, *it_result);
    std::cout << "After erase: \n";

    // for (auto it = s21_multiset.cbegin(); it != s21_multiset.cend(); ++it)
        // std::cout << "{" << it->first << " : " << it->second << "}\n";

    EXPECT_EQ(s21_multiset, multiset);
    EXPECT_TRUE(minimalHeightAVL(s21_multiset.Size(), s21_multiset.Height()));
    
    s21_multiset.Insert(Item(3));
    multiset.insert(Item(3));
    EXPECT_EQ(s21_multiset, multiset);
    EXPECT_TRUE(minimalHeightAVL(s21_multiset.Size(), s21_multiset.Height()));
}

TEST(MultiSet, T1EraseRBegin)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset;
    s21_multiset.Insert(Item(4));
    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(7));

    std::multiset<Item, ComparatorItem> multiset;
    multiset.insert(Item(4));
    multiset.insert(Item(3));
    multiset.insert(Item(7));

    s21::MultiSet<Item, ComparatorItem>::const_iterator s21_it = s21_multiset.cbegin();
    std::multiset<Item, ComparatorItem>::const_iterator it = multiset.cbegin();
    for(int i = 0; i < 2; i++) {
        ++s21_it;
        ++it;
    }

    s21::MultiSet<Item, ComparatorItem>::iterator s21_it_result = s21_multiset.Erase(s21_it);
    std::multiset<Item, ComparatorItem>::iterator it_result = multiset.erase(it);

    EXPECT_EQ(s21_it_result, s21_multiset.end());
    EXPECT_EQ(it_result, multiset.end());

    std::cout << "After erase: \n";

    // for (auto it = s21_multiset.cbegin(); it != s21_multiset.cend(); ++it)
        // std::cout << "{" << it->first << " : " << it->second << "}\n";


    EXPECT_EQ(s21_multiset, multiset);
}

TEST(MultiSet, T2EraseRoot)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset;
    s21_multiset.Insert(Item(4));
    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(7));

    std::multiset<Item, ComparatorItem> multiset;
    multiset.insert(Item(4));
    multiset.insert(Item(3));
    multiset.insert(Item(7));

    s21::MultiSet<Item, ComparatorItem>::const_iterator s21_it = s21_multiset.cbegin();
    std::multiset<Item, ComparatorItem>::const_iterator it = multiset.cbegin();
    for(int i = 0; i < 1; i++) {
        ++s21_it;                    //SEGMENTATION FAULT!!!!!
        ++it;
    }

    s21::MultiSet<Item, ComparatorItem>::iterator s21_it_result = s21_multiset.Erase(s21_it);
    std::multiset<Item, ComparatorItem>::iterator it_result = multiset.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    std::cout << "After erase: \n";

    // for (auto it = s21_multiset.cbegin(); it != s21_multiset.cend(); ++it)
        // std::cout << "{" << it->first << " : " << it->second << "}\n";


    EXPECT_EQ(s21_multiset, multiset);   
}

TEST(MultiSet, T2_1EraseRoot)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset;
    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(4));

    std::multiset<Item, ComparatorItem> multiset;
    multiset.insert(Item(3));
    multiset.insert(Item(4));

    s21::MultiSet<Item, ComparatorItem>::const_iterator s21_it = s21_multiset.cbegin();
    std::multiset<Item, ComparatorItem>::const_iterator it = multiset.cbegin();
    for(int i = 0; i < 1; i++) {
        ++s21_it;
        ++it;
    }

    s21::MultiSet<Item, ComparatorItem>::iterator s21_it_result = s21_multiset.Erase(s21_it);
    std::multiset<Item, ComparatorItem>::iterator it_result = multiset.erase(it);

    EXPECT_EQ(s21_it_result, s21_multiset.end());
    EXPECT_EQ(it_result, multiset.end());

    std::cout << "After erase: \n";

    // for (auto it = s21_multiset.cbegin(); it != s21_multiset.cend(); ++it)
        // std::cout << "{" << it->first << " : " << it->second << "}\n";


    EXPECT_EQ(s21_multiset, multiset);
}

TEST(MultiSet, T3RandomErase)
{
    // return;
    s21::MultiSet<Item, ComparatorItem> s21_multiset;

    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(5));
    s21_multiset.Insert(Item(5));
    s21_multiset.Insert(Item(4));

    s21_multiset.Insert(Item(14));
    s21_multiset.Insert(Item(11));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(8));
    s21_multiset.Insert(Item(-8));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(-18));
    s21_multiset.Insert(Item(6));
    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(29));
    s21_multiset.Insert(Item(30));
    s21_multiset.Insert(Item(31));
    s21_multiset.Insert(Item(34));
    s21_multiset.Insert(Item(37));


    std::multiset<Item, ComparatorItem> multiset;

    multiset.insert(Item(3));
    multiset.insert(Item(5));
    multiset.insert(Item(5));
    multiset.insert(Item(4));

    multiset.insert(Item(14));
    multiset.insert(Item(11));
    multiset.insert(Item(7));
    multiset.insert(Item(8));
    multiset.insert(Item(-8));
    multiset.insert(Item(7));
    multiset.insert(Item(-18));
    multiset.insert(Item(6));
    multiset.insert(Item(3));
    multiset.insert(Item(29));
    multiset.insert(Item(30));
    multiset.insert(Item(31));
    multiset.insert(Item(34));
    multiset.insert(Item(37));



    // std::cout << s21_multiset << "\n\n";
    s21::MultiSet<Item, ComparatorItem>::const_iterator s21_it = s21_multiset.cbegin();
    std::multiset<Item, ComparatorItem>::const_iterator it = multiset.cbegin();
    for (int i = 0; i < 7; ++i) {
        ++s21_it;
        ++it;
    }

    s21::MultiSet<Item, ComparatorItem>::iterator s21_it_result = s21_multiset.Erase(s21_it);
    std::multiset<Item, ComparatorItem>::iterator it_result = multiset.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_multiset, multiset);
    EXPECT_TRUE(minimalHeightAVL(s21_multiset.Size(), s21_multiset.Height()));    
}


TEST(MultiSet, T4RandomErase)
{
    // return;
    s21::MultiSet<Item, ComparatorItem> s21_multiset;

    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(5));
    s21_multiset.Insert(Item(5));
    s21_multiset.Insert(Item(4));

    s21_multiset.Insert(Item(14));
    s21_multiset.Insert(Item(11));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(8));
    s21_multiset.Insert(Item(-8));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(-18));
    s21_multiset.Insert(Item(6));
    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(29));
    s21_multiset.Insert(Item(30));
    s21_multiset.Insert(Item(31));
    s21_multiset.Insert(Item(34));
    s21_multiset.Insert(Item(37));


    std::multiset<Item, ComparatorItem> multiset;

    multiset.insert(Item(3));
    multiset.insert(Item(5));
    multiset.insert(Item(5));
    multiset.insert(Item(4));

    multiset.insert(Item(14));
    multiset.insert(Item(11));
    multiset.insert(Item(7));
    multiset.insert(Item(8));
    multiset.insert(Item(-8));
    multiset.insert(Item(7));
    multiset.insert(Item(-18));
    multiset.insert(Item(6));
    multiset.insert(Item(3));
    multiset.insert(Item(29));
    multiset.insert(Item(30));
    multiset.insert(Item(31));
    multiset.insert(Item(34));
    multiset.insert(Item(37));



    // std::cout << s21_multiset << "\n\n";
    s21::MultiSet<Item, ComparatorItem>::const_iterator s21_it = s21_multiset.cbegin();
    std::multiset<Item, ComparatorItem>::const_iterator it = multiset.cbegin();
    for (int i = 0; i < 11; ++i) {
        ++s21_it;
        ++it;
    }

    s21::MultiSet<Item, ComparatorItem>::iterator s21_it_result = s21_multiset.Erase(s21_it);
    std::multiset<Item, ComparatorItem>::iterator it_result = multiset.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_multiset, multiset);
    EXPECT_TRUE(minimalHeightAVL(s21_multiset.Size(), s21_multiset.Height()));    
}

TEST(MultiSet, T5RandomErase)    // seems like std::multimap erases not the first element in the node
{
    // return;
    s21::MultiSet<Item, ComparatorItem> s21_multiset;

    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(5));
    s21_multiset.Insert(Item(5));
    s21_multiset.Insert(Item(4));

    s21_multiset.Insert(Item(14));
    s21_multiset.Insert(Item(11));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(8));
    s21_multiset.Insert(Item(-8));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(-18));
    s21_multiset.Insert(Item(6));
    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(29));
    s21_multiset.Insert(Item(30));
    s21_multiset.Insert(Item(31));
    s21_multiset.Insert(Item(34));
    s21_multiset.Insert(Item(37));


    std::multiset<Item, ComparatorItem> multiset;

    multiset.insert(Item(3));
    multiset.insert(Item(5));
    multiset.insert(Item(5));
    multiset.insert(Item(4));

    multiset.insert(Item(14));
    multiset.insert(Item(11));
    multiset.insert(Item(7));
    multiset.insert(Item(8));
    multiset.insert(Item(-8));
    multiset.insert(Item(7));
    multiset.insert(Item(-18));
    multiset.insert(Item(6));
    multiset.insert(Item(3));
    multiset.insert(Item(29));
    multiset.insert(Item(30));
    multiset.insert(Item(31));
    multiset.insert(Item(34));
    multiset.insert(Item(37));



    // std::cout << s21_multiset << "\n\n";
    s21::MultiSet<Item, ComparatorItem>::const_iterator s21_it = s21_multiset.cbegin();
    std::multiset<Item, ComparatorItem>::const_iterator it = multiset.cbegin();
    for (int i = 0; i < 3; ++i) {
        ++s21_it;
        ++it;
    }

    // s21::MultiSet<Item, ComparatorItem>::iterator s21_it_result = s21_multiset.Erase(s21_it);
    // std::multiset<Item, ComparatorItem>::iterator it_result = multiset.erase(it);

    auto s21_it2 = s21_multiset.cbegin();
    auto it2     = multiset.cbegin();
    while (s21_it2 != s21_multiset.cend() && it2 != multiset.cend()) {
        // std::cout << "{" << it2->first << " : " << it2->second << "}\t == ";
        // std::cout << "{" << s21_it2->first << " : " << s21_it2->second << "}\n";
        ++s21_it2;
        ++it2;
    }

    // EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_multiset, multiset);
    EXPECT_TRUE(minimalHeightAVL(s21_multiset.Size(), s21_multiset.Height()));    
}

TEST(MultiSet, T6RandomErase)
{
    // return;
    s21::MultiSet<Item, ComparatorItem> s21_multiset;

    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(5));
    s21_multiset.Insert(Item(5));
    s21_multiset.Insert(Item(4));

    s21_multiset.Insert(Item(14));
    s21_multiset.Insert(Item(11));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(8));
    s21_multiset.Insert(Item(-8));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(-18));
    s21_multiset.Insert(Item(6));
    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(29));
    s21_multiset.Insert(Item(30));
    s21_multiset.Insert(Item(31));
    s21_multiset.Insert(Item(34));
    s21_multiset.Insert(Item(37));


    std::multiset<Item, ComparatorItem> multiset;

    multiset.insert(Item(3));
    multiset.insert(Item(5));
    multiset.insert(Item(5));
    multiset.insert(Item(4));

    multiset.insert(Item(14));
    multiset.insert(Item(11));
    multiset.insert(Item(7));
    multiset.insert(Item(8));
    multiset.insert(Item(-8));
    multiset.insert(Item(7));
    multiset.insert(Item(-18));
    multiset.insert(Item(6));
    multiset.insert(Item(3));
    multiset.insert(Item(29));
    multiset.insert(Item(30));
    multiset.insert(Item(31));
    multiset.insert(Item(34));
    multiset.insert(Item(37));



    // std::cout << s21_multiset << "\n\n";
    s21::MultiSet<Item, ComparatorItem>::const_iterator s21_it = s21_multiset.cbegin();
    std::multiset<Item, ComparatorItem>::const_iterator it = multiset.cbegin();
    for (int i = 0; i < 5; ++i) {
        ++s21_it;
        ++it;
    }

    EXPECT_EQ(s21_multiset, multiset);
    
    s21::MultiSet<Item, ComparatorItem>::iterator s21_it_result = s21_multiset.Erase(s21_it);
    std::multiset<Item, ComparatorItem>::iterator it_result = multiset.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_multiset, multiset);
    EXPECT_TRUE(minimalHeightAVL(s21_multiset.Size(), s21_multiset.Height()));    
}

TEST(MultiSet, T7RandomEraseRoot)
{
    // return;
    s21::MultiSet<Item, ComparatorItem> s21_multiset;

    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(5));
    s21_multiset.Insert(Item(5));
    s21_multiset.Insert(Item(4));

    s21_multiset.Insert(Item(14));
    s21_multiset.Insert(Item(11));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(8));
    s21_multiset.Insert(Item(-8));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(-18));
    s21_multiset.Insert(Item(6));
    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(29));
    s21_multiset.Insert(Item(30));
    s21_multiset.Insert(Item(31));
    s21_multiset.Insert(Item(34));
    s21_multiset.Insert(Item(37));


    std::multiset<Item, ComparatorItem> multiset;

    multiset.insert(Item(3));
    multiset.insert(Item(5));
    multiset.insert(Item(5));
    multiset.insert(Item(4));

    multiset.insert(Item(14));
    multiset.insert(Item(11));
    multiset.insert(Item(7));
    multiset.insert(Item(8));
    multiset.insert(Item(-8));
    multiset.insert(Item(7));
    multiset.insert(Item(-18));
    multiset.insert(Item(6));
    multiset.insert(Item(3));
    multiset.insert(Item(29));
    multiset.insert(Item(30));
    multiset.insert(Item(31));
    multiset.insert(Item(34));
    multiset.insert(Item(37));



    EXPECT_EQ(s21_multiset, multiset);
    // std::cout << s21_multiset << "\n\n";
    s21::MultiSet<Item, ComparatorItem>::const_iterator s21_it = s21_multiset.cbegin();
    std::multiset<Item, ComparatorItem>::const_iterator it = multiset.cbegin();
    for (int i = 0; i < 10; ++i) {
        ++s21_it;
        ++it;
    }

    // std::cout << "Erase: " << s21_it->first << '\n';
    s21::MultiSet<Item, ComparatorItem>::iterator s21_it_result = s21_multiset.Erase(s21_it);
    std::multiset<Item, ComparatorItem>::iterator it_result = multiset.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_multiset, multiset);
    EXPECT_TRUE(minimalHeightAVL(s21_multiset.Size(), s21_multiset.Height()));    
}

TEST(MultiSet, T8RandomEraseRoot)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset;
    s21_multiset.Insert(Item(60));
    s21_multiset.Insert(Item(50));
    s21_multiset.Insert(Item(70));
    s21_multiset.Insert(Item(45));
    s21_multiset.Insert(Item(55));
    s21_multiset.Insert(Item(65));
    s21_multiset.Insert(Item(80));
    s21_multiset.Insert(Item(41));
    s21_multiset.Insert(Item(54));
    s21_multiset.Insert(Item(58));
    s21_multiset.Insert(Item(61));
    s21_multiset.Insert(Item(75));
    s21_multiset.Insert(Item(85));
    s21_multiset.Insert(Item(57));
    s21_multiset.Insert(Item(88));
    s21_multiset.Insert(Item(90)); 
   
    std::multiset<Item, ComparatorItem> multiset;
    multiset.insert(Item(60));
    multiset.insert(Item(50));
    multiset.insert(Item(70));
    multiset.insert(Item(45));
    multiset.insert(Item(55));
    multiset.insert(Item(65));
    multiset.insert(Item(80));
    multiset.insert(Item(41));
    multiset.insert(Item(54));
    multiset.insert(Item(58));
    multiset.insert(Item(61));
    multiset.insert(Item(75));
    multiset.insert(Item(85));
    multiset.insert(Item(57));
    multiset.insert(Item(88));
    multiset.insert(Item(90));


    EXPECT_EQ(s21_multiset, multiset);
    // std::cout << s21_multiset << "\n\n";
    s21::MultiSet<Item, ComparatorItem>::const_iterator s21_it = s21_multiset.cbegin();
    std::multiset<Item, ComparatorItem>::const_iterator it = multiset.cbegin();
    for (int i = 0; i < 7; ++i) {
        ++s21_it;
        ++it;
    }

    // std::cout << "Erase: " << s21_it->first << '\n';
    s21::MultiSet<Item, ComparatorItem>::iterator s21_it_result = s21_multiset.Erase(s21_it);
    std::multiset<Item, ComparatorItem>::iterator it_result = multiset.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_multiset, multiset);
    EXPECT_TRUE(minimalHeightAVL(s21_multiset.Size(), s21_multiset.Height()));    
}

TEST(MultiSet, T9RandomErase)
{
    // return;
    s21::MultiSet<Item, ComparatorItem> s21_multiset;

    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(5));
    s21_multiset.Insert(Item(5));
    s21_multiset.Insert(Item(4));

    s21_multiset.Insert(Item(14));
    s21_multiset.Insert(Item(11));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(8));
    s21_multiset.Insert(Item(-8));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(-18));
    s21_multiset.Insert(Item(6));
    s21_multiset.Insert(Item(3));
    s21_multiset.Insert(Item(29));
    s21_multiset.Insert(Item(30));
    s21_multiset.Insert(Item(31));
    s21_multiset.Insert(Item(34));
    s21_multiset.Insert(Item(37));


    std::multiset<Item, ComparatorItem> multiset;

    multiset.insert(Item(3));
    multiset.insert(Item(5));
    multiset.insert(Item(5));
    multiset.insert(Item(4));

    multiset.insert(Item(14));
    multiset.insert(Item(11));
    multiset.insert(Item(7));
    multiset.insert(Item(8));
    multiset.insert(Item(-8));
    multiset.insert(Item(7));
    multiset.insert(Item(-18));
    multiset.insert(Item(6));
    multiset.insert(Item(3));
    multiset.insert(Item(29));
    multiset.insert(Item(30));
    multiset.insert(Item(31));
    multiset.insert(Item(34));
    multiset.insert(Item(37));



    // std::cout << s21_multiset << "\n\n";
    s21::MultiSet<Item, ComparatorItem>::const_iterator s21_it = s21_multiset.cbegin();
    std::multiset<Item, ComparatorItem>::const_iterator it = multiset.cbegin();
    for (int i = 0; i < 8; ++i) {
        ++s21_it;
        ++it;
    }

    s21::MultiSet<Item, ComparatorItem>::iterator s21_it_result = s21_multiset.Erase(s21_it);
    std::multiset<Item, ComparatorItem>::iterator it_result = multiset.erase(it);

    EXPECT_EQ(*s21_it_result, *it_result);

    EXPECT_EQ(s21_multiset, multiset);
    EXPECT_TRUE(minimalHeightAVL(s21_multiset.Size(), s21_multiset.Height()));    
}
























// TEST(MultiSet, T0RandomExtract)  // TODO: enable it later
// {
//     // return;
//     s21::MultiSet<Item, ComparatorItem> s21_multiset;

//     s21_multiset.Insert(Item(3));
//     s21_multiset.Insert(Item(5));
//     s21_multiset.Insert(Item(5));
//     s21_multiset.Insert(Item(4));

//     s21_multiset.Insert(Item(14));
//     s21_multiset.Insert(Item(11));
//     s21_multiset.Insert(Item(7));
//     s21_multiset.Insert(Item(8));
//     s21_multiset.Insert(Item(-8));
//     s21_multiset.Insert(Item(7));
//     s21_multiset.Insert(Item(-18));
//     s21_multiset.Insert(Item(6));
//     s21_multiset.Insert(Item(3));
//     s21_multiset.Insert(Item(29));
//     s21_multiset.Insert(Item(30));
//     s21_multiset.Insert(Item(31));
//     s21_multiset.Insert(Item(34));
//     s21_multiset.Insert(Item(37));


//     std::multiset<Item, ComparatorItem> multiset;

//     multiset.insert(Item(3));
//     multiset.insert(Item(5));
//     multiset.insert(Item(5));
//     multiset.insert(Item(4));

//     multiset.insert(Item(14));
//     multiset.insert(Item(11));
//     multiset.insert(Item(7));
//     multiset.insert(Item(8));
//     multiset.insert(Item(-8));
//     multiset.insert(Item(7));
//     multiset.insert(Item(-18));
//     multiset.insert(Item(6));
//     multiset.insert(Item(3));
//     multiset.insert(Item(29));
//     multiset.insert(Item(30));
//     multiset.insert(Item(31));
//     multiset.insert(Item(34));
//     multiset.insert(Item(37));



//     // std::cout << s21_multiset << "\n\n";
//     s21::MultiSet<Item, ComparatorItem>::const_iterator s21_it = s21_multiset.cbegin();
//     std::multiset<Item, ComparatorItem>::const_iterator it = multiset.cbegin();
//     for (int i = 0; i < 8; ++i) {
//         ++s21_it;
//         ++it;
//     }

//     s21::MultiSet<Item, ComparatorItem>::node_type s21_it_result = s21_multiset.Extract(s21_it);
//     std::multiset<Item, ComparatorItem>::node_type it_result = multiset.extract(it);

//     EXPECT_EQ(it_result.key(), s21_it_result.Get().first);
//     EXPECT_EQ(it_result.mapped(), s21_it_result.Get().second);

//     EXPECT_EQ(s21_multiset, multiset);
//     EXPECT_TRUE(minimalHeightAVL(s21_multiset.Size(), s21_multiset.Height()));    

// // TODO: leaks?
// //    delete &s21_it_result;
// //    delete &it_result;

// }






// TEST(MultiSet, T1RandomExtract)
// {
//     // return;
//     s21::MultiSet<Item, ComparatorItem> s21_multiset;

//     s21_multiset.Insert(Item(3));
//     s21_multiset.Insert(Item(5));
//     s21_multiset.Insert(Item(5));
//     s21_multiset.Insert(Item(4));

//     s21_multiset.Insert(Item(14));
//     s21_multiset.Insert(Item(11));
//     s21_multiset.Insert(Item(7));
//     s21_multiset.Insert(Item(8));
//     s21_multiset.Insert(Item(-8));
//     s21_multiset.Insert(Item(7));
//     s21_multiset.Insert(Item(-18));
//     s21_multiset.Insert(Item(6));
//     s21_multiset.Insert(Item(3));
//     s21_multiset.Insert(Item(29));
//     s21_multiset.Insert(Item(30));
//     s21_multiset.Insert(Item(31));
//     s21_multiset.Insert(Item(34));
//     s21_multiset.Insert(Item(37));


//     std::multiset<Item, ComparatorItem> multiset;

//     multiset.insert(Item(3));
//     multiset.insert(Item(5));
//     multiset.insert(Item(5));
//     multiset.insert(Item(4));

//     multiset.insert(Item(14));
//     multiset.insert(Item(11));
//     multiset.insert(Item(7));
//     multiset.insert(Item(8));
//     multiset.insert(Item(-8));
//     multiset.insert(Item(7));
//     multiset.insert(Item(-18));
//     multiset.insert(Item(6));
//     multiset.insert(Item(3));
//     multiset.insert(Item(29));
//     multiset.insert(Item(30));
//     multiset.insert(Item(31));
//     multiset.insert(Item(34));
//     multiset.insert(Item(37));



//     // std::cout << s21_multiset << "\n\n";
//     s21::MultiSet<Item, ComparatorItem>::const_iterator s21_it = s21_multiset.cbegin();
//     std::multiset<Item, ComparatorItem>::const_iterator it = multiset.cbegin();
//     for (int i = 0; i < 4; ++i) {
//         ++s21_it;
//         ++it;
//     }

//     s21::MultiSet<Item, ComparatorItem>::node_type s21_it_result = s21_multiset.Extract(s21_it);
//     std::multiset<Item, ComparatorItem>::node_type it_result = multiset.extract(it);

//     EXPECT_EQ(it_result.key(), s21_it_result.Get().first);
//     EXPECT_EQ(it_result.mapped(), s21_it_result.Get().second);

//     EXPECT_EQ(s21_multiset, multiset);
//     EXPECT_TRUE(minimalHeightAVL(s21_multiset.Size(), s21_multiset.Height()));    
// }


}  // namespace

// GCOVR_EXCL_STOP