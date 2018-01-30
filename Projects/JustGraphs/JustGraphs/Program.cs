using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JustGraphs
{
    class Program
    {
        static void Main(string[] args)
        {
            Graph testGraph = new Graph(4, false, false);
            testGraph.AddNode(1, 2, 1);
            testGraph.AddNode(2, 3, 3);
            testGraph.AddNode(2, 4, 8);
            testGraph.AddNode(3, 4, 5);
            Console.WriteLine("{0}", testGraph.GetCost(2, 3));
        }
    }
}
