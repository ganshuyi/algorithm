// 2019029089_GAN SHU YI_11802
#include <stdlib.h>
#include <iostream>

using namespace std;

int N; // number of vertices
int M; // number of edges

typedef struct Edge {
    int src, dest, weight;
} Edge;

// for union-find
typedef struct subset {
    int parent;
    int rank;
} subset;


Edge * edge;
subset subsets[1000];


void createGraph(int E)
{ 
    edge = new Edge[E];
}
 

int find(int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets[i].parent);
 
    return subsets[i].parent;
}
 

void Union(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
 
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 

void swapFunc(Edge* edge1, Edge* edge2)
{
	Edge temp;
	temp = *edge1;
	*edge1 = *edge2;
	*edge2 = temp;	
}


int partition (int low, int high)  
{  
    Edge pivot = edge[high];  
    int i = (low - 1);   
  
    for (int j = low; j <= high - 1; j++)  
    {    
        if (edge[j].weight < pivot.weight || 
			(edge[j].weight == pivot.weight && edge[j].src < pivot.src) ||
				(edge[j].weight == pivot.weight && edge[j].src == pivot.src && edge[j].dest < pivot.dest)) {
				i++;
				swapFunc(&edge[i], &edge[j]);
		}
    }  
    swapFunc(&edge[i + 1], &edge[high]);  
    return (i + 1);
}  
  

void quickSort(int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(low, high);  
    
        quickSort(low, pi - 1);  
        quickSort(pi + 1, high);  
    }  
} 
 

void KruskalMST()
{
    Edge result[N]; 
    int e = 0; 
    int i = 0; 
 
    for (int v = 0; v < N; ++v) 
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    while (e < N - 1 && i < M) 
    {
        Edge next_edge = edge[i++];
 
        int x = find(next_edge.src);
        int y = find(next_edge.dest);
 
        if (x != y) {
            result[e++] = next_edge;
            Union(x, y);
        }
    }
	   
	cout << e << "\n";
	
	for (i = 0; i < e; i++){
		cout << result[i].src << " " << result[i].dest << " " << result[i].weight << "\n";
	}
}
 

int main()
{
    cin >> N >> M;
    
    createGraph(M);

	int x, y, w;
	for (int i = 0; i < M; i++) {
 		cin >> x >> y >> w;
 		edge[i].src = x;
 		edge[i].dest = y;
 		edge[i].weight = w;
	}
	
	quickSort(0, M - 1);
    
	KruskalMST();
 
    return 0;
}
