// Include a GCC-specific header that includes the whole standard library.
#include <bits/stdc++.h>
using namespace std;

int main() {
	// Speed up I/O by disabling synchronization with C stdio and between cin and cout.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Read input
	size_t n;
	cin >> n;
	vector<int> pieces(n);
	for (auto& piece : pieces) {
		cin >> piece;
	}

	// Implement your solution here
	sort(pieces.begin(), pieces.end(), greater<int>());
	int alice = 0, bob = 0;
	for (size_t i = 0; i < pieces.size(); ++i) {
		if (i % 2 == 0) alice += pieces[i];
		else bob += pieces[i];
	}

	cout << alice << ' ' << bob << '\n';
}
