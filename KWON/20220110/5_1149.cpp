#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int m[1001][3] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);

	cout.tie(NULL);
	cin.tie(NULL);

	int RGB[3];

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> RGB[0] >> RGB[1] >> RGB[2];
		m[i][0] = min(m[i - 1][1], m[i - 1][2]) + RGB[0];
		m[i][1] = min(m[i - 1][0], m[i - 1][2]) + RGB[1];
		m[i][2] = min(m[i - 1][0], m[i - 1][1]) + RGB[2];
	}

	cout << min({ m[N][0], m[N][1], m[N][2] });
	
	return 0;
}