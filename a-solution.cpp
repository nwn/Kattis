// Include a GCC-specific header that includes the whole standard library.
#include <bits/stdc++.h>
using namespace std;

constexpr double PI = acos(-1.0);

int main() {
	// Speed up I/O by disabling synchronization with C stdio and between cin and cout.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Read input
	int M, N;
	double R;
	cin >> M >> N >> R;
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;

	// Implement your solution here
	double min_dist = 1.0e10;
	for (int i = 0; i <= min(ay, by); ++i) {
		double radial_dist = R * (ay - i + by - i) / N;
		double angular_dist = PI * abs(ax - bx) / M * R * i / N;

		min_dist = min(min_dist, radial_dist + angular_dist);
	}

	cout.precision(15);
	cout << min_dist << '\n';
}
