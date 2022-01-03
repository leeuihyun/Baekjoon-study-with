#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int M, N;

vector<int> A;

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

	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		if (i == 1)
			continue;
		if (isPrimeNumber(i))
			A.push_back(i);
	}

	for (int i = 0; i < A.size(); i++)
		cout << A.at(i) << "\n";

	return 0;
}