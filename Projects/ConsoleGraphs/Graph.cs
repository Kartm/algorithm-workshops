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
            public int nodeB;
            public int cost = 0; //*default cost

            public Connection(int nodeB, int cost = 0)
            {
                this.nodeB = nodeB;
                this.cost = cost;
            }
        }

        public int NodeAmount { get; private set; }
        public int EdgeAmount { get; private set; }
        public bool IsDirected { get; private set; }

        private List<List<Connection>> GraphList { get; set; }
        
        //todo summary
        public Graph(int nodeAmount, int edgeAmount, bool isDirected = false)
        {
            this.NodeAmount = nodeAmount;
            this.EdgeAmount = edgeAmount;
            this.IsDirected = isDirected;
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
            if(GraphList[nodeA].Exists(x => x.nodeB == nodeB) == true)
            {
                return true;
            }
            else if(!IsDirected)
            {
                return GraphList[nodeB].Exists(x => x.nodeB == nodeA);
            }

            return false;
        }

        public int GetCost(int nodeA, int nodeB) //todo if unweighted, always return 0
        {
            if(GraphList[nodeA].Exists(x => x.nodeB == nodeB) == true)
            {
                return GraphList[nodeA].Where(x => x.nodeB == nodeB).Single().cost;
            }
            else if(!IsDirected)
            {
                return GraphList[nodeB].Where(x => x.nodeB == nodeA).Single().cost;
            }

            return 0;
        }

        public List<Connection> GetNeighbors(int node)
        {
            return GraphList[node];
        }
        //contains
    }
}