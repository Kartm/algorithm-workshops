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
                //cout << "Node " << currentNode << " neighbor " << neighborNode << " ";
                int newDistance = distanceFromSource[currentNode] + Graph[currentNode][i].second;
                if(distanceFromSource[neighborNode] > newDistance || distanceFromSource[neighborNode] == -1)
                {
                    if(!visited[neighborNode])
                    {
                        distanceFromSource[neighborNode] = newDistance;
                        neighbor.first = newDistance * (-1);
                        //cout << "UNVISITED, Previous of node " << neighborNode << " is: " << currentNode;
                        previous[neighborNode] = currentNode;
                        theOrder.push(neighbor);
                    }
                }
                //cout << "\n";
            }
        }
        //cout << "\n\n";
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
    vector<int> previous = uno.second;
    int maxDifference = 0;

    for(int i = 1; i <= nodes; i++) //getting every connection of two nodes
    {
        vector<int> distances = uno.first;
        int originalDistance = distances[nodes];

        int nodeA = i;
        int nodeB = previous[i];

        int nodeAindex = -1;
        int nodeBindex = -1;
        for(int j = 0; j < Graph[nodeA].size(); j++)
        {
            if(Graph[nodeA][j].first == nodeB)
            {
                nodeBindex = j;
                //cout << i << " neighbor " << Graph[nodeA][j].first << " Index is " << j << "\n";
            }
        }
        for(int j = 0; j < Graph[nodeB].size(); j++)
        {
            if(Graph[nodeB][j].first == nodeA)
            {
                nodeAindex = j;
                //cout << i << " neighbor " << Graph[nodeB][j].first << " Index is " << j << "\n";
            }
        }
        //int originalCost = Graph[nodeA][nodeBindex].second;
        Graph[nodeA][nodeBindex].second *= 2;
        Graph[nodeB][nodeAindex].second *= 2;
        uno = Dijkstra(Graph, nodes, cost, 1);

        int newDistance = distances[nodes];
        if(newDistance > maxDifference)
            maxDifference = newDistance;
        
        Graph[nodeA][nodeBindex].second /= 2;
        Graph[nodeB][nodeAindex].second /= 2;
        cout << i << " -> " << previous[i] << "\n";
    }
    cout << "MAX " << maxDifference;
    return 0;
    /*
    for(int i = nodes; i > 1 ; i = previous[i]) //getting every connection of two nodes
    {
        cout << i << " -> " << previous[i] << "\n";
    }

    4 5
    1 3 5
    1 2 1
    2 3 2
    2 4 1
    3 4 2
    */
}