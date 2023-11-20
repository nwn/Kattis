// Include a GCC-specific header that includes the whole standard library.
#include <bits/stdc++.h>
using namespace std;

struct Road {
	size_t dest, length;
};

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

	// Implement your solution here
	vector<size_t> path = { 0, 1 };

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
