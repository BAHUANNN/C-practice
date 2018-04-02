#ifndef _recursion_
#define _recursion_

#include "map.h"
#include "vector.h"
#include "set.h"
#include "gwindow.h"
#include "gbufferedimage.h"

using namespace std;

void personal();

int gcd(int a, int b);

void serpinskii(GWindow &w, int x1, int x2, int x3, int y1, int y2, int y3, int size, int order) ;

int floodFill(GBufferedImage& image, int x, int y, int color);

void personalCurriculum(Map<string, Vector<string> > & prereqMap, string goal);

string generate(Map<string, Vector<string> > & grammar, string symbol);

#endif
