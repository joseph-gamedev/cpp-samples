#pragma once

#include <vector>

class Graph;
class GraphNode;

class Algorithms
{
public:
	static void DepthFirstSearch(Graph* graph , GraphNode* node);
	static void BreadthFirstSearch(Graph* graph, GraphNode* startNode, GraphNode* goalNode);
};
