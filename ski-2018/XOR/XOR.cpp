#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printVector(vector<int> V)
{
    for(int i = 1; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }
    cout << "\n";
    return;
}

int main()
{
    //cin.tie(0);
    //cout.tie(0);
    //ios_base::sync_with_stdio(0);
    int n; cin >> n; //dlugosc tablicy
    int m; cin >> m; //ilosc podpowiedzi
    
    vector<int> V (n+1);
    priority_queue<pair<pair<int, int>, int> > Q; //*<<length,start>, x>

    for(int i = 0; i < m; i++)
    {
        int a; cin >> a; //od pozycji a
        int b; cin >> b; //do pozycji b
        int x; cin >> x; //wynik to x
        Q.push(make_pair(make_pair(b-a, a), x));
    }

    //!w poleceniu liczymy od 1
    while(!Q.empty())
    {
        printVector(V);
        int start = Q.top().first.second;
        int length = Q.top().first.first;
        int x = Q.top().second;
        Q.pop();
        if(length == 0) 
        {
            V[start] = x;
        }
        else
        {
            
        }
    }

    return 0;
}