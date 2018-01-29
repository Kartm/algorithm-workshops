using System;

namespace ConsoleGraphs
{
    class Program
    {
        static void Main(string[] args)
        {
            int nodeAmount = 5;
            int edgeAmount = 4;

            Graph test = new Graph(nodeAmount, edgeAmount);
            test.AddEdge(1, 2);
            test.AddEdge(1, 3);
            test.AddEdge(3, 4);
            test.AddEdge(4, 5);

            if(test.ConnectionExists(1, 3))
                System.Console.WriteLine(test.GetCost(1, 3));
            System.Console.WriteLine("Exists: {0}", test.ConnectionExists(1, 3));

            GraphTraversal test2 = new GraphTraversal(test, nodeAmount);
            test2.RecursiveDFS(1);
            Console.ReadLine();
        }
    }
}
