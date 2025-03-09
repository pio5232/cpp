#include <iostream>
namespace mystd
{
	using namespace std;

	class ostream
	{
	public:
		ostream& operator<< (const char* const str)
		{
			printf("%s", str);
			return *this;
		}

		ostream& operator<<(char str)
		{
			printf("%c", str);
			return *this;
		}
		ostream& operator<< (int num)
		{
			printf("%d", num);
			return *this;
		}
		ostream& operator<< (double e)
		{
			printf("%g", e);
			return *this;
		}

		ostream& operator<< (ostream& (*fp)(ostream& ostr))
		{
			return fp(*this);
		}
	};

	ostream& endl(ostream& ostr)
	{
		ostr << "\n";
		fflush(stdout);
		return ostr;
	}
	ostream cout;
}

int main()
{
	using mystd::cout;
	using mystd::endl;

	cout << "simple string" << endl << 3.14 << endl << 123 << endl;


	return 0;
}