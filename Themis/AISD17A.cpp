#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    /*
    3 4
    ABEB
    EBAF
    AADF
    */
    int height, width;
    cin >> height >> width;
    int nodes = height * width;
    vector<vector<char> > CharGraph (height + 1, vector<char> (width + 1));
    vector<vector<int> > Graph (nodes + 1);
    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= width; j++)
        {
            char input; cin >> input;
            CharGraph[i][j] = input;
        }
    }
    
    cout << "\n\n";
    //DISPLAY THE GRAPH
    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= width; j++)
        {
            cout << CharGraph[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";

    //TRAVERSAL
    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= width; j++)
        {
            cout << CharGraph[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}