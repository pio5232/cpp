#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Stringclass.h"

String::String()
{
	len = 0;
	str = nullptr;
}

String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String()
{
	if (str)
		delete[] str;
}

String& String::operator=(const String& s)
{
	if (str)
		delete[] str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}

String& String::operator+=(const String& s)
{
	len += (s.len - 1);
	char* tempstr = new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	if (str)
		delete[] str;
	str = tempstr;
	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}

bool String::operator==(const String& s)
{
	return strcmp(str,s.str);
}

String String::operator+(const String& s)
{
	char* tempstr = new char[len + s.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	String temp(tempstr);
	delete[] tempstr;
	return temp;
}

ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;
	return os;

	// TODO: 여기에 return 문을 삽입합니다.
}

istream& operator>>(istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
	// TODO: 여기에 return 문을 삽입합니다.
}

int main()
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "동일 문자열! " << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	String str4;
	cout << "문자열 입력";
	cin >> str4;
	cout << "입력한 문자열 : " << str4 << endl;
	return 0;
}