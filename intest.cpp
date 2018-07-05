#include "std_lib_facilities.h"

int main() {
	cout << "Please enter your name\n";
	string first_name;
	int age;
	cin >> first_name;
    cout << "Please enter your age:\n";
	cin >> age;
    cout << "Name: ";
	cout << first_name << " \n"<<"Age: " << age <<" years old" <<endl;
	keep_window_open();
}
