#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cmath>

using namespace std;

/*
Zamiana liczb z systemu dziesiętnego na silniowy system pozycyjny i odwrotnie
*/

long long Factorial(long long number)
{
    long long result = 1;
    while(number > 0)
    {
        result *= number;
        number--;
    }
    return result;
}

long long Length(long long number)
{
    long long length = 0;
    for(; number != 0; number /= 10, length++); //calculating the length of the integer
    return length;
}

long long FactorialToDecimal(long long factorial)
{
    long long result = 0;
    long long factorialCounter = 0;
    while(factorial > 0)
    {
        result += (factorial % 10) * Factorial(factorialCounter);
        factorial /= 10;
        factorialCounter++;
    }
    return result;
}

long long DecimalToFactorial(long long decimal)
{
    //finding the biggest factorial we can divide the decimal by
    long long n = 1;
    long long biggestFactorial = 1; //equals Factorial(n)
    while(biggestFactorial * n < decimal)
    {
        biggestFactorial *= n;
        n++;
    }
    long long dividingResult = 1; //default value is 1
    n--;

    long long result = 0;
    long long resultMultiplicator = pow(10, n-1);
    while(dividingResult > 0)
    {
        
        dividingResult = decimal / biggestFactorial;
        result += dividingResult * resultMultiplicator;
        resultMultiplicator /= 10;
        //cout << "n = " << n << " decimal = " << decimal << " biggestFactorial = " << biggestFactorial << "RESULT = " << dividingResult <<"\n";
        decimal -= dividingResult * biggestFactorial;
        //cout << dividingResult << " ";
        biggestFactorial /= n;
        n--;
    }
    
    return result;
}

int main()
{
    cout << "Podaj liczbe w systemie dziesietnym, ktora chcesz zamienic na liczbe w silniowym systemie pozycyjnym: ";
    long long decimal;
    cin >> decimal;
    cout << decimal << " = " << DecimalToFactorial(decimal) << "\n";
    cout << "Podaj liczbe w silniowym systemie pozycyjnym, ktora chcesz zamienic na liczbe w systemie dziesietnym: ";
    long long factorial;
    cin >> factorial;
    cout << factorial << " = " << FactorialToDecimal(factorial);
    return 0;
}