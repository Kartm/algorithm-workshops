#include <iostream>
#include <vector>
#include <string>

using namespace std;

//skompresowany napis zapisany w tablicy
//string to tablica charow
void PrintChars(vector<char> &buffer)
{
    for(int i = 0; i < buffer.size(); i++)
        cout << buffer[i];
}

int main()
{
    string text; cin >> text;
    bool insideBrackets = false;
    vector<char> buffer;
    for(int i = 0; i < text.length(); i++)
    {
        if(text[i] == '(')
        {
            insideBrackets = !insideBrackets;
            continue;
        }
        if(text[i] == ')')
        {
            PrintChars(buffer);
            buffer.clear();
            continue;
        }
        if(insideBrackets)
            buffer.push_back(text[i]);
        cout << text[i];
    }
    return 0;
}