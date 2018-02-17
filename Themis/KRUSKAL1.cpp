#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int Find(int node, vector<int> &representative)
{
    if(representative[node] == node)
        return node;

    representative[node] = Find(representative[node], representative);
    return representative[node];
}

void Union(int nodeA, int nodeB, vector<int> &representative)
{
    int rootA = Find(nodeA, representative);
    int rootB = Find(nodeB, representative);
    if(rootA == rootB)
        return;
    representative[rootA] = rootB;
}

bool IsCycle(int nodeA, int nodeB, vector<int> &representative)
{
    if(Find(nodeA, representative) == Find(nodeB, representative))
        return true;
    return false;
}

struct Edge
{
    int cost;
    int index;
    int nodeA;
    int nodeB;
};

struct Compare
{
    bool operator()(const Edge &a, const Edge &b)
    {
        if(a.cost != b.cost)
            return a.cost > b.cost;
        else
            return a.index > b.index;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> representative (nodes + 1, -1);
    vector<vector<pair<int, int> > > Graph (nodes + 1);
    for(int i = 1; i <= nodes; i++)
    {
        representative[i] = i;
    }    
    
    priority_queue<Edge, vector<Edge>, Compare> Queue;
    for(int i = 0; i < edges; i++)
    {
        int nodeA, nodeB, cost;
        cin >> nodeA >> nodeB >> cost;

        Edge edge;
        edge.nodeA = nodeA;
        edge.nodeB = nodeB;
        edge.cost = cost;
        edge.index = i + 1;
        Queue.push(edge);
    }

    while(!Queue.empty())
    {
        Edge currentEdge = Queue.top();
        Queue.pop();

        int nodeA = currentEdge.nodeA;
        int nodeB = currentEdge.nodeB;
        int cost = currentEdge.cost;
        //cout << "NOW: " << nodeA << " with " << nodeB << ", cost " << cost << "\n";

        if(!IsCycle(nodeA, nodeB, representative))
        {
            cout << currentEdge.index << "\n";
            //cout << nodeA << " not forming cycle with " << nodeB << "\n";
            Graph[nodeA].push_back(make_pair(nodeB, cost));
            Graph[nodeB].push_back(make_pair(nodeA, cost));
            Union(nodeA, nodeB, representative);
        }
    }
    return 0;
}