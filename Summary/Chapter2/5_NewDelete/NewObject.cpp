#include <iostream>
#include <string.h>
using namespace std;

class Simple
{
public:
	Simple()
	{
		cout << "I'm simple constructor!" << endl;
	}
};

int main()
{
	cout << "case 1 : ";
	Simple* sp1 = new Simple();

	cout << "case 2 : ";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple));

	cout << "end of main" << endl;

	delete sp1;
	free(sp2);
	return 0;
}