#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

const int S = 1 << 19; //* enough for this exercise
vector<int> tree (S * 2);
vector<int> maxArr (S * 2);

void updateInterval(int pos)
{
	while(pos > 1)
	{
		pos /= 2;
		maxArr[pos] = max(maxArr[pos * 2], maxArr[pos * 2 + 1]) + tree[pos];
	}
}

void addInterval(int l, int r, int value)
{
	l += S;
	r += S;
	if(l == r)
	{
		maxArr[l] += value;
		updateInterval(l);
		return;
	}

	int initialL = l;
	int initialR = r;

	maxArr[l] += value;
	maxArr[r] += value;

	while(l / 2 != r / 2)
	{
		if(l % 2 == 0)
		{
			tree[l + 1] += value;
			maxArr[l + 1] += value;
		}
		if(r % 2 == 1)
		{
			tree[r - 1] += value;
			maxArr[r - 1] += value;
		}
		l /= 2;
		r /= 2;
		maxArr[l] = max(maxArr[2 * l], maxArr[2 * l + 1]) + tree[l];
		maxArr[r] = max(maxArr[2 * r], maxArr[2 * r + 1]) + tree[r];
	}
	updateInterval(initialL);
	updateInterval(initialR);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int input; cin >> input;
		if(input == 1)
		{
			int a, b; cin >> a >> b;
			addInterval(a, b, 1);
		}
		else if (input == 2)
		{
			int a, b; cin >> a >> b;
			addInterval(a, b, -1);
		}
		else if (input == 0)
		{
			cout << maxArr[1] << "\n";
		}
	}
	return 0;
}
