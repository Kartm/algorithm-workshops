#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//znajdowanie rozwiazania
int main()
{
    int n1, n2, m1, m2;
    cout << "n1: "; cin >> n1;
    cout << "n2: "; cin >> n2;
    cout << "m1: "; cin >> m1;
    cout << "m2: "; cin >> m2;

    vector<pair<int, int> > results;
    results.push_back(make_pair(m1, m2));
    for(int i = 0; i < 20; i++) //test
    {
        cout << results[i].first << " " << results[i].second << "\n";
        results[i].first += n1;
        results[i].second += n2;
    }
    cout << "wynik: " << m1;
    
    return 0;
}