/*
 * Graph.cc
 *
 *  Created on: Oct 26, 2011
 *      Author: Work
 */

#include "Graph.h"
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

void Graph::addEdge(int parent, int child)
{
	if(parent > this->numberOfVerticies || child > this->numberOfVerticies)
	{
		printf("The Edges exceed the boundary!");
		return;
	}

	if(parent == child)
	{
		printf("This is just a point!");
		return;
	}

	this->verticies[parent].insert(child);
	if(this->digraph)
		this->verticies[child].insert(parent);
}
