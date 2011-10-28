/*
 * BreadthFirstSearchTest.cpp
 *
 *  Created on: Oct 27, 2011
 *      Author: Work
 */

#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <vector>
#include <iostream>
#include <Graph.h>
#include <BreadthFirstSearchTest.h>
using namespace std;

Graph bfsGraph(WIDTH * HEIGHT);

/**
 * Use a queue structure to generate the edges
 * the edges will be immediately Above, Below, Left and Right of the source point
 * so.. (d is for pointing down)
 * 1 <- 2 -> 3
 * ^    ^    ^
 * 4 <- 5 -> 6
 * d    d    d
 * 7 <- 8 -> 9
 */

bool verifyValidLocation(int vertex, int MAX_SIZE)
{
	return (vertex < 0 || vertex >= (MAX_SIZE));
}

Graph generateGraphFromSource(Graph graph, int source)
{
	queue<int> q;
	q.push(source);
	int MAX_SIZE;
	MAX_SIZE = WIDTH * HEIGHT;
	bool *nodeState = new bool[MAX_SIZE]; // For Visited Nodes;
	for(int i = 0;i<MAX_SIZE;i++)
		nodeState[i] = 0;
	while(!q.empty())
	{
		int vertex = q.front();
		q.pop();

		if(verifyValidLocation(vertex,MAX_SIZE) || nodeState[vertex])
		{
			continue;
		}
		nodeState[vertex] = true;
		int above, below, left, right;
		above = vertex + WIDTH;
		below = vertex - WIDTH;
		left  = vertex - 1;
		right = vertex + 1;

		if((vertex >= (WIDTH) && !nodeState[below]) && !verifyValidLocation(below, MAX_SIZE))
		{
			graph.addEdge(vertex, below);
			q.push(below);
		}
		if((vertex <= (MAX_SIZE - WIDTH) && !nodeState[above]) && !verifyValidLocation(above, MAX_SIZE))
		{
			graph.addEdge(vertex, above);
			q.push(above);
		}
		if(((vertex % WIDTH) != 0 && !nodeState[left]) && !verifyValidLocation(left, MAX_SIZE))
		{
			graph.addEdge(vertex, left);
			q.push(left);
		}
		if(((vertex % WIDTH) != (WIDTH-1) && !nodeState[right]) && !verifyValidLocation(right, MAX_SIZE))
		{
			graph.addEdge(vertex, right);
			q.push(right);
		}
	}

	return graph;
}

void setupBreadthFirstSearchTest()
{
	bfsGraph = generateGraphFromSource(bfsGraph, 4);
}



void checkEdgeValuesValid()
{
	typedef set<int> EDGES;
	EDGES getEdges;
	getEdges = bfsGraph.verticies.at(13);
	EDGES::iterator getEdgesIter;

	std::cout << "Checking the node paths: " << endl;
	for(getEdgesIter=getEdges.begin(); getEdgesIter!=getEdges.end();getEdgesIter++)
	{
		std::cout << "13," << *getEdgesIter << endl;
	}
	getEdgesIter = getEdges.find(12);
	ASSERT(getEdgesIter!=getEdges.end());

	//Check edges 17,22 & 17,16
	getEdges = bfsGraph.verticies.at(17);

	std::cout << "Checking the node paths: " << endl;
	for(getEdgesIter=getEdges.begin(); getEdgesIter!=getEdges.end();getEdgesIter++)
	{
		std::cout << "17," << *getEdgesIter << endl;
	}
	getEdgesIter = getEdges.find(16);
	ASSERT(getEdgesIter!=getEdges.end());
}

void validateDistanceToDestinationFromSource(int source, int dest, int gridWidth, int gridHeight)
{
	Graph thisGraph(gridWidth * gridHeight);
	thisGraph = generateGraphFromSource(thisGraph, source);


}


void BreadthFirstSearchTest::runBFSSuite(){
	cute::suite s;
	//TODO add your test here
	setupBreadthFirstSearchTest();
	s.push_back(CUTE(checkEdgeValuesValid));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "BreadthFirstSearch Suite");
}

BreadthFirstSearchTest::BreadthFirstSearchTest()
{
	;
}

