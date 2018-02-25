#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int fragmentsAmount;
    cin >> fragmentsAmount;
    vector<int> prefixes (fragmentsAmount);
    prefixes[0] = 0;
    
    for(int i = 1; i <= fragmentsAmount; i++)
    {
        int input; cin >> input;
        prefixes[i] = input;
        prefixes[i] += prefixes[i-1];
    }

    int questions;
    cin >> questions;
    for(int i = 0; i < questions; i++)
    {
        int input; cin >> input;
        for(int j = 1; j <= fragmentsAmount; j++)
        {
            if(input <= prefixes[j])
            {
                cout << j << "\n";
                break;
            }
        }
    }
    
    return 0;
}