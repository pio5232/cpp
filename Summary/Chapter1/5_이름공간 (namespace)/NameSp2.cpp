#include <iostream>

namespace BestComImpl
{
	void SimpleFunc(void);
}

namespace ProgComImpl
{
	void SimpleFunc();
}

int main()
{
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();

	return 0;
}

void BestComImpl::SimpleFunc()
{
	std::cout << "BestComImpl�� ������ �Լ� " << std::endl;

}
void ProgComImpl::SimpleFunc()
{
	std::cout << "ProgComImpl�� ������ �Լ� " << std::endl;
}