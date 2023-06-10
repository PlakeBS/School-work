#pragma once
#include "OtherClasses.h"
class Graph {
private:
	int numberOfVertices;
	Edge* h = nullptr;
	vector <list<Edge>> adjacencyListGraph;
	vector <list<Edge>> adjacencyListMST;
	list <vector<Edge>> adjacencyListGraph2;
	resultSetClass* resultSet = (resultSetClass*)malloc(sizeof(numberOfVertices));
	//resultSetClass resultSet();
	Edge tempEdge;
public:
	Graph();
	Graph(int vertices);
	void addEdge(int source, int destination, int weight);
	void printGraph();  
	void primMST();
	void printMST();
};
