#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int BinarySearch(vector<long long int> &prefixes, long long int &searchFor, long long int &length)
{
    int left = 0;
    int right = length - 1;
    while(right >= left)
    {
        int middle = (left + right) / 2;
        if(prefixes[middle] == searchFor)
        {
            return middle;
        }
        else if(prefixes[middle] > searchFor)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }
    return left;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int fragmentsAmount;
    cin >> fragmentsAmount;
    vector<long long int> prefixes (fragmentsAmount);
    
    long long int sum = 0;
    for(int i = 0; i < fragmentsAmount; i++)
    {
        long long int input; cin >> input;
        sum += input;
        prefixes[i] = sum;
    }

    int questions;
    cin >> questions;
    for(int i = 0; i < questions; i++)
    {
        long long int input; cin >> input;
        cout << BinarySearch(prefixes, input, fragmentsAmount) + 1 << "\n";
    }
    
    return 0;
}