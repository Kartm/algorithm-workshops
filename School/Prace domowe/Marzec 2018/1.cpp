#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

/*
Liczbę nieparzystą można zapisać jako sumę liczby pierwszej i dwukrotnemu
iloczynowi kwadratu pewnej liczby.
9 = 7 + 2×1^2
15 = 7 + 2×2^2
21 = 3 + 2×3^2
25 = 7 + 2×3^2
27 = 19 + 2×2^2
33 = 31 + 2×1^2
Opierając się na takim sposobie zapisu liczby możemy utworzyć funkcję gold(x) która każdej
liczbie nieparzystej przypisuje parę liczb: np. gold(9) = (7,1), gold(15) = (7,2), itd… . 

a) Napisz funkcję wyznaczającą parę liczb występującą w rozkładzie.
b) Podaj która liczba pierwsza występuje najczęściej w rozkładzie liczb z przedziału (200,300).
Jeżeli kilka liczb występuje z taką samą częstotliwością to wypisujemy wszystkie liczby.
c) Jaka jest najmniejsza liczba nieparzysta, która nie spełnia tej zależności(odpowiedź wraz z
dowodem).
*/

vector<long long> Sieve(long long max)
{
    vector<long long> sieve(max + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    vector<long long> result;
    for(long long i = 2; i <= sqrt(max); i++)
        if(sieve[i] == true)
            for(long long j = i*i; j <= max; j+=i)
                sieve[j] = false;

    for(long long i = 2; i <= max; i++)
        if(sieve[i] == true)

            result.push_back(i);
    
    return result;
}


pair<long long, long long> Gold(long long x)
{
    //X = Y + 2×Z^2
    vector<long long> sieve = Sieve(x);
    priority_queue<pair<long long, long long> > results;
    long long z = 0;
    while(z < sieve.back())
    {
        long long Z2 = 2 * z * z;
        long long Y = x - Z2;
        for(long long i = 0; i < sieve.size(); i++)
        {
            if(sieve[i] == Y)
            {
                results.push(make_pair(z, Y));
            }
        }
        z++;
    }
    pair<long long, long long> result = make_pair(results.top().second, results.top().first);
    return result;
}

int main()
{
    //podpunkt a
    long long x;
    cin >> x;
    pair<long long, long long> test = Gold(x);
    cout << "Gold(" << x << ") = " << test.first << ", " << test.second << "\n";

    //podpunkt b
    //* store 'Gold(i).first', 'x' and sort by x
    
    vector<long long> results (300, 0); 
    for(long long i = 201; i < 300; i+=2)
        results[Gold(i).first]++;

    priority_queue<pair<long long, long long> > validResults; //results != 0 only, sorting them
    for(int i = 1; i < 300; i++)
    {
        if(results[i] != 0)
            validResults.push(make_pair(results[i], i));
    }

    long long biggestAmount;
    biggestAmount = validResults.top().first;
    cout << "Najwiecej liczb pierwszych wystepuje z czestotliwoscia " << biggestAmount << ": ";
    while(!validResults.empty())
    {
        if(biggestAmount == validResults.top().first)
        {
            pair<long long, long long> foo = validResults.top();
            validResults.pop();
            cout << foo.second << " ";
        }
        else
        {
            break;
        }
    }
    cout << "\n";

    //podpunkt c
    /*
    Zaleznosc o ktorej mowa w poleceniu:
    "Liczbę nieparzystą można zapisać jako sumę liczby pierwszej i dwukrotnemu
    iloczynowi kwadratu pewnej liczby.
    np. 9 = 7 + 2×1^2"

    Jaka jest najmniejsza liczba nieparzysta, która nie spełnia tej zależności?
    Sprobujmy rozlozyc liczbe 1. Musi to byc suma:
    - liczby pierwszej
    - dwukrotnosci kwadratu pewnej liczby

    Pierwszy skladnik sumy musi byc wiec liczba pierwsza mniejsza lub rowna 1. Nie istnieje taka liczba.
    Drugi skladnik sumy ma wynosic 1, czyli musi byc to dwukrotnosc kwadratu jakiejs liczby (x):
    1 = 2 * x ^ 2
    x = sqrt(2) / 2
    W liczbie x wystepuje pierwiastek z 2, liczba niewymierna.
    Funkcja Gold(1) nie zwraca zadnej wartosci.
    Uznajemy wiec, ze dla liczby 1 cale wyrazenie nie spelnia zaleznosci.
    */
    pair<long long, long long> test2 = Gold(1);
    cout << "Gold(1) = " << "(" << test2.first << ", " << test2.second << ")";
    return 0;
}