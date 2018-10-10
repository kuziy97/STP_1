#pragma once
#include <iostream>
#include <cmath>
#include<stdexcept>
#include<string>

using namespace std;
class Drobi {
private:
	int chislitel;
	int znamenatel;
	int gcd(int chislitel, int znamenatel) {
		while (chislitel != 0 && znamenatel != 0) {
			if (abs(chislitel) > abs(znamenatel))
				chislitel = abs(chislitel) % abs(znamenatel);
			else
				znamenatel = abs(znamenatel) % abs(chislitel);
		}
		return (abs(znamenatel) + abs(chislitel));
	}
	void simply() {
		int del = gcd(chislitel, znamenatel);
		chislitel /= del;
		znamenatel /= del;
		if (znamenatel < 0) {
			chislitel *= (-1);
			znamenatel *= (-1);
		}
	}
public:
	Drobi(int chislitel, int znamenatel) : chislitel(chislitel), znamenatel(znamenatel) {
		if (this->znamenatel == 0) throw logic_error("Деление на нуль!!!");
		simply();
	}
	Drobi() : chislitel(0), znamenatel(1) {}
	Drobi(int value) : chislitel(value), znamenatel(1) {}
	int getChislitel() const {
		return chislitel;
	}
	int getZnamenatel() const {
		return znamenatel;
	}
	string GetFractString(){
		string str;
		str+=to_string(chislitel);
		str += '/';
		str+=to_string(znamenatel);
		return str;
	}
	int compareTo(const Drobi &other) const {
		return getChislitel() * other.getZnamenatel() - getZnamenatel() * other.getZnamenatel();
	}

	string GetCh() {
		return to_string(chislitel);
	}

	string GetZn() {
		return to_string(znamenatel);
	}




};

ostream &operator<<(ostream &stream, const Drobi &drobi) {
	return stream << drobi.getChislitel() << "/" << drobi.getZnamenatel();
}

Drobi operator+(const Drobi &a, const Drobi &b) {
	int corpChislitel = a.getChislitel() * b.getZnamenatel() + b.getChislitel() * a.getZnamenatel();
	int corpZnamenatel = a.getZnamenatel() * b.getZnamenatel();
	return Drobi(corpChislitel, corpZnamenatel);
}

Drobi operator-(const Drobi &a) {
	return Drobi(-a.getChislitel(), a.getZnamenatel());
}


Drobi operator-(const Drobi &a, const Drobi &b) {
	return a + -b;
}

Drobi operator*(const Drobi &a, const Drobi &b) {
	return Drobi(a.getChislitel() * b.getChislitel(), a.getZnamenatel() * b.getZnamenatel());
}

Drobi operator/(const Drobi &a, const Drobi &b) {
	return Drobi(a.getChislitel() * b.getZnamenatel(), a.getZnamenatel() * b.getChislitel());
}

Drobi power(const Drobi &drobi, int power) {
	if (power > 0)
		return Drobi((int)pow(drobi.getChislitel(), power), (int)pow(drobi.getZnamenatel(), power));
	else
		return Drobi((int)pow(drobi.getZnamenatel(), -power), (int)pow(drobi.getChislitel(), -power));
}

Drobi square (const Drobi &drobi) {
		return Drobi((int)pow(drobi.getChislitel(), 2), (int)pow(drobi.getZnamenatel(), 2));
}

Drobi rev(const Drobi &drobi) {
	return 1 / drobi;
}