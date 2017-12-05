#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int arr[1000];
void PrintBack(int arr[], int lastIndex)
{
    for(int i = 0; i < lastIndex; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int operations; cin >> operations;
    int lastIndex = 0;
    for(int i = 0; i < operations; i++)
    {
        int input; cin >> input;
        switch(input)
        {
            case 0:
                PrintBack(arr, lastIndex);
            break;
            case 1:
                int number; cin >> number;
                arr[lastIndex] = number;
                lastIndex++;
            break;
        }
    }
    return 0;
}