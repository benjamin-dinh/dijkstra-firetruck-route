//
// Created by Benjamin Dinh on 3/9/20.
//

#ifndef P5_INTERSECTION_H
#define P5_INTERSECTION_H
#include "RunFind.h"

class Vertices{
 public:
  int x;
  int y;
  int time;
  Vertices();
};

class Intersection{
 public:
  bool isKnown;
  Vertices previousVertex;
  int distanceToVertex;
  int count; // count for number of adjacent vertices
  int count2; // count for stopping entire process
  Intersection();
  Vertices adjacencyList[4];
};



#endif //P5_INTERSECTION_H
