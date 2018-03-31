#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int tests; cin >> tests;
    for(int i = 0; i < tests; i++)
    {
        int x; cin >> x; //looking for this
        int aAmount; cin >> aAmount;
        vector<int> A (aAmount);
        for(int j = 0; j < aAmount; j++)
        {
            cin >> A[j];
        }

        int bAmount; cin >> bAmount;
        vector<int> B (bAmount);
        for(int j = 0; j < bAmount; j++)
        {
            cin >> B[j];
        }

        sort(A.begin(), A.begin() + aAmount);
    }
    
    return 0;
}