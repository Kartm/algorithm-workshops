#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

struct Square
{
    int x;
    int y;
    int height;
}

void Flood(int posX, int posY, vector<vector<pair<int, bool> > > &Graph, int &remaining, priority_queue<pair<int, bool> &Queue)
{
    //* is flooded
    if(!Graph[posX][posY].second)
    {
        priority_queue<pai
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int width, height, posX, posY, minimum;
    cin >> width >> height >> posX >> posY >> minimum;
    vector<vector<pair<int, bool> > > Graph (height + 1, vector<pair<int, bool> > (width + 1));
    priority_queue<pair<int, bool> Queue;
    //<height, isFlooded>
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int input; cin >> input;
            Graph[i][j].first = input;
        }
    }

    int remaining = minimum;
    while(remaining > 0)
    {
        Flood(posX, posY, Graph, remaining, Queue);
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if()//! tutaj
            Graph[i][j].push_back(input);
        }
    }

    return 0;
}