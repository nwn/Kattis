// Include a GCC-specific header that includes the whole standard library.
#include <bits/stdc++.h>
using namespace std;

int main() {
	// Speed up I/O by disabling synchronization with C stdio and between cin and cout.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Read input
	size_t N, M;
	cin >> N >> M;

	vector<int> gnomes(M);
	for (auto& gnome : gnomes) {
		cin >> gnome;
	}

	// Implement your solution here
	std::vector<int> solution(N);
	std::iota(begin(solution), end(solution), 1);

	for (const auto& gnome : solution) {
		cout << gnome << '\n';
	}
}
