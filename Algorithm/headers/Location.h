#ifndef LOCATION_H_
#define LOCATION_H_

/*
    struct for representing locations in the grid.
*/

#include <iostream>
#include "NodeState.h"
using namespace std;
struct Location
{
    int row, col;
	double hOfn;
	int distance;
	int direction;
	NodeState_t nodeState;
	double priority;
    Location()
    {
        row = col = distance = direction = hOfn = 0;
        nodeState = NEW;
    };

    Location(int r, int c)
    {
        row = r;
        col = c;
		distance = 0;
		direction = 0;
		hOfn = 0;
		nodeState = NEW;
    };

	Location(int r, int c, int dist)
	{
		row = r;
		col = c;
		distance = dist;
		direction = 0;
		hOfn = 0;
		updatePriority(dist, 0);
		nodeState = NEW;
	};

	Location(int r, int c, int dist, int heuristic)
	{
		row = r;
		col = c;
		distance = dist;
		hOfn = heuristic;
		updatePriority(dist, heuristic);
		nodeState = NEW;
	};

	void updatePriority(int dist, double heur)
	{
		priority = dist + heur;
	};

	double getPriority(){ return priority; };

	friend bool operator==(const Location &loc1, const Location &loc2)
	{
		return loc1.row == loc2.row && loc1.col == loc2.col;
	}

	friend bool operator!=(const Location &loc1, const Location &loc2)
	{
		return loc1.row != loc2.row || loc1.col != loc2.col;
	}

	friend bool operator<(const Location &loc1,const Location &loc2)
	{
		int rowPrime = 98193;
		int colPrime = 13873;

		return (loc1.row * rowPrime + loc1.col * colPrime) < (loc2.row * rowPrime + loc2.col * colPrime);
	}

	friend ostream& operator<<(ostream &os, const Location &loc)
	{
		os << "(" << loc.row << "," << loc.col << ") :: Distance: " << loc.distance << " :: h(n): " << loc.hOfn << " :: f(n): " << (loc.priority);
		return os;
	}
};
#endif //LOCATION_H_
