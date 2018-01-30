using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleGraphs
{
    static class GraphLoader
    {
        private static int GetEdgeAmount(string[] graphArray)
        {
            return graphArray.GetLength(0);
        }

        private static int GetNodeAmount(string[] graphArray)
        {
            List<int> nodes = new List<int>();
            foreach (string line in graphArray)
            {
                string[] characters = line.Split(new char[] { ' ' });
                nodes.Add(Convert.ToInt32(characters[0]));
                nodes.Add(Convert.ToInt32(characters[1]));
            }
            return nodes.Max();
        }

        private static bool CheckIfWeighted(string[] graphArray)
        {
            if (graphArray[0].Split(new char[] { ' ' }).Length == 3)
            {
                Console.WriteLine("Graph weighted.");
                return true;
            }
            else
            {
                Console.WriteLine("Graph not weighted.");
                return false;
            }
        }

        public static Graph LoadFromFile(string path, bool isDirected = false)
        {
            string[] graphArray = File.ReadAllLines(path);

            int nodeAmount = GetNodeAmount(graphArray);
            int edgeAmount = GetEdgeAmount(graphArray);
            bool isWeighted = CheckIfWeighted(graphArray);
            Graph temporaryGraph = new Graph(nodeAmount, edgeAmount, isDirected);

            if(isWeighted)
            {
                Console.WriteLine("Loading weighted graph.");
                foreach (string line in graphArray)
                {
                    string[] characters = line.Split(new char[] { ' ' });
                    temporaryGraph.AddEdge(Convert.ToInt32(characters[0]), Convert.ToInt32(characters[1]), Convert.ToInt32(characters[2]));
                }
            }
            else
            {
                Console.WriteLine("Loading unweighted graph.");
                foreach (string line in graphArray)
                {
                    string[] characters = line.Split(new char[] { ' ' });
                    temporaryGraph.AddEdge(Convert.ToInt32(characters[0]), Convert.ToInt32(characters[1]));
                }
            }
            return temporaryGraph;
        }
    }
}
