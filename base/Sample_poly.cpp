#include "polynomial.h"
#include <clocale>

int main() {
	setlocale(LC_ALL, "Russian");
	Polynomial P;
	std::vector<double> values(3);
	std::cout << "������� �������" << std::endl;
	std::cin >>P;
	std::cout << P<<std::endl;
	std::cout << "������� �������� ���������� x:"<<" ";
	std::cin >> values[0];
	std::cout << "������� �������� ���������� y:" <<" ";
	std::cin >> values[1];
	std::cout << "������� �������� ���������� z:" << " ";
	std::cin >> values[2];

	std::cout << "��������� ����������:" << P.calculate(values) << std::endl;
}