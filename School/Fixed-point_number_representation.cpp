#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> ReverseVector(vector<int> input)
{
    vector<int> reversed;
    for(int i = input.size() - 1; i >= 0; i--)
    {
        reversed.push_back(input[i]);
    }
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

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    double realNumber; cin >> realNumber;
    int leftSide = (int)realNumber;
    vector<int> binaryLeftSide = ReverseVector(BackwardIntegerToBinary(leftSide));

    double rightSide = realNumber - (double)leftSide;
    int approximation = 32;
    for(int i = 0; i < approximation; i++)
    {

    }
    //cout << leftSide;
    //cout << endl << rightSide;
    /*binary = BackwardIntegerToBinary(test);
    for(int i = 0; i < binary.size(); i++)
    {
        cout << binary[i];
    }*/
    return 0;
}