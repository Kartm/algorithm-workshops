#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;
/*
6 5
1 2
1 3
2 4
3 5
3 6
*/

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int> > Graph (nodes + 1);

    queue<int> theOrder;
    for(int j = 0; j < edges; j++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        Graph[nodeA].push_back(nodeB);
    }


    return 0;
}