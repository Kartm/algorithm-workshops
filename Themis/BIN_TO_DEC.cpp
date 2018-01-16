#include <iostream>

using namespace std;

int power(int number, int pow)
{
    int result = 1;
    if(pow == 0)
        return 1;
    else
        for(int i = 0; i < pow; i++)
            result *= number;

    return result;
}

int main()
{
    int n; cin >> n; //111111111
    int dec = 0;
    int pow = 0;
    while(n > 0)
    {
        if(n % 10 == 1)
        {
            dec += power(2, pow);
            cout << "n = " << n << "\n";
        }
        else
            cout << "!!!!!!!!1n = " << n << "\n";
            
        n /= 10;
        pow++;
    }
    cout << dec;
    return 0;
    //1023

}