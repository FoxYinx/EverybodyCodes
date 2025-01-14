#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "DisjointSet.h"

int distance(const Pos& a, const Pos& b);
int constellationSize(const vector<Edge>& constellation);
vector<Edge> createEdges(const vector<Pos>& G);
vector<Edge> sortEdgesByWeight(const vector<Pos>& G);
vector<Edge> kruskal(const vector<Pos>& G);

#endif
