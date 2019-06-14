#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    vector<int> things;

    int operations; cin >> operations;
    int number, operation;
    for (int i = 0; i < operations; i++){
        cin >> operation;
        switch(operation){
            case -1:{
                things.pop_back();
            }
            case 0:{
                cout << things.at((int)things.size() - 1) << endl;
            }
            case 1:{
                cin >> number;
                things.push_back(number);
            }
        }
    }

    return 0;
}
