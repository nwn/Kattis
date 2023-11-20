// Include a GCC-specific header that includes the whole standard library.
#include <bits/stdc++.h>
using namespace std;

int main() {
	// Speed up I/O by disabling synchronization with C stdio and between cin and cout.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Read input
	size_t N, B, R;
	cin >> N >> B >> R;

	vector<pair<int, int>> blue_plants(B);
	for (auto & [x, y] : blue_plants) {
		cin >> x >> y;
	}
	vector<pair<int, int>> red_plants(R);
	for (auto & [x, y] : red_plants) {
		cin >> x >> y;
	}

	vector<vector<double>> dist(B);
	vector<double> all_dists;
	all_dists.reserve(B * R);
	for (size_t b = 0; b < B; ++b) {
		dist[b].resize(R);
		for (size_t r = 0; r < R; ++r) {
			double dx = red_plants[r].first - blue_plants[b].first;
			double dy = red_plants[r].second - blue_plants[b].second;
			double d = hypot(dx, dy);
			dist[b][r] = d;
			all_dists.push_back(d);
		}
	}
	sort(begin(all_dists), end(all_dists));
	all_dists.erase(unique(begin(all_dists), end(all_dists)), end(all_dists));

	// Implement your solution here
	double solution = 0.0;

	cout.precision(16);
	cout << solution << '\n';
}
