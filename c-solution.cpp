// Include a GCC-specific header that includes the whole standard library.
#include <bits/stdc++.h>
using namespace std;

uint64_t step(uint64_t n) {
	if (n % 2 == 0) return n / 2;
	else return 3 * n + 1;
}

int main() {
	// Speed up I/O by disabling synchronization with C stdio and between cin and cout.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Read input
	while (true) {
		uint64_t A, B;
		cin >> A >> B;
		if (A == 0 && B == 0) break;

		// Implement your solution here
		std::vector<uint64_t> A_values;
		for (uint64_t a = A; a != 1; a = step(a)) {
			A_values.push_back(a);
		}
		std::vector<uint64_t> B_values;
		for (uint64_t b = B; b != 1; b = step(b)) {
			B_values.push_back(b);
		}

		uint64_t same_value = 1;
		while (!A_values.empty() && !B_values.empty() && A_values.back() == B_values.back()) {
			same_value = A_values.back();
			A_values.pop_back();
			B_values.pop_back();
		}
		size_t A_steps = A_values.size();
		size_t B_steps = B_values.size();

		cout << A << " needs " << A_steps << " steps, ";
		cout << B << " needs " << B_steps << " steps, ";
		cout << "they meet at " << same_value << "\n";
	}
}
