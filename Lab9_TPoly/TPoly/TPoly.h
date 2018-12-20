#pragma once

#include <string>
#include <list>

class TPoly
{
public:
	class TMember
	{
	private:
		int coefficient;

		int degree;

	public:
		explicit TMember(int c = 0, int n = 0);

		int getDegree() const;

		int getCoefficient() const;

		void setDegree(int n);

		void setCoefficient(int c);

		bool operator==(const TMember &sec);

		TMember differentiate();

		double calculate(double a);

		std::string toString();
	};

	explicit TPoly(int c = 0, int n = 0);

	int getDegree();

	int getCoefficient(int degree);

	void clear();

	TPoly operator+(const TMember &elem);

	TPoly operator+(const TPoly &sec);

	TPoly operator-(const TMember &elem);

	TPoly operator-(const TPoly &sec);

	TPoly operator*(const TMember &elem);

	TPoly operator*(const TPoly &sec);

	TPoly operator-();

	bool operator==(const TPoly &sec);

	TPoly differentiate();

	double calculate(double a);

	TMember &element(int idx);

	TPoly &operator=(const TPoly &sec) = default;

private:
	std::list<TMember> poly;
};
