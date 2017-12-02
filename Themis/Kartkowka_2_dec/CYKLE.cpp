#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;
/*
6 5
1 2
1 3
2 4
3 5
3 6
*/

void Test()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int> > Graph (nodes + 1);
    for(int j = 0; j < edges; j++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        Graph[nodeA].push_back(nodeB);
        Graph[nodeB].push_back(nodeA);
    }

    vector<bool> visited (nodes + 1, false);
    vector<int> previous (nodes + 1, -1);
    for(int k = 1; k <= nodes; k++)
    {
        if(visited[k] == false)
        {
            stack<int> order;
            order.push(k);

            while(!order.empty())
            {
                int current = order.top();
                order.pop();
                visited[current] = true;
                for(int j = 0; j < Graph[current].size(); j++)
                {
                    int neighbor = Graph[current][j];
                    previous[neighbor] = current;
                    if(!visited[neighbor])
                    {
                        order.push(neighbor);
                    }
                    else if (previous[previous[neighbor]] == neighbor)
                    {
                        cout << "TAK"; //cykl
                        return;
                    }
                }
            }
        }
    }
    cout << "NIE";
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int tests; cin >> tests;
    for(int i = 0; i < tests; i++)
    {
        //cout << "TEST LOOP";
        Test();
    }
    return 0;
}