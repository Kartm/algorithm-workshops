using System;
using System.Diagnostics;
using System.IO;

namespace ConsoleGraphs
{
    class Program
    {
        static void Main(string[] args)
        {
            Graph test = GraphLoader.LoadFromFile("graph.txt.txt");

            GraphTraversal test2 = new GraphTraversal(test, test.NodeAmount);
            //test2.RecursiveDFS(1);
            test2.Dijkstra(1, 5);
            test2.ResetVisited();

            Console.ReadLine();
        }
    }
}
