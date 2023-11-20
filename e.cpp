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

	// Implement your solution here
	double solution = 0.0;

	cout.precision(16);
	cout << solution << '\n';
}
