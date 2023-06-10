#pragma once
#include "Graph.h"
#include "OtherClasses.h"
#include <iostream>
using namespace std;
#include <fstream>;
#include <queue>
#include <list>
#include <string>
#include <vector>
ofstream fileName;
struct pqData
{
    int keyWeight, keyDestinationVertex, keySourceVertex;
};
class Compare
{
public:
    bool operator() (const pqData& lhs, const pqData& rhs) const
    {
        return(lhs.keyWeight > rhs.keyWeight);
    }

    priority_queue<pqData, vector<pqData>, Compare> pq;
};
class Edge {
private:
    int sourceVertex, destinationVertex, edgeWeight;
    Edge* nextEdge;
public:
    void setEdge(Edge next);
    int getSource();
    int getDestination();
    int getWeight();
    Edge();
    Edge(int source, int denstination, int weight);   
};
class resultSetClass {
public:
    int parent, weight;

    resultSetClass() {
        parent = -1;
        weight = -1;
    }

};
