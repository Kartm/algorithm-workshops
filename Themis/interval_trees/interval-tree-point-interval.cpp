#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

const int S = 1 << 17; //* approximately 10^5, enough for this exercise
vector<int> tree (S * 2);

void insert(int value, int pos)
{
	pos += S;
	tree[pos] = value;
	while(pos > 1) //while having any parent node
	{
		pos /= 2; //moving to parent
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1]; //parent is equal to its' children value
	}
}

int calculateSum(int l, int r)
{
	if(l == r)
		return tree[l + S];

	l += S;
	r += S;
	int result = tree[l] + tree[r];
	while(l / 2 != r / 2) //we sum up the children unless we reach their common parent
	{
		if(l % 2 == 0) //left child on the left
		{
			result += tree[l + 1];
		}
		if (r % 2 == 1) //right child on the right
		{
			result += tree[r - 1];
		}
		l /= 2;
		r /= 2;
	}
	return result;
}