#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int N, T;

bool isPrimeNumber(int x) {
	int end = (int)sqrt(x);
	for (int i = 2; i <= end; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int count = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		if (data == 1)
			continue;
		if (isPrimeNumber(data))
			count++;
	}

	cout << count;

	return 0;
}