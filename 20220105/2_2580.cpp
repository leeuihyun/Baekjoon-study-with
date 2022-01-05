#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int cnt = 0;
int A[9][9] = { 0, };
vector<pair<int, int>> blank;
bool flag = false;

bool check(pair<int, int> p) {
	int start_r, start_c;
	start_r = p.first / 3;
	start_c = p.second / 3;

	for (int i = 0; i < 9; i++) {
		if (A[p.first][i] == A[p.first][p.second] && i != p.second)
			return false;
		if (A[i][p.second] == A[p.first][p.second] && i != p.first)
			return false;
	}
	for (int i = start_r * 3; i < start_r * 3 + 3; i++) {
		for (int j = start_c * 3; j < start_c * 3 + 3; j++) {
			if (A[i][j] == A[p.first][p.second]) {
				if (i != p.first && j != p.second)
					return false;
			}
		}
	}

	return true;
}
void sudoku(int n) {
	if (flag)
		return;

	if (n == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << A[i][j] << " ";
			}
			cout << "\n";
		}
		flag = true;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		A[blank[n].first][blank[n].second] = i;
		if (!flag && check(blank[n]))
			sudoku(n + 1);
	}

	A[blank[n].first][blank[n].second] = 0;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	pair<int, int> tmp;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> A[i][j];
			if (A[i][j] == 0) {
				cnt++;
				tmp.first = i;
				tmp.second = j;
				blank.push_back(tmp);
			}
		}
	}

	cout << "\n\n";

	sudoku(0);

	return 0;
}