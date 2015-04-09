#include <iostream>
#include <list>
using namespace std;
// Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
class graph{
	int v;
	list<int> *adj;

public:
	graph(int v);
	void addEdge(int u, int v);
	bool isBFS(int s, int t);
};

graph::graph(int v){
	this->v = v;
	adj = new list<int>[v];
} 

void graph::addEdge(int x, int y){
	adj[x].push_back(y); // add v to u's list
}

bool graph::isBFS(int s, int t){
	bool *visited = new bool[v];
	for(int j=0; j<v; j++)
		 visited[j] = false;
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	list<int>::iterator i;
	while(!queue.empty()){
		int f = queue.front();
		if(f==t)
			return true;
		queue.pop_front();
		for(i = adj[f].begin(); i != adj[f].end(); i++){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	return false;	
}

int main(){
	graph g(4);
	g.addEdge(0,1);
	g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.isBFS(3,0) ? cout << "yes" : cout << "no";
	return 0;
}