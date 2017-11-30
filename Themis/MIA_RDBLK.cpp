#include <queue>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

pair<vector<int>, vector<int> > Dijkstra(vector<vector<pair<int, int> > > &Graph, int nodes, int edges, int startNode)
{
    vector<int> distanceFromSource (nodes + 1, -1);
    distanceFromSource[startNode] = 0;
    vector<bool> visited (nodes + 1, false);
    vector<int> previous (nodes + 1, -1);
    priority_queue<pair<int, int> > theOrder;
    theOrder.push(make_pair(0, startNode));
    while(!theOrder.empty())
    {
        pair<int, int> current = theOrder.top();
        theOrder.pop();
        int currentNode = current.second;
        int currentCost = current.first * (-1);
        if(!visited[currentNode])
        {
            visited[currentNode] = true;
            for(int i = 0; i < Graph[currentNode].size(); i++)
            {
                pair<int, int> neighbor = make_pair(Graph[currentNode][i].second, Graph[currentNode][i].first);
                int neighborCost = neighbor.first * (-1);
                int neighborNode = neighbor.second;
                int newDistance = distanceFromSource[currentNode] + Graph[currentNode][i].second;
                if(distanceFromSource[neighborNode] > newDistance || distanceFromSource[neighborNode] == -1)
                {
                    if(!visited[neighborNode])
                    {
                        distanceFromSource[neighborNode] = newDistance;
                        neighbor.first = newDistance * (-1);
                        previous[neighborNode] = currentNode;
                        theOrder.push(neighbor);
                    }
                }
            }
        }
    }
    return make_pair(distanceFromSource, previous);
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<pair<int, int> > > Graph(nodes + 1);
    int nodeA, nodeB, cost;
    for(int i = 0; i < edges; i++)
    {
        cin >> nodeA >> nodeB >> cost;
        Graph[nodeA].push_back(make_pair(nodeB, cost));
        Graph[nodeB].push_back(make_pair(nodeA, cost));
    }

    //Using Dijkstra's algorithm for the first time
    pair<vector<int>, vector<int> > uno = Dijkstra(Graph, nodes, cost, 1);

    int N = nodes; //N
    vector<int> previous = uno.first;
    vector<int> path = uno.second;
    int originalDistance = path[N];
    int originalN = N;
    while(N > 0)
    {
        cout << N << " ";
        N = previous[N];
    }
    return 0;
}