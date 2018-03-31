#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

enum Operator
{
    Greater,
    Less,
    LessOrEqual,
    GreaterOrEqual,
};

bool CheckMonotonicity(vector<int> &str, Operator op)
{
    switch(op)
    {
        case 0: //greater
        {
            for(int i = 0; i < str.size() - 1; i++)
            {
                if(!(str[i] < str[i+1]))
                {
                    return false;
                }
            }
            break;
        }
        case 1: //less
        {
            for(int i = 0; i < str.size() - 1; i++)
            {
                if(!(str[i] > str[i+1]))
                {
                    return false;
                }
            }
            break;
        }
        case 2: //lessorequal
        {
            for(int i = 0; i < str.size() - 1; i++)
            {
                if(!(str[i] >= str[i+1]))
                {
                    return false;
                }
            }
            break;
        }
        case 3: //greaterorequal
        {
            for(int i = 0; i < str.size() - 1; i++)
            {
                if(!(str[i] <= str[i+1]))
                {
                    return false;
                }
            }
            break;
        }
    }
    return true;
}

void CheckMonotonicityFunction(vector<int> &str)
{
    cout << "Checking monotonicity. Operation: \n";
    cout << "Greater [0]\nLess[1]\nLessOrEqual[2]\nGreaterOrEqual[3]\n\n";
    int choice; cin >> choice;
    string message = (CheckMonotonicity(str, (Operator)choice)) ? "True." : "False.";
    cout << message;
}

int ArAverage(int a, int b)
{
    return (a+b)/2;
}

int GeoAverage(int a, int b)
{
    return sqrt(a+b);
}

enum StringType
{
    Arithmetical,
    Geometrical,
};

bool CheckType(vector<int> &str, StringType type)
{
    switch(type)
    {
        case 0: //arithmetical
        {
            for(int i = 1; i < str.size() - 2; i++)
            {
                if(str[i] != ArAverage(str[i-1], str[i+1]))    
                    return false;
            }
            
        }
        case 1: //geometrical
        {
            for(int i = 1; i < str.size() - 2; i++)
            {
                if(str[i] != GeoAverage(str[i-1], str[i+1]))    
                    return false;
            }
        }
    }

    return true;
}

void CheckTypeFunction(vector<int> &str)
{
    cout << "\n\nChecking type. Choose: \n";
    cout << "Arithmetical [0]\nGeometrical[1]\n";
    int choice; cin >> choice;
    string message = (CheckType(str, (StringType)choice)) ? "True." : "False.";
    cout << message;
}

int main()
{
    cout << "Dlugosc ciagu: ";
    int length; cin >> length;
    vector<int> str (length);
    for(int i = 0; i < length; i++)
    {
        cin >> str[i];
    }
    system("clear");
    CheckMonotonicityFunction(str);
    CheckTypeFunction(str);
    //1 2 3 4
    return 0;
}