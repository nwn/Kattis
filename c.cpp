// Include a GCC-specific header that includes the whole standard library.
#include <bits/stdc++.h>
using namespace std;

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
		uint64_t A_steps = 1, B_steps = 2, same_value = 3;

		cout << A << " needs " << A_steps << " steps, ";
		cout << B << " needs " << B_steps << " steps, ";
		cout << "they meet at " << same_value << "\n";
	}
}
