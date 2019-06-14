#include <iostream>
#include <vector>
#include <utility>
#include <query>

using namespace std;
int main(){
    int cities, connections;
    cin >> cities >> connections;
    vector<pair<int, int> > connectionVector(cities+1);
    for(int i = 0; i < connections; i++){
        int cityA, cityB, cost;
        connectionVector[cityA] = make_pair(cost, cityB);
    }
}

/*
6 10
1 2 2
1 6 1
1 5 3
4 1 5
2 6 2
2 3 5
4 3 4
3 5 4
4 5 4
5 6 3
*/
