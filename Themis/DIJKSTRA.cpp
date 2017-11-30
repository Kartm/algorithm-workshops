#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int nodes; cin >> nodes;
    int edges; cin >> edges;

    vector<vector<pair<int, int> > > Graph(nodes + 1);
    for(int i = 0; i < edges; i++)
    {
        int nodeA, nodeB, cost;
        cin >> nodeA >> nodeB >> cost;
        Graph[nodeA].push_back(make_pair(nodeB, cost));
        Graph[nodeB].push_back(make_pair(nodeA, cost));
    }

    vector<int> distanceFromSource(nodes + 1, -1);
    priority_queue<pair<int, int> > theOrder;
    vector<bool> visited (nodes + 1, false);
    
    distanceFromSource[1] = 0;
    theOrder.push(make_pair(0, 1));

    while(!theOrder.empty())
    {
        pair<int, int> current = theOrder.top();
        theOrder.pop();
        int currentNode = current.second;
        int currentCost = current.first;
        
        if(!visited[currentNode])
        {
            visited[currentNode] = true;
            for(int i = 0; i < Graph[currentNode].size(); i++)
            {
                pair<int, int> neighbor = make_pair(Graph[currentNode][i].second, Graph[currentNode][i].first);
                int neighborNode = neighbor.second;
                int neighborCost = neighbor.first * (-1);
                int newDistance = distanceFromSource[currentNode] + (Graph[currentNode][i].second);
                if(distanceFromSource[neighborNode] > newDistance || distanceFromSource[neighborNode] == -1)
                {
                    if(!visited[currentNode])
                    {
                        distanceFromSource[neighborNode] = newDistance;
                        neighbor.first = newDistance * (-1);
                        theOrder.push(neighbor);
                    }
                }
            }
        }
    }

    for(int i = 2; i <= nodes; i++)
        cout << distanceFromSource[i] << " ";

    return 0;
}

5 6
1 2 1
1 3 4
2 4 3
3 4 8
2 5 1
4 5 9