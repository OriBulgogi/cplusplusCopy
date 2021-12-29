#include <cstring>
#include "String.h"
#include <iostream>
using namespace std;

String::String()
{
	init("","", strlen(""), strlen(""));
}
String::String(const char* str)
{
	init("",str,strlen(""),strlen(str));
}
String::String(const String& str)
{
	init(str.str_,"",strlen(str.str_),strlen(""));
}
String::~String()
{
		delete[] this->str_;
}
const char* String:: print(bool show)
{
	if (show) {
		cout << this->str_;
	}
	return this->str_;
}
int String::size() 
{
	return len_;
}
int String::length() 
{
	return this->size();
}
int String::capacity() 
{
	return this->capa_;
}

//2단계
void String::init(const char* str_left, const char* str_right, int left_len, int right_len) 
{
	this->len_ = left_len + right_len;
	this->capa_ = len_ + 1;
	char* tempstr = new char[this->capa_];
	strcpy_s(tempstr, capa_, str_left);
	strcat_s(tempstr, capa_, str_right);
	delete[] this->str_;
	this->str_ = tempstr;
}
String& String :: assign(const String& str)
{
	return this->assign(str.str_);
}
String& String::assign(const char* s)
{
	init(s, "", strlen(s), strlen(""));
	return *this;
}
String& String :: operator=(const String& str)
{
	return this->assign(str.str_);
}
String& String :: operator=(const char* s)
{
	return this->assign(s);
}

String& String::append(const String& str)
{
	return this->append(str.str_);
}

String& String:: append(const char* s)
{
	init(this->str_, s, strlen(this->str_),strlen(s));
	return *this;
}
String& String :: operator+=(const String& str)
{
	return this->append(str.str_);
}
String& String ::operator+=(const char* s)
{
	return this->append(s);
}

char& String::operator[](int index)
{
	if (index < 0) {
		index = 0;
	}else if(index >= this->len_){
		index = this->len_-1;
	}
	return this->str_[index];
}

void String :: shrink_to_fit()
{
	this->assign(this->str_);
}

//3단계

String String::operator+(const String& str)
{
	return this->operator+(str.str_);
}

String String::operator+(const char* s)
{
	String new_string;
	new_string.assign(*this).append(s);
	return new_string;
}

ostream& operator<<(ostream& os, const String& str)
{
	os << str.str_ <<endl;
	return os;
}
istream& operator>>(istream& is, String& str)
{
	char temp[sizeof(str.str_)];
	is >> temp;
	str.assign(temp);
	return is;
}

