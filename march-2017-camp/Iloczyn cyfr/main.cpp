#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
//najmniejsze dzielniki liczby
int main()
{
    long int input; cin >> input;
    vector<long> dividers;
    if(input > 1){
        for(int i = 9; i > 1; i--){
            if(input % i == 0){
                dividers.push_back(i);
                input = input/i;
                i++;
            }
        }
        ///SORTOWANIE BABELKOWE
        for(int i = 0; i < (int)dividers.size() - 1; i++){
            for(int j = 0; j < (int)dividers.size() - 1; j++){
                if(dividers[j] > dividers[j+1])
                    swap(dividers[j], dividers[j+1]);
            }
            /*for(int j = 0; j < dividers.size() - 2; j++){
                if(dividers[j+1] == dividers[j+2]){
                    dividers[j+1] = dividers[j+1] * dividers[j+2];
                    dividers.erase(dividers.begin() + j + 2);
                }
            }*/

        }

        if(input > 1){
            cout << "NIE";
        } else {
            for(int i = 0; i < (int)dividers.size(); i++){
                cout << dividers[i];
            }
        }
    }
    else if (input == 0)
        cout << "0";
    else if (input == 1){
        cout << "1";
    }
    return 0;
}
