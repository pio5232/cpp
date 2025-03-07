#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		cout << "create obj" << num << endl;
	}

	~Temporary()
	{
		cout << "destroy obj : " << num << endl;
	}

	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}

	void ShoWd() const
	{
		cout << " " << num << " " << endl;
	}
};

int main()
{
	Temporary(100);
	cout << "********************* after maKE!!" << endl << endl;

	Temporary(200).ShowTempInfo();
	cout << "********************* after maKE!!" << endl << endl;

	const Temporary& ref = Temporary(300);
	cout << "********************* after maKE!!" << endl << endl;
	ref.ShoWd();
}