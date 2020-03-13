//
// Created by Benjamin Dinh on 3/9/20.
//

#ifndef P5_INTERSECTION_H
#define P5_INTERSECTION_H

class Vertices{
 public:
  int x;
  int y;
  int time;
  Vertices();
  Vertices(int m, int n, int t);
};

class Intersection{
 public:
  bool isKnown;
  Vertices previousVertex;
  int timeToVertex;
  int adjCount; // count for number of adjacent vertices
  Intersection();
  Vertices adjacencyList[4];
};



#endif //P5_INTERSECTION_H
