// Author Sean Davis

#include "FindMax.h"
#include <stdlib.h>
#include "BinaryHeap.h"


FindMax::FindMax(int citySize, const StreetBlock *streets, int numStreets)
{
  for (int i = 0; i < numStreets; i++) {
    Intersection& startInt = city[streets[i].startX][streets[i].startY];
    Intersection& endInt = city[streets[i].endX][streets[i].endY];
    startInt.adjacencyList[startInt.count].x = streets[i].endX;
    startInt.adjacencyList[startInt.count].y = streets[i].endY;
    endInt.adjacencyList[endInt.count].x = streets[i].startX;
    endInt.adjacencyList[endInt.count].y = streets[i].startY;
    startInt.adjacencyList[startInt.count++].time =
        1000000*(abs(streets[i].startX-streets[i].endX)+abs(streets[i].startY-streets[i].endY))/(streets[i].speed);
    endInt.adjacencyList[endInt.count++].time = startInt.adjacencyList[startInt.count++].time;
  }
} // FindMax()

void FindMax::find(Coordinate fireHouses[4], Coordinate *furthest, int *time)
{
  BinaryHeap<Intersection> fireHouseHeap(4);
  for (int i = 0; i<4;i++) {
    fireHouseHeap.insert(city[fireHouses[i].x][fireHouses[i].y]);
  }
} // find()

