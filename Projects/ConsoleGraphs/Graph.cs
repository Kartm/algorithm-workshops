using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleGraphs
{
    public class Graph:IEnumerable
    {
        private class Connection
        {
            public int nodeB;
            public int cost = 0; //*default cost

            public Connection(int nodeB, int cost = 0)
            {
                this.nodeB = nodeB;
                this.cost = cost;
            }
        }

        private int nodeAmount;
        private int edgeAmount;
        private bool isDirected;
        private List<List<Connection>> graph;
        
        //todo summary
        public Graph(int nodeAmount, int edgeAmount, bool isDirected = false)
        {
            this.nodeAmount = nodeAmount;
            this.edgeAmount = edgeAmount;
            this.isDirected = isDirected;
            graph = new List<List<Connection>> (nodeAmount + 1);
            for(int i = 0; i < nodeAmount + 1; i++)
            {
                graph.Add(new List<Connection> ());
            }
        }

        public void AddEdge(int nodeA, int nodeB, int cost = 0)
        {
            graph[nodeA].Add(new Connection(nodeB, cost));
            if(!isDirected)
            {
                graph[nodeB].Add(new Connection(nodeA, cost));
            }
        }

        public bool ConnectionExists(int nodeA, int nodeB)
        {
            if(graph[nodeA].Exists(x => x.nodeB == nodeB) == true)
                return true;
            else if(!isDirected)
                return graph[nodeB].Exists(x => x.nodeB == nodeA);
            return false;
        }

        public int GetCost(int nodeA, int nodeB) //todo if unweighted, always return 0
        {
            if(graph[nodeA].Exists(x => x.nodeB == nodeB) == true)
                return graph[nodeA].Where(x => x.nodeB == nodeB).Single().cost;
            else if(!isDirected)
                return graph[nodeB].Where(x => x.nodeB == nodeA).Single().cost;
            return 0;
        }
        //contains
    }
}