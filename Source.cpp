
#include <vector>;
#include <string>;
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
	Graph g;
	vector<vector<int>> in;
	int n;
	string user;

	// Request end number of nodes from user
	cout << "Number of Nodes: ";
 	cin >> n;
	in.resize(n, vector<int>(n));
	// request adjascency matrix from user, in lower triangle format
	// users will input list enclosed in brackets as prompted with entries separated by comas

	
	cout << endl << "You will now enter each row of your adjacency matrix," << endl << "please seperate entries with commas and enclose each list in square brackets" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		int count = -1;
		if (i == 0)
			cout << "Please enter row " << i + 1 << " of the lower triangular matrix" << endl << "You should input " << i + 1 << " entry" << endl << endl;
		else
			cout << endl << "Please enter row " << i + 1 << " of the lower triangular matrix" << endl << "You should input " << i + 1 << " comma seperated entries" << endl << endl;

		cin >> user;

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

	
	// Populates adjascency matrix from input 2d vector 'in' (row by row)
	for (int i = 0; i < n; i++)
	{
		g.addNode(in[i]);
	}
	
	// Output visual display of adjascency matrix
	cout << endl <<  "The adjacency matrix of the graph input: " << endl << endl;
	g.disp();

}