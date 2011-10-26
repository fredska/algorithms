/*
 * Graph.h
 *
 *  Created on: Oct 26, 2011
 *      Author: Work
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <Location.h>
#include <Edge.h>
using namespace std;
#ifndef GRAPH_H_
#define GRAPH_H_
struct Graph
{

	bool digraph;
	int numberOfVerticies;
	vector<vector<Location> > adjacencyList;
	Graph();
	Graph(int numOfVerts);
	Graph(int numOfVerts, bool isDigraph);
	~Graph();

	void setup();
	void addEdge(Edge edge);
	void reset();

};

#endif /* GRAPH_H_ */
