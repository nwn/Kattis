// Include a GCC-specific header that includes the whole standard library.
#include <bits/stdc++.h>
using namespace std;

struct Road {
	size_t dest, length;
};

vector<size_t> sdsp_successor(vector<vector<Road>> adj_list, size_t dest) {
	using Edge = tuple<size_t, size_t, size_t>; // length, successor, node
	priority_queue<Edge, vector<Edge>, greater<Edge>> queue;
	queue.emplace(0, dest, dest);

	constexpr size_t INF = 1ull << 60;
	vector<size_t> next(adj_list.size(), -1);
	vector<size_t> dist(adj_list.size(), INF);

	// Calculate distance and successor functions using Dijkstra's algorithm.
	while (!queue.empty()) {
		auto [len, via, node] = queue.top();
		queue.pop();
		if (len >= dist[node]) continue;

		dist[node] = len;
		next[node] = via;
		for (auto road : adj_list[node]) {
			if (len + road.length < dist[road.dest]) {
				queue.emplace(len + road.length, node, road.dest);
			}
		}
	}

	return next;
}

vector<size_t> shortest_path(vector<vector<Road>> adj_list, size_t src, size_t dest) {
	using Edge = tuple<size_t, size_t, size_t>; // length, successor, node
	priority_queue<Edge, vector<Edge>, greater<Edge>> queue;
	queue.emplace(0, dest, dest);

	constexpr size_t INF = 1ull << 60;
	vector<size_t> next(adj_list.size(), -1);
	vector<size_t> dist(adj_list.size(), INF);

	// Calculate distance and successor functions using Dijkstra's algorithm.
	while (!queue.empty()) {
		auto [len, prev, node] = queue.top();
		queue.pop();
		if (len >= dist[node]) continue;

		dist[node] = len;
		next[node] = prev;
		if (node == src) break;
		for (auto road : adj_list[node]) {
			if (len + road.length < dist[road.dest]) {
				queue.emplace(len + road.length, node, road.dest);
			}
		}
	}

	if (dist[src] >= INF) return {};

	// Reconstruct shortest path from the successor function.
	vector<size_t> path;
	for (size_t next_node = src; next_node != dest; next_node = next[next_node]) {
		path.push_back(next_node);
	}
	path.push_back(dest);
	return path;
}

int main() {
	// Speed up I/O by disabling synchronization with C stdio and between cin and cout.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Read input
	size_t N, M;
	cin >> N >> M;
	vector<vector<Road>> adj_list(N);
	for (size_t i = 0; i < M; ++i) {
		size_t a, b, d;
		cin >> a >> b >> d;
		adj_list[a].emplace_back(Road {b, d});
		adj_list[b].emplace_back(Road {a, d});
	}

	// Calculate the shortest path from each node to the end.
	auto successors = sdsp_successor(adj_list, 1);

	// Cut the first edge of each shortest path (only in one direction).
	for (size_t node = 0; node < adj_list.size(); ++node) {
		if (successors[node] >= N) continue;
		auto& adj_succ = adj_list[successors[node]];
		for (size_t adj = 0; adj < adj_succ.size(); ++adj) {
			if (adj_succ[adj].dest == node) {
				adj_succ.erase(begin(adj_succ) + adj);
			}
		}
	}

	// Recalculate the shortest path.
	auto path = shortest_path(adj_list, 0, 1);
	if (path.empty()) {
		cout << "impossible\n";
	} else {
		cout << path.size();
		for (auto node : path) {
			cout << " " << node;
		}
		cout << "\n";
	}
}
