#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void DFS(int currentNode, vector<vector<int> > &Graph, vector<bool> &visited, vector<int> &in, vector<int> &out)
{
    visited

    for(int i = 1; i <= nodes; i++)
    {
        cout << "Node " << i << " in: " << in[i] << ", out: " << out[i] << "\n";
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int> > Graph (nodes + 1);
    for(int i = 0; i < edges; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        Graph[nodeA].push_back(nodeB);
    }

    vector<int> in (nodes + 1);
    vector<int> out (nodes + 1);
    vector<bool> visited (nodes + 1, false);
    DFS(1, Graph, visited, in, out);
    
    return 0;
}