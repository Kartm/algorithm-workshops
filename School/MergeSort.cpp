#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

vector<int> GenerateRandomVector(int size, int min, int max)
{
    srand(time(NULL));
    vector<int> result;
    for(int i = 0; i < size; i++)
    {
        result.push_back((rand() % max - min + 1) + min);
    }
    return result;
}

vector<int> Merge(vector<int> &vec, int begin, int middle, int end)
{
    int i = 0, j = middle + 1;
    cout << "Merge: begin = " << begin << ", middle = " << middle << ", end = " << end << "\n";
    while()
    {
        if(i > middle) //wyczerpany zbior
        {

        }
        if(j >= end) //wyczerpany zbior
        {
            
        }
    }
    

}

vector<int> MergeSort(vector<int> &vec, int begin, int end)
{
    if(end > begin)
    {
        int middle = (begin + end) / 2;
        MergeSort(vec, begin, middle);
        MergeSort(vec, middle + 1, end);
        Merge(vec, begin, middle, end);
    }
}

int main()
{
    //fstream file;
    //file.open("dane_obrazki.txt", std::ios::in);
    int size = 1000;
    vector<int> test = GenerateRandomVector(1000, 1, 100);
    for(int i = 0; i < 1000; i++)
    {
        cout << test[i] << "\n";
    }
    
    return 0;
}