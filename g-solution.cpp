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
	unordered_set<int> seen;
	for (auto& gnome : gnomes) {
		cin >> gnome;
		seen.emplace(gnome);
	}

	size_t pos = 0;
	for (int i = 1; i <= N; ++i) {
		if (seen.count(i) > 0) continue;

		while (pos < gnomes.size() && gnomes[pos] < i) ++pos;
		gnomes.insert(begin(gnomes) + pos, i);
	}

	for (const auto& gnome : gnomes) {
		cout << gnome << '\n';
	}
}
