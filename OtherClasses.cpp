#include "OtherClasses.h"
#include "Graph.h"
void Edge::setEdge(Edge next) {
    nextEdge = &next;
}
int Edge::getSource() {
    return sourceVertex;
}
int Edge::getDestination() {
    return destinationVertex;
}
int Edge::getWeight() {
    return edgeWeight;
}
Edge::Edge() {
    sourceVertex = -1;
    destinationVertex = -1;
    edgeWeight = -1;
    nextEdge = nullptr;
}
Edge::Edge(int source, int denstination, int weight) {
    sourceVertex = source;
    destinationVertex = denstination;
    edgeWeight = weight;
}


