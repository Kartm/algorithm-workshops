#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int vec[1000] = {-1};
    bool set[1000] = {false};
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int input; cin >> input;
        switch(input)
        {
            case 0: //wypisanie calego
                for(int i = 0; i < 1000; i++)
                {
                    if(set[i] == true)
                        cout << vec[i] << " ";
                    else
                        continue;
                }
            break;
            
            case 1: //dodanie liczby
                int number; cin >> number;
                for(int i = 0; i < 1000; i++)
                {
                    if(set[i] == false)
                    {
                        vec[i] = number;
                        continue;
                    } 
                }
            break;
        }
    }
    
    return 0;
}