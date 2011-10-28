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
void generateGraphFromSource(int source)
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

		if(vertex < 0 || vertex >= (MAX_SIZE) || nodeState[vertex])
		{
			continue;
		}
		nodeState[vertex] = true;
		int above, below, left, right;
		above = vertex + WIDTH;
		below = vertex - WIDTH;
		left  = vertex - 1;
		right = vertex + 1;

		if(vertex > (WIDTH))
		{
			bfsGraph.addEdge(vertex, below);
			q.push(below);
		}
		if(vertex <= (MAX_SIZE - WIDTH))
		{
			bfsGraph.addEdge(vertex, above);
			q.push(above);
		}
		if((vertex % WIDTH) != 1)
		{
			bfsGraph.addEdge(vertex, left);
			q.push(left);
		}
		if((vertex % WIDTH) != 0)
		{
			bfsGraph.addEdge(vertex, right);
			q.push(right);
		}
	}
}

void setupBreadthFirstSearchTest()
{
	generateGraphFromSource(13);
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
		std::cout << "13," << *getEdgesIter << endl;
	}
	getEdgesIter = getEdges.find(16);
	ASSERT(getEdgesIter!=getEdges.end());

	getEdgesIter = getEdges.find(22);
		ASSERT(getEdgesIter!=getEdges.end());
}

void shouldReturnShortestDistanceToVertex()
{

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

