#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Girl;

class Boy
{
private:
	int height;
	friend class Girl;
public:
	Boy(int len) : height(len) {}

	void ShowYourFriendInto(Girl& frn);
};

class Girl
{
private:
	char phNum[20];
public :
	Girl(const char* num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;
};

void Boy::ShowYourFriendInto(Girl& frn)
{
	cout << "Her phone number : " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy& frn)
{
	cout << "His Height : " << frn.height << endl;
}

int main()
{
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInto(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}