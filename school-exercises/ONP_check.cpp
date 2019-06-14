#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    string text; cin >> text;
    int count = 0;
    for(int i = 0; i < text.length(); i++)
    {
        if(text[i] > 48 && text[i] < 57) //numbers
        {
            count++;
        }
        else if(text[i] == '+' || text[i] == '-' || text[i] == '*')
        {
            if(count < 2)
            {
                cout << "NOT OK";
                return 0;
            }
            count--;
        }
    }
    if(count == 1)
    {
        cout << "OK";
    }
    else
    {
        cout << "NOT OK";
    }
    return 0;
}