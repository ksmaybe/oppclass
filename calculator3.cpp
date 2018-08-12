#include "calc3.h"

Complex expression();



int main()
{
	Complex val;
	val.setComplex(0, 0);
	cout << '>';
	int h = 0;
	while (cin)
	{
		Token t = ts.get();



			if (t.kind == 'q') break;
			if (t.kind == ';')
			{
				if (hi.value1 == 0) {
					history.push_back(line.name);
					hit.value1 += 1;
					line.name = "";
					cout << '=' << val << endl << endl;
					cout << '>';
				}
				else
				{
					cout << '=' << history[hit.value1-hi.value1] << endl << endl;
					hi.value1 = 0;
					cout << '>';
				}
			}
			else
				ts.putback(t);
			val = expression();
		
	}
	keep_window_open();
	return 0;
}
/*
int main()
{
	Complex a, b, c, d,e,f;
	cout << "Setting first complex number: " << endl;
	a.setComplex();
	cout << "Setting second complex number: " << endl;
	b.setComplex();
	cout << "2+b= " << endl;
	c = 2+b;
	cout << c << endl;
	cout << "a-2= " << endl;
	d = a-2;
	cout << d << endl;
	cout << "2*b= " << endl;
	e = 2*b;
	cout << e << endl;
	cout << "a/2= " << endl;
	f = a/2;
	cout << f << endl;
}*/