#ifndef __BFS_H
#define __BFS_H

#include <iostream>
#include <stdio.h>
#include <list>

#define MAX_ROW 3
#define MAX_COL 11
#define CHARGEPOSID 22

class bfsclass {
public:
    typedef struct {
        int row;
        int col;
        int predecessor;
    }point;

    typedef struct {
        float x;
        float y;
    }pointdef;

    int getTrails(point start,point end,std::list<point>*trailsout);
    int mergeTrails(std::list<bfsclass::point>trails,std::);

}
#endif