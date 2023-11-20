// Include a GCC-specific header that includes the whole standard library.
#include <bits/stdc++.h>
using namespace std;

constexpr static size_t N = 4;
using Board = array<array<int, N>, N>;

void transpose(Board& board) {
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = i + 1; j < N; ++j) {
			swap(board[i][j], board[j][i]);
		}
	}
}

void flip(Board& board) {
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < N / 2; ++j) {
			swap(board[i][j], board[i][N - j - 1]);
		}
	}
}

void transform(Board& board, int direction) {
	if (direction == 0) {
		// LEFT
	} else if (direction == 1) {
		// UP
		transpose(board);
	} else if (direction == 2) {
		// RIGHT
		flip(board);
	} else if (direction == 3) {
		// DOWN
		flip(board);
		transpose(board);
		flip(board);
	}
}

void shift_left(Board& board) {
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < N - 1; ++j) {
			// Shift past any leading zeroes
			size_t k = j;
			while (k < N && board[i][k] == 0) ++k;
			rotate(begin(board[i]) + j, begin(board[i]) + k, end(board[i]));

			// Shift past any intermediate zeroes
			k = j + 1;
			while (k < N && board[i][k] == 0) ++k;
			rotate(begin(board[i]) + j + 1, begin(board[i]) + k, end(board[i]));

			if (board[i][j] == 0) continue;

			// Merge cells
			if (board[i][j] == board[i][j + 1]) {
				board[i][j] = 0;
				rotate(board[i].begin() + j, board[i].begin() + j + 1, board[i].end());
				board[i][j] *= 2;
			}
		}
	}
}

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

	transform(board, direction);
	shift_left(board);
	transform(board, direction);

	for (const auto& row : board) {
		bool first = true;
		for (const auto& cell : row) {
			cout << (first ? "" : " ") << cell;
			first = false;
		}
		cout << '\n';
	}
}
