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
	parent = new int[graph.numberOfVerticies];
	parent[source] = -1;
	while(!q.empty())
	{
		int vertex = q.front();
		if(nodeState[vertex]!=VISITED)
		cout << "Viewing Node: " << (vertex+1) << endl;
		nodeState[vertex] = VISITED;
		q.pop();

		set<int> getEdges = graph.verticies.at(vertex);
		set<int>::iterator getEdgesIter;

		for(getEdgesIter=getEdges.begin(); getEdgesIter!=getEdges.end();getEdgesIter++)
		{
			if(nodeState[*getEdgesIter]!=VISITED)
			{
				parent[*getEdgesIter] = vertex;
				nodeState[*getEdgesIter] = DISCOVERED;
				q.push(*getEdgesIter);
			}
		}


	}
}

void BreadthFirstSearch::findShortestPathUsingBFS(int dest)
{
	/*
	 * From the Java Implementation of S.Lee
	 * https://github.com/sglee77/algorithm/blob/master/java/src/main/java/search/BreadthFirstSearch.java
	 *
	 * public void populateShortestPathToVertex(int vertex,StringBuffer result) {
		if(vertex >= graph.getNumberOfVertices()) { throw new IllegalArgumentException("Invalid vertex"); }

		if(vertex == source) {
			result.append(source);
		} else if(parent[vertex] == -1) {
			throw new RuntimeException("No path from " + source + " to " + vertex + " exist");
		} else {
			populateShortestPathToVertex(parent[vertex], result);
			result.append(vertex);
		}
	}
	 */
}

