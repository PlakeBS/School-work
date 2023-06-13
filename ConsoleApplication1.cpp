
using namespace std;
#include <fstream>
#include <queue>
#include <list>
#include <string>
#include <vector>
#include <iostream>
ofstream fileName;
ifstream gd_graphData;
struct pqData
{
	int keyWeight, keyDestinationVertex, keySourceVertex;
};
class Compare
{
public:
	bool operator() (const pqData& lhs, const pqData& rhs) const
	{
		return (lhs.keyWeight > rhs.keyWeight); //min priority
	}
};
class edge
{
public:
	int sourceVertex, destinationVertex, edgeWeight;
	edge* nextEdge;
	//Public functions
	edge()
	{
		sourceVertex = -1;
		destinationVertex = -1;
		edgeWeight = -1;
		nextEdge = nullptr;
	}
	edge(int source, int destination, int weight)
	{
		sourceVertex = source;
		destinationVertex = destination;
		edgeWeight = weight;
		nextEdge = nullptr;
	}
};
class resultSetClass
{
public:
	int parent, weight;
	resultSetClass() {
		parent = -1;
		weight = -1;
	}
};
class graph
{
private:
public:
	int numberOfVertices;
	vector<list<edge>> adjacencyListGraph;
	vector<list<edge>> adjacencyListMST;
	vector<resultSetClass> resultSet;

