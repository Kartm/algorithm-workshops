using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ConsoleGraphs
{
    public class Graph
    {
        public class Connection
        {
            public int Node { get; private set; }
            public int Cost { get; private set; }

            public Connection(int nodeB, int cost = 0)
            {
                Node = nodeB;
                Cost = cost;
            }
        }

        public int NodeAmount { get; private set; }
        public int EdgeAmount { get; private set; }
        public bool IsDirected { get; private set; }
        public bool IsWeighted { get; private set; }

        private List<List<Connection>> GraphList { get; set; }
        
        //todo summary
        public Graph(int nodeAmount, int edgeAmount, bool isDirected, bool isWeighted)
        {
            NodeAmount = nodeAmount;
            EdgeAmount = edgeAmount;
            IsDirected = isDirected;
            IsWeighted = isWeighted;

            GraphList = new List<List<Connection>> (nodeAmount + 1);
            for(int i = 0; i < nodeAmount + 1; i++)
            {
                GraphList.Add(new List<Connection> ());
            }
        }

        public List<List<Connection>> GetGraph()
        {
            return GraphList;
        }

        public void AddEdge(int nodeA, int nodeB, int cost = 0)
        {
            GraphList[nodeA].Add(new Connection(nodeB, cost));
            if(!IsDirected)
            {
                GraphList[nodeB].Add(new Connection(nodeA, cost));
            }
        }

        public bool ConnectionExists(int nodeA, int nodeB)
        {
            if(GraphList[nodeA].Exists(x => x.Node == nodeB) == true)
            {
                return true;
            }
            else if(!IsDirected)
            {
                return GraphList[nodeB].Exists(x => x.Node == nodeA);
            }

            return false;
        }

        public int GetCost(int nodeA, int nodeB) //todo if unweighted, always returns 0
        {
            if (IsWeighted)
            {
                if (GraphList[nodeA].Exists(x => x.Node == nodeB) == true)
                {
                    return GraphList[nodeA].Where(x => x.Node == nodeB).Single().Cost;
                }
                else if (!IsDirected)
                {
                    return GraphList[nodeB].Where(x => x.Node == nodeA).Single().Cost;
                }
            }
            else
            {
                return 0;
            }
            return 0;
        }

        public List<Connection> GetNeighbors(int node)
        {
            return GraphList[node];
        }
    }
}