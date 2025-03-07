#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	int age;
	char name[50];
public:
	Person(int myage, const char* myname) :age(myage)
	{
		strcpy(name, myname);
	}
	
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old" << endl;
	}
};

class UnivStudent : public Person
{
private:
	char major[50];

public:
	UnivStudent(const char* myname, int myage, const char* myMajor) : Person(myage, myname)
	{
		strcpy(major, myMajor);
	}

	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		cout << "My Major is " << major << endl << endl;
	}
};

int main()
{
	UnivStudent ustd1("LEE", 22, "COMPUTER ENG");
	ustd1.WhoAreYou();

	UnivStudent ustd2("YOON", 21, "ELECTRONIC ENG");
	ustd2.WhoAreYou();
	return 0;
}