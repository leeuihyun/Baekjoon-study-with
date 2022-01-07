#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int cnt = 0, i;
vector<int> primeN;

bool isPrimeNumber(int num) {
	int n = sqrt(num);
	for (int k = 2; k <= n; k++) {
		if (num % k == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	int sum = 0;
	int left = 0, right = 0;

	if (N > 1) {
		for (i = 2; i <= N; i++)
			if (isPrimeNumber(i))
				primeN.push_back(i);

		if (primeN.back() == N)
			cnt++;

		while (1) {
			if (sum <= N) {
				sum += primeN[right];
				right++;
			}
			else if (sum > N) {
				sum -= primeN[left];
				left++;
			}
			if (right == primeN.size())
				break;
			if (sum == N) {
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}