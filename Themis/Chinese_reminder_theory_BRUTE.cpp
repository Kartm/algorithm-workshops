#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Congruence Calculate(Congruence a, Congruence b)
{
    
}

struct Congruence //x ≡ y (mod n)
{
    int y;
    int n;
};

int main()
{
    int amount; cin >> amount; //amount of congruences
    amount = 2;
    vector<Congruence> Vec (2);
    for(int i = 0; i < amount; i++)
    {
        cin >> Vec[i].y >> Vec[i].n;
    }
    return 0;
}