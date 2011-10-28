#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <vector>
#include <iostream>
#include <Graph.h>
#include <GraphTest.h>
#include <BreadthFirstSearch.h>
#include <BreadthFirstSearchTest.h>
using namespace std;

void thisisatest()
{
	ASSERT(false);
}

void runSuite()
{
	GraphTest gt;

	cute::suite s;
	s.push_back(CUTE(thisisatest));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "Graph Tests");
}

Graph generateGraph()
{
	Graph result(10,false);

	result.addEdge(Edge(0,1));
	result.addEdge(Edge(0,2));
	result.addEdge(Edge(1,5));
	result.addEdge(Edge(1,6));
	result.addEdge(Edge(2,3));
	result.addEdge(Edge(2,4));
	result.addEdge(Edge(2,5));
	result.addEdge(Edge(3,0));
	result.addEdge(Edge(3,8));
	result.addEdge(Edge(3,4));
	result.addEdge(Edge(4,9));
	result.addEdge(Edge(6,7));
	result.addEdge(Edge(7,2));
	result.addEdge(Edge(7,9));

	return result;
}

int main(){
	GraphTest gt;
	gt.runGraphTestSuite();

	BreadthFirstSearchTest bfsTest;
	bfsTest.runBFSSuite();

	BreadthFirstSearch bfs;
	bfs.searchGraphUsingBreadthFirstSearch(generateGraph(),0);
    return 0;
}



