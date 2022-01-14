#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int arr[101][101];
bool visited[101][101];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int cnt = 0;
void dfs(int x, int y) {
	visited[x][y] = true;
	cnt += 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}
		if (!visited[nx][ny] && arr[nx][ny]==0) {
			dfs(nx, ny);
		}
	}
}
int main() {
	cin >> m >> n >> k;
	vector <int> v;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = a; j < c; j++) {
			for (int t = b; t < d; t++) {
				arr[j][t] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j]==0) {
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}