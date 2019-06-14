#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;
int main(){
    string test; cin >> test;
    test[0] = toupper(test[0]);
    cout << test;
}
