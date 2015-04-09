#include <iostream>
#include <list>
using namespace std;

class graph{
	int V;
	list <int> *adj;
	void DFSutil(int v, bool visited[]);

public:
	graph(int V);
	void addEdge(int x, int y);
	void DFS(int s);
};

graph::graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void graph::addEdge(int x, int y){
	adj[x].push_back(y);
}

void graph::DFSutil(int v, bool visited[]){
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for(i=adj[v].begin(); i!=adj[v].end(); i++){
		if(!visited[*i]){
			visited[*i] = true;
			DFSutil(*i, visited);
		}
	}
}

void graph::DFS(int v){
	bool *visited = new bool[V];
	for(int i=0; i<V; i++)
		visited[i] = false;
	DFSutil(v, visited);		 
}

int main(){
	graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "DGS traversal from vertex 2 \n";
    g.DFS(2);  
	return 0;	
}