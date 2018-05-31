using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PucleGenerator
{
    public static class Algorithms
    {
        public static int GCD(int a, int b) //Greatest common divider
        {
            if(a == 0)
            {
                return b;
            }
            return GCD(b % a, a);
        }

        public static List<int> GetAllDividers(int a, int b)
        {
            List<int> results = new List<int>();
            int gcd = GCD(a, b);
            Console.WriteLine(gcd);
            for (int divider = 1; divider <= gcd; divider++)
            {
                if (gcd % divider == 0)
                {
                    results.Add(divider);
                }
            }
            return results;
        }
    }
}
