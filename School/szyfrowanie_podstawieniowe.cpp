#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

string encrypt(string rawText, string keyword)
{
    int ti = 0, ki = 0; //ti - current rawText index, ki - current keyword index
    int keywordLength = keyword.size();
    string result = "";
    while(ti < rawText.size())
    {
        ki = ki % keywordLength;
        result += alphabet[(rawText[ti] + keyword[ki]) % 27];
        ti++;
        ki++;
    }
    return result;
}

int main()
{
    string keyword;
    cout << "Enter the keyword: ";
    getline(cin, keyword);
    cout << "Enter the text to encrypt: ";
    string rawText;
    getline(cin, rawText);
    cout << "Encrypted text: " << encrypt(rawText, keyword);
    return 0;
}