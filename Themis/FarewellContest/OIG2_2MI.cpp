#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n; //moc zbioru
    long long k; //podzielnik

    long long min = INT_MAX;
    long long max = 0;

    for(int i = 0; i < n; i++)
    {
        long long input;
        cin >> input;
        if(input > max)
        {
            max = input;
        }
        if(input < min)
        {
            min = input;
        }
    }

    
    return 0;
}