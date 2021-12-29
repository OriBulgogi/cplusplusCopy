#include <iostream>
using namespace std;

class String
{
public:

	String();
	String(const char* s);
	String(const String& s);
	~String();

	void init(const char* str, const char* s, int len_str_, int len_s);
	void print();

	int size();
	int length();
	int capacity();

protected:
	int len_;
	char* str_;
	int capa_;
	friend istream& operator>>(istream& is, String& str);
	friend ostream& operator<<(ostream& os, const String& str);
public:		//2단계
	String& assign(const String& str);
	String& assign(const char* s);
	String& operator=(const String& str);
	String& operator=(const char* s);
	String& append(const String& str);
	String& append(const char* s);
	String& operator+=(const String& str);
	String& operator+=(const char* s);
	char& operator[](int index);
	void shrink_to_fit();
	const char* print(bool show = true);

public:		//3단계
	String operator+(const String& str);
	String operator+(const char* s);

};
ostream& operator<<(ostream& os, const String& str);


