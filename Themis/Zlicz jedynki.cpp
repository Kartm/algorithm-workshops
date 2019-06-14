#include <iostream>
using namespace std;

int main(){
    int score = 0;
    int input;
    while(input != 0){
        cin >> input;
        if(input == 1)
            score++;
    }
    cout << score;
    return 0;
}
