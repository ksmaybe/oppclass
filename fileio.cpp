#include "std_lib_facilities.h"

struct Reading
{
	int hour;
	double temperature1;
	double temperature2;
};

int main()
{
	cout << "Please input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist) error("can't open input file ", iname);

	string oname;
	cout << "Please enter name of output file: ";
	cin >> oname;
	ofstream ost{ oname };
	if (!ost) error("can't open out put file ", oname);

	vector<Reading> temps;
	string input;
	int hour;
	double temperature1;
	double temperature2;
	while(ist >> input)
	{
		istringstream ss(input);
		string token;
		getline(ss, token, ',');
		stringstream d(token);
		d >> hour;
		string token1;
		getline(ss, token1, ',');
		stringstream k1(token1);
		k1 >> temperature1;
		string token2;
		getline(ss, token2, '\n');
		stringstream k2(token2);
		k2 >> temperature2;
		if (hour < 0 || 23 < hour) error("hour out of range");
		temps.push_back(Reading{ hour,temperature1,temperature2 });
	}
	int t = temps.size();
	for (int i = 0; i<t; ++i)
		ost << temps[i].hour << '	' << temps[i].temperature1 << '	'<< temps[i].temperature2 << endl;
	keep_window_open();
	return 0;
}
