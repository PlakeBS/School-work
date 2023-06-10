// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Graph.h"
#include "OtherClasses.h"
#include <iostream>
using namespace std;
#include <fstream>;
#include <queue>
#include <list>
#include <string>
#include <vector>
#include <deque>
ofstream fileName;
/*class Graph {
private:
    int numberOfVertices;
    Edge h(0,0,0);
    vector <list<Edge>> adjacencyListGraph;
    vector <list<Edge>> adjacencyListMST;
    //resultSetClass* resultSet = (resultSetClass*)malloc(sizeof(numberOfVertices));
    resultSetClass resultSet();
    Edge tempEdge;
public:

    Graph() {
        numberOfVertices = 0;
        cout << "Default - Empty Graph Created";
    }
    Graph(int vertices) {
        numberOfVertices = vertices;
        //adjacencyListGraph;
    }
    
    
   
    


    
    
};*/

int main()
{
    cout << "Welcome to the MST Test Program\n";
    cout << "Enter output file name: ";

    string nameForFile;
    ifstream fn_FileName;
    ifstream gd_graphData;
    cin >> nameForFile;
    cout << nameForFile;
    fileName.open(nameForFile + ".txt");
    if (fileName.fail()) {
        cout << "file" << nameForFile << "cannot be opened – program terminated" << endl;
        exit(1);
    }
    fileName << "Output file: " << nameForFile << endl;
    fileName << "Welcome to the MSt test Program";
    cout << "Testing Default Scenario" << endl; fileName << "Testing Default Scenario" << endl;

    //create empty graph here
    Graph bigBoy = Graph();
    bigBoy.primMST();
    bigBoy.printMST();
    cout << "Testing File Data" << endl; fileName << "Testing File Data" << endl;
    cout << "Enter file name for graph data: ";
    string gn_GraphName;
    cin >> gn_GraphName;
    fileName << "File name for graph data: " << gn_GraphName << endl;
    gd_graphData.open(gn_GraphName + ".txt");
    if (!(gd_graphData.is_open())) {
        cout << "file" << gn_GraphName << "cannot be opened or does not exist – program terminated";
        exit(1);
    }
    else if (gd_graphData.eof()) {
        cout << "file" << gn_GraphName << "contains no data – program terminated";
        fileName << "file" << gn_GraphName << "contains no data – program terminated";
    }
    int nov_numOfVert, noe_numOfEdges;
    gd_graphData >> nov_numOfVert;
    gd_graphData >> noe_numOfEdges;
    while (!(gd_graphData.eof())) {
        if (nov_numOfVert < 0) {
            cout << "ERROR: number of vertices: " << nov_numOfVert << "is less than zero\n";
            cout << "Empty Graph Will Be Created\n";
            Graph emptyGraph = Graph(0);
        }
        else if (nov_numOfVert == 0) {
            cout << "Number of vertices: " << nov_numOfVert << " is equal to zero\n";
            cout << "Empty Graph Will Be Created\n";
            Graph theGraph = Graph(0);
        }
        else if (nov_numOfVert > 0) {
            cout << "Number of vertices: " << nov_numOfVert << " is valid\n";
        }
        if (noe_numOfEdges < (nov_numOfVert -1)) {
            cout << "ERROR: " << noe_numOfEdges << " edges invalid to create connected graph" << endl; fileName << "ERROR: " << noe_numOfEdges << " edges invalid to create connected graph" << endl;
            cout << "Empty Graph Will Be Created" << endl; fileName << "Empty Graph Will Be Created" << endl;
            Graph theGraoh = Graph(0);
        }
        else if (noe_numOfEdges < 0) {

        }
        else {
            cout << "Graph with " << nov_numOfVert << " and " << noe_numOfEdges << "will be created" << endl; fileName << "Graph with " << nov_numOfVert << " and " << noe_numOfEdges << "will be created" << endl;
            Graph theGraph = Graph(nov_numOfVert);
        }
        cout << "Number of input edges to process is: " << noe_numOfEdges << endl; fileName << "Number of input edges to process is: " << noe_numOfEdges << endl;
    }
    bigBoy.printGraph();
    bigBoy.primMST();
    bigBoy.printMST();
    cout << "Thank you for running the MST Test Program written by <your name>!" << endl; fileName << "Thank you for running the MST Test Program written by <your name>!" << endl;

    gd_graphData.close();
    fileName.close();

    /*
    if(list < 0) {
       cout << "ERROR: number of vertices: <number of vertices> is less than zero"
    }
    */

}










