//
// Created by Benjamin Dinh on 3/9/20.
//

#include "Intersection.h"
#include <cstring>

Vertices::Vertices(){
  x = NULL;
  y = NULL;
  time = NULL;
}

Vertices::Vertices(int m, int n, int t){
  x=m;
  y=n;
  time=t;
}

Intersection::Intersection() {
  isKnown = false;
  distanceToVertex = 1000000;
  adjCount = 0;
//  for (int i = 0; i<4; i++){
//    adjacencyList[i].x = NULL;
//    adjacencyList[i].y = NULL;
//    adjacencyList[i].time = NULL;
//  }
}
