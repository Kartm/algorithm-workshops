#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

bool isPalindrom(string text){
    bool check = true;
    for(int i = 0, j = text.length()-1; i < text.length(), j > 0; i++, j--){
        if(text[i] != text [j])
            check = false;
    }
    return check;
}
int main()
{
    int testAmount; cin >> testAmount;
    for(int i = 0; i < testAmount; i++){
        string input; cin >> input;
        if(isPalindrom(input))
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }
    return 0;
}
