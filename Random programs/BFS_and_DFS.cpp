//#include "stdafx.h"
#include <queue>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

void PrintQueue(queue<int> foo)
{
	cout << "QUEUE: ";
	while(!foo.empty())
	{
		cout << foo.front() << " ";
		foo.pop();
	}
	cout << "\n";
}

void BFS(vector<vector<int> > graph, int nodes, int edges)
{
	vector<bool> visited(nodes + 1, false);
	queue<int> theOrder;
	theOrder.push(1); //assuming that there is node '1'
	while(!theOrder.empty())
	{
		PrintQueue(theOrder);
		int currentNode = theOrder.front();
		theOrder.pop(); //not this
		if(!visited[currentNode]){
			cout << " unvisited,";
			if(!graph[currentNode].empty())
			{
				cout << " neighbors: ";
				for(int i = 0; i < graph[currentNode].size(); i++)
				{
					int currentNeighbor = graph[currentNode][i];

					int foo = (visited[currentNeighbor]) ? 1 : 0;
					cout << currentNeighbor << "[v" << foo << "] ";
					if(!visited[currentNeighbor])
						theOrder.push(currentNeighbor);
				}
			}
		}
		cout << "\n";
		visited[currentNode] = true;
	}
}

void DFS(vector<vector<int> > &graph, int nodes, int edges)
{
	return;
}


int main()
{
	cout << "[nodes amount] [edges amount]: ";
	int nodes; cin >> nodes;
	int edges; cin >> edges;
	vector<vector<int> > Graph(edges + 1);
	cout << "Enter the nodes [a] [b]: \n";
	for (int i = 0; i < edges; i++)
	{
		int a; cin >> a;
		int b; cin >> b;
		Graph[a].push_back(b);
	}
	cout << "\n [0] for BFS, [1] for DFS: ";
	int choice; cin >> choice;
	if (choice == 0)
		BFS(Graph, nodes, edges);
	else
		DFS(Graph, nodes, edges);

    return 0;
}

