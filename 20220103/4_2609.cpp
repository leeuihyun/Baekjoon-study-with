#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;

int gcd(int a, int b) {
	if (a > b) {
		if (b == 0)
			return a;
		else
			return gcd(b, a % b);
	}
	else {
		if (a == 0)
			return b;
		else
			return gcd(a, b % a);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int count = 0;

	cin >> M >> N;

	int result = gcd(M, N);

	cout << result << "\n" << (M * N) / result;

	return 0;
}