#include <iostream>
#include "Text.h"
using namespace std;


int main() 
{

	Text txt1("txt1");
	Text txt2("txt2");
	Text txt3(txt2);
	String str1("str1");
	cout << txt3;

	txt1.append("middle");
	cout << txt1;

	txt1.append(str1);
	cout << txt1;

	txt1.append(txt2);
	cout << txt1;

	cout << txt1.lines();

	return 0;
}

