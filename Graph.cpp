#include "Graph.h"
Graph::Graph() {
    numberOfVertices = 0;
    cout << "Default - Empty Graph Created";
}
Graph::Graph(int vertices) {
    numberOfVertices = vertices;
    //adjacencyListGraph;
}
void Graph::addEdge(int source, int destination, int weight) {
    if (numberOfVertices == 0) {
        cout << "Empty Graph – Cannot Add Edge: " <<
            source << "," << destination << "," << weight << endl;
        fileName << "Empty Graph – Cannot Add Edge: " <<
            source << "," << destination << "," << weight << endl;
    }
    else if ((source < 0 || destination < 0) || (source > numberOfVertices || destination > 0)) {
        cout << "Invalid Source or Destination Vertex – Cannot Add Edge: " << source << ","
            << destination << "," << weight << "," << "- Edge request ignored" << endl;
        fileName << "Invalid Source or Destination Vertex – Cannot Add Edge: " << source << ","
            << destination << "," << weight << "," << "- Edge request ignored" << endl;
    }
    else if (weight <= 0) {
        cout << "Invalid Weight – Cannot Add Edge: " << source << ","
            << destination << "," << weight << " - Edge request ignored" << endl;
        fileName << "Invalid Weight – Cannot Add Edge: " << source << ","
            << destination << "," << weight << " - Edge request ignored" << endl;
    }
    else {
        //(source, destination, weight);
        adjacencyListGraph[source].push_back(tempEdge);
        cout << "Edge Added: " << source << ", " << destination << ", " << weight;
        fileName << "Edge Added: " << source << ", " << destination << ", " << weight;
        Edge destinationVertex = Edge(destination, source, weight);
        adjacencyListGraph[destination].push_back(destinationVertex);
        cout << "Edge Added: " << destination << ", " << source << ", " << weight;
        fileName << "Edge Added: " << destination << ", " << source << ", " << weight;

    }

}
void Graph::printGraph() {
    cout << "“Full Graph – Adjacency List" << endl;
    fileName << "“Full Graph – Adjacency List" << endl;
    for (int i = 0; i < adjacencyListGraph.size(); i++) {
        cout << "Adj[Vertex] -> (destination1, cost1)(destination2, cost2)";
    }
}
void Graph::primMST() {
    pqData extractedPQData;
    pqData intoPQData;
    bool* mst = new bool(numberOfVertices);

    for (int i = 0; i < sizeof(mst); i++) {
        mst[i] = false;
    }
    // ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ;
     //resultSetClass* resultSet() = new resultSetClass(numberOfVertices) ; 
     //resultSetClass* resultSet();



    resultSetClass instances;
    // for (int i = 0; i < sizeof(resultSet); i++) {
         //resultSet[i] = instances;
    // }
    int* weights = new int(numberOfVertices);
    for (int i = 0; i < sizeof(weights); i++) {
        weights[i] = INT_MAX;
    }
    // priority_queue;
     //? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ;
     //Vertex 0 is starting vertex – create non - edge priority queue entry to start MST
     //Vertex = 0;

    // creating non-edge priority queue entry to start MST
    priority_queue<pqData> testingQ;
    testingQ.top();
    weights[0] = 0;
    intoPQData.keyWeight = weights[0];
    intoPQData.keyDestinationVertex = 0;
    intoPQData.keySourceVertex = 0;
    //  add pqData to min-heap priority queue


    //resultSet[0].parent = -1;
    while (!(testingQ.empty())) {
        extractedPQData = testingQ.top();
        testingQ.pop();
        if (mst[extractedPQData.keyDestinationVertex]) {
            continue;
        }
        mst[extractedPQData.keyDestinationVertex] = true;
        if ((extractedPQData.keyDestinationVertex != 0) || (extractedPQData.keySourceVertex != 0)) {
            //? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ;
            Edge adjacencyEntry(extractedPQData.keySourceVertex, extractedPQData.keyDestinationVertex, extractedPQData.keyWeight);
            adjacencyListMST.at(extractedPQData.keySourceVertex).push_back(adjacencyEntry);
            //resultSet[extractedPQData.keyDestinationVertex].parent = extractedPQData.keySourceVertex;
            //resultSet[extractedPQData.keyDestinationVertex].weight = extractedPQData.keyWeight;
        }

        Edge temp = Edge(0, 0, 0);
        Edge testVar = Edge(intoPQData.keyWeight, intoPQData.keyWeight, intoPQData.keyWeight);
        temp.setEdge(testVar);
        for (int i = 0; i < extractedPQData.keyDestinationVertex; i++) {
            if (mst[temp.getDestination()]) {
                if (weights[temp.getDestination()] > temp.getWeight()) {
                    Edge daEdge = Edge(intoPQData.keyWeight, intoPQData.keyDestinationVertex, intoPQData.keySourceVertex);
                    testingQ.push(intoPQData);
                    weights[temp.getDestination()] = temp.getWeight();
                }
            }


        }

    }

    delete[]weights;
    delete[]mst;
    // delete[]resultSet;
}
void Graph::printMST() {
    int totalMSTWeight = 0;
    int nbr = 10;
    cout << "Minimum Spanning Tree" << endl;
    if (numberOfVertices == 0) {
        cout << "Empty Graph – No MST" << endl;
        return;
    }
    //for (int i = 0; i < sizeof(resultSet); i++) {
    cout << "Edge: " << nbr;
    // }
}