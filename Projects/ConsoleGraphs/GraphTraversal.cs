using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleGraphs
{
    public class GraphTraversal
    {
        protected Graph graph;
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
        private void RecursiveDFSLogic(int startNode)
        {
            visited[startNode] = true;
            Console.WriteLine("Current node {0}", startNode);
            foreach (var item in graph.GetNeighbors(startNode))
            {
                if (visited[item.Node] == false)
                {
                    RecursiveDFSLogic(item.Node);
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
        private class Node
        {
            public int NodeId { get; set; }
            public int Distance { get; set; }
        }

        private class Container
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

        private void DijkstraLogic(int startNode, int endNode)
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
                        int currentNeighbor = connection.Node;
                        int newDistance = distances[currentNode] + connection.Cost;
                        if(distances[currentNeighbor] > newDistance)
                        {
                            distances[currentNeighbor] = newDistance;
                        }

                        Console.WriteLine("{0}: {1}", currentNode, connection.Cost);
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

        #region CycleCheck

        //todo Here
        /*
        private bool IsPointingToAncestor(int node, int ancestor)
        {
            foreach (var item in graph.GetNeighbors(node))
            {
                if (item.Node == ancestor)
                {
                    return true;
                }
            }
            return false;
        }

        
        private bool CycleCheckDirected(int currentNode)
        {
            visited[currentNode] = true;
            Console.WriteLine("Current node {0}", currentNode);
            foreach (var item in graph.GetNeighbors(currentNode))
            {
                if (visited[item.node] == false)
                {
                    RecursiveDFSLogic(item.node);
                    if (item.node == currentNode || IsPointingToAncestor(item.node, currentNode))
                    {
                        return true;
                    }
                }
            }
            return false;
        }*/

        private bool CycleCheckUndirected(int startNode)
        {
            visited[startNode] = true;
            Console.WriteLine("Current node {0}", startNode);
            foreach (var item in graph.GetNeighbors(startNode))
            {
                if (visited[item.Node] == false)
                {
                    RecursiveDFSLogic(item.Node);
                }
                else
                {
                    return true;
                }
            }
            return false;
        }

        private bool CycleCheckLogic(int startNode, bool isDirected = false)
        {
            if(isDirected)
            {
                return false;
                //return CycleCheckDirected(startNode);
            }
            else
            {
                return CycleCheckUndirected(startNode);
            }
        }

        public void CycleCheck(int startNode, bool isDirected)
        {
            ResetVisited();
            Console.WriteLine("Is cycle: {0}", CycleCheckLogic(startNode, isDirected));
        }

        #endregion

        #region Bipartite
        private List<int> colors = new List<int>(); //! two-colouring the nodes

        private bool CheckBipartiteLogic(int currentNode)
        {
            visited[currentNode] = true;
            Console.WriteLine("Current node {0}", currentNode);
            foreach (var item in graph.GetNeighbors(currentNode))
            {
                if (visited[item.Node] == false)
                {
                    //check the adjacent colors
                    foreach (var item2 in graph.GetNeighbors(item.Node))
                    {
                        if(colors[currentNode] == colors[item2.Node])
                        {
                            return false;
                        }
                    }
                    colors[item.Node] = colors[currentNode] * (-1);
                    Console.WriteLine("Coloring {0} as {1}", item.Node, colors[item.Node]);
                    RecursiveDFSLogic(item.Node);
                }
            }
            return true;
        }

        public void CheckBipartite(int startNode)
        {
            ResetVisited();
            for (int i = 0; i < nodeAmount + 1; i++)
            {
                colors.Add(0);
            }
            colors[startNode] = 1;
            Console.WriteLine("Is cycle: {0}", CycleCheckLogic(startNode, CheckBipartiteLogic(startNode)));
        }
        #endregion
    }
}