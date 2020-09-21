#include <iostream>
#include "Graph/Graph.h"
#include "Algorithms.h"

int main()
{
	Graph graph;
	GraphNode* node1 = graph.CreateNode();
	GraphNode* node2 = graph.CreateNode();
	GraphNode* node3 = graph.CreateNode();
	GraphNode* node4 = graph.CreateNode();
	GraphNode* node5 = graph.CreateNode();
	graph.CreateEdge(node1, node2);
	graph.CreateEdge(node1, node5);
	graph.CreateEdge(node2, node3);
	graph.CreateEdge(node3, node4);
	std::list<AdjacencyInfo*> adjList = node1->GetAdjacencyList();
	std::cout << "DepthFirstSearch" << std::endl;
	Algorithms::DepthFirstSearch(&graph, node1);
	graph.ClearVisits();
	std::cout << "BreadthFirstSearch" << std::endl;
	Algorithms::BreadthFirstSearch(&graph, node1, node3);
	std::cin.get();
}