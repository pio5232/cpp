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
    // x는 Base의 private => 접근 불가
    // y는 protected y;의 형태 => 접근 가능
    // z는 protected z;의 형태 => 접근 가능

}

class DDerived2 : public Derived
{
    // DDerived2는 private x, protected y, protected z를 상속
    // x는 Base의 private => 접근 불가
    // y는 protected y;의 형태 -> 접근 가능 
    // z는 protected z;의 형태 -> 접근 가능.
}

// 만약 
class DDerived3 : private Derived
{
    // 로 받았더라도 
    // x는 Base의 private => 접근 불가
    // y는 자신의 private y;의 형태 -> 접근 가능 
    // z는 자신의 private z;의 형태 -> 접근 가능.
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