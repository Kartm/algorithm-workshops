#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

const int S = 1 << 17; //* approximately 10^5, enough for this exercise
vector<int> tree (S * 2);

int get(int pos)
{
	pos += S;
	int result = tree[pos];
	while(pos > 1)
	{
		pos /= 2;
		result += tree[pos];
	}
	return result;
}

void update(int l, int r, int value)
{
	if(l == r)
	{
		tree[l + S] += value;
		return;
	}
	l += S;
	r += S;
	tree[l] += value;
	tree[r] += value;
	while(l / 2 != r / 2)
	{
		if(l % 2 == 0) //left node - we need to increment the node on the right
		{
			tree[l + 1] += value;
		}
		if(r % 2 == 1) //right node - we need to increment the node on the left
		{
			tree[r - 1] += value;
		}
		l /= 2;
		r /= 2;
	}
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
			int a, b, c;
			cin >> a >> b >> c;
			//add c on interval [a, b]
			update(a, b, c);
		}
		else if (input == 0)
		{
			int a; cin >> a;
			//read a
			cout << get(a) << "\n";
		}
	}
	return 0;
}
