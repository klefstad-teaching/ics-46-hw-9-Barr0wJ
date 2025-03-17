#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
	int numVertices = G.size();
	vector<int> distances(numVertices,INF);
	previous.assign(numVertices, -1);
	vector<bool> visited(numVertices,false);
	distances[source] = 0;
	previous[source] = -1;
	priority_queue<pair<int,int>> minHeap; //pair<vertex,weight>
	minHeap.push({source,0});
	while (!minHeap.empty()){
		int u = minHeap.top().first;
		minHeap.pop();
		if(visited[u]) continue;
		visited[u] = true;
		for (Edge edge:G[u]){
			int v = edge.dst;
			int weight = edge.weight;
			if((!visited[v])&&(distances[u]+weight < distances[v])){
				distances[v] = distances[u] + weight;
				previous[v] = u;
				minHeap.push({v,distances[v]});
			}
		}
	}
	return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
	int size = previous.size();
	stack<int> output;
	vector<int> re_ordered;
	output.push(destination);
	for (int i = 1; i<size;i++){
		output.push(previous[i]);
	}
	while(!output.empty()){
		re_ordered.push_back(output.top());
		output.pop();
	}
	return re_ordered;
}

void print_path(const vector<int>& v, int total){
	int size = v.size();
	for (int i = 0;i<size;i++){
        cout << v[i] << " ";
    }
    cout << endl << "Total cost is " << total << endl;
}