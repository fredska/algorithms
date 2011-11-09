/*
 * AStar.cpp
 *
 *  Created on: Nov 3, 2011
 *      Author: Work
 */
#include "AStar.h"
#include "Location.h"
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <time.h>
using namespace std;

/*
    constants
 */
const int TDIRECTIONS = 4;
const char CDIRECTIONS[4] = {'N', 'E', 'S', 'W'};
const int DIRECTIONS[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };      //{N, E, S, W}

Graph *grid;
vector<vector<Location> > pathgrid;
vector<vector<bool> > passable;
int ROWS = 20;
int COLS = 20;

double HEURISTIC_CONSTANT = 5;
AStar::AStar()
{
	init();
};

AStar::AStar(int row, int col)
{
	ROWS = row;
	COLS = col;
	init();
};

void AStar::init()
{
	pathgrid = vector<vector<Location> >(ROWS, vector<Location>(COLS, Location()));
	passable = vector<vector<bool> >(ROWS, vector<bool>(COLS, true));

	//setup 3 walls
	// ------ 0% -> 60% width ------
	//                -- 40% -> 100% width ----
	// .......x................................. |
	// .......x................................. |
	// xxxxxxxxxxxxxxxxxxxxxxxxxxxxx............ 10%
	// .......x................................. to
	// .......x................................. 90%
	// .......x.......xxxxxxxxxxxxxxxxxxxxxxxxxx Height
	// .......x................................. |
	// .........................................

	//Wall 1, 0% -> 60% width at 20% height
	for(int x = 0; x < (int)(ROWS * 0.6); x++)
	{
		passable[x][(int)COLS * 0.2] = false;
	}

	//Wall 2, 40% -> 100% at 70% height
	for(int x = (int)ROWS * 0.4; x < (int)(ROWS); x++)
	{
		passable[x][(int)COLS * 0.7] = false;
	}

	//Wall 3, 10% to 90% Height, at 30% width
	for(int y = (int)COLS * 0.1; y < (int)COLS * 0.9; y++)
	{

	}
};

bool verifyLocationBoundaries(Location &loc)
{
	return (loc.row >= 0 && loc.row < ROWS) && (loc.col >= 0 && loc.col < COLS);
};

//Because we only have 4 directions to choose from, use the Manhantann distance calculation;
//h(n) = D * (abs(n.x-goal.x) + abs(n.y-goal.y))
// Where D is a constant value that determines how far out we will search
double heuristicValueReturn(Location &src, Location &dest)
{
	return HEURISTIC_CONSTANT * (abs(src.row - dest.row) + abs(src.col - dest.col));
};

bool A_Star_Sort(Location loc1, Location loc2)
{
	return (loc1.hOfn + loc1.distance) < (loc2.hOfn + loc2.distance);
};

//returns the new location from moving in a given direction with the edges wrapped
Location getLocation(const Location &loc, int direction)
{
	return Location( (loc.row + DIRECTIONS[direction][0] + ROWS) % ROWS,
			(loc.col + DIRECTIONS[direction][1] + COLS) % COLS );
};

/* http://theory.stanford.edu/~amitp/GameProgramming/ImplementationNotes.html
 * Implementation:
 * 	OPEN = priority queue containing START
 *	CLOSED = empty set
 *	while lowest rank in OPEN is not the GOAL:
 *	  current = remove lowest rank item from OPEN
 *	  add current to CLOSED
 *	  for neighbors of current:
 *		cost = g(current) + movementcost(current, neighbor)
 *		if neighbor in OPEN and cost less than g(neighbor):
 *		  remove neighbor from OPEN, because new path is better
 *		if neighbor in CLOSED and cost less than g(neighbor): **
 *		  remove neighbor from CLOSED
 *		if neighbor not in OPEN and neighbor not in CLOSED:
 *		  set g(neighbor) to cost
 *		  add neighbor to OPEN
 *		  set priority queue rank to g(neighbor) + h(neighbor)
 *		  set neighbor's parent to current
 *
 *	reconstruct reverse path from goal to start
 *		by following parent pointers
 */
void AStar::producePath(Location src, Location dest)
{
	init();

	//Loc is for the source starting point;
	vector<Location> qLoc;
	Location curLoc;
	bool unexploredFound = false;
	qLoc.push_back(src);
	int counter = 0;
	while(!qLoc.empty())
	{
		counter++;
		//Get the Location on the top of the queue
		Location vert = qLoc.at(0);
		vert.nodeState = VISITED;
		//"pop" from the top
		qLoc.assign(qLoc.begin() + 1, qLoc.end());

		if(vert==dest)
		{
			curLoc = vert;
			unexploredFound = true;
			qLoc.clear();
			break;
		}
		for(int d=0; d < TDIRECTIONS; d++)
		{
			Location nLoc = getLocation(vert,d);
			if(pathgrid[nLoc.row][nLoc.col].nodeState == NEW && passable[nLoc.row][nLoc.col] == true)
			{
				nLoc.direction = d;
				nLoc.distance = vert.distance + 1;
				pathgrid[nLoc.row][nLoc.col] = vert;
				qLoc.push_back(nLoc);
			}
		}
	}
	/*
	while(curLoc.distance > 0)
	{
		curLoc = pathgrid[curLoc.row][curLoc.col];
		cout << curLoc << endl;
	}
	*/
	cout << "BFS Search Complete :: Nodes Checked: " << counter << endl;
};

