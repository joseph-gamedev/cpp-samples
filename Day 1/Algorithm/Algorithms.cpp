#include "Algorithms.h"
#include "Graph/Graph.h"
#include <iostream>
#include <queue>

void Algorithms::DepthFirstSearch(Graph* graph, GraphNode* node)
{
	if (!node->IsVisited())
	{
		std::cout << node->GetId() << std::endl;
	}
	node->SetVisited(true);
	auto adjInfo = node->GetAdjacencyList();
	for (auto adj: adjInfo)
	{
		GraphNode* node = adj->GetNode();
		if (node)
		{
			if (!node->IsVisited())
			{
				node->SetVisited(true);
				std::cout << node->GetId()<< std::endl;
				DepthFirstSearch(graph, node);
			}
		}
	}
}

void Algorithms::BreadthFirstSearch(Graph* graph, GraphNode* startNode, GraphNode* goalNode)
{
	std::queue<GraphNode*> nodeQueue;
	startNode->SetVisited(true);
		
	nodeQueue.push(startNode);

	while (!nodeQueue.empty())
	{
		GraphNode* frontInQueue = nodeQueue.front();
		nodeQueue.pop();
		if (frontInQueue == goalNode)
		{		
			return ;
		}
		auto adjList  = frontInQueue->GetAdjacencyList();
		for (auto adj : adjList)
		{
			GraphNode* node = adj->GetNode();
			if (!node->IsVisited())
			{
				std::cout << node->GetId() << std::endl;
				node->SetVisited(true);
				nodeQueue.push(node);
			}
			
		}
	}

}

