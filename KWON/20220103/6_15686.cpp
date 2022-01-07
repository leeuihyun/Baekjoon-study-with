#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> sequence;

void good_sequence() {
	int cnt = 3;

	for (int i = 2; i < N; i++) {
		if (cnt % 2 == 0) {
			if (sequence.at(i - 2) == 2)
				sequence.push_back(3);
			else if (sequence.at(i - 2) == 3)
				sequence.push_back(2);
		}
		else
			sequence.push_back(1);

		cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int count = 0;

	cin >> N;

	if (N == 1)
		sequence.push_back(1);
	else if (N == 2) {
		sequence.push_back(1);
		sequence.push_back(2);
	}
	else if (N > 2) {
		good_sequence();
	}

	for (int i = 0; i < N; i++)
		cout << sequence.at(i);

	return 0;
}