#include <iostream>
#include <cstdlib>

using namespace std;

pair<int, int> sortPair(pair<int, int> input)
{
    if(input.first >= input.second)
        return make_pair(input.first, input.second);
    else
        return make_pair(input.second, input.first);
}

int main()
{
    pair<int, int> intPair;
    cin >> intPair.first >> intPair.second;
    //od większej odejmujemy mniejszą
    while(intPair.first != intPair.second)
    {
        intPair = sortPair(intPair);
        intPair.first = intPair.first - intPair.second;
    }
    cout << intPair.first;
    return 0;
}