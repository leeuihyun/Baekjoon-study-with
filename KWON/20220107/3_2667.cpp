#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int N, M, cnt, area = 0;
int A[25][25] = { 0, };
int visited[25][25] = {0,};
vector<int> cntArr;

void DFS(int x, int y) {
	if (x - 1 >= 0 && A[x - 1][y] == 1 && visited[x - 1][y] == 0) {
		cnt++;
		visited[x - 1][y] = 1;
		DFS(x - 1, y);
	}
	if (x + 1 < N && A[x + 1][y] == 1 && visited[x + 1][y] == 0) {
		cnt++;
		visited[x + 1][y] = 1;
		DFS(x + 1, y);
	}
	if (y - 1 >= 0 && A[x][y - 1] == 1 && visited[x][y - 1] == 0) {
		cnt++;
		visited[x][y - 1] = 1;
		DFS(x, y - 1);
	}
	if (y + 1 < N && A[x][y + 1] == 1 && visited[x][y + 1] == 0) {
		cnt++;
		visited[x][y + 1] = 1;
		DFS(x, y + 1);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			A[i][j] = (int)tmp[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 1 && visited[i][j] == 0) {
				cnt = 1;
				visited[i][j] = 1;
				DFS(i, j);
				area++;
				cntArr.push_back(cnt);
			}
		}
	}
	sort(cntArr.begin(), cntArr.end());

	cout << area << "\n";
	for (int i = 0; i < cntArr.size(); i++)
		cout << cntArr[i] << "\n";

	return 0;
}