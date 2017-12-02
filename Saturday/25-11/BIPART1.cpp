#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;
/*
7 7
1 2
2 3
3 1
4 5
5 6
6 7
7 4
*/

int FirstUnvisited(vector<bool> vec)
{
    for(int i = 1; i < vec.size(); i++)
        if(!vec[i]) //if unvisited
            return i;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int> > Graph(nodes + 1);
    for(int i = 0; i < edges; i++)
    {
        int a, b; cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    //BFS until the whole graph is visited
    //nodes - the last node
    vector<bool> visited(nodes + 1, false);

    while(!visited[nodes])
    {
        queue<int> theOrder;
        theOrder.push(FirstUnvisited(visited));

        int loopLength = 0;
        bool isCycle = false;
        while(!theOrder.empty())
        {
            int currentElement = theOrder.front();
            if(visited[currentElement]) //if it's already visited, then it is a cycle
            {
                cout << "LOOP!\n";
                isCycle = true;
                break;
            }
            loopLength++;
            visited[currentElement] = true;
            theOrder.pop();
            for(int i = 0; i < Graph[currentElement].size(); i++)
            {
                int currentNeighbor = Graph[currentElement][i];
                if(!visited[currentNeighbor])
                    theOrder.push(currentNeighbor);
            }
        }
        cout << "Loop length: " << loopLength;
        if(isCycle && loopLength % 2 == 1)
        {
            cout << "NIE";
            break;
        }
        if(!isCycle)
        {
            cout << "TAK";
        }
    }
    return 0;
}