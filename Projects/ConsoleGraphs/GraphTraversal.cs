using System;
using System.Collections.Generic;

namespace ConsoleGraphs
{
    public class GraphTraversal
    {
        private Graph graph;
        private int nodeAmount;
        private List<bool> visited;

        public void ResetVisited()
        {
            for(int i = 0; i < nodeAmount + 1; i++)
            {
                visited.Add(false);
            }
        }

        public GraphTraversal(Graph graph, int nodeAmount)
        {
            this.graph = graph;
            this.nodeAmount = nodeAmount;
        }

        public void RecursiveDFS(int currentNode, List<bool> visited)
        {
            if(visited[currentNode] == false)
            {
                System.Console.WriteLine("Current node {0}", currentNode);
                foreach (var item in graph)
                {
                    
                }
            }
        }
    }
}