#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
/*
8
2 10
4 13
2 8
2 9
1 2
1 3
1 4
1 1

5
1 2
3 9
2 6
1 3
1 2

6 
2 9 
2 7 
3 8 
1 2 
1 3 
1 1
*/

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n; cin >> n; //ilosc wierzcholkow
	queue<long long> Q; //<stopien, indeks>

	long long vertexDegreeSum = 0;

	vector<long long> sums (n+1, 0);
	vector<long long> degrees (n+1, 0);

	for(int i = 1; i <= n; i++)
	{
		long long d; cin >> d; //stopien wierzcholka
		long long s; cin >> s; //suma numerow sasiadow
		
		degrees[i] = d;
		sums[i] = s;

		vertexDegreeSum += d;
		Q.push(i);
	}

	// suma stopni wierzcholkow musi byc parzysta
	if(vertexDegreeSum % 2 == 1) { cout << "NIEMOZLIWE"; return 0; }

	vector<int> results;

	while(!Q.empty())
	{
		//cout << "Size: " << Q.size() << ", remaining one: " << Q.front() << "\n";

		long long n = Q.front(); //numer aktualnego wierzcholka
		long long d = degrees[n]; //stopien aktualnego wierzcholka
		long long s = sums[n]; //suma numerow sasiadow 
		Q.pop();

		if(d == 1)
		{
			degrees[n] = 0;
			sums[n] = 0;

			sums[s] -= n;
			degrees[s]--;
			if(degrees[s] == 1)
			{
				Q.push(s);
			}
			//cout << n << " --- " << s << "\n";
			results.push_back(n); results.push_back(s);
		}
	}

	//jezeli wszystkie pojedyncze zostaly wykorzystane i degrees[i] > 0
	for(int i = 1; i <= n; i++)
	{
		if(degrees[i] > 0)
		{
			cout << "NIEMOZLIWE\n";
			return 0;
		}
	}
	
	cout << "OK\n";
	cout << results.size()/2 << "\n";
	for(int i = 0; i < results.size() - 1; i+=2)
	{
		cout << results[i] << " " << results[i+1] << "\n";
	}

	return 0;
}
