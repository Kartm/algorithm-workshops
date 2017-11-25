#include "stdafx.h"
#include <queue>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

void BFS(vector<vector<int> > &graph, int nodes, int edges)
{
	vector<bool> visited(nodes + 1, false);
}

void DFS(vector<vector<int> > &graph, int nodes, int edges)
{
	return;
}


int main()
{
	cout << "[nodes amount] [edges amount]: ";
	int nodes; cin >> nodes; //wprowadzamy wierzcho³ki
	int edges; cin >> edges;
	vector<vector<int> > Graph(edges + 1);
	cout << "Enter the nodes [a] [b]: \n";
	for (int i = 0; i < edges; i++)
	{
		int a; cin >> a;
		int b; cin >> b;
		//Graph[a].push_back(b);
	}
	cout << "\n [0] for BFS, [1] for DFS: ";
	int choice; cin >> choice;
	if (choice == 0)
		BFS(Graph, nodes, edges);
	else
		DFS(Graph, nodes, edges);

    return 0;
}
