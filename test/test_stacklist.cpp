#include <../gtest/gtest.h>
#include "StackList.h"
#include <sstream>

TEST(TStackList, create_stack_list)
{
    ASSERT_NO_THROW(TStackList<int>());
}

TEST(TStackList, push_any_elements)
{
    TStackList<int> S;
    S.Push(1);
    S.Push(2);
    EXPECT_EQ(2, S.Get());
}

TEST(TStackList, pop_any_elements)
{
    TStackList<int> S;
    S.Push(1);
    S.Push(2);
    S.Push(3);
    S.Pop();
    S.Pop();
    EXPECT_EQ(1, S.Get());
}

TEST(TStackList, find_max_element)
{
    TStackList<int> S;
    S.Push(1);
    S.Push(3);
    S.Push(-5);
    EXPECT_EQ(3, S.GetMaxElement());
}

TEST(TStackList, find_min_element)
{
    TStackList<int> S;
    S.Push(1);
    S.Push(3);
    S.Push(-5);
    EXPECT_EQ(-5, S.GetMinElement());
}

TEST(TStackList, write_stack_list_file)
{
    const int size = 9;
    TStackList<int> S;
    for (int i = 0; i < size / 2; i++)
        S.Push(i);
    S.WriteToFile("StackListOI.txt");
    string expString = "0123";
    string StackList = "";
    ifstream fin("StackListOI.txt");
    fin >> StackList;
    fin.close();
    EXPECT_EQ(expString, StackList);
}

