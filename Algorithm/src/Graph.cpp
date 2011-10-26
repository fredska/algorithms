/*
 * Graph.cc
 *
 *  Created on: Oct 26, 2011
 *      Author: Work
 */

#include "Graph.h"
#include "Edge.h"
using namespace std;

Graph::Graph(){
	this->numberOfVerticies = 0;
	this->digraph = 0;
}

Graph::Graph(int numOfVerts)
{
	this->numberOfVerticies = numOfVerts;
	this->digraph = 0;
}

Graph::Graph(int numOfVerts, bool isDigraph)
{
	this->numberOfVerticies = numOfVerts;
	this->digraph = isDigraph;
}

Graph::~Graph()
{
	;
}

void Graph::setup()
{
	//Create the array
//	vector<vector<Location> > awesome2DMatrix(25,vector<Location>(2));
//	adjacencyList = awesome2DMatrix;
	addEdge(Edge(Location(1,1),Location(3,3)));
	addEdge(Edge(Location(1,6),Location(4,3)));
	addEdge(Edge(Location(1,10),Location(5,3)));
	addEdge(Edge(Location(1,1),Location(51,32)));
	addEdge(Edge(Location(1,6),Location(921,74)));

	vector<vector<Location> >::iterator iter_ii;
	vector<Location>::iterator iter_jj;

	for(iter_ii=adjacencyList.begin(); iter_ii!=adjacencyList.end();iter_ii++)
	{
		for(iter_jj=(*iter_ii).begin();iter_jj!=(*iter_ii).end();iter_jj++)
		{
			int row = iter_jj->row;
			int col = iter_jj->col;
			cout << row << "," << col << endl;
		}
	}
}

void Graph::addEdge(Edge edge)
{
	vector<vector<Location> >::iterator iter_ii;
	if(adjacencyList.empty())
	{
		vector<Location> newLoc; newLoc.push_back(edge.to);
		adjacencyList.push_back(newLoc);
		return;
	}
	for(iter_ii=adjacencyList.begin(); iter_ii!=adjacencyList.end();iter_ii++)
	{
		vector<Location> checkLoc = *iter_ii;
		Location checkThisLoc = checkLoc.at(0);
		if(checkThisLoc==edge.to)
		{
			printf("I Found my location!");
		}
	}
}