	graph()
	{
		numberOfVertices = 0;
		cout << "Default - Empty Graph Created" << endl;
	}
	graph(int vertices)
	{
		numberOfVertices = vertices;
		adjacencyListGraph.resize(numberOfVertices);
		adjacencyListMST.resize(numberOfVertices);
	}
	~graph() {
		resultSet.clear();
	}
	void addEdge(int source, int destination, int weight)
	{
		if (numberOfVertices == 0) {
			cout << "Empty Graph – Cannot Add Edge: " <<
				source << "," << destination << "," << weight << endl;
			fileName << "Empty Graph – Cannot Add Edge: " <<
				source << "," << destination << "," << weight << endl;
		}
		else if ((source < 0 || destination < 0) || (source > numberOfVertices || destination > numberOfVertices)) {
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
			edge edgeObject(source, destination, weight);
			edge destinationObject(destination, source, weight);

			edgeObject.nextEdge = &destinationObject;
			adjacencyListGraph[source].push_back(edgeObject);
			cout << "Edge Added: " << source << ", " << destination << ", " << weight << endl; fileName << "Edge Added: " << source << ", " << destination << ", " << weight << endl;

			
			
			adjacencyListGraph[destination].push_back(destinationObject);
			cout << "Edge Added: " << destination << ", " << source << ", " << weight << endl;fileName << "Edge Added: " << destination << ", " << source << ", " << weight << endl;
		}
	}
	void printGraph() {
		cout << "Full Graph - Adjacency List" << endl;fileName << "Full Graph - Adjacency List" << endl; fileName << "Full Graph - Adjacency List" << endl; fileName << "Full Graph - Adjacency List" << endl;
		for (int i = 0; i < adjacencyListGraph.size(); i++) {
			cout << "Adj[" << i << "] -> "; fileName << "Adj[" << i << "] -> ";
			for (const auto& edge : adjacencyListGraph[i])
			{
				cout << "(" << edge.destinationVertex << "," << edge.edgeWeight << ")"; fileName << "(" << edge.destinationVertex << "," << edge.edgeWeight << ")";
			}
			cout << endl; fileName << endl;
		}
	}
	void primMST()
	{
		//creating pqData instances
		pqData extractedPQData{}, intoPQData{};
		if (numberOfVertices == 0) {
			return;
		}
		//creating and then initializing a set of arrays 
		resultSet.resize(numberOfVertices);
		adjacencyListMST.resize(numberOfVertices);
		bool* mst = new bool[numberOfVertices]; // Will be used to let us know if we have been to that node before
		int* weights = new int[numberOfVertices]; // used to figure out the weight
		for (int i = 0; i < numberOfVertices; i++) {
			mst[i] = false;
			resultSet[i] = resultSetClass();
			weights[i] = INT_MAX;
		}

		priority_queue<pqData, vector<pqData>, Compare> pq;
		weights[0] = 0;
		intoPQData.keyWeight = weights[0];
		intoPQData.keyDestinationVertex = 0;
		intoPQData.keySourceVertex = 0;

		pq.push(intoPQData);

		resultSet[0].parent = -1;//It is breaking right here
		while (!(pq.empty()))
		{
			extractedPQData = pq.top();
			pq.pop();
			if (mst[extractedPQData.keyDestinationVertex] == true) {
				continue;
			}
			mst[extractedPQData.keyDestinationVertex] = true;
			if ((extractedPQData.keyDestinationVertex != 0) || (extractedPQData.keySourceVertex != 0)) {

				edge sourceMST(extractedPQData.keySourceVertex, extractedPQData.keyDestinationVertex, extractedPQData.keyWeight);
				edge destinationMST(extractedPQData.keyDestinationVertex, extractedPQData.keySourceVertex, extractedPQData.keyWeight);
				sourceMST.nextEdge = &destinationMST;
				adjacencyListMST[extractedPQData.keySourceVertex].push_back((sourceMST));
				adjacencyListMST[extractedPQData.keyDestinationVertex].push_back((destinationMST));

				resultSet[extractedPQData.keyDestinationVertex].parent = extractedPQData.keySourceVertex;
				resultSet[extractedPQData.keyDestinationVertex].weight = extractedPQData.keyWeight;
			}

			for (const auto &edge : adjacencyListGraph[extractedPQData.keyDestinationVertex]) {
				if ((mst[edge.destinationVertex]) == false) {
					if (weights[edge.destinationVertex] > edge.edgeWeight) {
						intoPQData.keyWeight = edge.edgeWeight;
						intoPQData.keySourceVertex = edge.sourceVertex;
						intoPQData.keyDestinationVertex = edge.destinationVertex;

						pq.push(intoPQData);
						weights[edge.destinationVertex] = edge.edgeWeight;

					}
				}

			}
		}
		delete[] mst;
		delete[] weights;
	}
	void printMST() {
		int totalMSTWeight = 0;
		cout << "Minimum Spanning Tree" << endl; fileName << "Minimum Spanning Tree" << endl;
		if (numberOfVertices == 0) {
			cout << "Empty Graph - No MST" << endl; fileName << "Empty Graph - No MST" << endl;
			return;
		}
		for (int i = 1; i < numberOfVertices; i++) {
			std::cout << "Edge: " << i << " - " << resultSet[i].parent << " weight: " << resultSet[i].weight << endl; fileName << "Edge: " << i << " - " << resultSet[i].parent << " weight: " << resultSet[i].weight << endl;
			totalMSTWeight += resultSet[i].weight;

		}
		cout << "Total cost of MST: " << totalMSTWeight << endl; fileName << "Total cost of MST: " << totalMSTWeight << endl;
		cout << "MST Graph - Adjacency List" << endl; fileName << "MST Graph - Adjacency List" << endl;
		for (int i = 0; i < numberOfVertices; i++) {
			cout << "Adj[" << i << "] -> "; fileName << "Adj[" << i << "] -> ";
			for (const auto& edge : adjacencyListMST[i]) {
				cout << "(" << edge.destinationVertex << ", " << edge.edgeWeight << ")"; fileName << "(" << edge.destinationVertex << ", " << edge.edgeWeight << ")";
			}
			cout << endl; fileName << endl;
		}
	}
};
int main()
{
	std::cout << "Welcome to the MST Test Program\n";
	std::cout << "Enter output file name: ";
	string daString;
	string nameForFile;
	ifstream fn_FileName;
	int source, destination, weight;
	cin >> nameForFile;
	std::cout << nameForFile;
	fileName.open(nameForFile + ".txt");
	if (!fileName.is_open()) {
		std::cout << "file" << nameForFile << "cannot be opened – program terminated" << endl;
		exit(1);
	}
	fileName << "Output file: " << nameForFile << endl;
	fileName << "Welcome to the MSt test Program";
	std::cout << "Testing Default Scenario" << endl; fileName << "Testing Default Scenario" << endl;

	//create empty graph here
	graph bigBoy;
	bigBoy.primMST();
	bigBoy.printMST();
	std::cout << endl << "Testing File Data" << endl; fileName << "Testing File Data" << endl;
	std::cout << "Enter file name for graph data: ";
	string gn_GraphName;
	cin >> gn_GraphName;
	fileName << "File name for graph data: " << gn_GraphName << endl;
	gd_graphData.open(gn_GraphName + ".txt");
	if ((gd_graphData.fail())) {
		std::cout << "file" << gn_GraphName << "cannot be opened or does not exist - program terminated";
		exit(1);
	}
	if (gd_graphData.eof()) {
		std::cout << "file" << gn_GraphName << "contains no data – program terminated";
		fileName << "file" << gn_GraphName << "contains no data – program terminated";
	}
	int nov_numOfVert, noe_numOfEdges;
	gd_graphData >> nov_numOfVert;
	gd_graphData >> noe_numOfEdges;
	/**/
	string skip;
	while (!gd_graphData.eof()) {
		if (nov_numOfVert < 0) {
			std::cout << "ERROR: number of vertices: " << nov_numOfVert << "is less than zero\n";
			std::cout << "Empty Graph Will Be Created\n";
			for (int i = 0; i < noe_numOfEdges+1; i++) {
				getline(gd_graphData, skip);
			}
			graph emptyGraph = graph(0);
		}
		else if (nov_numOfVert == 0) {
			std::cout << "Number of vertices: " << nov_numOfVert << " is equal to zero\n";
			std::cout << "Empty Graph Will Be Created\n";
			for (int i = 0; i < noe_numOfEdges+1; i++) {
				getline(gd_graphData, skip);
			}
			graph theGraph = graph(0);
		}
		else if (nov_numOfVert > 0)
		{
			std::cout << "Number of vertices: " << nov_numOfVert << " is valid\n";
			if (noe_numOfEdges < (nov_numOfVert - 1))
			{
				std::cout << "ERROR: " << noe_numOfEdges << " edges invalid to create connected graph" << endl; fileName << "ERROR: " << noe_numOfEdges << " edges invalid to create connected graph" << endl;
				std::cout << "Empty Graph Will Be Created " << endl; fileName << " Empty Graph Will Be Created" << endl;
				for (int i = 0; i < noe_numOfEdges+1; i++) {
					getline(gd_graphData, skip);
				}
				graph theGraph = graph(0);
			}
			else if (noe_numOfEdges < 0)
			{
				std::cout << "ERROR: " << noe_numOfEdges << " edges invalid to create connected graph" << endl; fileName << "ERROR: " << noe_numOfEdges << " edges invalid to create connected graph" << endl;
				std::cout << "Empty Graph Will Be Created " << endl; fileName << "Empty Graph Will Be Created" << endl;
				for (int i = 0; i < noe_numOfEdges+1; i++) {
					getline(gd_graphData, skip);
				}
				graph theGraph = graph(0);
			}

			else
			{
				std::cout << "Graph with " << nov_numOfVert << " and " << noe_numOfEdges << " will be created" << endl; fileName << "Graph with " << nov_numOfVert << " and " << noe_numOfEdges << " will be created" << endl;
				graph theGraph(nov_numOfVert);
				bigBoy = theGraph;
				for (int i = 0; i < noe_numOfEdges; i++) {
					gd_graphData >> source;
					gd_graphData >> destination;
					gd_graphData >> weight;
					if (nov_numOfVert <= source){
						cout << "ERROR: invalid input number of vertices is less than given source vertex " << endl;					
					}
					else {
						bigBoy.addEdge(source, destination, weight);
					}
				}
				std::cout << "Number of input edges to process is: " << noe_numOfEdges << endl; fileName << "Number of input edges to process is: " << noe_numOfEdges << endl;
				bigBoy.primMST();
				bigBoy.printGraph();
				bigBoy.printMST();
			}
		}
		gd_graphData >> nov_numOfVert;
		gd_graphData >> noe_numOfEdges;
	}
	std::cout << "Thank you for running the MST Test Program written by <your name>!" << endl; fileName << "Thank you for running the MST Test Program written by Blake Parker Simpson!" << endl;
	/**/
	gd_graphData.close();
	fileName.close();
	
}


