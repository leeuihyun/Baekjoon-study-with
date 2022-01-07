#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int n, k;
bool visited[MAX];

int bfs(int n, int k) {
	queue <pair<int, int>> q;
	q.push(make_pair(n, 0));
	visited[n] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == k)return y;
		if (x + 1 < MAX && !visited[x + 1]) {
			visited[x + 1] = true;
			q.push(make_pair(x + 1, y + 1));
		}
		if (x - 1 >= 0 && !visited[x - 1]) {
			visited[x - 1] = true;
			q.push(make_pair(x - 1, y + 1));
		}
		if (x * 2 < MAX && !visited[x * 2]) {
			visited[x * 2] = true;
			q.push(make_pair(x * 2, y + 1));
		}
	}
}

int main() {
	cin >> n >> k;
	cout << bfs(n, k);
	return 0;
}