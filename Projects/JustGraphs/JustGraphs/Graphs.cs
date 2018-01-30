using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JustGraphs
{
    public class Graph
    {
        private bool isDirected { get; set; }
        private bool isWeighted { get; set; }
        private int nodesAmount, edgesAmount;

        protected class Path
        {
            private int nodeB { get; set; }
            private int cost { get; set; }
            private bool hasWeight { get; set; }

            public Path(int nodeB, int cost)
            {
                this.nodeB = nodeB;
                this.cost = cost;
                hasWeight = true;
            }

            public Path(int nodeB)
            {
                this.nodeB = nodeB;
                hasWeight = false;
            }

            public int GetNode()
            {
                return this.nodeB;
            }

            public int GetPathCost()
            {
                return this.cost;
            }
        }

        protected List<List<Path>> list; //actual graph is being stored here

        /// <summary>
        /// Main graph class. Use it to initialize a graph.
        /// </summary>
        /// <param name="nodesAmount">The amount of nodes in a graph.</param>
        /// <param name="edgesAmount">The amount of edges in a graph (optional)</param>
        /// <param name="isDirected">Is graph directed?</param>
        /// <param name="isWeighted">Is graph weighted?</param>
        public Graph(int nodesAmount, bool isDirected, bool isWeighted, int edgesAmount = 0)
        {
            this.isDirected = isDirected;
            this.isWeighted = isWeighted;
            this.nodesAmount = nodesAmount;
            this.edgesAmount = edgesAmount;
            list = new List<List<Path>> (nodesAmount + 1);
        }

        public void AddNode(int nodeA, int nodeB, int cost = 0)
        {
            list[nodeA].Add(new Path(nodeB, cost));
            if (isDirected == false)
            {
                list[nodeB].Add(new Path(nodeA, cost));
            }
        }

        public void RemoveConnection(int nodeA, int nodeB)
        {
            list[nodeA].RemoveAll(x => x.GetNode().Equals(nodeB));
            if (isDirected == false)
            {
                list[nodeB].RemoveAll(x => x.GetNode().Equals(nodeA));
            }
        }

        public int GetCost(int nodeA, int nodeB)
        {
            if (isWeighted)
            {
                try
                {
                    return list[nodeA].Where(x => x.GetNode().Equals(nodeB)).Single().GetPathCost();
                }
                catch
                {
                    return list[nodeB].Where(x => x.GetNode().Equals(nodeA)).Single().GetPathCost();
                }
                finally
                {
                    //what's next?
                }
            }
            else
            {
                return -1; //! WATCH OUT HERE
            }
            //TODO: EXCEPTION HERE OR STH
        }

    }
}
