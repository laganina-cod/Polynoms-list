#include "list.h"
#include <gtest.h>



TEST(myNode, can_create_node)
{
	ASSERT_NO_THROW(myNode <int> Nd);
}


TEST(myNode, can_create_parameter_dependent_node)
{
	ASSERT_NO_THROW(myNode<int> (6,nullptr));
}

TEST(myList,can_create_list)
{
	ASSERT_NO_THROW(myList<int>());
}

TEST(myList,can_get_size)
{
	myList <int> Nd;
	EXPECT_EQ(Nd.size(),0);
}

TEST(myList, can_push_front_when_is_empty)
{
	myList <int> Nd;
	ASSERT_NO_THROW(Nd.push_front(2));

}

TEST(myList, can_push_back_when_is_not_empty)
{
	myList <int> Nd ;
	Nd.push_front(1);
	ASSERT_NO_THROW(Nd.push_back(2));

}

TEST(myList, can_push_back_when_is_empty)
{
	myList<int> Nd;
	ASSERT_NO_THROW(Nd.push_back(2));

}

TEST(myList, cant_pop_front_when_is_empty)
{
	myList<int> Nd;
	ASSERT_ANY_THROW(Nd.pop_front());

}

TEST(myList, can_pop_back_when_is_not_empty)
{
	myList<int> Nd;
	Nd.push_front(1);
	ASSERT_NO_THROW(Nd.pop_back());

}

TEST(myList, cant_pop_back_when_is_empty)
{
	myList<int> Nd;
	ASSERT_ANY_THROW(Nd.pop_back());

}

TEST(myList, can_pop_front_when_is_not_empty)
{
	myList<int> Nd;
	Nd.push_front(1);
	ASSERT_NO_THROW(Nd.pop_front());

}


TEST(myList, pop_front_is_correct)
{
	myList<int> Nd;
	Nd.push_front(1);
	Nd.push_front(2);
	EXPECT_EQ(2,Nd.pop_front());
	EXPECT_EQ(1,Nd.pop_front());

}

TEST(myList, pop_back_is_correct)
{
	myList<int> Nd;
	Nd.push_back(1);
	Nd.push_back(2);
	EXPECT_EQ(2,Nd.pop_back());
	EXPECT_EQ(1,Nd.pop_back());

}

TEST(myList, inserst_is_correct)
{
	myList<int> Nd;
	Nd.push_front(1);
	Nd.push_front(2);
	Nd.insert(1,3);
	Nd.pop_back();
	EXPECT_EQ(3,Nd.pop_back());
    EXPECT_EQ(1,Nd.pop_front());
}

TEST(myList, search_is_correct)
{
	myList<int> Nd;
	Nd.push_front(1);
	Nd.push_front(2);
	EXPECT_EQ(Nd.search(1),2);
}
TEST(myList, delete_is_correct)
{
	myList<int> Nd;
	Nd.push_front(1);
	Nd.push_front(2);
	Nd.delete_el(0);
	EXPECT_EQ(1,Nd.pop_back());
}

