#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

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
    while (a != b)
    {
        i++;
        if(a > b)
        {
            b = congB.remainder + (congB.divider * i);
        }
        else
        {
            a = congA.remainder + (congA.divider * i);
        }
    }
    congC.remainder = a;
    congC.divider = congA.divider * congB.divider;
    return congC;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cout << "Operations: ";
    int operations; cin >> operations;
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
        Congruence congC = Calculate(congA, congB);
        cout << "x --- " << congC.remainder << " (mod " << congC.divider << ")";
    }
    return 0;
}