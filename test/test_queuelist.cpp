#include <../gtest/gtest.h>
#include "QueueList.h"
#include <sstream>

TEST(TQueueList, create_queue_list)
{
    ASSERT_NO_THROW(TQueueList<int>());
}

TEST(TQueueList, push_any_elements)
{
    TQueueList<int> Q;
    Q.Push(1);
    Q.Push(2);
    EXPECT_EQ(1, Q.Get());
}

TEST(TQueueList, pop_any_elements)
{
    TQueueList<int> Q;
    Q.Push(1);
    Q.Push(2);
    Q.Push(3);
    Q.Push(4);
    Q.Pop();
    Q.Pop();
    Q.Push(5);
    Q.Pop();
    EXPECT_EQ(4, Q.Get());
}

TEST(TQueueList, find_max_element)
{
    TQueueList<int> Q;
    Q.Push(1);
    Q.Push(3);
    Q.Push(-5);
    EXPECT_EQ(3, Q.GetMaxElement());
}

TEST(TQueueList, find_min_element)
{
    TQueueList<int> Q;
    Q.Push(1);
    Q.Push(3);
    Q.Push(-5);
    EXPECT_EQ(-5, Q.GetMinElement());
}

TEST(TQueueList, write_queue_list_file)
{
    const int size = 9;
    TQueueList<int> Q;
    for (int i = 0; i < size / 2; i++)
        Q.Push(i);
    Q.WriteToFile("QueueListOI.txt");
    string expString = "0123";
    string QueueList = "";
    ifstream fin("QueueListOI.txt");
    fin >> QueueList;
    fin.close();
    EXPECT_EQ(expString, QueueList);
}