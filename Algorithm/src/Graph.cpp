/*
 * Graph.cc
 *
 *  Created on: Oct 26, 2011
 *      Author: Work
 */

#include "Graph.h"
#include "Edge.h"
#include <iostream>
#include <stdio.h>
using namespace std;

Graph::Graph(int numOfVerts)
{
	this->numberOfVerticies = numOfVerts;
	this->digraph = 0;
	init(this->numberOfVerticies, this->digraph);
}

Graph::Graph(int numOfVerts, bool isDigraph)
{
	this->numberOfVerticies = numOfVerts;
	this->digraph = isDigraph;
	init(this->numberOfVerticies, this->digraph);
}

Graph::~Graph()
{
	;
}

void Graph::init(int numOfVerticies, bool isDiGraph)
{
	this->verticies.resize(numOfVerticies);
}

void Graph::addEdge(Edge edge)
{
	if(edge.to > this->numberOfVerticies || edge.from > this->numberOfVerticies)
	{
		printf("The Edges exceed the boundary!");
		return;
	}

	if(edge.to == edge.from)
	{
		printf("This is just a point!");
		return;
	}

	this->verticies[edge.to].insert(edge.from);
}

set<int> Graph::fetchAdjacencyList(int vertexPos)
{
	set<int> result;
	if(vertexPos > this->numberOfVerticies) return result;

	vector<set<int> >::iterator vertexIter;
	int count = 0;
	return this->verticies.at(vertexPos);
}
