#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

bool visited[1000001];
//memset(visited, 0, (n+1)*sizeof(int));

int FirstUnvisited(int maxNode)
{
    for(int i = 1; i <= maxNode; i++)
        if(!visited[i])
            return i;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int> > Graph(1000001);
    for(int i = 0; i < edges; i++)
    {
        int a, b; cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    while(!visited[nodes]) //while the last node is unvisited
    {
        queue<int> theOrder;
        theOrder.push(FirstUnvisited(nodes));

        int loopLength = 0;
        bool isCycle = false;
        while(!theOrder.empty())
        {
            
        }
    }
    return 0;
}