#include "_2_Car.h"

int main()
{
	Car run99;
	run99.InitMemebers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}