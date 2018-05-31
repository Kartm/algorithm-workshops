using System;

/*
I wrote this piece of code to celebrate the Pi Day 2018 and for train my coding abilities.
Also, don't forget about my own curiosity! It motivated me to study some methods to calculate this mysterious number.

CalculatingPi by Łukasz Blachnicki
*/

namespace CalculatingPi
{
    class Program
    {
        static void Main(string[] args)
        {
            for(int i = 1; i <= 100; i++)
            {
                double result = Methods.Polygons(i);
                Console.WriteLine("Precision {0}, pi = {1}, error = {2}", i, result, (result - Math.PI).ToString("0." + new string('#', 339)));
            }
            Console.ReadLine();
        }
    }
}
