#include <iostream>
using namespace std;
#include <fstream>
#include <queue>
#include <list>
#include <string>
#include <vector>
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
		cout << "Default - Empty Graph Created";
	}
	graph(int vertices) 
	{
		numberOfVertices = vertices;
		adjacencyListGraph.resize(numberOfVertices);
		adjacencyListMST.resize(numberOfVertices);
	}
	~graph() {
		/*for (int i = 0; i < adjacencyListGraph.size(); i++) {
			edge* temp = nullptr;
			while (adjacencyListGraph[i].front().nextEdge!= nullptr) {
				edge* deleteNextEdge = temp -> nextEdge;
				delete adjacencyListGraph[i].front().nextEdge;
				temp =deleteNextEdge;
			}
		}
		for (int i = 0; i < adjacencyListMST.size(); i++) {
			edge* temp = nullptr;
			while (adjacencyListMST[i].front().nextEdge != nullptr) {
				edge* deleteNextEdge = temp->nextEdge;
				delete adjacencyListMST[i].front().nextEdge;
				temp = deleteNextEdge;
			}
		}*/
	} 
	void addEdge(int source, int destination, int weight)
	{
		if (numberOfVertices == 0) {
			cout << "Empty Graph – Cannot Add Edge: " <<
				source << "," << destination << "," << weight << endl;
			//fileName << "Empty Graph – Cannot Add Edge: " <<
			//	source << "," << destination << "," << weight << endl;
		}
		else if ((source < 0 || destination < 0) || (source > numberOfVertices || destination > numberOfVertices)) {
			cout << "Invalid Source or Destination Vertex – Cannot Add Edge: " << source << ","
				<< destination << "," << weight << "," << "- Edge request ignored" << endl;
			//fileName << "Invalid Source or Destination Vertex – Cannot Add Edge: " << source << ","
			//	<< destination << "," << weight << "," << "- Edge request ignored" << endl;
		}
		else if (weight <= 0) {
			cout << "Invalid Weight – Cannot Add Edge: " << source << ","
				<< destination << "," << weight << " - Edge request ignored" << endl;
			//fileName << "Invalid Weight – Cannot Add Edge: " << source << ","
			//	<< destination << "," << weight << " - Edge request ignored" << endl;
		}
		else {
			edge edgeObject(source, destination, weight);
			//edgeObject.nextEdge = &adjacencyListGraph[destination].front();
			adjacencyListGraph[source].push_back(edgeObject);
			cout << "Edge Added: " << source << ", " << destination << ", " << weight << endl; //fileName << "Edge Added: " << source << ", " << destination << ", " << weight;
			
			edge destinationObject(destination, source, weight);
			adjacencyListGraph[destination].push_back(destinationObject);
			cout << "Edge Added: " << destination << ", " << source << ", " << weight << endl;//fileName << "Edge Added: " << destination << ", " << source << ", " << weight;
		}
	}
	void printGraph() {
		cout << "Full Graph - Adjacency List" << endl;//fileName << "Full Graph - Adjacency List" << endl;
		for (int i = 0; i < adjacencyListGraph.size(); i++) {
			cout << "Adj[" << i << "] -> ";
			for (const auto& edge : adjacencyListGraph[i])
			{
				cout << "(" << edge.destinationVertex << "," << edge.edgeWeight << ")";
			}
			cout << endl;
		}
	}
	void primMST()
	{
		//cout << " ITS OVER ";
		//creating pqData instances
		pqData extractedPQData, intoPQData;	
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
		//cout << "ANAKIN ";
		//non-edge priority queue to start Minimum spanning tree		
		//weights[0] = 0;
		//////daPQData.keyDestinationVertex = adjacencyListGraph[0].front().destinationVertex;
		//////daPQData.keySourceVertex = adjacencyListGraph[0].front().sourceVertex;
		//////daPQData.keyWeight = adjacencyListGraph[0].front().edgeWeight;
		intoPQData.keyWeight = weights[0];
		intoPQData.keyDestinationVertex = 0;
		intoPQData.keySourceVertex = 0;	
		////for (int i = 0; i < numberOfVertices; i++) {
		////	daPQData.keyDestinationVertex = adjacencyListGraph[i].front().destinationVertex;
		////	daPQData.keySourceVertex = adjacencyListGraph[i].front().sourceVertex;
		////	daPQData.keyWeight = weights[0];
		////}
		priority_queue<pqData, vector<pqData>, Compare> pq;
		/*for (const auto& edge: adjacencyListGraph[i]) {
			source = edge.sourceVertex;
			destination = edge.destinationVertex;
			weight = edge.edgeWeight;
			daPQData.keySourceVertex = source;
			daPQData.keyDestinationVertex = destination;
			daPQData.keyWeight = weight;
			
			i++;
		}*/
		
		pq.push(intoPQData);
		
		resultSet[0].parent = -1;//It is breaking right here
		cout << "176" << adjacencyListMST.size() << endl;
		cout << " I wonder if i can get this in on time: " << resultSet.size() << endl;
		int i = 0;
		while (!(pq.empty())) 
		{
			cout << "DEMON SLAYER" << endl;
			extractedPQData = pq.top();
			pq.pop();
			if (mst[extractedPQData.keyDestinationVertex] == true) {
				cout << "tanjiro" << endl;
				continue;
			}
			mst[extractedPQData.keyDestinationVertex] = true;
			cout << "189" << endl;
			if ((extractedPQData.keyDestinationVertex != 0) || (extractedPQData.keySourceVertex != 0)) {
				//adjacencyListMST[j].push_back(edge(extractedPQData.keySourceVertex, extractedPQData.keyDestinationVertex, extractedPQData.keyWeight));
				edge* ptr = &adjacencyListMST[extractedPQData.keyDestinationVertex].front();
				//edge daEdge = edge(extractedPQData.keySourceVertex, extractedPQData.keyDestinationVertex, extractedPQData.keyWeight);
				//if (adjacencyListMST[extractedPQData.keyDestinationVertex]. == nullptr) {
				if(adjacencyListMST[extractedPQData.keyDestinationVertex].front().nextEdge != nullptr) {
					adjacencyListMST[extractedPQData.keyDestinationVertex].push_back(daEdge);
			//	}
				}
				else {
					adjacencyListMST[extractedPQData.keyDestinationVertex].push_back(daEdge);
				}
				//addEdge(extractedPQData.keySourceVertex, extractedPQData.keyDestinationVertex, extractedPQData.keyWeight);
				resultSet[extractedPQData.keyDestinationVertex].parent = extractedPQData.keySourceVertex;
				resultSet[extractedPQData.keyDestinationVertex].weight = extractedPQData.keyWeight;
				cout << "205" << endl;
				cout << endl << endl << endl << endl;
			}
			cout << endl << "208" << endl;

			for (const auto& edge : adjacencyListMST[extractedPQData.keyDestinationVertex]) {
				//for () {
					cout << " I want to be the very best " << endl;
					if (!mst[edge.destinationVertex]) {
						cout << " LIKE NO ONE EVER WAS" << weights[edge.destinationVertex] << endl;
						if (weights[edge.destinationVertex] > edge.edgeWeight) {
							cout << "TO TRAIN THEM IS MY CAUSE" << endl;
							intoPQData.keyWeight = edge.edgeWeight;
							intoPQData.keySourceVertex = edge.sourceVertex;
							intoPQData.keyDestinationVertex = edge.destinationVertex;
							pq.push(intoPQData);
							weights[edge.destinationVertex] = edge.edgeWeight;

						}

					//}
				}

			}
			i++;
		}
		//delete[] mst;
		//delete[] weights;
	}
	void printMST() {
		int totalMSTWeight = 0;
		cout << "Minimum Spanning Tree" << endl;
		if (numberOfVertices == 0) {
			cout << "Empty Graph - No MST" << endl;
			return;
		}
		for (int i = 1; i < numberOfVertices; i++) {
			std::cout << "Edge: " << i << " - " << resultSet[i].parent << " weight: " << resultSet[i].weight << endl;
			totalMSTWeight += resultSet[i].weight;
			
		}
		std::cout << "Total cost of MST: " << totalMSTWeight << endl;
		std::cout << "MST Graph - Adjacency List" << endl;
		for (int i = 0; i < adjacencyListMST.size(); i++) {
			std::cout << "Adj[" << i << "] -> ";
			for (const auto &edge : adjacencyListMST[i]) {
				std::cout << "(" << edge.destinationVertex << ", " << edge.edgeWeight << ")";
			}
		cout << endl;
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
	//cin >> nameForFile;
	nameForFile = "testing";
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
	//bigBoy.primMST();
	//bigBoy.printMST();
	std::cout << endl << "Testing File Data" << endl; fileName << "Testing File Data" << endl;
	std::cout << "Enter file name for graph data: ";
	string gn_GraphName;
	//cin >> gn_GraphName;
	gn_GraphName = "CIS-Land1";
	fileName << "File name for graph data: " << gn_GraphName << endl;
	gd_graphData.open(gn_GraphName + ".dat");
	if (!(gd_graphData.is_open())) {
		std::cout << "file" << gn_GraphName << "cannot be opened or does not exist - program terminated";
		exit(1);
	}
	else if (gd_graphData.eof()) {
		std::cout << "file" << gn_GraphName << "contains no data – program terminated";
		fileName << "file" << gn_GraphName << "contains no data – program terminated";
	}
	int nov_numOfVert, noe_numOfEdges;
	gd_graphData >> nov_numOfVert;
	gd_graphData >> noe_numOfEdges;
	std::cout << "cool" << endl;
	/**/

	//while (!(gd_graphData.eof())) {
		if (nov_numOfVert < 0) {
			std::cout << "ERROR: number of vertices: " << nov_numOfVert << "is less than zero\n";
			std::cout << "Empty Graph Will Be Created\n";
			graph emptyGraph = graph(0);
		}
		else if (nov_numOfVert == 0) {
			std::cout << "Number of vertices: " << nov_numOfVert << " is equal to zero\n";
			std::cout << "Empty Graph Will Be Created\n";
			graph theGraph = graph(0);
		}
		else if (nov_numOfVert > 0) 
		{
			std::cout << "Number of vertices: " << nov_numOfVert << " is valid\n";
			if (noe_numOfEdges < (nov_numOfVert - 1)) 
			{
				std::cout << "ERROR: " << noe_numOfEdges << " edges invalid to create connected graph" << endl; fileName << "ERROR: " << noe_numOfEdges << " edges invalid to create connected graph" << endl;
				std::cout << "Empty Graph Will Be Created" << endl; fileName << "Empty Graph Will Be Created" << endl;
				graph theGraph = graph(0);
			}
			else if (noe_numOfEdges < 0) 
			{
				std::cout << "ERROR: " << noe_numOfEdges << " edges invalid to create connected graph" << endl; fileName << "ERROR: " << noe_numOfEdges << " edges invalid to create connected graph" << endl;
				std::cout << "Empty Graph Will Be Created" << endl; fileName << "Empty Graph Will Be Created" << endl;
				graph theGraph = graph(0);
			}
			else 
			{
				std::cout << "Graph with " << nov_numOfVert << " and " << noe_numOfEdges << " will be created" << endl; fileName << "Graph with " << nov_numOfVert << " and " << noe_numOfEdges << "will be created" << endl;
				graph theGraph(nov_numOfVert);
				bigBoy = theGraph;
				for (int i = 0; i < noe_numOfEdges; i++) {
					gd_graphData >> source;
					gd_graphData >> destination;
					gd_graphData >> weight;
					bigBoy.addEdge(source, destination, weight);
				}
			} 
		}
		std::cout << "Number of input edges to process is: " << noe_numOfEdges << endl; fileName << "Number of input edges to process is: " << noe_numOfEdges << endl;
		

		
	//}
	bigBoy.primMST();
	bigBoy.printGraph();
	bigBoy.primMST();
	bigBoy.printMST();
	bigBoy.~graph();
	std::cout << "Thank you for running the MST Test Program written by <your name>!" << endl; fileName << "Thank you for running the MST Test Program written by <your name>!" << endl;
/**/
	gd_graphData.close();
	fileName.close();
}