#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//Chinskie twierdzenie o resztach - wersja brute
struct Congruence
{
    int divider;
    int remainder;
};

Congruence Calculate(Congruence &congA, Congruence &congB)
{
    Congruence congC;
    int i = 0;
    int a = congA.remainder + (congA.divider * i);
    int b = congB.remainder + (congB.divider * i);
    i++;
    while (a != b)
    {
        int oldA = a;
        int oldB = b;
        if(a > b)
            b = congB.remainder + (congB.divider * i);
        else
            a = congA.remainder + (congA.divider * i);

        if (b == oldB)
            if(a > b)
                b = congB.remainder + (congB.divider * i);

        i++;
    }
    congC.remainder = a;
    congC.divider = congA.divider * congB.divider;
    return congC;
}

int main()
{
    cout << "Operations: ";
    int operations; cin >> operations;
    if(operations < 2)
    {
        cout << "Too few operations.";
        return 0;
    }

    vector<Congruence> Congruences (operations);
    for(int i = 0; i < operations; i++)
    {
        int y, n;
        cin >> y >> n;
        Congruences[i].remainder = y;
        Congruences[i].divider = n;
    }

    for(int i = 0; i < operations - 1; i++)
    {
        Congruence congA = Congruences[i];
        Congruence congB = Congruences[i+1];
        Congruences[i+1] = Calculate(congA, congB);
    }
    cout << "x === " << Congruences[operations - 1].remainder << " (mod " << Congruences[operations - 1].divider << ")";
    return 0;
}