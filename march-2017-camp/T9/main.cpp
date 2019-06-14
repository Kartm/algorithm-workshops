#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

///slowo na T9

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string output;

    string T9[8] = {"abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"};


    string input; cin >> input;
    for(int i = 0; i < input.length(); i++){
        for(int j = 0; j < 8; j++){
            if (T9[j].find(input[i]) != string::npos){
                output.append(1, '0' + j + 2);
                break;
            }
        }
    }
    cout << output;
    return 0;
}
