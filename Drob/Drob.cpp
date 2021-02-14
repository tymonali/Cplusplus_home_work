#include "Drob.h"


Drob::Drob() :ch(0), zn(1) {}

Drob::Drob(int a, int b) : ch(a), zn(b) {}

void Drob::Print()
{
	if (ch == 0)
	{
		cout << 0 << "\n";
	}
	else if (ch == zn)
	{
		cout << 1 << "\n";
	}
	else
	{
		cout << ch << "/" << zn << "\n";
	}
}

int Drob::gcd(int m, int n)
{
	return (n != 0) ? gcd(n, m % n) : m;
}
int Drob::NOK(int a, int b)
{
	return abs(a * b) / gcd(a, b);
}

int Drob::NOD(int n, int m)
{
	while (m != 0 && n != 0)
	{
		if (m > n)
		{
			m = m % n;
		}
		else
		{
			n = n % m;
		}
	}
	return m + n;
}

Drob Drob::Add(Drob b)
{
	Drob tmp;
	int nok = NOK(zn, b.zn);
	cout << "NOK(" << zn << ", " << b.zn << ") = " << nok << "\n";
	tmp.zn = nok;
	tmp.ch = ((nok / zn) * ch) + ((nok / b.zn) * b.ch);
	return tmp;
}

Drob Drob::Subtraction(Drob b)
{
	Drob tmp;
	int nok = NOK(zn, b.zn);
	cout << "NOK(" << zn << ", " << b.zn << ") = " << nok << "\n";
	tmp.zn = nok;
	tmp.ch = ((nok / zn) * ch) - ((nok / b.zn) * b.ch);
	return tmp;
}

Drob Drob::Multiplication(Drob b)
{
	Drob tmp;
	tmp.ch = ch * b.ch;
	tmp.zn = zn * b.zn;
	int nod = NOD(tmp.ch, tmp.zn);
	cout << "NOD(" << tmp.ch << ", " << tmp.zn << ") = " << nod << "\n";
	if (nod != 1)
	{
		tmp.ch /= nod;
		tmp.zn /= nod;
	}
	return tmp;
}

Drob Drob::Division(Drob b)
{
	Drob tmp;
	tmp.ch = ch * b.zn;
	tmp.zn = zn * b.ch;
	int nod = NOD(tmp.ch, tmp.zn);
	cout << "NOD(" << tmp.ch << ", " << tmp.zn << ") = " << nod << "\n";
	if (nod != 1)
	{
		tmp.ch /= nod;
		tmp.zn /= nod;
	}
	return tmp;
}

Drob Drob::operator+(const Drob& obj)
{
	Drob tmp;
	int nok = NOK(zn, obj.zn);
	cout << "NOK(" << zn << ", " << obj.zn << ") = " << nok << "\n";
	tmp.zn = nok;
	tmp.ch = ((nok / zn) * ch) + ((nok / obj.zn) * obj.ch);
	return tmp;
}

Drob Drob::operator-(const Drob& obj)
{
	Drob tmp;
	int nok = NOK(zn, obj.zn);
	cout << "NOK(" << zn << ", " << obj.zn << ") = " << nok << "\n";
	tmp.zn = nok;
	tmp.ch = ((nok / zn) * ch) - ((nok / obj.zn) * obj.ch);
	return tmp;
}

Drob Drob::operator*(const Drob& obj)
{
	Drob tmp;
	tmp.ch = ch * obj.ch;
	tmp.zn = zn * obj.zn;
	int nod = NOD(tmp.ch, tmp.zn);
	cout << "NOD(" << tmp.ch << ", " << tmp.zn << ") = " << nod << "\n";
	if (nod != 1)
	{
		tmp.ch /= nod;
		tmp.zn /= nod;
	}
	return tmp;
}

Drob Drob::operator/(const Drob& obj)
{
	Drob tmp;
	tmp.ch = ch * obj.zn;
	tmp.zn = zn * obj.ch;
	int nod = NOD(tmp.ch, tmp.zn);
	cout << "NOD(" << tmp.ch << ", " << tmp.zn << ") = " << nod << "\n";
	if (nod != 1)
	{
		tmp.ch /= nod;
		tmp.zn /= nod;
	}
	return tmp;
}