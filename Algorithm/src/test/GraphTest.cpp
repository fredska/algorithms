/*
 * GraphTest.cpp
 *
 *  Created on: Oct 27, 2011
 *      Author: Work
 */

#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <Graph.h>
#include <GraphTest.h>
using namespace std;

Graph graph(10);

void setupGraphTest()
{
	graph.addEdge(0,1);
	graph.addEdge(0,2);
	graph.addEdge(0,3);
	graph.addEdge(5,3);
	graph.addEdge(3,2);
	graph.addEdge(0,1);
}

void truefalse(int x)
{
  cout << (x?"True":"False") << endl;
}

void testGraphEdgeValid()
{
	typedef set<int> EDGES;
	EDGES getEdges;
	getEdges = graph.verticies.at(0);
	EDGES::iterator getEdgesIter;

	getEdgesIter = getEdges.find(1);
	ASSERT(getEdgesIter!=getEdges.end());
	getEdgesIter = getEdges.find(3);
	ASSERT(getEdgesIter!=getEdges.end());

	getEdges = graph.verticies.at(3);

	getEdgesIter = getEdges.find(2);
	ASSERT(getEdgesIter!=getEdges.end());
}

void GraphTest::runGraphTestSuite()
{
	cute::suite s;
	setupGraphTest();
	s.push_back(CUTE(testGraphEdgeValid));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "Graph Test");
}

GraphTest::GraphTest()
{
}


