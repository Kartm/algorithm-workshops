#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int Reverse(int n)
{
    int reversed = 0;
    while(n > 0)
    {
        reversed *= 10;
        reversed += n % 10;
        n /= 10;
    }
    return reversed;
}

bool IsPalindrome(int n)
{
    return (n == Reverse(n));
}

bool IsSumAPalindrome(int n)
{
    return (n+Reverse(n) == Reverse(n+Reverse(n)));
}

int Product(int n)
{
    int product = 1;
    while(n > 0)
    {
        product *= n % 10;
        if(product == 0) return 0;
        n /= 10;
    }
    return product;
}

int ThePower(int n)
{
    int power = 0;
    while(n > 9 && n != 0)
    {
        n = Product(n);
        power++;
    }
    return power;
}

int main()
{
    int Powers[9] = {0};
    int maxOne = -1;
    int minOne = -1;

    const int intAmount = 1000; //amount of input numbers
    ifstream file("59.txt");
    if(file.is_open())
    {
        int arr[intAmount];
        for(int i = 0; i < intAmount; i++)
        {
            file >> arr[i];
            int power = ThePower(arr[i]);
            Powers[power] = Powers[power] + 1;
            if(power == 1)
            {
                if(maxOne == -1)
                {
                    maxOne = arr[i];
                    minOne = arr[i];
                }
                else
                {
                    if(arr[i] > maxOne)
                        maxOne = arr[i];
                    else if (arr[i] < minOne)
                        minOne = arr[i];
                }
            }
        }
    }
    else
    {
        cout << "Couldn't open file.";
        return 1;
    }
    cout << "Min = " << minOne << ", max = " << maxOne << "\n";

    int check = 0;
    for(int i = 0; i <= 8; i++)
    {
        cout << i << " power amount: " << Powers[i] << "\n";
        check += Powers[i];
    }

    cout << "check: " << check;
    file.close();
    return 0;
}