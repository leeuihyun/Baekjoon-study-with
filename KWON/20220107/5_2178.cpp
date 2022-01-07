#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
string input;
int cnt = 0;
int A[100][100] = { 0, };
int visited[100][100] = { 0, };
int distanceArr[100][100] = { 0, };
queue<pair<int, int>> q;

bool rcChk(int r, int c) {
	if (r < 0 || c < 0 || r >= N || c >= M || visited[r][c] || A[r][c] == 0)
		return false;
	return true;
}

void BFS() {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		if (rcChk(r, c - 1)) {
			distanceArr[r][c - 1] = distanceArr[r][c] + 1;
			visited[r][c - 1] = 1;
			q.push({ r, c - 1 });
		}
		if (rcChk(r + 1, c)) {
			distanceArr[r + 1][c] = distanceArr[r][c] + 1;
			visited[r + 1][c] = 1;
			q.push({ r + 1, c });
		}
		if (rcChk(r, c + 1)) {
			distanceArr[r][c + 1] = distanceArr[r][c] + 1;
			visited[r][c + 1] = 1;
			q.push({ r, c + 1 });
		}
		if (rcChk(r - 1, c)) {
			distanceArr[r - 1][c] = distanceArr[r][c] + 1;
			visited[r - 1][c] = 1;
			q.push({ r - 1, c });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			A[i][j] = (int)input[j] - '0';
		}
	}

	q.push({ 0,0 });
	distanceArr[0][0] = 1;
	visited[0][0] = 1;
	BFS();

	cout << distanceArr[N - 1][M - 1];

	return 0;
}