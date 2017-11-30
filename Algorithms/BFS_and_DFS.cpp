#include <queue>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

/*
10 10
1 2
1 3
1 4
3 5
4 6
6 7
7 8
8 9
9 10
10 8
1
*/

void BFS(const vector<vector<int> > &graph, int nodes, int edges)
{
	vector<bool> visited(nodes + 1, false);
	queue<int> theOrder;
	theOrder.push(1);
	while(!theOrder.empty())
	{
		int currentNode = theOrder.front();
		cout << "Current node: " << currentNode << "\n";
		theOrder.pop();
		visited[currentNode] = true;
		//cout << "Amount of " << currentNode << " neighbors: " << graph[currentNode].size() << "[" << graph[currentNode].empty() << "]" << endl;
		for(int i = 0; i < graph[currentNode].size(); i++)
		{
			int currentNeighbor = graph[currentNode][i];
			if(!visited[currentNeighbor])
			{
				theOrder.push(currentNeighbor);
			}
		}
	}
}

void RecursiveDFS(vector<vector<int> > graph, vector<bool> visited, int node)
{
	cout << "Current node: " << node << "\n";
	visited[node] = true;
	for(int i = 0; i < graph[node].size(); i++)
	{
		int currentNeighbor = graph[node][i];
		if(!visited[currentNeighbor])
			RecursiveDFS(graph, visited, currentNeighbor);
	}
}

void DFS(const vector<vector<int> > &graph, int nodes, int edges)
{
	vector<bool> visited(nodes + 1, false);
	RecursiveDFS(graph, visited, 1);
}


int main()
{
	cout << "[nodes amount] [edges amount]: ";
	int nodes; cin >> nodes; //wprowadzamy wierzcholki
	int edges; cin >> edges;
	vector<vector<int> > Graph(nodes + 1, vector<int>{});
	cout << "Enter the nodes [a] [b]: \n";
	for (int i = 0; i < edges; i++)
	{
		int a; cin >> a;
		int b; cin >> b;
		Graph[a].push_back(b);
	}
	cout << "\n[0] for BFS, [1] for recursive DFS: ";
	int choice; cin >> choice;
	if (choice == 0)
		BFS(Graph, nodes, edges);
	else
		DFS(Graph, nodes, edges);
    return 0;
}
