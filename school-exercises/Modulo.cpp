#include <iostream>
#include <cstdlib>

using namespace std;

int modulo(int a, int b)
{
    int integer = 0;
    int reszta = 0;
    while(true)
    {
        int multiplied = 0;
        for(int i = 0; i <= integer; i++)
            multiplied += b;

        int nowareszta = a - multiplied;
        if(reszta == nowareszta || nowareszta < 0)
            return reszta;

        reszta = nowareszta;
        integer++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int number; cin >> number;
    int divider; cin >> divider;

    cout << modulo(number, divider);
    return 0;
}