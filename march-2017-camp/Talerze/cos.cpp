#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    vector<int> things;

    int operations; scanf("%d", &operations);
    int number, operation;
    for (int i = 0; i < operations; i++){
        scanf("%d", &operation);
        if (operation == 1){
            scanf("%d", &number);
            things.push_back(number);
        } else if (operation == 0){
            printf("%d\n", things.back());
        } else if (operation == -1){
            things.pop_back();
        }
    }

    return 0;
}
