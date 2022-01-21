#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int A[501][501] = { 0, };
int m[501][501] = { 0, };

void triangle(int index) {
	while (index > 1) {
		for (int i = 1; i <= index; i++)
			m[index][i] = A[index][i] + max(m[index + 1][i], m[index + 1][i + 1]);

		index -= 1;
	}

	if (index == 1)
	{
		m[1][1] = A[1][1] + max(m[2][1], m[2][2]);
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			int data;
			cin >> data;
			A[i][j] = data;
		}
	}

	for (int i = 1; i <= N; i++)
		m[N][i] = A[N][i];

	triangle(N - 1);

	cout << m[1][1];

	return 0;
}