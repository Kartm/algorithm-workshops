#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    cout << "Set the amount of nodes: ";
    int nodes; cin >> nodes;
    cout << "Set the amount of edges: ";
    int edges; cin >> edges;
    vector<vector<pair<int, int> > > graph (nodes + 1);
    cout << "Enter the nodes. [node] [neighbor] [cost] e. g. \"1 3 5\": \n";
    for(int i = 0; i < edges; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back(make_pair(b, cost));
        graph[b].push_back(make_pair(a, cost));
    }

    return 0;
}
