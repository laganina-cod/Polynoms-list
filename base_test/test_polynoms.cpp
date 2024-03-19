#include"polynomial.h"
#include <gtest.h>

TEST(Monom, can_create_monom) {
	ASSERT_NO_THROW(Monom M());
}

TEST(Monom, can_create_param_monom) {
	std::map<char, int> m;
	m['x'] = 2;
	m['y'] = 2;
	m['z'] = 2;
	ASSERT_NO_THROW(Monom M(m,2));
}

TEST(Monom, can_add_similar_monoms) {
	std::map<char, int> m;
	m['x'] = 2;
	m['y'] = 2;
	m['z'] = 2;
	std::map<char, int> m1;
	m1['x'] = 2;
	m1['y'] = 2;
	m1['z'] = 2;
	Monom mon(m, 3);
	Monom mon1(m1, 5);
	mon += mon1;
	EXPECT_EQ(8, mon.getcoefficient());
}



TEST(Monom, add_throws_when_monoms_are_not_similar) {
	std::map<char, int> m;
	m['x'] = 2;
	m['y'] = 2;
	m['z'] = 2;
	std::map<char, int> m1;
	m1['x'] = 2;
	m1['y'] = 3;
	m1['z'] = 2;
	Monom mon(m, 3);
	Monom mon1(m1, 5);
	ASSERT_ANY_THROW(mon += mon1);
	
}

TEST(Monom, calculate_is_correct) {
	std::map<char, int> m;
	m['x'] = 2;
	m['y'] = 2;
	m['z'] = 2;
	Monom M(m, 2);
	std::vector<double> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	EXPECT_EQ(72, M.calculate(v));
}


TEST(Polynomial, can_create_Polynomial)
{
	ASSERT_NO_THROW(Polynomial P());

}

TEST(Polynomial, can_push_element) {
	Polynomial P;
	std::map<char, int> m;
	m['x'] = 2;
	m['y'] = 2;
	m['z'] = 2;
	Monom mon(m, 3);
	EXPECT_NO_THROW(P.push(mon));
}

TEST(Polynomial, can_calculate_correctly) {
	Polynomial P;
	std::map<char, int> m;
	m['x'] = 2;
	m['y'] = 2;
	m['z'] = 2;
	Monom mon(m, 2);
	std::map<char, int> m1;
	m1['x'] = 2;
	m1['y'] = 3;
	m1['z'] = 2;
	Monom mon1(m1, 2);
	P.push(mon);
	P.push(mon1);
	std::vector<double> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	EXPECT_EQ(216, P.calculate(v));

}

TEST(Polynomial, can_multyply_const) {
	Polynomial P;
	std::map<char, int> m;
	m['x'] = 2;
	m['y'] = 2;
	m['z'] = 2;
	Monom mon(m, 2);
	P.push(mon);
	P = P*2;
	std::vector<double> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	EXPECT_EQ(144, P.calculate(v));
}

TEST(Polynomial, can_multyply_polynom) {
	Polynomial P;
	Polynomial P1;
	std::map<char, int> m;
	m['x'] = 1;
	m['y'] = 1;
	m['z'] = 1;
	Monom mon(m, 2);
	P.push(mon);
	
	std::map<char, int> m1;
	m1['x'] = 1;
	m1['y'] = 1;
	m1['z'] = 1;
	Monom mon1(m1, 2);
	P1.push(mon1);
	Polynomial result = P * P1;
	std::vector<double> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	EXPECT_EQ(144, result.calculate(v));
	
}

TEST(Polynomial, can_substract_polynom) {
	Polynomial P;
	Polynomial P1;
	std::map<char, int> m;
	m['x'] = 1;
	m['y'] = 1;
	m['z'] = 1;
	Monom mon(m, 2);
	P.push(mon);

	std::map<char, int> m1;
	m1['x'] = 1;
	m1['y'] = 1;
	m1['z'] = 1;
	Monom mon1(m1, 3);
	P1.push(mon1);
	Polynomial result = P1-P;
	std::vector<double> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	EXPECT_EQ(6, result.calculate(v));
}