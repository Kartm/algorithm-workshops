#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <utility>
#include <climits>

using namespace std;

void Symmetry(vector<vector<int> > &arr, int width, int height)
{
    
}

pair<int, int> BiggestSmallest(vector<vector<int> > &arr, int width, int height)
{
    int smallest = INT_MAX;
    int biggest = 0;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(arr[i][j] < smallest)
            {
                smallest = arr[i][j];
            }
            else if (arr[i][j] > biggest)
            {
                biggest = arr[i][j];
            }
        }
    }
    return make_pair(smallest, biggest);
}

int main()
{
    fstream file;
    file.open("dane.txt", ios::in);
    const int height = 200;
    const int width = 320;
    if(file.good())
    {
        vector<vector<int> > arr (height, vector<int> (width));
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                file >> arr[i][j];
            }
        }
        pair<int, int> first = BiggestSmallest(arr, width, height);

        cout << "smallest " << first.first << ", biggest " << first.second << "\n";
        cout << "minimal " << Symmetry(arr, width, height) << "\n";
    }
    
    return 0;
}