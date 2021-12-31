#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int N, S;

vector<int> queen;
int tmp, result = 0;

int check(int r) {
	for (int j = 0; j < r; j++) {
		if ((queen[j] == queen[r]) || ((r - j) == (abs(queen[j] - queen[r]))))
			return 0;
	}
	return 1;
}

void nQueen(int r) {
	if (r == N) {
		result++;
		return;
	}

	for (int i = 0; i < N; i++) {
		queen[r] = i;
		if (check(r))
			nQueen(r + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		queen.push_back(-1);

	nQueen(0);

	cout << result;

	return 0;
}