#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> Sieve(int max)
{
    vector<int> sieve(max + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    vector<int> result;
    for(int i = 2; i <= sqrt(max); i++)
    {
        if(sieve[i] == true)
        {
            for(int j = i*i; j <= max; j+=i)
            {
                sieve[j] = false;
            }
        }
    }

    for(int i = 2; i <= max; i++)
    {
        if(sieve[i] == true)
        {
            result.push_back(i);
        }
    }
    
    return result;
}

vector<int> Decomposition(vector<int> &sieve, int number, int sieveBoundary)
{
    vector<int> result;
    result.push_back(0); //na ile liczb pierwszych mozna rozlozyc

    int left = 0, right = 0;
    int sumCounter = 1;
    int currentSum = sieve[0]; 

    //while(left >= 0 && right <= sieve.size() - 1)
    while(left >= 0 && right <= sieveBoundary - 1)
    {
        if(currentSum < number)
        {
            if(right + 1 <= sieveBoundary) //checking not to exit the array
            {
                right++;
            }
            currentSum += sieve[right];
            sumCounter++;
        }
        else if(currentSum > number)
        {
            currentSum -= sieve[left];
            left++;
            sumCounter--;
        }
        else if (currentSum == number)
        {
            result[0] = sumCounter;
            for(int i = left; i <= right; i++)
            {
                result.push_back(sieve[i]);
            }
            return result;
        }
    }
    return result;
}

int main()
{
    int number;
    cout << "Podaj liczbe pierwsza: ";
    cin >> number;

    vector<int> sieve = Sieve(number);

    vector<int> test = Decomposition(sieve, number, sieve.size());
    cout << "Liczbe pierwsza " << number << " mozna przedstawic w postaci sumy " << test[0] << " kolejnych liczb pierwszych: ";
    for(int i = 1; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }
    cout << "\n";

    vector<int> sieveMain = Sieve(1000000);
    int maxIndex = 0;
    int maxPrime = 0;
    cout << "Szukanie liczby pierwszej mniejszej od miliona, ktora mozna zapisac jako sume najwiekszej liczby kolejnych liczb pierwszych...\n[Obliczenia sa czasochlonne]\n";
    for(int i = 0; i < sieveMain.size(); i++)
    {
        int currentPrimeNumber = sieveMain[i];
        vector<int> sieve2 = Sieve(currentPrimeNumber);
        vector<int> test2 = Decomposition(sieve2, currentPrimeNumber, sieve2.size());
        if(test2[0] > maxPrime)
        {
            maxIndex = i;
            maxPrime = test2[0];
        }
    }

    cout << "Znaleziona liczba to " << sieveMain[maxIndex] << ", suma " << maxPrime << " kolejnych liczb pierwszych.";
    return 0;
}