#include <vector>
#include <iostream>

using namespace std;

int visitedCounter = 0;

void DFS(int node, int previous, vector<vector<int> > &Graph, vector<bool> &visited, int movesLeft)
{
    if(movesLeft + 1 == visitedCounter) return;
    visited[node] = true;
    for(int i = 0; i < Graph[node].size(); i++)
    {
        int neighbor = Graph[node][i];
        if(!visited[neighbor])
        {
            visitedCounter++;
            DFS(neighbor, node, Graph, visited, movesLeft);
        }
    }
}

int main()
{
    int nodes; cin >> nodes;
    int edges = nodes - 1;
    vector<vector<int> > Graph (nodes + 1);
    for(int i = 0; i < edges; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        Graph[nodeA].push_back(nodeB);
        Graph[nodeB].push_back(nodeA);
    }
    int steps; cin >> steps;

    vector<bool> visited (nodes + 1, false);
    DFS(1, -1, Graph, visited, steps);
    cout << visitedCounter;

}