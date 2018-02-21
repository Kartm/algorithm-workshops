#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string text; cin >> text;

    for(int i = 0; i < text.length(); i++)
    {
        if(text[i] > 48 && text[i] < 57) //* numer
        {
            //nothing
        }
        else //char
        {
            switch(text[i])
            {
                case '+':
                {
                    
                    break;
                }
                case '-':
                {

                    break;
                }
                case '*':
                {

                    break;
                }
            }
        }
    }
    return 0;
}