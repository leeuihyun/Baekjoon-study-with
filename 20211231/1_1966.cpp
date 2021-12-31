#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int T, N, M;

struct priority_Q {
	queue<int> q;
	vector<int> p;
};

vector<priority_Q> A;
vector<int> result;

int printer_Q(int doc, int max, priority_Q Q) {
	int count = 1;
	while (1) {
		if ((Q.p).front() < max) {
			(Q.q).push((Q.q).front());
			(Q.p).push_back((Q.p).front());
			(Q.q).pop();
			(Q.p).erase((Q.p).begin());
		}
		else {
			if ((Q.q).front() == doc) {
				break;
			}
			(Q.q).pop();
			(Q.p).erase((Q.p).begin());
			max = (Q.p).front();
			for (int i = 0; i < (Q.q).size(); i++)
				if (max < (Q.p).at(i))
					max = (Q.p).at(i);
			count++;
		}
	}

	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		int priority = 0, max = 0;
		priority_Q tmp;
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> priority;
			if (max < priority)
				max = priority;
			(tmp.p).push_back(priority);
			(tmp.q).push(j);
		}
		A.push_back(tmp);
		int count = printer_Q(M, max, A.at(i));
		result.push_back(count);
	}

	for (int i = 0; i < T; i++)
		cout << result.at(i) << "\n";

	return 0;
}