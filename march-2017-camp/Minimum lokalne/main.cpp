#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int length; cin >> length;
    int numbers[length];
    vector<int> minimas;
    for(int i = 0; i < length; i++){
        cin >> numbers[i];
    }

    if(length == 0) {

    } else if (length == 1){
        minimas.push_back(numbers[length-1]);
    } else {
        if(numbers[0] < numbers[1]){
            minimas.push_back(numbers[0]);
        }
        if(numbers[length - 1] < numbers[length - 2]){
            minimas.push_back(numbers[length - 1]);
        }
        for(int i = 1; i < length - 1; i++){
            if(numbers[i] < numbers[i-1] && numbers[i] < numbers[i+1]){
                minimas.push_back(numbers[i]);
            }
        }
    }

    sort(minimas.begin(), minimas.end());
    minimas.erase(unique(minimas.begin(), minimas.end()), minimas.end());
    /*for(int i = 0; i < minimas.size(); i++){
            cout << minimas[i] << " ";
    }*/
    /*///wyszukiwanie duplikatów
    for(int i = 0; i < (int)minimas.size() - 1; i++){
        if(minimas[i] == minimas[i+1]){
            minimas.erase(minimas.begin() + i);
            i--;
        }
    }*/


    cout << minimas.size();

    return 0;
}
