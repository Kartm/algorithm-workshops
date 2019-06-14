#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

vector<int> ReverseVector(vector<int> input)
{
    vector<int> reversed;
    for(int i = input.size() - 1; i >= 0; i--)
        reversed.push_back(input[i]);
    return reversed;
}

vector<int> BackwardIntegerToBinary(int integer)
{
    vector<int> binaryRepresentation;
    while(integer > 0)
    {
        int foo = integer % 2;
        if(foo == 1)
            binaryRepresentation.push_back(1);
        else
            binaryRepresentation.push_back(0);
        integer = integer / 2;
    }
    return binaryRepresentation;
}

pair<int, double> Multiply(double input)
{
    double multiplied = input * 2.0;
    int leftSide = (int)multiplied;
    double rightSide = multiplied - (double)leftSide;
    return make_pair(leftSide, rightSide);
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cout << "Set approximation: ";
    int approximation; cin >> approximation;
    cout << "Enter a real number: ";
    double realNumber; cin >> realNumber;


    int leftSide = (int)realNumber;
    cout << "Left side in fixed-point representation: ";
    vector<int> binaryLeftSide = ReverseVector(BackwardIntegerToBinary(leftSide));
    for(int i = 0; i < binaryLeftSide.size(); i++)
        cout << binaryLeftSide[i];
    cout << "\n";

    cout << "Right side in fixed-point representation: ";
    double rightSide = realNumber - (double)leftSide;
    for(int i = 0; i < approximation; i++)
    {
        pair<int, double> result = Multiply(rightSide);
        if(result.first == 1)
            cout << "1";
        else
            cout << "0";
        rightSide = result.second;
    }
    return 0;
}
