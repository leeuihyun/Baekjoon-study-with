#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct location{
	int x;
	int y;
};

vector<location> A;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		location tmp;
		cin >> tmp.x; cin >> tmp.y;
		A.push_back(tmp);
	}

	struct {
		bool operator()(location a, location b) {
			if (a.y == b.y)
				return a.x < b.x;
			else
				return a.y < b.y;
		}
	} compare;

	sort(A.begin(), A.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << A.at(i).x << " " << A.at(i).y << "\n";
	}

	return 0;
}