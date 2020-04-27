#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 
# define INF 0x4
typedef pair<int, int> iPair; 
class Graph 
{ 
    int V;    
    list< pair<int, int> > *adj; 
public: 
    Graph(int V);  
    void addEdge(int u, int v, int w); 
    void primMST(); 
}; 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
void Graph::primMST() 
{ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  	int src = 0; 
    vector<int> key(V, INF); 
    vector<int> parent(V, -1); 
    vector<bool> inMST(V, false); 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
  
        inMST[u] = true;  
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 
            if (inMST[v] == false && key[v] > weight) 
            { 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 
    for (int i = 1; i < V; ++i) 
        printf("%d - %d\n", parent[i], i); 
} 
  int main() 
{ 
    int V = 9; 
    Graph g(V); 
    g.addEdge(1, 3, 4); 
    g.addEdge(1, 2, 4); 
    g.addEdge(2, 3, 2); 
    g.addEdge(3, 4, 3); 
    g.addEdge(3, 5, 4); 
    g.addEdge(3, 6, 2); 
    g.addEdge(5, 6, 3); 
    g.addEdge(4, 5, 3); 
    cout<<"PATH of Prim's Algorithm as : \n";
    g.primMST(); 
    cout<<"Cost is : 14";
  
    return 0; 
} 
