#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;
/*
7 7
1 2 1
2 3 2
3 4 1
4 5 1
4 7 5
5 6 1
6 7 1
*/
int main()
{
    cout << "[nodes amount] [edges amount]: ";
    int nodes; cin >> nodes;
    int edges; cin >> edges;

    vector<pair<int, vector<int>> > Graph(nodes + 1);
    for(int i = 0; i < edges; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Graph[a].first = c;
        Graph[a].second.push_back(b);
    }

    int startNode = 1;
    vector<int> distanceFromSource(nodes + 1, -1);
    distanceFromSource[startNode] = 0;
    priority_queue<pair<int, int> > priority;
    for(int i = 1; i <= nodes; i++)
    {
        if(i == startNode)
            priority.push(make_pair(startNode, 0));
        else
            priority.push(make_pair(i, -1));
    }
    while(!priority.empty())
    {
        pair<int, int> currentPair = priority.top();
        int currentNode = currentPair.first; //node's number
        int currentNodeDistance = currentPair.second * (-1);
        cout << "Current node " << currentNode << "\n";
        priority.pop();
        for(int i = 0; i < Graph[currentNode].second.size(); i++) //loop through all neighbors
        {
            int currentNeighbor = Graph[currentNode].second[i];
            int newDistance = distanceFromSource[currentNode] + currentNodeDistance;
            if(currentNodeDistance < distanceFromSource[currentNeighbor])
            {
                distanceFromSource[currentNeighbor] = newDistance;
                currentPair.first = newDistance * (-1);
                priority.push(currentPair);
                cout << "TEST13\n";
            }
        }
    }
    return 0;
}