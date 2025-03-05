#include <iostream>

namespace BestComImpl
{
	void SimpleFunc(void);
}
namespace BestComImpl
{
	void PrettyFunc();
}

namespace ProgComImpl
{
	void SimpleFunc();
}

int main()
{
	BestComImpl::SimpleFunc();
	return 0;
}

void BestComImpl::SimpleFunc()
{
	std::cout << "BestComImpl이 정의한 함수 " << std::endl;
	PrettyFunc();
	ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc()
{
	std::cout << "So Pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc()
{
	std::cout << "ProgComImpl이 정의한 함수 " << std::endl;
}