//For the priority queue
bool operator<(Location &loc1, Location &loc2)
{
	return loc1.getPriority() < loc2.getPriority();
};

double getDistance(Location &loc1, Location &loc2)
{
	double d1 = abs(loc1.row-loc2.row),
			d2 = abs(loc1.col-loc2.col),
			dr = min(d1, ROWS-d1),
			dc = min(d2, COLS-d2);
	return sqrt((dr*dr) + (dc*dc));
}
/* http://theory.stanford.edu/~amitp/GameProgramming/ImplementationNotes.html
 * Implementation:
 * 	OPEN = priority queue containing START
 *	CLOSED = empty set
 *	while lowest rank in OPEN is not the GOAL:
 *	  current = remove lowest rank item from OPEN
 *	  add current to CLOSED
 *	  for neighbors of current:
 *		cost = g(current) + movementcost(current, neighbor)
 *		if neighbor in OPEN and cost less than g(neighbor):
 *		  remove neighbor from OPEN, because new path is better
 *		if neighbor in CLOSED and cost less than g(neighbor): **
 *		  remove neighbor from CLOSED
 *		if neighbor not in OPEN and neighbor not in CLOSED:
 *		  set g(neighbor) to cost
 *		  add neighbor to OPEN
 *		  set priority queue rank to g(neighbor) + h(neighbor)
 *		  set neighbor's parent to current
 *
 *	reconstruct reverse path from goal to start
 *		by following parent pointers
 */

struct priorityLoc
{
	template<class Location>
	bool operator()(const Location& loc1, const Location& loc2)
	{ return loc1.priority > loc2.priority;}
};

void AStar::producePathWithPriorityQueue(Location src, Location dest)
{
	//Test with priority queue;
	init();
	int counter = 0;
	priority_queue<Location, vector<Location>, priorityLoc> pq;
	priority_queue<Location> pq_backup; // Used to help remove an open location
	vector<vector<bool> > closed = vector<vector<bool> >(ROWS, vector<bool>(COLS, false));
	vector<vector<int> > open_map = vector<vector<int> >(ROWS, vector<int>(COLS, 0));
	for(int x = 0; x < ROWS; x++)
	{
		for(int y = 0; y < COLS; y++)
		{
			closed[x][y] = 0;
			open_map[x][y] = -1;
		}
	}
	static Location *vert;
	static Location *nLoc;
	src.updatePriority(0, heuristicValueReturn(src, dest));

	open_map[src.row][src.col] = true;
	pq.push(src);

	while(!pq.empty())
	{
		counter++;
		//Get the top Location in the priority Queue
		vert = new Location(pq.top().row, pq.top().col, pq.top().distance, pq.top().priority);
		if(*vert == dest)
		{
			break;
		}
		pq.pop();
		//cout << *vert << endl;
		//Remove the current Location from the queue and open_map
		open_map[vert->row][vert->col] = false;
		//cout << " ---------------- " << endl;
		//Add the current Location to the Closed set;
		closed[vert->row][vert->col] = true;

		//Dump the Priority Queue contents;



		/*
		 *		if neighbor in OPEN and cost less than g(neighbor):
		 *		  remove neighbor from OPEN, because new path is better
		 *		if neighbor in CLOSED and cost less than g(neighbor): **
		 *		  remove neighbor from CLOSED
		 */

		for(int d = 0; d < TDIRECTIONS; d++)
		{
			nLoc = new Location(getLocation(*vert,d).row, getLocation(*vert,d).col, vert->distance + 1);

			if(passable[nLoc->row][nLoc->col] == false)
				continue;

			if(closed[nLoc->row][nLoc->col] == true)
			{
				continue;
			}

			bool tentative_is_better = false;
			double tentative_g_score = vert->distance + getDistance(*nLoc, dest);
			if(open_map[nLoc->row][nLoc->col] == -1)
			{
				//pq.push(*nLoc);
				tentative_is_better = true;
			}
			else if(tentative_g_score < open_map[nLoc->row][nLoc->col])
			{				tentative_is_better = true;			}

			if(tentative_is_better)
			{
				pathgrid[nLoc->row][nLoc->col] = *vert;
				open_map[nLoc->row][nLoc->col] = tentative_g_score;
				nLoc->distance = vert->distance + 1;
				nLoc->updatePriority(nLoc->distance, heuristicValueReturn(*nLoc, dest));
				if(tentative_g_score >= open_map[nLoc->row][nLoc->col])
				{
					pq.push(*nLoc);
				}
			}
			delete nLoc;
		}
		delete vert;

		while(!pq.empty())
		{
			pq_backup.push(pq.top());
			//cout << pq.top() << endl;
			pq.pop();
		}

		while(!pq_backup.empty())
		{
			pq.push(pq_backup.top());
			pq_backup.pop();
		}
	};

	/*
	Location finalLoc = pq.top();
	while(finalLoc.distance > 0)
	{
		finalLoc = pathgrid[finalLoc.row][finalLoc.col];
		//cout << finalLoc << endl;
	}
	*/
	cout << "A* Search Finished!  Nodes Checked: " << counter << endl;
};
