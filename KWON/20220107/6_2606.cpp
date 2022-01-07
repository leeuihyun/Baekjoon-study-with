#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int C[101][101] = { 0, };
int visited[101] = { 0, };
int cnt = 0;

void DFS(int num) {
	visited[num] = 1;
	cnt++;

	for (int i = 1; i <= N; i++)
		if (C[num][i] == 1 && visited[i] == 0)
			DFS(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;
	/*
	cin >> N;
	cin >> M; 으로 했는데 틀렸음;;
	*/

	for (int i = 0; i < M; i++) {
		int n, m;
		cin >> n >> m;
		C[n][m] = C[m][n] = 1;
	}

	DFS(1);

	cout << cnt - 1;

	return 0;
}