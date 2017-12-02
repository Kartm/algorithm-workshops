#include <iostream>
#include <cstdlib>

using namespace std;

bool visited[1000000]; //default is false

void DFS(int node)
{
    visited[node] = true;
    for(int i = 0; i < Graph[node].size(); i++)
    {
        int neighbor = Graph[node][i];
        if(!visited[neighbor])
        {
            DFS(neighbor;)
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}