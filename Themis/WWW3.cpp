#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
//const int N = 10E5;

int DFS_down(int currentNode, vector<vector<int> > &Graph, int nodes, vector<bool> &visited, vector<int> &childrenAmount)
{
    cout << "DFS at node " << currentNode << "\n";
    visited[currentNode] = true;
    for(int i = 0; i < Graph[currentNode].size(); i++)
    {
        childrenAmount[currentNode]++;
        int neighbor = Graph[currentNode][i];
        if(!visited[neighbor])
        {
            DFS_down(neighbor, Graph, nodes, visited, childrenAmount);
        }
    }
    cout << currentNode << " has " << childrenAmount[currentNode] << " children\n";
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    /*
    7
    1 2
    1 3
    1 4
    4 5
    4 6
    4 7
    */
    int nodes; cin >> nodes;
    int edges = nodes - 1;
    vector<vector<int> > Graph(nodes + 1);
    for(int i = 0; i < edges; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        Graph[nodeA].push_back(nodeB);
    }

    int operations; cin >> operations;
    for(int i = 0; i < operations; i++)
    {
        //DFS, zaczynamy zliczanie od 1 i schodzimy w dol
        vector<bool> visited (nodes + 1, false);
        vector<int> childrenAmount (nodes + 1, 1);
        DFS_down(1, Graph, nodes, visited, childrenAmount);
    }
    return 0;
}