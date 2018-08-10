#include "std_lib_facilities.h"

class vect
{
	int sz;
	double* elem;
	int space;
public:
	vect(const vect& arg);
	vect & operator=(const vect& a);
	vect(int s)
		:sz{ s }, elem{ new double[s] } {
		space = s;
		for (int i = 0; i < sz; ++i) elem[i] = 0.0;
	   }
	   vect(initializer_list<double> lst)
	   :sz{static_cast<int>(lst.size())},elem{new double[sz]}
	   {
	   copy(lst.begin(), lst.end(), elem);
	   }
	   double& operator[](int n) { return elem[n]; }
	~vect()
	{
		delete[] elem;
	}
	double get(int i);
	void set(int i, double d);
	void reserve(int newalloc);
	void resize(int newsize);
	void push_back(double d);
};

double vect::get(int i)
{
	return elem[i];
}

void vect::set(int i, double d)
{
	elem[i] = d;
}

void vect::reserve(int newalloc)
{
	if (newalloc <= space) return;
	double* p = new double[newalloc];
	for (int i = 0; i < sz; ++i) p[i] = elem[i];
	delete[] elem;
	elem = p;
	space = newalloc;
}


void vect::resize(int newsize)
{
	reserve(newsize);
	for (int i = sz; i < newsize; ++i) elem[i] = 0;
	sz = newsize;
}

void vect::push_back(double d)
{
	if (space == 0) reserve(8);
	else if (sz == space) reserve(2 * space);
	elem[sz] = d;
	++sz;
}


vect::vect(const vect& arg)
	:sz{arg.sz},elem{new double[arg.sz]}
{
	copy(arg.elem,arg.elem+arg.sz,elem);
}

vect& vect::operator=(const vect& a)
{
	double* p = new double[a.sz];
	copy(a.elem, a.elem+a.sz, p);
	delete[] elem;
	elem = p;
	sz = a.sz;
	return *this;
}

void f(int n)
{
	cout << n << endl;
	vect v(n);
	v[2]=2.2;
	vect v2 = v;
	v[1]=9.9;
	v2[0]= 8.8;
	cout << v.get(0) << '\t' << v.get(1) << '\t' << v.get(2) << endl;
	cout << v2.get(0) << '\t' << v2.get(1) << '\t' << v2.get(2) << endl;

}

int main()
{
	for(int i= 3;i<1000;++i) f(i);
	keep_window_open();
	return 0;
}