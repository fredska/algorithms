/*
 * AStar.h
 *
 *  Created on: Nov 3, 2011
 *      Author: Work
 */
#include "Graph.h"
#include "Location.h"
#ifndef ASTAR_H_
#define ASTAR_H_

struct AStar
{
public:
	Graph grid;
	AStar();
	AStar(int, int);
	void init();
	void producePath(Location, Location);
	void producePathWithPriorityQueue(Location, Location);
};


#endif /* ASTAR_H_ */
