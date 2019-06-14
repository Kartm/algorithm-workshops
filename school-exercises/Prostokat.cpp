#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void TwoBiggest(vector<int> arr, int &max1, int &max2, int p)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] % p != 0)
        {
            if(arr[i] > max1)
            {
                if(max1 > max2) max2 = max1;
                max1 = arr[i];
            }
            if(arr[i] != max1 && arr[i] > max2)
            {
                max2 = arr[i];
            }
        }
    }
}

int main()
{
    
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int input; cin >> input;
        arr.push_back(input);
    }
    int p; cin >> p;

    int max1 = 0;
    int max2 = 0;
    TwoBiggest(arr, max1, max2, p);
    cout << "Max1 " << max1 << ", max2 " << max2 << ", pole " << max1*max2;
}