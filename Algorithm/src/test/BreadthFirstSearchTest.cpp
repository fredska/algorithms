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

Graph bfsGraph(10);

void setupBreadthFirstSearchTest()
{
	bfsGraph.addEdge(Edge(0,1));
	bfsGraph.addEdge(Edge(0,2));
	bfsGraph.addEdge(Edge(1,5));
	bfsGraph.addEdge(Edge(1,6));
	bfsGraph.addEdge(Edge(2,3));
	bfsGraph.addEdge(Edge(2,4));
	bfsGraph.addEdge(Edge(2,5));
	bfsGraph.addEdge(Edge(3,0));
	bfsGraph.addEdge(Edge(3,8));
	bfsGraph.addEdge(Edge(3,4));
	bfsGraph.addEdge(Edge(4,9));
	bfsGraph.addEdge(Edge(6,7));
	bfsGraph.addEdge(Edge(7,2));
	bfsGraph.addEdge(Edge(7,9));
}

void checkEdgeValuesValid()
{
	typedef set<int> EDGES;
	EDGES getEdges;
	getEdges = bfsGraph.verticies.at(0);
	EDGES::iterator getEdgesIter;

	getEdgesIter = getEdges.find(1);
	ASSERT(getEdgesIter!=getEdges.end());

	getEdges = bfsGraph.verticies.at(3);

	getEdgesIter = getEdges.find(8);
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

