#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, T;
int count = 0;
int A[50] = { 1, };

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num < 2) continue;
		A[i] = num;
	}

	sort(A, A + N);

	int result = 1;
	result = A[0] * A[N - 1];

	cout << result;

	return 0;
}