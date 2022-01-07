#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int cnt = 0, result = 100000;
int visited[100000] = { 0, };
queue<pair<int, int>> q;

void BFS() {
	while (!q.empty()) {
		int data = q.front().first;
		int n = q.front().second;
		q.pop();

		if (data == K) {
			cnt = n;
			break;
		}

		if (data - 1 >= 0)
			if (visited[data - 1] == 0) {
				visited[data - 1] = 1;
				q.push(make_pair(data - 1, n + 1));
			}
		if (data + 1 <= 100000) 
			if (visited[data + 1] == 0) {
				visited[data + 1] = 1;
				q.push(make_pair(data + 1, n + 1));
			}
		if (data * 2 <= 100000)
			if (visited[data * 2] == 0) {
				visited[data * 2] = 1;
				q.push(make_pair(data * 2, n + 1));
			}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> K;

	visited[N] = 1;
	q.push(make_pair(N, 0));
	BFS();

	cout << cnt;

	return 0;
}