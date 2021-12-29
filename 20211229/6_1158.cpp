#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int A[5001] = { 0 , };

int a(int index, int k, int max) {
	for (int i = 0; i < k; i++) {
		index++;
		if (index > max)
			index = 1;
		while (A[index] == 0) {
			index++;
			if (index > max)
				index = 1;
		}
	}
	return index;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, K, sum = 0;
	
	cin >> N;
	sum = N;

	for (int i = 1; i <= N; i++) {
		A[i] = 1;
	}

	cin >> K;

	int i = K;

	cout << "<";
	for (; sum > 1; sum--) {
		A[i] = 0;
		cout << i << ", ";
		i = a(i, K, N);
	}
	for (int i = 1; i <= N; i++) {
		if (A[i] == 1) {
			cout << i << ">";
			break;
		}
	}

	return 0;
}