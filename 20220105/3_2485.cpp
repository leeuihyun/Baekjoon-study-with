#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int N, n, cnt = 0, i;

int A[100000];

int abc(int a, int b) {
	if (a % b == 0)
		return b;
	else
		return abc(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	cin >> A[0];
	cin >> A[1];
	n = abc(A[1] - A[0], A[1] - A[0]);

	for (i = 2; i < N; i++) {
		cin >> A[i];
		n = abc(n, A[i] - A[i - 1]);
	}

	i = 0;
	while (i < N - 1) {
		int j = 1;
		while (1) {
			if (A[i] + n * j == A[i + 1])
				break;
			else {
				cnt++;
				j++;
			}
		}
		i++;
	}

	cout << cnt;

	return 0;
}