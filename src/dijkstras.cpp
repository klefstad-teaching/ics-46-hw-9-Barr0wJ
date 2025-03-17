#include dijkstras.h

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
	int numVertices = G.size();
	vector<int> distances(numVertices,INF);
	vector<bool> visited(numVertices,false);
	distances[source] = 0;
	previous[source] = -1;
	priority_queue<pair<int,int>> minHeap; //pair<vertex,weight>
	minHeap.push({source,0});
	while (!minHeap.empty()){
		int u = minHeap.extract_shortest_path().first();
		if(visited[u]) continue;
		visited[u] = true;
		for (Edge edge:G[u]){
			int v = edge.dst;
			int weight = edge.weight;
			if((!visited[v])&&(distances[u]+weight < distance[v])){
				distance[v] = distance[u] + weight;
				previous[v] = u;
				minHeap.push({v,distances[v]});
			}
		}
	}
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
	
}