#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    long long t;
    cin >> t;
    long long currentMax = -9223372036854775807;
    for(int i = 0; i < t; i++)
    {
        long long input;
        cin >> input;
        if(input > currentMax)
        {
            currentMax = input;
        }
        cout << currentMax << "\n";
    }
    
    return 0;
}