#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;

void DFS(int node, int previous, vector<vector<int> > &Graph, vector<bool> &visited)
{
    visited[node] = true;
    cout << "Now node " << node << "\n";
    for(int i = 0; i < Graph[node].size(); i++)
    {
        int neighbor = Graph[node][i];
        if(!visited[neighbor])
        {
            DFS(neighbor, node, Graph, visited);
        }
    }
}

void Test()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int> > Graph (nodes + 1);
    for(int j = 0; j < edges; j++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        Graph[nodeA].push_back(nodeB);
        Graph[nodeB].push_back(nodeA);
    }

    vector<bool> visited (nodes + 1, false);
    DFS(1, -1, Graph, visited);
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int tests; cin >> tests;
    for(int i = 0; i < tests; i++)
    {
        //cout << "TEST LOOP";
        Test();
    }
    return 0;
}