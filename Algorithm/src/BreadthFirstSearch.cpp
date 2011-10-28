/*
 * BreadthFirstSearch.cpp
 *
 *  Created on: Oct 27, 2011
 *      Author: Work
 */
#include <BreadthFirstSearch.h>
BreadthFirstSearch::BreadthFirstSearch()
{
	;
}

BreadthFirstSearch::~BreadthFirstSearch()
{
	;
}

void BreadthFirstSearch::searchGraphUsingBreadthFirstSearch(Graph graph, int source)
{
	/*
	 * 1  procedure BFS(Graph,source):
2      create a queue Q
3      enqueue source onto Q
4      mark source
5      while Q is not empty:
6          dequeue an item from Q into v
7          for each edge e incident on v in Graph:
8              let w be the other end of e
9              if w is not marked:
10                  mark w
11                  enqueue w onto Q
	 */

	q.push(source);
	nodeState = new NodeState_t[graph.numberOfVerticies];
	nodeState[source] = VISITED;

	while(!q.empty())
	{
		int searchNumber = q.front();
		cout << "Viewing Node: " << (searchNumber+1) << endl;
		nodeState[searchNumber] = VISITED;
		q.pop();

		set<int> getEdges = graph.verticies.at(searchNumber);
		set<int>::iterator getEdgesIter;

		for(getEdgesIter=getEdges.begin(); getEdgesIter!=getEdges.end();getEdgesIter++)
		{
			if(nodeState[*getEdgesIter]!=VISITED)
			{
				nodeState[*getEdgesIter] = DISCOVERED;
				q.push(*getEdgesIter);
			}
		}


	}
}


