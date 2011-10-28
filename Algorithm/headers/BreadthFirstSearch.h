/*
 * BreadthFirstSearch.h
 *
 *  Created on: Oct 27, 2011
 *      Author: Work
 */

#include <NodeState.h>
#include <Graph.h>
#include <queue>
using namespace std;
#ifndef BREADTHFIRSTSEARCH_H_
#define BREADTHFIRSTSEARCH_H_

struct BreadthFirstSearch
{
private:
	int minimumDistance;
	NodeState_t *nodeState;
	int *parent;
	int *distance;
	queue<int> q;
public:
	BreadthFirstSearch();
	~BreadthFirstSearch();
	void searchGraphUsingBreadthFirstSearch(Graph graph, int source);
	void findShortestPathUsingBFS(int dest);
	void findNextStepForShortestPath(int dest);
	int distanceToDestination(int dest);
};


#endif /* BREADTHFIRSTSEARCH_H_ */
