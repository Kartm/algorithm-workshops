#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<int> PrimeFactors(int number)
{
    vector<int> factors;
    int dividor = 2;
    int maxDividor = sqrt(number);
    cout << "Number = " << number << ", dividor = " << dividor << ", maxDividor = " << maxDividor << "\n";
    while(number > 0 && dividor <= maxDividor)
    {
        cout << "I'm in [" << dividor << "]\n";
        if(number % dividor == 0) //can divide
        {
            cout << "Can divide\n";
            //cout << dividor << " ";
            factors.push_back(dividor);
            number = number / dividor;
        }
        else
        {
            cout << "Can't divide\n";
            dividor++;
        }
    }
    
    return factors;
}

int main()
{
    cout << "Enter number: ";
    int number; cin >> number;
    vector<int> factors = PrimeFactors(number);
    for(int i = 0; i < factors.size(); i++)
        cout << factors[i] << " ";
    return 0;
}