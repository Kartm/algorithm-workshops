#include <iostream>

using namespace std;

int main()
{
    int length; cin >> length;
    string word; cin >> word;

    for(int i = 0; i < length - 1; i++){
        if(word[i] > word[i+1]){
            word.erase(i, 1);
            break;
        }
    }
    if(word.length() == length){
        word.erase(word.length() - 2, 1);
    }

    ///word.erase(word.length() - 2, 1);
    cout << word;
    return 0;
}
