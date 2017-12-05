#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int> > Graph (nodes + 1);
    vector<int> intoAmount (nodes + 1, 0);
    for(int j = 0; j < edges; j++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        Graph[nodeA].push_back(nodeB);
        intoAmount[nodeB]++;
    }

    priority_queue<int> order;
    for(int i = 1; i <= nodes; i++)
        if(intoAmount[i] == 0)
            order.push(i);

    int visitedCounter = 0;
    queue<int> printOrder;
    while(!order.empty())
    {
        int currentNode = order.top();
        visitedCounter++;
        printOrder.push(currentNode);
        order.pop();
        for(int i = 0; i < Graph[currentNode].size(); i++) //his children
        {
            intoAmount[Graph[currentNode][i]]--;
            if(intoAmount[Graph[currentNode][i]] == 0)
                order.push(Graph[currentNode][i]);
        }
        Graph[currentNode].clear();
    }

    if(visitedCounter == nodes)
    {
        while(!printOrder.empty())
        {
            cout << printOrder.front() << " ";
            printOrder.pop();
        }
    }
    else
        cout << "NIE";
    return 0;
}