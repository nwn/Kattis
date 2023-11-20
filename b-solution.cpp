// Include a GCC-specific header that includes the whole standard library.
#include <bits/stdc++.h>
using namespace std;

int main() {
	// Speed up I/O by disabling synchronization with C stdio and between cin and cout.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		size_t N;
		cin >> N;
		if (N == 0) break;

		// Implement your solution here
		std::string reg(32, '?');
		for (size_t n = 0; n < N; ++n) {
			string instr;
			int i;
			cin >> instr >> i;
			if (instr == "CLEAR") {
				reg[i] = '0';
			} else if (instr == "SET") {
				reg[i] = '1';
			} else {
				int j;
				cin >> j;
				if (instr == "OR") {
					if (reg[i] == '1' || reg[j] == '1') reg[i] = '1';
					else if (reg[i] == '0' && reg[j] == '0') reg[i] = '0';
					else reg[i] = '?';
				} else if (instr == "AND") {
					if (reg[i] == '0' || reg[j] == '0') reg[i] = '0';
					else if (reg[i] == '1' && reg[j] == '1') reg[i] = '1';
					else reg[i] = '?';
				}
			}
		}
		reverse(begin(reg), end(reg));
		cout << reg << '\n';
	}
}
