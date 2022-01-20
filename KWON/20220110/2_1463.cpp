#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int T, N;
int memoization[1000001] = { 0, };
int result = 1000000;

int f(int n, int cnt) {
	if (n == 1) {
		if (result > cnt) {
			result = cnt;
			memoization[n] = result;
		}
	}
	if (n % 3 == 0) {
		if (memoization[n / 3] && cnt + 1 >= result)
			memoization[n] = memoization[n / 3];
		else 
			memoization[n / 3] = f(n / 3, cnt + 1);
	}
	if (n % 2 == 0) {
		if (memoization[n / 2] && cnt + 1 >= result)
			memoization[n] = memoization[n / 2];
		else
			memoization[n / 2] = f(n / 2, cnt + 1);
	}
	if (n > 1) {
		if (memoization[n - 1] && cnt + 1 >= result)
			memoization[n] =  memoization[n - 1];
		else
			memoization[n - 1] = f(n - 1, cnt + 1);
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	cout << f(N, 0);

	return 0;
}