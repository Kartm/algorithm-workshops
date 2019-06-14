#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    const int N = 3; //ilosc niewiadomych
    //A - wspolczynniki
    //B - wyrazy wolne
    double A[N][N], B[N], X[N] = {0};
    for(int i = 0; i < N; i++) //wejscie
    {
        cout << "Wiersz " << i + 1 << ": ";
        for(int j = 0; j < N; j++)
            cin >> A[i][j];
        cin >> B[i];
    }

    //iteracja po kazdym wierszu i rozwiazywanie rownania
    for(int i = 0; i < N; i++)
    {
        if(A[i][i] == 0)
        {
            int j = i + 1;
            while(j < N && A[j][i] == 0)
                j++;
            if(j == N)
            {
                cout << "Brak rozwiazan.\n";
                return 0;
            }
            else
            {
                for(int k = i; k < N; k++)
                {
                    swap(A[i][k], A[j][k]);
                }
                swap(B[i], B[j]);
            }
        }
        for(int j = i + 1; j < N; j++)
        {
            double p = A[j][i]/A[i][i];
            for(int k = i; k < N; k++)
                A[j][k] -= A[i][k] * p;
            B[j] = B[i] * p;
        }        
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << B[i] << "\n";
    }

    for(int i = 0; i < N; i++)
    {
        if(A[i][i] == 0)
            cout << "Brak rozwiazan.\n";
    }

    for(int i = N - 1; i >= 0; i--)
    {
        X[i] = B[i];
        for(int j = i + 1; j < N; j++)
        {
            X[i] -= X[j] * A[i][j];
        }
        X[i] /= A[i][i];
        cout << X[i] << " ";
    }

    /*
    1 2 3 4
    5 6 7 8
    9 1 2 3
    */
}