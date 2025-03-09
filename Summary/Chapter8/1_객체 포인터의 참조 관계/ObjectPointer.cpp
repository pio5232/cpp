#include <iostream>
using namespace std;

class Person
{
public:
	void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person
{
public:
	void Study() { cout << "Study\n"; }
};

class PartTimeStudent : public Student
{
public:
	void Work() { cout << "Work\n"; }
};

int main()
{
	Person* ptr1 = new Student();
	Person* ptr2 = new PartTimeStudent();
	Student* ptr3 = new PartTimeStudent();

	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Sleep();

	delete ptr1; delete ptr2; delete ptr3;
	return 0;
}