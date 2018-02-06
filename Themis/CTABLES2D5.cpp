#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size; cin >> size;
    int diagonalAmount = 2 * size - 1;
    vector<vector<int> > Matrix (size + 1, vector<int> (size + 1));
    vector<int> Diagonals (diagonalAmount + 1, 0);

    for(int i = 0; i < size; i++) //row
    {
        for(int j = 0; j < size; j++) //column
        {
            int input; cin >> input;
            Matrix[i][j] = input;
            Diagonals[i+j] += input;
        }
    }

    int largestDiagonalValue = -1;
    int largestDiagonal = -1;
    for(int i = 0; i < diagonalAmount; i++)
    {
        //cout << "Diagonal " << i + 1 << " size: " << Diagonals[i] << "\n";
        if(Diagonals[i] > largestDiagonalValue)
        {
            largestDiagonal = i;
            largestDiagonalValue = Diagonals[i];
        }
            
    }

    cout << largestDiagonal + 1 << ": ";
    
    int coordinate = (largestDiagonal / 2);

    for(int i = 0; i < size; i++) //row
    {
        for(int j = 0; j < size; j++) //column
        {
            if(i + j == largestDiagonal)
                cout << Matrix[i][j] << " ";
        }
    }
    return 0;
}