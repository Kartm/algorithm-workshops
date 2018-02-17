#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

//8 3 1 5 4 8 2 1 6
//all elements less than pivot are in the left array
//all elements greater or equal to pivot are in the right array
void QuickSort(int leftIndex, int rightIndex, vector<int> &numbers)
{
    int pivotIndex = (leftIndex + rightIndex)/2;
    int x = leftIndex;
    int y = rightIndex;
    while (x < y)
    {           
        //searching for the right indexes           
        while(numbers[x] < numbers[pivotIndex]) x++;
        while(numbers[y] > numbers[pivotIndex]) y--;
        if (x <= y)
        {
            swap(numbers[x], numbers[y]);
            x++;
            y--;
        }

        //sorting the divided parts
        if(leftIndex < y)
            QuickSort(leftIndex, y, numbers);   
        if(rightIndex > x)
            QuickSort(x, rightIndex, numbers);
    }
}

int main()
{
    int elements;
    cin >> elements;
    vector<int> numbers (elements);
    for(int i = 0; i < elements; i++)
    cin >> numbers[i];

    //cout << "Before sorting: ";
    //for(int i = 0; i < elements; i++)
    //cout << numbers[i] << " ";

    QuickSort(0, elements - 1, numbers);

    //cout << "\nAfter sorting: ";
    for(int i = 0; i < elements; i++)
    cout << numbers[i] << " ";
    return 0;
}