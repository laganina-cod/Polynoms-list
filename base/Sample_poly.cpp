#include "polynomial.h"
#include <clocale>

int main() {
	setlocale(LC_ALL, "Russian");
	Polynomial P;
	std::vector<double> values(3);
	std::cout << "¬ведите полином" << std::endl;
	std::cin >>P;
	std::cout << P<<std::endl;
	std::cout << "¬ведите значение переменной x:"<<" ";
	std::cin >> values[0];
	std::cout << "¬ведите значение переменной y:" <<" ";
	std::cin >> values[1];
	std::cout << "¬ведите значение переменной z:" << " ";
	std::cin >> values[2];

	std::cout << "–езультат вычислени€:" << P.calculate(values) << std::endl;
}