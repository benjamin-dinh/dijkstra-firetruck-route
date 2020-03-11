// Author Sean Davis

#include "FindMax.h"
#include <stdlib.h>


FindMax::FindMax(int citySize, const StreetBlock *streets, int numStreets)
{
  Intersection city[1000][1000];
  for (int i = 0; i < numStreets; i++) {
    Intersection& startInt = city[streets[i].startX][streets[i].startY];
    Intersection& endInt = city[streets[i].endX][streets[i].endY];
    startInt.adjacencyList[startInt.count].x = streets[i].startX;
    startInt.adjacencyList[startInt.count].y = streets[i].startY;
    endInt.adjacencyList[startInt.count].x = streets[i].endX;
    endInt.adjacencyList[startInt.count].y = streets[i].endY;
    startInt.adjacencyList[startInt.count++].time =
        1000000*(abs(streets[i].startX-streets[i].endX)+abs(streets[i].startY-streets[i].endY))/(streets[i].speed);
    endInt.adjacencyList[endInt.count++].time = startInt.adjacencyList[startInt.count++].time;
  }
} // FindMax()

void FindMax::find(Coordinate fireHouses[4], Coordinate *furthest, int *time)
{
} // find()

