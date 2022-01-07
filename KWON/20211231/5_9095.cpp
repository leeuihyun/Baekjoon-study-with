#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int N, S;

vector<pair<int, int>> A;

void numSum(int data, int sum, int index) {
	sum += data;

	if (data > 3)
		return;

	if (sum == A.at(index).first)
		A.at(index).second++;
	else if (sum > A.at(index).first)
		return;

	numSum(1, sum, index);
	numSum(2, sum, index);
	numSum(3, sum, index);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		A.push_back(make_pair(data, 0));
		numSum(1, 0, i);
		numSum(2, 0, i);
		numSum(3, 0, i);
	}

	for (int i = 0; i < N; i++) {
		cout << A.at(i).second << "\n";
	}

	return 0;
}