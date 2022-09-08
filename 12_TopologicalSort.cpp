// 2019029089_GAN SHU YI_11802

#include <iostream> 
#include <list> 
#include <stack>

using namespace std; 


class Graph { 
    int V; // number of vertices
    list<int>* adj; 
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack); 
	bool isCyclicUtil(int v, bool visited[], bool *recStack);
	
	public:
    Graph(int V); 
    void addEdge(int v, int w);
    bool isCyclic();
    void topologicalSort();
}; 
  
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
} 

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    {
        visited[v] = true; 
        recStack[v] = true; 
   
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false; 
    return false; 
} 
   
bool Graph::isCyclic() 
{  
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
} 

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack)                                
{ 
    
    visited[v] = true;
    
    adj[v].sort();
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 

    Stack.push(v);
} 
  

void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
  
    bool* visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
   
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            topologicalSortUtil(i, visited, Stack); 
   
    while (Stack.empty() == false) { 
        cout << Stack.top() + 1 << " "; 
        Stack.pop(); 
    } 
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
    if (g.isCyclic()) 
		cout << 0 << endl;
    else {
    	cout << 1 << endl;
    	g.topologicalSort();
	}
     
  
    return 0; 
}
