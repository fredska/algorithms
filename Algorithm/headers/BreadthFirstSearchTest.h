/*
 * BreadthFirstSearchTest.h
 *
 *  Created on: Oct 27, 2011
 *      Author: Work
 */
#include <NodeState.h>
#include <queue>
#ifndef BREADTHFIRSTSEARCHTEST_H_
#define BREADTHFIRSTSEARCHTEST_H_

struct BreadthFirstSearchTest
{
private:
	int minimumDistance;
	NodeState_t *nodeState;
	queue<int> q;
public:
	BreadthFirstSearchTest();
	void operator() ();
	void runBFSSuite();
	void findShortestPathViaBFS(Graph graph, int source, int dest);
};

#endif /* BREADTHFIRSTSEARCHTEST_H_ */
