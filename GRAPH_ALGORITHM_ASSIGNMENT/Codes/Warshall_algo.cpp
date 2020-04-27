#include <bits/stdc++.h> 
#include<iostream>
using namespace std; 
#define V 4  
#define INF 99999999   
void printSolution(int dist[][V]);  
void floydWarshall (int graph[][V])  
{  
    int dist[V][V], i, j, k;  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
    for (k = 0; k < V; k++)  
    {  
        for (i = 0; i < V; i++)  
        {  
            for (j = 0; j < V; j++)  
            {  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
    printSolution(dist);  
}  
void printSolution(int dist[][V])  
{  
    cout<<"Matrix shows the shortest distances between every pair of vertices \n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
}  
int main()  
{  
    int graph[V][V] = { {0, 5, INF, -3},  
                        {INF, 0, INF, 8},  
                        {INF, 4, 0, -2},  
                        {5, 3, INF, 0}  
                    };  
    floydWarshall(graph);  
    return 0;  
}  
