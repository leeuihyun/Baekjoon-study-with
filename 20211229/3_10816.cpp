#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int A[500000], B[500000];

int lower_bound(int start, int end, int target) {
	int l = start;
	int r = end - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (A[mid] >= target)
			r = mid;
		else
			l = mid + 1;
	}

	return r;
}
int upper_bound(int start, int end, int target) {
	int l = start;
	int r = end - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (A[mid] > target)
			r = mid;
		else
			l = mid + 1;
	}

	if (A[r] == target)
		return r + 1;
	else
		return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A[i] = num;
	}
	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		B[i] = upper_bound(0, N, num) - lower_bound(0, N, num);
	}

	for (int i = 0; i < M; i++)
		cout << B[i] << " ";

	return 0;
}