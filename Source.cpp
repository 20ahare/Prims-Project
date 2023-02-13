
#include <vector>;
#include <iostream>;
using namespace std;


class Graph
{
	private:

		// Adjascency Matrix
		vector<vector<int>> adj = {};

		// Number of nodes in graph (initialized to zero)
		int nodes=0;
	
	
		//Increase adjascency Matrix by adding one to each vector
		void createNode()
		{
			nodes = nodes + 1;
			adj.push_back(vector<int>(nodes));
		}

		// Modify adjascency matrix by adding weights to existing connections
		void createEdge(int a, int b, int weight)
		{
			adj[a][b] = weight;
		}
	
	public:

		

		// Takes in a vector that provides a list of weights corresponding to the existing nodes  
		void addNode(vector<int> weights)
		{
			createNode();
			for (int i = 0; i < nodes; i++)
			{
				createEdge(nodes-1, i, weights[i]);
			}
		}
		// Displays accrued adjascency matrix in triangle array form
		void disp()
		{
			for (int i = 0; i < nodes; i++)
			{
				cout << "|";
			
				for (int j = 0; j <= i; j++)
				{
					cout << adj[i][j] << "|";
				}
				cout << endl;
			}
		}
};

int main()
{
	Graph g;
	vector<vector<int>> in;
	int n;

	// Request end number of nodes from user
	cout << "Number of Nodes: ";
 	cin >> n;
	in.resize(n, vector<int>(n));
	// request adjascency matrix from user, in nxn format
	cout << endl << "Please enter the adjascency matrix of the graph in row order: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> in[i][j];
		}
	}
	
	// Add vectors to adjascency matrix from input 2d vector 'in' (row by row)
	for (int i = 0; i < n; i++)
	{
		cout << "i = " << i << endl;
		g.addNode(in[i]);
	}
	
	// Output visual display of adjascency matrix
	g.disp();

}