#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <stack>
#include <iomanip>

using namespace std;

//attribute's length is 10
//mantise's (?) length is 21

int main()
{
    double input; cin >> input;
    vector<int> binary(32, 0);
    if(input < 0)
    {
        binary[0] = 1;
        input = -input;
    }
    
    int totalPart = floor(input);

    long long unsigned foo = 1, attribute = 0;
    while(foo < totalPart)
    {
        attribute++;
        foo = foo * 2;
    }
    cout << attribute;

    //attribute to binary
    stack<int> binaryAttribute;
    while(attribute > 0)
    {
        if(attribute % 2 == 1)
            binaryAttribute.push(1);
        else
            binaryAttribute.push(0);
        attribute /= 2;
    }

    for(int i = 1; i <= 10; i++)
    {
        if(i > 10 - binaryAttribute.size())
        {
            if(!binaryAttribute.empty())
            {
                binary[i] = binaryAttribute.top();
                binaryAttribute.pop();
            }
        }
            
        cout << "indeks " << i << ", wartosc " << binary[i] << endl;
    }

    double fractionPart = input / (double)(pow(2, attribute));
    cout << setprecision(10) << "fraction " << fractionPart;
    return 0;
}