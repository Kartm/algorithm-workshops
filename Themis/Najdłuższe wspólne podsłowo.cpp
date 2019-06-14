#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;
int main(){
    string a,b;
    cin >> a >> b;
    int tab[b.length() + 1][a.length() + 1];
    ///tab[wiersz][kolumna];

    ///wypelnianie zerami
    for(int i = 0; i < b.length() + 1; i++){
        if(i == 0){
            for(int j = 0; j < a.length() + 1; j++){
                tab[j][i] = 0;
            }
        } else {
            tab[0][i] = 0;
        }
    }

    ///    a b c d
    ///  0 0 0 0 0
    ///a 0
    ///b 0
    ///c 0
    ///d 0

    stack<char> output;
    ///abababa abaabaa
    ///LCS
    for(int i = 1; i < b.length() + 1; i++){
        for(int j = 1; j < a.length() + 1; j++){
            if(a[j - 1] == b[i - 1]){
                tab[i][j] = tab[i-1][j-1] + 1;
            } else {
                tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
            }
        }
    }

    ///wypisywanie tablicy
    for(int i = 0; i < b.length() + 1; i++){
        for(int j = 0; j < a.length() + 1; j++){
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }

    ///dlugosc LCS
    cout << "LCS: " << tab[b.length()][a.length()] << endl;

    ///szukanie podslowa
    int i = b.length();
    int j = a.length();
    while(i > 0 && j > 0){
        if(tab[i][j] > tab[i-1][j-1]){
            output.push(b[tab[i][j]]);
            cout << "i = " << i << ", j = " << j << endl;
            i--;
            j--;
        } else {
            continue;
        }
    }

    for(int i = 0; i < output.size(); i++){
        cout << output.top() << ", ";
        output.pop();
    }

    return 0;
}
