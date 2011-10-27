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
	queue<int> q;
public:
	BreadthFirstSearch();
	~BreadthFirstSearch();
	void searchGraphUsingBreadthFirstSearch(Graph graph, int source);
	void findShortestPathUsingBFS(Graph graph, int source, int dest);

};


#endif /* BREADTHFIRSTSEARCH_H_ */
