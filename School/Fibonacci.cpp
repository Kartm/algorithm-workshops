#include <iostream>
#include <cstdlib>

using namespace std;
//f(n) = f(n-1) + f(n-2)
unsigned long long fib(int n)
{
    if(n > 2)
        return fib(n-1) + fib(n-2);
}

int main()
{
    unsigned int n; cin >> n;
    cout << fib(n-1);
    return 0;
}