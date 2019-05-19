#include <iostream>
using namespace std;
void BellmanFord(int graph[][3], int V, int E, int src)
{
    int *status = new int[V];
    bool flag = true;

    for (int i = 0; i < V; i++)
    {
        status[i] = INT_MAX;
    }

    status[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E ; j++)
        {
            if(status[ graph[j][1] ] > status[ graph[j][0] ] + graph[j][2] )
            {
                status[ graph[j][1] ] = status[ graph[j][0] ] + graph[j][2];
            }
        }
    }

    for ( int j = 0; j < E; j++)
    {
        if( status[graph[j][1]] > status[graph[j][0]] + graph[j][2] && status[j] != INT_MAX)
        {
            cout<<"Existed negative cycle\n";
            flag = false;
            break;
        }
    }
    

    if(flag)
    {
        for (int i = 0; i < V; i++)
        {
            cout<<status[i]<<" ";
        }
        cout<<"\n";
    }

}
int main()
{
    int V = 5 , E = 8;
    int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 }, 
                       { 1, 2, 3 }, { 1, 3, 2 },  
                       { 1, 4, 2 }, { 3, 2, 5 },  
                       { 3, 1, 1 }, { 4, 3, -3 } 
                     }; 

    BellmanFord(graph, V, E, 0); 
    return 0; 
}