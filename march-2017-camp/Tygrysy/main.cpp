#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int amount; cin >> amount;
    vector<int> tigers;
    for(int i = 0; i < amount; i++){
        int temp; cin >> temp;
        tigers.push_back(temp);
    }
    int maximum = 0;

    sort(tigers.begin(), tigers.end());

    for(int i = 0; i < (int)tigers.size(); i++){
        int current_maximum = 1;
        for(int j = tigers.size() - 1; j > 0; j--){
            //cout << "j: " << tigers[j] << " j-1: " << tigers[j-1] << "  RESULT: " << (float)tigers[j] / (float)tigers[j-1] << endl;
            if((double)tigers[j] / (double)tigers[j-1] < (double)2){
                current_maximum++;
            }
        }
        //cout << "CURRENT MAXIMUM: " << current_maximum << endl;
        if(current_maximum > maximum)
            maximum = current_maximum;
    }

    cout << maximum;
    return 0;
}
