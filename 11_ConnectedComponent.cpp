// 2019029089_GAN SHU YI_11802

#include <bits/stdc++.h>

using namespace std;
 

class Graph {
    int V; // number of vertices
    list<int>* adj;
    void DFSUtil(int v, bool visited[]);
 
public:
    Graph(int V); // constructor
    void addEdge(int v, int w);
    int NumberOfConnectedComponents();
};
 

int Graph::NumberOfConnectedComponents()
{
    bool* visited = new bool[V];
 
    int count = 0;
    for (int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            DFSUtil(v, visited);
            count += 1;
        }
    }
 
    return count;
}
 
void Graph::DFSUtil(int v, bool visited[])
{
 
    visited[v] = true;
 
    list<int>::iterator i;
 
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
	v--;
	w--;
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 

int main()
{
	int N; // number of vertices
    int M; // number of edges
    cin >> N >> M;
    
    Graph g(N);

	int x, y; 
	for (int i = 0; i < M; i++) {
 		cin >> x >> y;
 		g.addEdge(x, y);
	}
 
    cout << g.NumberOfConnectedComponents();
 
    return 0;
}
