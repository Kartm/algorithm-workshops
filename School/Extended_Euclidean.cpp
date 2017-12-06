#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if(a < b) swap(a, b);
    vector<vector<int> > results (100);
    //GCD
    int operationCounter = 0;
    for(int i = 0; b != 0; i++)
    {
        results[i].push_back(a);
        results[i].push_back(b);
        int div = (b != 0) ? a / b : 0;
        int mod = a % b;
        a = b;
        b = mod;
        cout << "i = " << i << ", a = " << a << " , b = " << b << "\n";
        results[i].push_back(div);
        results[i].push_back(mod);
        operationCounter++;
    }
    cout << "NWD = " << a << "\n\n";

    for(int i = 0; i <= operationCounter - 1; i++)
        cout << results[i][0] << " " << results[i][1] << " " << results[i][2] << " " << results[i][3] << "\n"; 

    cout << "\n\n";

    /*
    vector<<vector<int> > results
    A B N R
    */
    //reverse
    //one before the last - start
    int i = operationCounter - 1;
    int x = results[i][0];
    int y = results[i+1][0];
    int nx = 1;
    int ny = -results[i][2];

    for(; i >= 0; i--)
    {
        cout << i << " " << x << " " << y << " " << nx << " " << ny << "\n";
        y = results[i][0];
        nx += -results[i][2] * ny;
        swap(x, y);
        swap(nx, ny);
    }
    cout << i << " " << x << " " << y << " " << nx << " " << ny << "\n";
    //1547 560
    return 0;
}