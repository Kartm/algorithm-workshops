#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

const int imageSize = 20;

struct Image
{
    bool imageArr[imageSize][imageSize];
    bool rowBits[imageSize];
    bool columnBits[imageSize];
};

int main()
{
    fstream file;
    file.open("dane_obrazki.txt", std::ios::in);
    int amount = 200; //200 obrazkow
    vector<Image> vec;
    if(file.good())
    {
        for(int i = 0; i < amount; i++)
        {
            Image image;
            string line;
            for(int j = 0; j < imageSize; j++) //lines
            {
                file >> line;
                for(int k = 0; k < imageSize; k++) //individual characters
                {
                    image.imageArr[j][k] = line[k] - '0';
                }

                image.rowBits[j] = line[imageSize] - '0';
            }
            file >> line;
            for(int j = 0; j < imageSize; j++) //lines
            {
                image.columnBits[j] = line[j] - '0';
            }
            file >> line;
            vec.push_back(image);
        }
    }
    /*cout << "TEST: \n";
    Image test = vec[1];
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            cout << test.imageArr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "rowBits: \n";
    for(int i = 0; i < 20; i++)
    {
        cout << test.rowBits[i] << " ";
    }

    cout << "columnBits: \n";
    for(int i = 0; i < 20; i++)
    {
        cout << test.columnBits[i] << " ";
    }*/

    //! rewersy
    //* 1 - czarny
    //* 0 - bialy
    int reverseAmount = 0;
    for(int i = 0; i < amount; i++)
    {
        Image image = vec[i];
        int countBlack = 0;
        int countWhite = 0;
        for(int j = 0; j < imageSize; j++)
        {
            for(int k = 0; k < imageSize; k++)
            {
                if(image.imageArr[j][k] == 1)
                {
                    countBlack++;
                }
                else
                {
                    countWhite++;
                }
            }
        }
        if(countBlack > countWhite)
        {
            reverseAmount++;
        }
    }
    cout << "Reverse amount: " << reverseAmount << "\n";

    //! rekurencyjne
    bool printData = true;
    for(int i = 0; i < amount; i++)
    {
        Image image = vec[i];
        if(imageSize % 2 == 0)
        {
            int x = 0;
            int y = 0;
            while(x < imageSize/2 && y < imageSize/2)
            {
                if(image.imageArr[x][y] != image.imageArr[x+imageSize/2][y]
                || image.imageArr[x][y] != image.imageArr[x][y+imageSize/2]
                || image.imageArr[x][y] != image.imageArr[x+imageSize/2][y+imageSize/2])
                {
                    break;
                }
                //is recursive
                if(printData)
                {
                    cout << "rowBits: \n";
                    for(int j = 0; j < imageSize; j++)
                    {
                        cout << image.rowBits[j] << " ";
                    }

                    cout << "columnBits: \n";
                    for(int j = 0; j < imageSize; j++)
                    {
                        cout << image.columnBits[j] << " ";
                    }
                    printData = false;
                }
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}