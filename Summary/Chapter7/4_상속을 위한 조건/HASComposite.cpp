#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum) {}
	void Shot()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};


class Police 
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) : handcuffs(bcuff) 
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = nullptr;
	}

	void PutHandcuff()
	{
		cout << "SMAP!" << endl;
		handcuffs--;
	}

	void Shot()
	{
		if (pistol == nullptr)
			cout << "HUT BBANG!" << endl;
		else
			pistol->Shot();
	}

	~Police()
	{
		if (pistol != nullptr)
			delete pistol;
	}
};

int main()
{
	Police pman(5, 3);
	pman.Shot();
	pman.PutHandcuff();

	Police pman2(0, 3);
	pman2.Shot();
	pman2.PutHandcuff();

	return 0;
}