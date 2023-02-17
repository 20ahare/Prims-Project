/*
Project 1 Minimum Spaning Tree via Prims Algorithm
By Quinn Aiken & Alex Hare
DSA2
2/16/2023
This is our own code we wrote, we took insparation from https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/ 
and https://www.geeksforgeeks.org/measure-execution-time-function-cpp/ for recording execution time.
*/
#include <vector>;
#include <string>;
#include <iostream>;
#include <chrono>;
using namespace std;


class Graph
{
	private:

		// Adjascency Matrix
		vector<vector<int>> adj = {};

		// Number of nodes in graph (initialized to zero)
		int nodes = 0;
	
	
		//Increase adjascency Matrix by adding one to each vector
		void createNode()
		{
			for (int i = 0; i < nodes; i++)
			{
				adj[i].push_back(0);
			}
			nodes = nodes + 1;
			adj.push_back(vector<int>(nodes,0));
			
		}

		// Modify adjascency matrix by adding weights to existing connections
		void createEdge(int a, int b, int weight)
		{
			adj[a][b] = weight;
			adj[b][a] = weight;
		}
	
	public:

		// for empty graph populates given adj matrix
		void import(vector<vector<int>> in)
		{
			for (int i = 0; i < in.size(); i++)
			{
				addNode(in[i]);
			}
		}

		// performs prim's algorithm on graph and outputs MSP to console
		void Prims() 
		{
			Graph p;
			vector <bool> isknown;
			isknown.resize(nodes, false);
			vector<vector<int>> outGraph;
			outGraph.resize(nodes, vector<int>(nodes,0));

			
			isknown[0] = true;
			int minweight = INT_MAX;
			int minIndex = -1;
			int minRow = -1;
			
			//while loop runs until all vertexes are known
			while (count(isknown.begin(), isknown.end(), true) < isknown.size()) 
			{
				minweight = INT_MAX;//reset min and index so another minimum can be found 
				minIndex = -1;
				for (int ii = 0; ii < nodes; ii++) {
					for (int r = 0; r < nodes; r++) {
						if (isknown[ii] == true && adj[ii][r] < minweight && adj[ii][r]>0 && isknown[r] == false) {
							minweight = adj[ii][r];
							minIndex = r;
							minRow = ii;
						}
					}
				}
				isknown[minIndex] = true;//mark that we know that vertex to not check again
				outGraph[minRow][minIndex] = minweight; // add to output adjecency matrix
				outGraph[minIndex][minRow] = minweight;
			}
			p.import(outGraph);
			p.disp();
		}

		// Takes in a vector that provides a list of weights corresponding to the existing nodes  
		void addNode(vector<int> weights)
		{
			// Adds node to graph object
			createNode();
			// populates weights to and from new node
			for (int i = 0; i < nodes; i++)
			{
				createEdge(nodes-1, i, weights[i]);
			}
		}

		// Displays accrued adjascency matrix in square array form
		void disp()
		{
			// Iterate through each entry of matrix and seperate entries by row
			for (int i = 0; i < nodes; i++)
			{
				cout << "|";
			
				for (int j = 0; j < nodes; j++)
				{
					cout << adj[i][j] << "|";
				}
				cout << endl;
			}
		}
};

int main()
{
	// graph g will be user input graph
	Graph g;
	// 2d vector will store user adj matrix before it builds 'g'
	vector<vector<int>> in;
	// int used to store user described size of graph
	int n;
	// String used to store user input for parsing
	string user;

	// Request end number of nodes from user
	cout << "Number of Nodes: ";
 	cin >> n;

	// Create 2d vector to store user adj matrix
	in.resize(n, vector<int>(n));

	// request adjascency matrix from user, in lower triangle format
	// users will input list enclosed in brackets as prompted with entries separated by comas
	cout << endl << "You will now enter each row of your adjacency matrix," << endl << "please seperate entries with commas and enclose each list in square brackets" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		int count = -1;

		// User prompt for correct formatting
		if (i == 0) // If first entry omit mention of comma
			cout << "Please enter row " << i + 1 << " of the lower triangular matrix" << endl << "You should input " << i + 1 << " entry" << endl << endl;
		else 
			cout << endl << "Please enter row " << i + 1 << " of the lower triangular matrix" << endl << "You should input " << i + 1 << " comma seperated entries" << endl << endl;
		
		// take in user input, should be list of values as string
		cin >> user;

		// Parse user input, at each comma increase counter to enter next collumn of matrix
		for (int k = 1; k < user.length() ; k++)
		{
			count++;
			if (user.at(k) == ',' || user.at(k) ==']')
			{
				in[i][j] = stoi(user.substr(k-count,count));
				j++;
				count = -1;
			}
		}
	}
	
	// Populates adjascency matrix from input 2d vector 'in'
	g.import(in);
	
	// Output visual display of adjascency matrix
	cout << endl <<  "The adjacency matrix of the MSP from the input Graph: " << endl << endl;
	
	//	Execute prim's on graph and record time
	auto start = chrono::high_resolution_clock::now();
	g.Prims();
	auto end = chrono::high_resolution_clock::now();

	// display execution time cost
	auto total = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << endl << "Time taken to execute algorthm: " << total.count() << "ms" << endl;


}