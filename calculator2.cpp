#include "std_lib_facilities.h"
const char invalid = 'i';
const char name = 'a';
const char number = '8';
const char quit = 'q';
const char print = ';';

class Variable
{
public:
	string name;
	double value;
};
double get_value(string s);
void set_value(string s, double d);

vector<Variable> var_table;
double get_value(string s)
{
	for (Variable var : var_table)
		if (var.name == s) return var.value;
}
void set_value(string s, double d)
{
	for (Variable& var : var_table)
		if (var.name == s)
		{
			var.value = d;
			return;
		}
	var_table.push_back(Variable{ s,d });
}


class Token
{
public:
	char kind;
	double value;
	string name;
	Token(char ch) :kind{ ch } {};
	Token(char ch, double val) :kind{ ch }, value{ val } {};
	Token(char ch, string n) :kind{ ch }, name{ n } {};

};

class Token_stream
{
public:
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer{invalid};
};

void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer:");
	buffer = t;
	full = true;
}
Token Token_stream::get()
{
	//cout << "lslslsl";
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch)
	{
	case ';': case'q': case'=':
	case '(': case ')': case'+': case '-': case'*': case'/':
		return Token{ ch };

	case'.': case'0': case'1': case'2': case'3': case'4': case'5':
	case'6': case'7': case'8': case'9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8',val };

	}
	default:
		if (isalpha(ch))
		{
			string s;
			s += ch;
			while (cin.get(ch) && isalpha(ch)) s += ch;
			cin.putback(ch);
			return Token{ name, s };
		}
		return Token{ invalid,double(ch) };

	}
	return Token{ quit };
}

Token_stream ts;

double expression();
double primary() {
	Token t = ts.get();
	switch (t.kind) {
	case'(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case name:
		{
		Token t = ts.get();
			if(t.kind=='=')
			{
				double d = expression();
				set_value(t.name, d);
				return d;
			}
			else {
				ts.putback(t);
				return get_value(t.name);
			}
		}
	case number:
		return t.value;
	default:
		error("primary expected");
	}
}
double term()
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case'*':
			left *= primary();
			t = ts.get();
			break;
		case'/':
		{	double d = primary();
		if (d == 0)
			error("division by zero");
		left /= d;
		t = ts.get();
		break; }
		default:
			ts.putback(t);
			return left;
		}
	}
}
double expression()
{
	double left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind)
		{
		case'+':
			left += term();
			t = ts.get();
			break;
		case'-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

int main()
{
	double val = 0;
	cout << '>';
	while (cin)
	{
		Token t = ts.get();
		if (t.kind == 'q') break;
		if (t.kind == ';')
		{
			cout << '=' << val << endl;
			cout << '>';
		}
		else
			ts.putback(t);
		val = expression();
	}
	keep_window_open();
	return 0;
}
/*
Token get_token()
{
	return ts.get();
}

int main()
{
 vector<Token> tokens;
    // frazzyswizel!
    for(Token t = get_token(); t.kind != 'q'; t = get_token()) {
    	tokens.push_back(t);
	}

	for(Token tok : tokens) {
		if (tok.kind == '8')
			cout << "A number token with val = " << tok.value << '\n';
		else if (tok.kind == 'i')
			cout << "We received an invalid token of value "
			<< char(tok.value) << '\n';
		else if (tok.kind == 'a')
			cout << "A token with name: " << tok.name << endl;
        else
		    cout << "A token of kind " << tok.kind << '\n';
	}
    return 0;
}*/

/* main for test purposes:
int main()
{
    set_value("foo", 12.2);
    set_value("goo", 16.2);
    set_value("blue", 2.2);
    set_value("foo", 2.9);
    for(Variable var : var_table)
        cout << "Var " << var.name << " = " << var.value << endl;
}*/