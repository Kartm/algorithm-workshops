#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	//* time: 1s, memory: 64MB

	int n; cin >> n;
	vector<int> numbers;
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		numbers.push_back(x);
	}

	int leader = 0;
	int counter = 0;

	for(int i = 0; i < numbers.size(); i++)
	{
		if(counter == 0)
		{
			counter++;
			leader = numbers[i];
		}
		if(leader == numbers[i])
		{
			counter++;
		}
		else
		{
			counter--;
		}
	}

	int leaderOccurrences = 0;

	for(int i = 0; i < numbers.size(); i++)
		if(numbers[i] == leader)
			leaderOccurrences++;

	if(leaderOccurrences > n/2)
		cout << leader;
	else
		cout << "NIE MA LIDERA";

	return 0;
}