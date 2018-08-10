#include "std_lib_facilities.h"

class vect
{
	int sz;
	double* elem;
public:
	vect(int s)
		:sz(s), elem{ new double[s] } {} /*{
		for (int i = 0; i < sz; ++i) elem[i] = 0.0;
	}
	vect(initializer_list<double> lst)
		:sz{lst.size()},elem{new double[sz]}
	{
		copy(lst.begin(), lst.end(), elem);
	}*/
	~vect()
	{
		delete[] elem;
	}
	double get(int i);
	void set(int i, double d);
};

double vect::get(int i)
{
	return elem[i];
}

void vect::set(int i, double d)
{
	elem[i] = d;
}

void f(int n)
{
	vect v(n);
	cout << n << endl;
	v.set(2, 2.2);
	vect v2 = v;
	v.set(1, 9.9);
	v2.set(0,8.8);
	cout << v.get(0) << ' ' << v.get(1) << ' ' <<v.get(2) <<endl;
	cout << v2.get(0) << ' ' << v2.get(1) << ' ' << v2.get(2) << endl;
}

int main()
{
	for (int i = 3; i < 10000; i++)
		f(i);
	cout << "Finished looping\n";
	keep_window_open();
	return 0;
}