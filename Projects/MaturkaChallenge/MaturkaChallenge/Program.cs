using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MaturkaChallenge
{
    public class Program
    {
        static List<int[]> CorrectSets = new List<int[]>();

        static bool IsCorrect(int[] array)
        {
            for (int i = 0; i < array.Count() - 1; i++)
            {
                if((array[i] % 2 == 0) && (array[i+1] % 2 == 0))
                {
                    return false;
                }
            }
            return true;
        }

        static void CheckSets(List<int[]> sets)
        {
            foreach (int[] set in sets)
            {
                if(IsCorrect(set))
                {
                    CorrectSets.Add(set);
                }
            }
        }

        static void PrintArray(int[] array)
        {
            for (int i = 0; i < array.Count(); i++)
            {
                Console.Write(array[i] + " ");
            }
            Console.Write("\n");
        }

        static void Swap(ref int[] array, int pos1, int pos2)
        {
            int temp = array[pos1];
            array[pos1] = array[pos2];
            array[pos2] = temp;
        }

        static void Permutation(int n, int[] array) {
            if (n == 1)
            {
                //PrintArray(array);
                if(IsCorrect(array))
                {
                    CorrectSets.Add(array);
                }
            }
            else
            {
                for (int i = 0; i < n - 1; i++)
                {
                    Permutation(n - 1, array);
                    if (n % 2 == 0)
                    {
                        Swap(ref array, i, n - 1);
                    }
                    else
                    {
                        Swap(ref array, 0, n - 1);
                    }
                }
                Permutation(n - 1, array);
            }
        }

        static void Main(string[] args)
        {
            int[] set = { 1, 2, 3, 4, 5, 6, 7, 9 };
            Permutation(8, set);

            Console.WriteLine("Number of correct permutations: {0}", CorrectSets.Count);
            Console.Read();
        }
    }
}
