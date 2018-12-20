#include <cmath>
#include "TPoly.h"


TPoly::TPoly(int c, int n) {
	poly.emplace_back(c, n);
}

int TPoly::getDegree()
{
	return poly.begin()->getDegree();
}

int TPoly::getCoefficient(int degree)
{
	for (auto mem : poly)
	{
		if (mem.getDegree() == degree)
		{
			return mem.getCoefficient();
		}
	}
	return 0;
}

void TPoly::clear()
{
	poly.clear();
	poly.emplace_back(0, 0);
}

TPoly TPoly::operator+(const TMember &elem)
{
	TPoly res = *this;

	res.poly.remove(TMember(0, 0));

	for (auto it = res.poly.begin(); it != res.poly.end(); ++it)
	{
		int memExp = it->getDegree();
		int elemExp = elem.getDegree();
		if (memExp == elemExp)
		{
			int buf = it->getCoefficient() + elem.getCoefficient();
			if (buf != 0)
			{
				it->setCoefficient(buf);
			}
			else
			{
				res.poly.remove(*it);
			}
			if (res.poly.empty())
			{
				res.poly.emplace_back(0, 0);
			}
			return res;
		}
		else
		{
			if (elemExp > memExp)
			{
				TMember buf = elem;
				res.poly.insert(it, buf);
				return res;
			}
		}
	}

	res.poly.push_back(elem);

	return res;
}

TPoly TPoly::operator+(const TPoly &sec)
{
	TPoly res = *this;
	auto itFst = res.poly.begin();
	auto itSnd = sec.poly.begin();
	for (; itFst != res.poly.end(); ++itFst)
	{
		while (itSnd->getDegree() > itFst->getDegree() && itSnd != sec.poly.end())
		{
			res.poly.insert(itFst, *itSnd);
			++itSnd;
		}
		if (itSnd->getDegree() == itFst->getDegree())
		{
			int buf = itFst->getCoefficient() + itSnd->getCoefficient();
			if (buf != 0)
			{
				itFst->setCoefficient(buf);
			}
			else
			{
				res.poly.remove(*itFst);
			}
			++itSnd;
		}
	}
	if (itSnd != sec.poly.end())
	{
		res.poly.insert(itFst, itSnd, sec.poly.end());
	}
	if (res.poly.empty())
	{
		poly.emplace_back(0, 0);
	}
	return res;
}

TPoly TPoly::operator-(const TMember &elem)
{
	return *this + TMember(-elem.getCoefficient(), elem.getDegree());
}

TPoly TPoly::operator-(const TPoly &sec)
{
	TPoly res = *this;

	for (auto mem : sec.poly)
	{
		res = res - mem;
	}

	return res;
}

TPoly TPoly::operator*(const TMember &elem)
{
	TPoly res;

	for (auto mem : poly)
	{
		res = res + TMember(mem.getCoefficient() * elem.getCoefficient(), mem.getDegree() + elem.getDegree());
	}

	return res;
}

TPoly TPoly::operator*(const TPoly &sec)
{
	TPoly res;

	for (auto mem : poly)
	{
		for (auto secMem : sec.poly)
		{
			res = res + TMember(mem.getCoefficient() * secMem.getCoefficient(), mem.getDegree() + secMem.getDegree());
		}
	}

	return res;
}

TPoly TPoly::operator-()
{
	TPoly zero(0, 0);
	return zero - *this;
}

bool TPoly::operator==(const TPoly &sec)
{
	auto size = poly.size();
	if (size != sec.poly.size())
	{
		return false;
	}

	auto secMem = sec.poly.begin();
	for (auto mem : poly)
	{
		if (!(mem == *secMem))
		{
			return false;
		}
	}

	return true;
}

TPoly TPoly::differentiate()
{
	TPoly res;

	for (auto mem : poly)
	{
		if (mem.getDegree())
		{
			res = res + mem.differentiate();
		}
	}

	return res;
}

double TPoly::calculate(double a)
{
	double res = 0.0;

	for (auto i : poly)
	{
		res += i.calculate(a);
	}

	return res;
}

TPoly::TMember &TPoly::element(int idx)
{
	auto mem = poly.begin();
	for (int i = 0; i < idx; ++i)
	{
		mem++;
	}
	return *mem;
}

TPoly::TMember::TMember(int c, int n) : coefficient(c), degree(n)
{

}

int TPoly::TMember::getDegree() const
{
	return degree;
}

int TPoly::TMember::getCoefficient() const
{
	return coefficient;
}

void TPoly::TMember::setDegree(int n)
{
	degree = n;
}

void TPoly::TMember::setCoefficient(int c)
{
	coefficient = c;
}

bool TPoly::TMember::operator==(const TMember &sec)
{
	return coefficient == sec.coefficient && degree == sec.degree;
}

TPoly::TMember TPoly::TMember::differentiate()
{
	return TMember(coefficient * degree, degree - 1);
}

double TPoly::TMember::calculate(double a)
{
	return pow(a, degree) * coefficient;
}

std::string TPoly::TMember::toString()
{
	return std::to_string(coefficient) + "*x^" + std::to_string(degree);
}