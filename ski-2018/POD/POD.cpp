#include <iostream>

using namespace std;

int main()
{
    //parzysty iloczyn n i m - wtedy wygrywa A
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n; cin >> n;
        int m; cin >> m;
        bool nOdd = n & 1; //true if 1
        bool mOdd = m & 1;
        if(nOdd & mOdd) //if result is odd
        {
            cout << "B\n";
        }
        else
        {
            cout << "A\n";
        }
    }
}