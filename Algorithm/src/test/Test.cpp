#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <vector>
#include <iostream>
#include <Graph.h>
#include <Location.h>
#include <GraphTest.h>
#include <BreadthFirstSearch.h>
#include <BreadthFirstSearchTest.h>
#include <AStar.h>
#include <time.h>
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

	result.addEdge(0,1);
	result.addEdge(0,2);
	result.addEdge(1,5);
	result.addEdge(1,6);
	result.addEdge(2,3);
	result.addEdge(2,4);
	result.addEdge(2,5);
	result.addEdge(3,0);
	result.addEdge(3,8);
	result.addEdge(3,4);
	result.addEdge(4,9);
	result.addEdge(6,7);
	result.addEdge(7,2);
	result.addEdge(7,9);

	return result;
}

void printOutVector(vector<int> vInts)
{
	vector<int>::iterator itr;
	for(itr = vInts.begin(); itr!=vInts.end();itr++)
	{
		cout << *itr << ",";
	}
	cout << endl;
};

void printOutVector(vector<Location> locs)
{
	vector<Location>::iterator itr;
	for(itr=locs.begin();itr!=locs.end();itr++)
	{
		cout << "(" << itr->row << "," << itr->col << ") :: Distance: " << itr->distance << " :: f(n): " << (itr->distance + itr->hOfn) << endl;
	}
};

bool A_Star_Sort_Test(Location loc1, Location loc2)
{
	return (loc1.hOfn + loc1.distance) <= (loc2.hOfn + loc2.distance);
};

int main(){
	/*
	GraphTest gt;
	gt.runGraphTestSuite();

	BreadthFirstSearchTest bfsTest;
	bfsTest.runBFSSuite();

	BreadthFirstSearch bfs;
	bfs.searchGraphUsingBreadthFirstSearch(generateGraph(),0);
	 */
	int ROWS = 800;
	int COLS = 800;
	clock_t start, end;
	AStar astar(ROWS,COLS);
	int numOfLocations = 200;
	Location startLocs[numOfLocations];
	Location endLocs[numOfLocations];
	cout << "BFS Search Begin..." << endl;
	start = clock();
	astar.producePath(Location(ROWS/2,COLS/2),Location(0,0));
	end = clock(); cout << "BFS Time Elapse(ms): " << (double)(end - start) << endl;

	start = clock();
	astar.producePathWithPriorityQueue(Location(ROWS/2,COLS/2),Location(0,0));
	end = clock(); cout << "A* Time Elapse(ms): " << (double)(end - start) << endl;

	/*
	for(int testNum = 0; testNum < 10; testNum++)
	{
		srand(time(NULL));
		for(int i = 0; i < numOfLocations; i++)
		{
			startLocs[i] = Location(rand() % ROWS, rand() % COLS);
			endLocs[i] = Location(rand() % ROWS, rand() % COLS);
		}

		clock_t start, end;

		start = clock();
		for(int a = 0; a < numOfLocations; a++)
		{
			astar.producePath(startLocs[a],endLocs[a]);
		}
		end = clock();
		cout << "BFS for " << numOfLocations << " random locations took: " << (double)(end - start) << "ms" << endl;

		start = clock();
		for(int a = 0; a < numOfLocations; a++)
		{
			astar.producePath(startLocs[a],endLocs[a]);
		}
		end = clock();
		cout << "A* for " << numOfLocations << " random locations took: " << (double)(end - start) << "ms" << endl;

		start = clock();
		for(int a = 0; a < numOfLocations; a++)
		{
			astar.producePath(startLocs[a],endLocs[a]);
		}
		end = clock();
		cout << "A* for " << numOfLocations << " random locations took: " << (double)(end - start) << "ms" << endl;

		start = clock();
		for(int a = 0; a < numOfLocations; a++)
		{
			astar.producePath(startLocs[a],endLocs[a]);
		}
		end = clock();
		cout << "BFS for " << numOfLocations << " random locations took: " << (double)(end - start) << "ms" << endl;
	}
	*/
	return 0;
}



