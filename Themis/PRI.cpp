#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int Sieve(int a, int n)
{
    //1 ≤ a ≤ b ≤ 100000
    int amount = 0;
    vector<bool> prime (n + 1, true);
    prime[1] = false;
    for(int i = 2; i < sqrt(n); i++)
        if(prime[i])
            for(int j = i * i; j < n; j += i)
                prime[j] = false;

    for(int i = a; i < n; i++)
    {
        if(prime[i])
        {
            //cout << i << " ";
            amount++;
        }
    }
    return amount;
}

int main()
{
    int a,b; cin >> a >> b;
    cout << Sieve(a, b);
    return 0;
}