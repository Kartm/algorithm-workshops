#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string text; cin >> text;
    if(text.length() % 2 == 0)
    {
        cout << "(";
        for(int i = 0; i < text.length() / 2; i++)
        {
            cout << text[i];
        }
        cout << ")";
    }
    return 0;
}