#include <iostream>
#include <vector>

using namespace std;
bool isSorted(vector<int> vec){
    bool isSort = true;
    for(int i = 0; i < vec.size() - 1; i++){
        if(vec[i] > vec[i+1])
            return false;
    }
    return true;
}
int main(){
    int amount; cin >> amount;
    vector<int> numbers(amount);
    for(int i = 0; i < amount; i++){
        int temp; cin >> temp;
        numbers[i] = temp;
    }
    ///BUBBLE SORT
    cout << endl;
    while(!isSorted(numbers)){
        for(int i = 0; i < amount - 1; i++){
            if(numbers[i] > numbers[i+1]){
                swap(numbers[i], numbers[i+1]);
            }
            cout << numbers[i] << " ";
        }
        cout << numbers[amount - 1];
        cout << endl;
    }
    return 0;
}
