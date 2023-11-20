// Include a GCC-specific header that includes the whole standard library.
#include <bits/stdc++.h>
using namespace std;

constexpr static size_t N = 4;
using Board = array<array<int, N>, N>;

int main() {
	// Speed up I/O by disabling synchronization with C stdio and between cin and cout.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Read input
	Board board;
	for (auto& row : board) {
		for (auto& cell : row) {
			cin >> cell;
		}
	}
	int direction;
	cin >> direction;

	// Implement your solution here

	for (const auto& row : board) {
		bool first = true;
		for (const auto& cell : row) {
			cout << (first ? "" : " ") << cell;
			first = false;
		}
		cout << '\n';
	}
}
