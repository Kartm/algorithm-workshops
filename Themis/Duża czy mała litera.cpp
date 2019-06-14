#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;
int main(){
    char letter; cin >> letter;
    if(letter == toupper(letter))
        cout << "duza";
    else
        cout << "mala";
    return 0;
}
