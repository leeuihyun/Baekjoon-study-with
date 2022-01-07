#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M, V;
int A[1001][1001] = { 0, };
int visited[1001] = { 0, };

void DFS(int num) {
	cout << num << " ";
	visited[num] = 1;
	for (int i = 1; i <= N; i++) {
		if (A[num][i] == 1 && !visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int num) {
	queue<int> Q;

	visited[num] = 1;
	Q.push(num);

	while (!Q.empty()) {
		cout << Q.front() << " ";
		int n = Q.front();
		Q.pop();

		for (int i = 1; i <= N; i++) {
			if (A[n][i] == 1 && !visited[i]) {
				Q.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int row, col;
		cin >> row >> col;
		A[row][col] = 1;
		A[col][row] = 1;
	}

	DFS(V);
	for (int i = 0; i <= N; i++)
		visited[i] = 0;
	cout << "\n";
	BFS(V);

	return 0;
}