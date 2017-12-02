#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int> > Graph (nodes + 1, vector<int>(nodes + 1, 0));
    for(int i = 0; i < edges; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        Graph[nodeA][nodeB] = 1;
        Graph[nodeB][nodeA] = 1;
    }    

    //MACIERZOWA REPREZENTACJA
    cout << "Macierz:\n";
    for(int i = 1; i <= nodes; i++)
    {//wypisywanie kolejno wierszy
        for(int j = 1; j <= nodes; j++)
        {
            cout << Graph[i][j];
        }
        cout << "\n";
    }

    //LISTOWA REPREZENTACJA
    cout << "\nLista:\n";
    for(int i = 1; i <= nodes; i++)
    {//wypisywanie kolejno wierszy
        cout << i << ": ";
        for(int j = 1; j <= nodes; j++)
        {
            if(Graph[i][j] == 1)
                cout << j << " ";
        }
        cout << "\n";
    }
    /*
    4 5
    1 2
    1 3
    2 3
    2 4
    3 4
    */
    return 0;
}