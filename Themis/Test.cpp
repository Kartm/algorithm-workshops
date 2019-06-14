#include <iostream>
#include <vector>
#include <stack>
#define stala 100000
using namespace std;
int wierzcholki,krawedzie,mn;
//int ostatniWierzcholek;
bool odwiedzony[stala];

void DFS(vector<vector<int> >vec)
{
    stack <int>sztos;
    sztos.push(mn);
    while(!sztos.empty())
    {
        int w = sztos.top();
        cout << w << " ";
        sztos.pop();
        if(!odwiedzony[w])
        {
            for(int i=0; i<vec[w].size(); i++)
            {
                if(!odwiedzony[vec[w][i]])
                    sztos.push(vec[w][i]);
            }
        }
        odwiedzony[w] = true;
    }

}

int main()
{
    ios::sync_with_stdio(false);

    cin>>wierzcholki>>krawedzie;
    vector<vector<int> >vec(wierzcholki+1);

    for(int i=0; i<krawedzie; i++)
    {

        int a=0,b=0;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
        mn = a;
        //ostatniWierzcholek = b;
    }

    for(int i=1; i< wierzcholki + 1; i++)
    {
        if(!odwiedzony[i])
            DFS(vec);
    }


    return 0;
}
