#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
int S[20][20];
bool visited[20];
int result = 2147483647;

void abc(int idx, int count) {
	if (count == N / 2) {
		int start = 0, link = 0;
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (i == j) continue;
				if (visited[i] && visited[j])
					start += S[i][j] + S[j][i];
				else if (!visited[i] && !visited[j])
					link += S[i][j] + S[j][i];
			}
		}
		if (result > abs(start - link))
			result = abs(start - link);

		return;
	}
	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			abc(i + 1, count + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int count = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int data;
			cin >> data;
			S[i][j] = data;
		}
	}

	abc(0, 0);

	cout << result;

	return 0;
}