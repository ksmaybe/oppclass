#pragma once

#include "std_lib_facilities.h"
const char invalid = 'i';
const char name = 'a';
const char number = '8';
const char quit = 'q';
const char print = ';';
const char complex = 'c';

class Complex
{
private:
	double real;
	double imag;
public:
	Complex(int r = 0, int i = 0) :real(r), imag(i) {};

	double getreal() const
	{
		return this->real;
	}
	double getimag() const
	{
		return this->imag;
	}
	
	void setComplex(double a,double b)
	{
		this->real=a;
		this->imag=b;
	}
	Complex operator + (const Complex& c) const
	{
		Complex comp;
		comp.real = this->real + c.real;
		comp.imag = this->imag + c.imag;
		return comp;
	}
	Complex operator + (const double& c) const
	{
		Complex comp;
		comp.real = this->real + c;
		comp.imag = this->imag;
		return comp;
	}

	friend Complex operator+(const double& d, const Complex& c)
	{
		Complex comp;
		comp.real = c.real + d;
		comp.imag = c.imag;
		return comp;
	}

	Complex operator - (const Complex& c) const
	{
		Complex comp;
		comp.real = this->real - c.real;
		comp.imag = this->imag - c.imag;
		return comp;
	}
	friend Complex operator-(const double& d, const Complex& c)
	{
		Complex comp;
		comp.real = c.real - d;
		comp.imag = c.imag;
		return comp;
	}
	Complex operator - (const double& c) const
	{
		Complex comp;
		comp.real = this->real - c;
		comp.imag = this->imag;
		return comp;
	}
	Complex operator * (const Complex& c) const
	{
		Complex comp;
		comp.real = (this->real*c.real - this->imag*c.imag);
		comp.imag = (this->real*c.imag + this->imag*c.real);
		return comp;
	}
	Complex operator * (const double& c) const
	{
		Complex comp;
		comp.real = this->real * c;
		comp.imag = this->imag*c;
		return comp;
	}
	friend Complex operator*(const double& d, const Complex& c)
	{
		Complex comp;
		comp.real = d * c.real;
		comp.imag = d * c.imag;
		return comp;
	}
	Complex operator / (const Complex& c) const
	{
		Complex comp;
		comp.real = (this->real*c.real + this->imag*c.imag) / (c.real*c.real + c.imag*c.imag);
		comp.imag = (this->imag*c.real - this->real*c.imag) / (c.real*c.real + c.imag*c.imag);
		return comp;

	}
	Complex operator / (const double& c) const
	{
		Complex comp;
		comp.real = this->real / c;
		comp.imag = this->imag / c;
		return comp;
	}
	friend ostream& operator <<(ostream&os, Complex& c)
	{
		if (c.imag == 1)
		{
			return os << c.real << '+' << 'i';
		}
		if (c.imag == -1)
		{
			return os << c.real << '-' << 'i';
		}
		if (c.imag < 0)
		{
			return os << c.real << c.imag << 'i';
		}
		if (c.imag > 0)
		{
			return os << c.real << '+' << c.imag << 'i';
		};
		return os << c.real;

	}
};
class Variable
{
public:
	string name;
	Complex value;
};
Complex get_value(string s);
void set_value(string s, double d);
void print_vars();

class Token
{
public:
	char kind;
	Complex value;
	string name;
	Token(char ch) :kind{ ch } {};
	Token(char ch, Complex val) :kind{ ch }, value{ val } {};
	Token(char ch, string n) :kind{ ch }, name{ n } {};

};

class Token_stream
{
public:
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer{ invalid };
};

/*Complex operator + (const Complex& c);
Complex operator - (const Complex& c);
Complex operator * (const Complex& c);
Complex operator / (const Complex& c);*/

extern Token_stream ts;
extern vector<Variable> var_table;