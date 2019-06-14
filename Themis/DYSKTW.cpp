#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void Find(int current, int &nextFree, int &sectors, vector<bool> &filled, bool &areThereFree)
{
    if(filled[nextFree])
    {
        cout << "NIE\n";
    }
    if(!filled[current])
    {
        cout << current << "\n";
        return;
    }
    else if (current + 1 <= sectors)
    {
        Find(current + 1, sectors, filled, areThereFree);
    }
    else
    {
        cout << "NIE\n";
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sectors;
    cin >> sectors;
    vector<bool> filled (sectors + 1, false);
    vector<int> nextFreeArr (sectors + 1, false);

    for(int i = 0; i < sectors; i++)
    {
        int input;
        cin >> input;

        bool areThereFree = false;
        filled[input] = true;
        
        Find(input, sectors, filled, areThereFree);
    }
    return 0;
}