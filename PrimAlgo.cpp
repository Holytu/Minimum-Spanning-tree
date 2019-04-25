#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int Max_Weight = 1000;
class GraphMST
{
private:
	int num_vertex;
	vector<vector<int> > AdjMatrix;
public:
	GraphMST();
	GraphMST(int n);
	void AddEdge(int from, int to, int weight);
	void PrimMST(int Start = 0);
	int MinKeyExtract(int *key, bool *visited, int size);

};
GraphMST::GraphMST()
{
	num_vertex = 0;
}
GraphMST::GraphMST(int n)
{
	num_vertex = n;
	AdjMatrix.resize(num_vertex);
	for (int i = 0; i < num_vertex; i++)
	{
		AdjMatrix[i].resize(num_vertex);
	}
}
void GraphMST::AddEdge(int from, int to, int weight)
{
	AdjMatrix[from][to] = weight;
}
int GraphMST::MinKeyExtract(int *key, bool *visited, int size)
{
	int min = Max_Weight, min_idx = 0;
	for (int i = 0; i < size; i++)
	{
		if(visited[i] == false && key[i] < min)
		{
			min = key[i];
			min_idx = i;
		}
	}
	return min_idx;
}
void GraphMST::PrimMST(int Start)
{
	int *key = new int[num_vertex];
	int *predecessor = new int[num_vertex];
	bool *visited = new bool[num_vertex];

	for (int i = 0; i < num_vertex; i++)
	{
		key[i] = Max_Weight;
		predecessor[i] = -1;
		visited[i] = false;
	}

	key[Start] = 0;

	for (int i = 0; i < num_vertex; i++)
	{
		int u = MinKeyExtract(key, visited, num_vertex);
		visited[u] = true;

		for (int j = 0; j < num_vertex; j++)
		{
			if(AdjMatrix[u][j] < key[j] && visited[j] == false && AdjMatrix[u][j] != 0) // weight < key, unvisited
			{
				key[j] = AdjMatrix[u][j];
				predecessor[j] = u;
			}
		}
	}

	int x = (Start + 1) % num_vertex;
	while(x != Start)
	{
		cout<<predecessor[x]<<" - "<<x<<" : "<<AdjMatrix[predecessor[x]][x]<<"\n";
		x = (++x) % num_vertex;
	}
}

int main(void)
{
	GraphMST g6(7);
    g6.AddEdge(0, 1, 5);g6.AddEdge(0, 5, 3);
    g6.AddEdge(1, 0, 5);g6.AddEdge(1, 2, 10);
    g6.AddEdge(1, 4, 1);g6.AddEdge(1, 6, 4);
    g6.AddEdge(2, 1, 10);g6.AddEdge(2, 3, 5);g6.AddEdge(2, 6, 8);
    g6.AddEdge(3, 2, 5);g6.AddEdge(3, 4, 7);g6.AddEdge(3, 6, 9);
    g6.AddEdge(4, 1, 1);g6.AddEdge(4, 3, 7);g6.AddEdge(4, 5, 6);g6.AddEdge(4, 6, 2);
    g6.AddEdge(5, 0, 3);g6.AddEdge(5, 4, 6);
    g6.AddEdge(6, 1, 4);g6.AddEdge(6, 2, 8);g6.AddEdge(6, 3, 9);g6.AddEdge(6, 4, 2);

    g6.PrimMST(2);

	return 0;
}

