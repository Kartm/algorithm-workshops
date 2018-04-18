#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
/*
Dany jest ciąg n liczb. Powiemy, że ten ciąg jest permutacją jeśli zawiera wszystkie liczby od 1 do n. 
Napisz program sprawdzający czy dany ciąg jest permutacją.
*/

bool occurrences[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    int occurencesCounter = 0;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if(occurrences[input] == false)
        {
            occurencesCounter++;
            occurrences[input] = true;
        }
    }

    if(occurencesCounter < n)
    {
        cout << "NIE";
    }
    else
    {
        cout << "TAK";
    }
    
    return 0;
}