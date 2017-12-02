#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

/*
6 7
1 3 1
3 6 1
3 5 4
3 4 5
4 7 3
4 5 8
6 5 1
*/

int main()
{
    int nodes; int edges;
    vector<vector<pair<int, int> > > Graph(nodes+1);
    for(int i = 0; i < edges; i++y)
    {
        int nodeA, nodeB, cost;
        cin >> nodeA >> nodeB >> cost;
        Graph[nodeA].push_back(make_pair(nodeB, cost));
    }
    
    priority_queue<int> theOrder;
    int startNode; cin >> startNode;
    return 0;
}