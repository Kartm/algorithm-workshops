#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

/* SAMPLE DATA
4 5
1 3 4
1 2 1
3 2 8
3 4 2
2 4 1
*/

int main()
{
    //ENTERING THE GRAPH
    cout << "[nodes amount] [edges amount]: ";
    int nodes; cin >> nodes;
    int edges; cin >> edges;

    vector<vector<pair<int, int> > > Graph(nodes + 1);
    for(int i = 0; i < edges; i++)
    {
        int nodeA, nodeB, cost;
        cin >> nodeA >> nodeB >> cost;
        Graph[nodeA].push_back(make_pair(nodeB, cost));
    }

    //DIJKSTRA'S ALGORITHM
    cout << "[start node]: ";
    int startNode; cin >> startNode;
    vector<int> distanceFromSource(nodes + 1, -1);
    vector<int> previous(nodes + 1, -1);
    vector<bool> visited(nodes + 1, false);
    distanceFromSource[startNode] = 0;
    priority_queue<pair<int, int> > theOrder;
    
    theOrder.push(make_pair(0, startNode));

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

    //SUMMARY
    for(int i = 1; i <= nodes; i++)
        cout << "Cost to node " << i << " is " << distanceFromSource[i] << "\n";

    //PATH TO THE SELECTED NODE
    cout << "[target node]: ";
    int target; cin >> target;

    stack<int> path;
    path.push(target);
    while(target > 0)
    {
        if(previous[target] > 0)
            path.push(previous[target]);
        target = previous[target];
    }

    while(path.size() > 1)
    {
        cout << path.top() << " -> ";
        path.pop();
    }
    cout << path.top();
    path.pop();

    return 0;
}