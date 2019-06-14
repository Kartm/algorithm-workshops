#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);

    int containers, barrels; cin >> containers >> barrels;
    vector<int> facility[containers];
    for(int i = 0; i < barrels; i++){
        int container, barrel; //cin >> container >> barrel;
        scanf("%d %d", &container, &barrel);
        facility[container - 1].push_back(barrel);
    }

    for(int i = 0; i < containers; i++){
        printf("Zbiornik %d:", i+1);
        for(int j = (int)facility[i].size()-1; j >= 0; j--){
            printf(" %d", facility[i][j]);
        }
        printf("\n");
    }
    return 0;
}
