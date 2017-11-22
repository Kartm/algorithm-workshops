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
            break;

        reszta = nowareszta;
        integer++;
    }
    if(reszta == a)
        reszta = 0;
    return reszta;
}

int euclideanAlgorithm(int a, int b)
{
    if(b != 0)
        euclideanAlgorithm(b, modulo(a, b));
    else
        return a;
}
int main()
{
    int a, b; cin >> a >> b;
    cout << euclideanAlgorithm(a, b);
    return 0;
}