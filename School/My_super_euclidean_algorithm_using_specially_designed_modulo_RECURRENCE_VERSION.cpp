#include <iostream>
#include <cstdlib>

using namespace std;

int modulo(int a, int b)
{
    int integer = 0;
    int rest = 0;
    while(true)
    {
        int multiplied = 0;
        for(int i = 0; i <= integer; i++)
            multiplied += b;

        int newRest = a - multiplied;
        if(rest == newRest || newRest < 0)
            break;

        rest = newRest;
        integer++;
    }
    if(rest == a)
        return 0;
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