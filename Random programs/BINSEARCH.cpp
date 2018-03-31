#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch(vector<int> &vec, int searchFor)
{
    sort(vec.begin(), vec.begin() + vec.size());
    int left = 0;
    int right = vec.size() - 1;
    while(right > left)
    {
        int middle = (left + right) / 2;
        if(vec[middle] > searchFor)
        {
            right = middle;
        }
        else
        {
            left = middle + 1;
        }
    }
    return left - 1;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int numbers; cin >> numbers;
    vector<int> vec(numbers);
    for(int i = 0; i < numbers; i++)
    {
        cin >> vec[i];
    }

    int searchFor; cin >> searchFor;

    cout << BinarySearch(vec, searchFor);
    
    return 0;
}