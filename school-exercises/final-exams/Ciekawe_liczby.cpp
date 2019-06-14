#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

bool IsCorrect(int number)
{
    int divider = 2;
    int odd = 0;
    int lastDivider = 1;
    while(number > 0 && divider <= number)
    {
        cout << "[" << divider << "]";
        if(number % divider == 0) //divider is actually a divider
        {
            if(divider % 2 == 0) //is even
                return false;
            if(divider != lastDivider)
            {
                cout << "Odd divider " << divider << "\n";
                odd++;
            }
            number = number / divider;
        }
        else
            divider++;
    }
    cout << "Odd dividers " << odd << ", last divider " << divider << "\n";
    if(odd == 3)
        return true;
    else
        return false;
}

int main()
{
    /*const int intAmount = 1000; //amount of input numbers
    ifstream file("59.txt");
    if(file.is_open())
    {
        int arr[intAmount];
        for(int i = 0; i < intAmount; i++)
        {
            file >> arr[i];
            cout << arr[i] << "\n";
        }
    }
    else
    {
        cout << "Couldn't open file.";
        return 1;
    }

    cout << "\n\n";*/
    bool foo = IsCorrect(1287);
    if(foo)
        cout << 1;
    else
        cout << 0;

    //file.close();
    return 0;
}