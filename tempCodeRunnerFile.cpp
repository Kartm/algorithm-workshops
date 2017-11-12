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
    vector<int> previousNode (nodes + 1, -1);
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
    priority_queue<pair<int, int> > orderQueue;
    orderQueue.push(make_pair(0, source));
    while(!orderQueue.empty())
    {
        pair<int, int> currentElement = orderQueue.top();
        int currentCost = (-1) * currentElement.first;
        int currentNode = currentElement.second;
        cout << "C" << currentCost << " N" << currentNode << "\n";
        //find the cheapest neighbor
        for(int i = 0; i < graph[currentNode].size(); i++)
        {
            cout << "dupa " << i << endl;
            int costToNeighbor = graph[currentNode][i].second;
            int newDistance = distanceFromSource[currentNode] + costToNeighbor;
            if(newDistance < distanceFromSource[i] || distanceFromSource[i] == -1)
            {
                //updating neighbor's cost
                distanceFromSource[i] = newDistance;
                previousNode[i] = currentNode;
                //adding the neighbor to the queue
                if(!visited[i])
                    orderQueue.push(make_pair(newDistance * (-1), i));
            }
        }
        visited[currentNode] = true;
        orderQueue.pop();
    }

    cout << "The cheapest costs to nodes from source: " << endl;
    for(int i = 1; i <= nodes; i++)
    {
        cout << "Node " << i << ": cost = " << distanceFromSource[i] << endl;
    }

    return 0;
}
