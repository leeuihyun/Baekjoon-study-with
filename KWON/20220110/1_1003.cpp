#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int T, N;
size_t cnt_zero, cnt_one;
pair<size_t, size_t> memoization[41] = { {0,0}, };

pair<size_t, size_t> fibonacci(int n) {
	if (n == 0) {
		return memoization[n] = { 1,0 };
	}
	else if (n == 1) {
		return memoization[n] = { 0,1 };
	}
	else {
		if (memoization[n].first || memoization[n].second)
			return { memoization[n].first,memoization[n].second };
		else {
			pair<size_t, size_t> tmp1, tmp2;
			tmp1 = fibonacci(n - 1);
			tmp2 = fibonacci(n - 2);
			tmp1.first += tmp2.first;
			tmp1.second += tmp2.second;
			return memoization[n] = { tmp1.first,tmp1.second };
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cnt_zero = cnt_one = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		fibonacci(N);
		cout << memoization[N].first << " " << memoization[N].second << "\n";
	}

	return 0;
}