// Author Sean Davis

#include "FindMax.h"
#include <iostream>


FindMax::FindMax(int citySize, const StreetBlock *streets, int numStreets)
{
  intCount = 0;
  knownIntCount = 0;
  for (int i = 0; i < numStreets; i++) {
    Intersection& startInt = city[streets[i].startX][streets[i].startY];
    Intersection& endInt = city[streets[i].endX][streets[i].endY];
    startInt.adjacencyList[startInt.adjCount].x = streets[i].endX;
    startInt.adjacencyList[startInt.adjCount].y = streets[i].endY;
    endInt.adjacencyList[endInt.adjCount].x = streets[i].startX;
    endInt.adjacencyList[endInt.adjCount].y = streets[i].startY;
    startInt.adjacencyList[startInt.adjCount++].time =
        100000*(abs(streets[i].startX-streets[i].endX)+abs(streets[i].startY-streets[i].endY))/(streets[i].speed);
    endInt.adjacencyList[endInt.adjCount++].time =
        100000*(abs(streets[i].startX-streets[i].endX)+abs(streets[i].startY-streets[i].endY))/(streets[i].speed);
    if (startInt.adjCount == 1) {
      intCount++; // will not increment if new intersection was already made (adjCount > 1)
    }
    if (endInt.adjCount == 1) {
      intCount++; // will not increment if new intersection was already made (adjCount > 1)
    }
  }
} // FindMax()

void FindMax::find(Coordinate fireHouses[4], Coordinate *furthest, int *time)
{
  BinaryHeap<Vertices> fireHouseHeap(10000);
  for (int i = 0; i<4;i++) {
    city[fireHouses[i].x][fireHouses[i].y].timeToVertex = 0;
    fireHouseHeap.insert(Vertices(fireHouses[i].x,fireHouses[i].y,0));
  } // inserts firehouses as vertices into minHeap
  Vertices v;
  while(knownIntCount != intCount){
    fireHouseHeap.deleteMin(v);
    Intersection &interFire = city[v.x][v.y];
    if(interFire.isKnown){
      continue;
    }
    for (int i = 0; i< interFire.adjCount; i++){
      int newTime = interFire.timeToVertex + interFire.adjacencyList[i].time;
      if (city[interFire.adjacencyList[i].x][interFire.adjacencyList[i].y].timeToVertex > newTime) {
        // update distanceToVertex and insert into fireHouseHeap
        fireHouseHeap.insert(Vertices(interFire.adjacencyList[i].x,interFire.adjacencyList[i].y,newTime));
        city[interFire.adjacencyList[i].x][interFire.adjacencyList[i].y].timeToVertex = newTime;
      }
    }
    interFire.isKnown = true;
    knownIntCount++;
  }
  furthest->x = v.x;
  furthest->y = v.y;
  *time = (v.time*360)/100000;
} // find()

