#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;
/*
    a -> n
    97-122
*/

void Caesar(string &input)
{
    for(int i = 0; i < input.length(); i++)
    {
        char current = input[i];
        int modified = (current+13)%122;
        if(modified < 97) modified += 97 - 1;
        input[i] = modified;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string input;
    while(true)
    {
        getline(cin, input);
        if(input[0] == '!')
        {
            break;
        }
        Caesar(input);
        cout << input << "\n";
    }

    
    return 0;
}