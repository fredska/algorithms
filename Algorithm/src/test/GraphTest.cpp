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
#include <Graph.h>


using namespace std;

Graph graph(10);

void setupGraphTest()
{
	graph.addEdge(Edge(0,1));
	graph.addEdge(Edge(5,3));
	graph.addEdge(Edge(3,2));
	graph.addEdge(Edge(0,1));
}

void testGraphEdgeValid()
{
	set<int> getEdges;
	set<int>::iterator getEdgesIter;
	getEdges = graph.verticies.at(0);
	getEdgesIter = getEdges.find(1);
	ASSERT(*getEdgesIter==0);
}

void runGraphTestSuite()
{
	cute::suite s;
	//TODO add your test here
	setupGraphTest();
	s.push_back(CUTE(testGraphEdgeValid));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "Graph Test Suite");
}


