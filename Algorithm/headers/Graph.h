/*
 * Graph.h
 *
 *  Created on: Oct 26, 2011
 *      Author: Work
 */

#include <vector>
#include <set>
#include <Edge.h>
using namespace std;
#ifndef GRAPH_H_
#define GRAPH_H_
struct Graph
{

	bool digraph;
	int numberOfVerticies;
	vector<set<int> > verticies;
	Graph(int numOfVerts);
	Graph(int numOfVerts, bool isDigraph);
	~Graph();

	void init(int numOfVerticies, bool isDigraph);
	void addEdge(int parent, int child);
};

#endif /* GRAPH_H_ */
