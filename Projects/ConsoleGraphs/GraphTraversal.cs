using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleGraphs
{
    public class GraphTraversal
    {
        protected Graph graph = new Graph(0, 0);
        protected int nodeAmount;
        protected List<bool> visited = new List<bool>();

        public void ResetVisited()
        {
            for (int i = 0; i < nodeAmount + 1; i++)
            {
                visited.Add(false);
            }
        }

        public GraphTraversal(Graph graph, int nodeAmount)
        {
            this.graph = graph;
            this.nodeAmount = nodeAmount;
            ResetVisited();
        }

        #region DFS
        public void RecursiveDFSLogic(int startNode)
        {
            visited[startNode] = true;
            Console.WriteLine("Current node {0}", startNode);
            foreach (var item in graph.GetNeighbors(startNode))
            {
                if (visited[item.nodeB] == false)
                {
                    RecursiveDFSLogic(item.nodeB);
                }
            }
        }

        public void RecursiveDFS(int startNode) //todo clear visited
        {
            ResetVisited();
            RecursiveDFSLogic(startNode);
        }

        #endregion

        #region Dijkstra
        class Node
        {
            public int NodeId { get; set; }
            public int Distance { get; set; }
        }

        class Container
        {
            private List<Node> elements = new List<Node>();

            public bool IsEmpty()
            {
                return (elements.Count == 0) ? true : false;
            }

            public void AddNode(Node node)
            {
                elements.Add(node);
            }

            public Node GetMinimum()
            {
                return elements.OrderBy(node => node.Distance).First();
            }

            public void PopNode()
            {
                elements.Remove(GetMinimum());
            }

        }

        public void DijkstraLogic(int startNode, int endNode)
        {
            Container queue = new Container();
            int[] distances = new int[graph.NodeAmount + 1];
            for(int i = 1; i < graph.NodeAmount + 1; i++)
            {
                if(i == startNode)
                {
                    queue.AddNode(new Node() { NodeId = i, Distance = 0 });
                    distances[i] = 0;
                }
                else
                {
                    queue.AddNode(new Node() { NodeId = i, Distance = Int32.MaxValue });
                    distances[i] = Int32.MaxValue;
                }
            }

            while(!queue.IsEmpty())
            {
                int currentNode = queue.GetMinimum().NodeId;
                queue.PopNode();
                if(!visited[currentNode])
                {
                    visited[currentNode] = true;
                    foreach (Graph.Connection connection in graph.GetGraph()[currentNode])
                    {
                        int currentNeighbor = connection.nodeB;
                        int newDistance = distances[currentNode] + connection.cost;
                        if(distances[currentNeighbor] > newDistance)
                        {
                            distances[currentNeighbor] = newDistance;
                        }

                        Console.WriteLine("{0}: {1}", currentNode, connection.nodeB);
                    }
                }
            }
            Console.WriteLine("{0}'s distance is {1}.", endNode, distances[endNode]);
        }

        public void Dijkstra(int startNode, int endNode)
        {
            ResetVisited();
            DijkstraLogic(startNode, endNode);

        }
        #endregion
    }
}