#ifndef _FINDMAX_H
#define	_FINDMAX_H
#include "RunFind.h"
#include "Intersection.h"
#include <stdlib.h>
#include "BinaryHeap.h"

class FindMax {
public:
  FindMax(int citySize, const StreetBlock *streets, int numStreets);
  void find(Coordinate fireHouses[4], Coordinate *furthest, int *time);
  Intersection city[1000][1000];
  int intCount;
  int knownIntCount;
}; // class FindMax

#endif	/* _FINDMAX_H */

