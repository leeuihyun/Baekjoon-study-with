#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
vector<pair<int, int>> house, chicken;
bool visited[100] = { false, };
int result = 2147483647;

void chicken_distance(int idx, int count) {
	if (count == M) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int min = 2147483647;
			for (int j = 0; j < chicken.size(); j++) {
				if (visited[j]) {
					int distance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
					if (min > distance)
						min = distance;
				}
			}
			sum += min;
		}
		if (result > sum)
			result = sum;

		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			chicken_distance(i + 1, count + 1);
			visited[i] = false;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int count = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int data;
			cin >> data;
			if (data == 0) continue;
			else if (data == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (data == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	chicken_distance(0, 0);

	cout << result;

	return 0;
}