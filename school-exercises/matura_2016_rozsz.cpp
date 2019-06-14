#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

vector<bool> makeSieve(int n)
{
    vector<bool> sieve (n + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for(int i = 2; i < floor(sqrt(n)); i++)
    {
        if(sieve[i] == true)
        {
            for(int j = i + i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

int main()
{
    const int intAmount = 2000;
    int numberArray[intAmount];
    vector<bool> sieve = makeSieve(2000);

    int primeAmount = 0;
    ifstream file("dane4.txt");
    if(file.is_open())
    {
        for(int i = 0; i < intAmount; i++)
        {
            file >> numberArray[i];
        }
    }

    for(int i = 0; i < intAmount; i++)
    {
        //cout << "c " << numberArray[i] << "\n";
        if(sieve[numberArray[i]] == true)
            primeAmount++;
    }

    cout << primeAmount;
}