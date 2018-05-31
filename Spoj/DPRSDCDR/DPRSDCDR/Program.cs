using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DPRSDCDR
{
    class Program
    {
        static int Input()
        {
            int input = Console.Read();
            Console.WriteLine("[{0}]", input);
            return Convert.ToInt32(input);
        }
        static void Main(string[] args)
        {
            int testCases = Input();
            for(int i = 0; i < testCases; i++)
            {
                int busyTime = 0;
                busyTime += 10; //eats, sleeps and does other household chores
                int ct = Input();
                int labReports = Input();
                int ctTime = Input();
                int labReportsTime = Input();
                int classesTime = Input();
                busyTime += ct * ctTime;
                busyTime += labReports * labReportsTime;
                busyTime += classesTime;
                if(busyTime > 21) //depression
                {
                    Console.WriteLine("Hotash");
                }
                else
                {
                    Console.WriteLine("Khushi");
                }
            }
            Console.Read();
        }
    }
}
