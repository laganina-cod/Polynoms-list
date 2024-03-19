#include "list.h"
#include <gtest.h>




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
    EXPECT_EQ(2,Nd.pop_front());
}

TEST(myList, search_is_correct)
{
	myList<int> Nd;
	Nd.push_front(1);
	Nd.push_front(2);
	EXPECT_EQ(1,Nd.search(1));
}
TEST(myList, delete_is_correct)
{
	myList<int> Nd;
	Nd.push_front(1);
	Nd.push_front(2);
	Nd.push_front(1);
	Nd.delete_el(1);
	EXPECT_EQ(1,Nd.pop_back());
}

TEST(myList, list_can_assign) {
	myList<int> Nd;
	Nd.push_back(1);
	Nd.push_back(2);
	myList<int> Nd1;
	EXPECT_NO_THROW(Nd1 = Nd);
}

TEST(myList, assigned_list_is_equal_to_source_one) {
	myList<int> Nd;
	Nd.push_back(1);
	Nd.push_back(2);
	myList<int> Nd1;
	Nd1 = Nd;
	EXPECT_EQ(2, Nd1.pop_back());
}

TEST(myList, assigned_list_is_has_its_own_memory) {
	myList<int> Nd;
	Nd.push_back(1);
	Nd.push_back(2);
	myList<int> Nd1;
	Nd1 = Nd;
	Nd.push_back(3);
	EXPECT_EQ(2, Nd1.pop_back());
}
