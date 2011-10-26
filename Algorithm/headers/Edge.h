/*
 * Edge.h
 *
 *  Created on: Oct 26, 2011
 *      Author: Work
 */

#include <Location.h>

#ifndef EDGE_H_
#define EDGE_H_

struct Edge
{
public:
	Location to;
	Location from;

	Edge(Location input_to, Location input_from)
	{
		to = input_to;
		from = input_from;
	};
};


#endif /* EDGE_H_ */
