#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    cout << "Set the amount of nodes: ";
    int nodes; cin >> nodes;
    cout << "Set the amount of edges: ";
    int edges; cin >> edges;
    vector<vector<pair<int, int> > > graph (nodes + 1);
    vector<int> distanceFromSource (nodes + 1, -1);
    vector<bool> visited (nodes + 1, false);

    cout << "Enter the nodes. [node] [neighbor] [cost] e. g. \"1 3 5\": \n";
    for(int i = 0; i < edges; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back(make_pair(b, cost));
        graph[b].push_back(make_pair(a, cost));
    }
    cout << "\nEnter the source node: ";
    int source; cin >> source;

    ///Now the Dijkstra is coming
    distanceFromSource[source] = 0;
    priority_queue<pair<int, int> > theOrder;
    theOrder.push(make_pair((-1) * distanceFromSource[source], source));
    while(!theOrder.empty())
    {
        pair<int, int> currentQueueElement = theOrder.top();
        int currentNode = currentQueueElement.second;
        int currentCost = currentQueueElement.first;

        ///get the minimum
    }

    return 0;
}
