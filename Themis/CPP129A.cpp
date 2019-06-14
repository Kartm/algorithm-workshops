#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int NWD(int a, int b)
{
	while(b > 0)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	int n; cin >> n;
	//liczba liczb mniejszych od niej ktore sa wzglednie pierwsze
	//8 -> 4
	int counter = 0;
	for(int i = 1; i < n; i++)
	{
		if(NWD(n, i) == 1) counter++;
	}
	cout << counter;
	return 0;
}
