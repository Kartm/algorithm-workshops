#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

bool IsContaining(queue<int> queue, int integer)
{
    while(!queue.empty())
    {
        if(integer == queue.front())
            return true;
        queue.pop();
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int> > Graph (nodes + 1);
    vector<int> incoming (nodes + 1, 0);
    for(int i = 0; i < edges; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        Graph[nodeA].push_back(nodeB);
        incoming[nodeB]++;
    }

    queue<int> order;
    for(int i = 0; i < nodes; i++)
        if(incoming[i] == 0)
            order.push(i);

    for(int i = 0; i < nodes; i++)
    {
        int number; cin >> number;
        if(incoming[number] == 0) //OK
        {
            for(int j = 0; j < Graph[number].size(); j++)
            {
                incoming[Graph[number][j]]--;
            }
        }
        else //NOT FUCKING OK
        {
            cout << number;
            return 0;
        }
    }

    cout << "OK";
    return 0;
}