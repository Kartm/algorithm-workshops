#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Wierzcholek
{
    int x;
    int y;
};

int main()
{
    int n; //ilosc wierzcholkow;
    cin >> n;
    vector<Wierzcholek> Wierzcholki (n);
    for(int i = 0; i < n; i++)
    {
        cin >> Wierzcholki[i].x; //wspolrzedna x
        cin >> Wierzcholki[i].y; //wspolrzedna y
    }

    //obliczenie pola
    double pole = 0;
    for(int i = 0; i < n; i++)
    {
        int poprzedniX;
        if(i == 0)
            poprzedniX = Wierzcholki[n-1].x;
        else
            poprzedniX = Wierzcholki[i-1].x;
        int nastepnyX;
        if(i == n - 1)
            nastepnyX = Wierzcholki[0].x;
        else
            nastepnyX = Wierzcholki[i+1].x;
        pole += (nastepnyX - poprzedniX) * Wierzcholki[i].y;
    }

    cout << "Pole: " << pole/2;
    
    return 0;
}