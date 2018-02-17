#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int Find(int node, vector<int> &representative)
{
    if(representative[node] == node)
        return node;
    
    representative[node] = Find(representative[node], representative);
    return representative[node];
}

void Union(int nodeA, int nodeB, vector<int> &representative)
{
    int aRoot = Find(nodeA, representative);
    int bRoot = Find(nodeB, representative);
    if(aRoot == bRoot)
        return;
    representative[aRoot] = bRoot;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodes, edges, events;
    cin >> nodes >> edges >> events;
    vector<int> representative (nodes + 1, -1);

    for(int i = 1; i <= nodes; i++)
    {
        representative[i] = i;
    }

    for(int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b, representative);
    }


    /*for(int i = 1; i <= nodes; i++)
    {
        cout << "Representative of node" << i << " is " << representative[i] << "\n";
    }*/

    for(int i = 0; i < events; i++)
    {
        int a, b, type;
        cin >> type >> a >> b;
        switch(type)
        {
            case 0: //* find
            {
                if(Find(a, representative) == Find(b, representative))
                    cout << "TAK\n";
                else
                    cout << "NIE\n"; 
                break;
            }
            case 1: //* union
            {
                Union(a, b, representative);
                break;
            }
        }
    }
    return 0;
}