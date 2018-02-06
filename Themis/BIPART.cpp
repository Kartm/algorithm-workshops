#include <vector>
#include <iostream>

using namespace std;

void DFS(int currentNode, vector<vector<int> > &Graph, vector<bool> &visited, vector<short> &color, bool &state)
{
    visited[currentNode] = true;
    for(int i = 0; i < Graph[currentNode].size(); i++)
    {
        int currentNeighbor = Graph[currentNode][i];
        if(color[currentNode] == color[currentNeighbor])
        {
            state = false;
            return;
        }
        else
            color[currentNeighbor] = color[currentNode] * (-1);

        if(!visited[currentNeighbor])
            DFS(currentNeighbor, Graph, visited, color, state);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tests; cin >> tests;
    for(int test = 0; test < tests; test++)
    {
        int nodes, edges;
        cin >> nodes >> edges;
        vector<vector<int> > Graph (nodes + 1);
        vector<bool> visited (nodes + 1, false); 
        vector<short> color (nodes + 1, 0);
        for(int i = 0; i < edges; i++)
        {
            int a, b;
            cin >> a >> b;
            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }

        bool state = true;
        
        for(int i = 0; i < nodes; i++)
        {
            if(!visited[i])
            {
                color[i] = 1;
                DFS(i, Graph, visited, color, state);
            }
        }
        //color[1] = 1;
        //DFS(1, Graph, visited, color, state);

        if(state)
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }

}