#ifndef LOCATION_H_
#define LOCATION_H_

/*
    struct for representing locations in the grid.
*/

#include <iostream>
using namespace std;
struct Location
{
    int row, col;

    Location()
    {
        row = col = 0;
    };

    Location(int r, int c)
    {
        row = r;
        col = c;
    };
    bool operator==(Location& loc)
		{
    		return ((loc.col==col) && (loc.row==row));
    	}
};
#endif //LOCATION_H_
