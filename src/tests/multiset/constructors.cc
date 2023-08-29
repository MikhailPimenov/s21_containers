#include <gtest/gtest.h>

#include <stack>
#include <list>
#include <vector>
#include <deque>
#include <map>
#include <set>

#include "../../s21_map.h"
#include "../item.h"
#include "../map_helpers.h"

// GCOVR_EXCL_START

namespace
{


TEST(Map, T0DefaultConstructor)
{
    s21::MultiSet<Item> s21_multiset;
    std::multiset<Item> multiset;


    //EXPECT_EQ(s21_map, map);
}







}  // namespace

// GCOVR_EXCL_STOP
