#include"list.h"
#include <iostream>
#include <vector>
#include <map>
#include<sstream>
#include<cmath>

class Monom {
private:
	double coefficient;
	std::map<char, int> variables;
	Monom operator*(const Monom other) {
		Monom M = Monom(*this);
		M.coefficient *= other.coefficient;
		for (auto& item : other.variables) {
			M.variables[item.first] += item.second;
		}
		return M;
	}
public:
	Monom() : coefficient(0), variables({}) {}
	Monom(const Monom& other) {
		this->coefficient = other.coefficient;
		this->variables = other.variables;
	}
	Monom(const std::map<char,int> _variables, double _coefficient) {
		this->variables = _variables;
		this->coefficient = _coefficient;
	}
	friend class myIterator;
	friend class Polynomial;
	Monom operator+(const Monom& other) {
		if (this->variables == other.variables) {
			Monom M(this->variables, (this->coefficient) + (other.coefficient));
			return M;
		}
		else {
			throw "monoms are not similar";
		}
	}
	int sum_degree() const{
		int sum = 0;
		for (auto& item : variables) {
			sum += item.second;
		}
		return sum;
	}
	double calculate(std::vector<double> values) {
		double result = coefficient;
		int count=0;
		for (auto& it : variables) {
			result *= pow(values[count], it.second);
			count++;
		}
		return result;
	}
	double getcoefficient() const {
		return coefficient;
	}
   Monom& operator+=(const Monom& other) {
		if (this->variables == other.variables) {
			this->coefficient += other.coefficient;
			return *this;
		}
		else {
			throw "monoms are not similar";
		}
		return *this;
	}
	friend std::istream& operator>>(std::istream& istr, Monom& m) {
		std::string str;
		istr >> str;
		std::stringstream ss(str);
		std::string part;
		std::getline(ss, part, '*');

		m.coefficient = std::stod(part);
		while (std::getline(ss, part, '*')) {
			char name = part[0];
			int degree = std::stoi(part.substr(2));
			m.variables[name] = degree;
		}
		return istr;
	}
	friend std::ostream& operator<<(std::ostream& ostr, const Monom& m) {
		ostr << " + "<< "(" << m.coefficient << ")";
		for (auto& item : m.variables) {
			ostr << "*" << item.first << "^" << item.second;
		}
		return ostr;
	}
	
};
class Polynomial {
	myList<Monom> list;
public:
	Polynomial() {
		list = myList<Monom>();
	}
	Polynomial(const Polynomial& other) {
		this->list = other.list;
	}

	void push(const Monom& m){
		for (auto& it = list.begin(); it != list.end(); ++it) {
			if ((*it).variables==m.variables){
				(*it).coefficient += m.coefficient;
				return;
			}
			
		}
		list.push_back(m);
		
	}
	double calculate(std::vector<double> values) {
		double result = 0;
		auto it = list.begin();
		while (it.current) {
			result += (*it).calculate(values);
			++it;
	 }
		return result;
	}
	Polynomial operator*(const double num) {
		Polynomial result(*this);
		for (auto it = result.list.begin(); it != result.list.end(); ++it) {
			(*it).coefficient *= num;
		}
		return result;
	}
	bool iscorrectinput(std::string str) {
		for (char c : str) {
			if ((!std::isdigit(c)) && (c != 'x') && (c != 'y') && (c != 'z') && (c != '+') && (c != '-') && (c != '^') && (c != '*')){
				return false;
			}
		}
		return true;
	}
	Polynomial operator+( Polynomial& other) {
		Polynomial result(*this);
		for (auto it = other.list.begin(); it !=other.list.end(); ++it) {
			result.push(*it);
		}
		return result;
	}
	Polynomial operator-(Polynomial& other) {
		Polynomial tmp = other * (-1);
		Polynomial result = *this + tmp;
		return result;
	}
	Polynomial operator*(Polynomial& other) {
		Polynomial result;
		for (auto it = other.list.begin(); it != other.list.end(); ++it) {
			for (auto jt = list.begin(); jt != list.end(); ++jt) {
				result.push((*it) * (*jt));
			}
		}
		return result;
	}
	Polynomial& operator= (const Polynomial & other){
		this->list = other.list;
		return *this;
	}
	friend std::istream& operator>>(std::istream& istr, Polynomial& P) {
		Polynomial new_P;
		std::string str;
		istr >> str;
		if (!P.iscorrectinput(str)) {
			throw"Please input correctly:)";
		}
		std::string string_monom;
		if (str[0] == '-') {
			string_monom = '-';
			str = str.substr(1);
		}
		for (char c : str) {
			if (c == '-') {
				Monom monom;
				std::istringstream iss(string_monom);
				iss >> monom;
				P.push(monom);
				string_monom = '-';
			}
			else if (c == '+') {
				Monom monom;
				std::istringstream iss(string_monom);
				iss >> monom;
				P.push(monom);
				string_monom = '+';
			}
			else {
				string_monom.push_back(c);
			}
		}
		Monom monom;
		std::istringstream iss(string_monom);
		iss >> monom;
		P.push(monom);
		return istr;
	} 
	friend std::ostream& operator<<(std::ostream& ostr, Polynomial P) {
		for (auto it = P.list.begin(); it != P.list.end(); ++it) {
			ostr << (*it);
		}
		return ostr;
	}
	
};