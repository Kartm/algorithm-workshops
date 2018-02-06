using System;
using System.Diagnostics;
using System.IO;

namespace ConsoleGraphs
{
    class Program
    {
        static void Main(string[] args)
        {
            Graph test = GraphLoader.LoadFromFile("graph.txt.txt", true);

            GraphTraversal test2 = new GraphTraversal(test, test.NodeAmount);
            test2.CheckBipartite(1);
            test2.ResetVisited();

            Console.ReadLine();
        }
    }
}
