#include <iostream>
using namespace std;

class Base
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;
	
	Base() : num1(1), num2(2), num3(3) {}
};

class Derived : protected Base 
{
};



class Derived2 : protected Base
{
    // x�� Base�� private => ���� �Ұ�
    // y�� protected y;�� ���� => ���� ����
    // z�� protected z;�� ���� => ���� ����

}

class DDerived2 : public Derived
{
    // DDerived2�� private x, protected y, protected z�� ���
    // x�� Base�� private => ���� �Ұ�
    // y�� protected y;�� ���� -> ���� ���� 
    // z�� protected z;�� ���� -> ���� ����.
}

// ���� 
class DDerived3 : private Derived
{
    // �� �޾Ҵ��� 
    // x�� Base�� private => ���� �Ұ�
    // y�� �ڽ��� private y;�� ���� -> ���� ���� 
    // z�� �ڽ��� private z;�� ���� -> ���� ����.
}

class DD : public DDerived3
{
    void A()
    {

    }
};
int main()
{
	Derived drv;
	//cout << drv.num3 << endl;
	return 0;
}