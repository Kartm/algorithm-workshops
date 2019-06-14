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

int main()
{
    pair<int, int> intPair;
    cin >> intPair.first >> intPair.second;
    while(intPair.second != 0)
    {
        int theRest = modulo(intPair.first, intPair.second);
            
        //cout << "Modulo " << intPair.first << " " << intPair.second << " = " << theRest << endl;
        intPair.first = intPair.second;
        intPair.second = theRest;
        //cout << intPair.first << " " << intPair.second << endl << endl;
        //int x; cin >> x;
    }
    cout << intPair.first;
    return 0;
}