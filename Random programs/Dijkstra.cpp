#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;
/*
8 11
1 2 1
2 3 2
2 4 4
3 5 1
3 4 2
3 6 1
4 8 8
5 6 1
6 7 6
7 8 10
7 4 3
*/
int main()
{
    cout << "[nodes amount] [edges amount]: ";
    int nodes; cin >> nodes;
    int edges; cin >> edges;

    vector<vector<pair<int, int> > > Graph(nodes + 1);
    for(int i = 0; i < edges; i++)
    {
        int nodeA, nodeB, cost;
        cin >> nodeA >> nodeB >> cost;
        Graph[nodeA].push_back(make_pair(nodeB, cost));
        //cout << "pushing " << nodeA << " " << nodeB << " " << cost << "\n";
    }

    cout << "[start node]: ";
    int startNode; cin >> startNode;
    vector<int> distanceFromSource(nodes + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > theOrder;
    distanceFromSource[startNode] = 0;
    for(int i = 1; i <= nodes; i++)
        if(i == startNode)
            theOrder.push(make_pair(0, startNode));
        else
            theOrder.push(make_pair(-1, i));

    while(!theOrder.empty())
    {
        pair<int, int> parentPair = theOrder.top(); //first is the cost, second is the node
        int parentNode = parentPair.second;
        int parentCost = parentPair.first;
        cout << "Current node " << parentNode << " with cost " << parentCost << "\n";
        theOrder.pop();
        for(int i = 0; i < Graph[parentNode].size(); i++)
        {
            pair<int, int> childPair = Graph[parentNode][i]; //first is the node, second is the cost
            int newDistance = distanceFromSource[parentNode] + childPair.second; //parent node + cost to child from parent
            cout << "Child " << childPair.first << " its cost: " << childPair.second;
            if(childPair.second > newDistance || childPair.second == -1) //if the path is cheaper
            {
                cout << "Deal! ";
                distanceFromSource[childPair.first] = newDistance;
                childPair.second = newDistance;
                theOrder.push(childPair);
            }
            cout << "\n";
        }
    }

    for(int i = 1; i <= nodes; i++)
        cout << "Cost to " << i << " is " << distanceFromSource[i] << "\n";

    return 0;
}