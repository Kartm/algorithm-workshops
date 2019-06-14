#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
//czy liczba ma 5 dzielników
int main()
{
    int input; cin >> input;
    vector<int> dividers = {1};
    for(int i = 2; i < input; i++){
        if(input % i == 0){
            dividers.push_back(i);
            input = input/i;
            i--;
        }
    }
    dividers.push_back(input);
    ///SORTOWANIE BĄBELKOWE
    for(int i = 0; i < dividers.size() - 1; i++){
        for(int j = 0; j < dividers.size() - 1; j++){
            if(dividers[j] > dividers[j+1])
                swap(dividers[j], dividers[j+1]);
        }
        for(int j = 0; j < dividers.size() - 1; j++){
            if(dividers[j] == dividers[j+1]){
                dividers[j] = dividers[j] * dividers[j+1];
                dividers.erase(dividers.begin() + j);
            }
        }
        for(int j = 0; j < dividers.size() - 1; j++){
            if(dividers[j] > dividers[j+1])
                swap(dividers[j], dividers[j+1]);
        }
    }

    if(dividers.size() == 2){
        cout << "NIE";
    } else {
        for(int i = 1; i < dividers.size(); i++){
            cout << dividers[i] << endl;
        }
    }
    return 0;
}
