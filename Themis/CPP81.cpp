#include <iostream>
#include <cstdlib>

using namespace std;

long long quickPower(long long a, long long b)
{
	if(b != 0) //wykladnik dodatni
	{
		long long result = quickPower(a, b/2);
		if(b % 2 == 0) //wykladnik parzysty
		{
			return result * result;
		}
		else //wykladnik nieparzysty
		{
			return result * result * a;
		}
	}
	else //wykladnik rowny 0
	{
		return 1;
	}
}

int main()
{
	//a <= 1000, b <=500000000
	long long a; cin >> a;
	long long b; cin >> b;

	cout << quickPower(a, b);
	
	return 0;
}
