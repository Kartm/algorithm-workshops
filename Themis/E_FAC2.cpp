#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> Sieve(int maxInt)
{
    vector<int> vec;
    vector<bool> prime (maxInt + 1, true);
    for(int i = 2; i < sqrt(maxInt); i++)
        if(prime[i])
            for(int j = i * i; j < maxInt; j += i)
                prime[j] = false;

    for(int i = 2; i <= maxInt; i++)
        if(prime[i])
            vec.push_back(i);

    return vec;
}

void PrimeFactors(int n, vector<int> &precalculated)
{
    int index = 0;
    int root = sqrt(n);
    while(n > 1 && precalculated[index] <= root)
    {
        while(n % precalculated[index] == 0 )
        {
            cout << precalculated[index] << " ";
            n = n / precalculated[index];
        }
        index++; 
    }
    if(n > 1)
        cout << n;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int maxNumber = 1000000;
    vector<int> precalculatedPrimes = Sieve(maxNumber);
    int tests; cin >> tests;
    for(int i = 0; i < tests; i++)
    {
        int n; cin >> n;
        PrimeFactors(n, precalculatedPrimes);
        cout << "\n";
    }
    return 0;
}