#include <iostream>
#include <string>
using namespace std;

int main()
{
    char tab[6] = {'e', 'y', 'u', 'i', 'o', 'a'};
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string input; cin >> input;
    int result = 0;
    for(int i = 0; i < input.length(); i++){
        for(int j = 0; j < 6; j++){
            if(input[i] == tab[j])
                result++;
        }
    }
    cout << result;
    return 0;
}
