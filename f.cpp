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
	int alice = 42, bob = 42;

	cout << alice << ' ' << bob << '\n';
}
