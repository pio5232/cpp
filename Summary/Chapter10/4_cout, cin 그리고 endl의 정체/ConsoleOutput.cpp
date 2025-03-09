#include <iostream>
namespace mystd
{
	using namespace std;

	class ostream
	{
	public:
		void operator<< (const char* const str)
		{
			printf("%s", str);
		}

		void operator<<(char str)
		{
			printf("%c", str);
		}
		void operator<< (int num)
		{
			printf("%d", num);
		}
		void operator<< (double e)
		{
			printf("%g", e);
		}

		void operator<< (ostream& (*fp)(ostream& ostr))
		{
			fp(*this);
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

	cout << "simple string";
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	cout << endl;

	return 0;
}