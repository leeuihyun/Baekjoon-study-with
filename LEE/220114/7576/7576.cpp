#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[1001][1001];
bool number_check = false;
bool visited[1001][1001];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

queue <pair<pair<int, int>, int>> q;
int cnt;
void solve() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (arr[nx][ny] == 0 && !visited[nx][ny]) {
				arr[nx][ny] = 1;
				visited[nx][ny] = true;
				q.push(make_pair(make_pair(nx, ny), cnt + 1));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				visited[i][j] = true;
				q.push(make_pair(make_pair(i, j), 0));
			}
			else number_check = true;   
		}
	}
	if (!number_check) {
		cout << "0";
		return 0;
	}
	else {
		solve();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 0) {
					cout << "-1";
					return 0;
				}
			}
		}
		cout << cnt;
	}


	return 0;
}