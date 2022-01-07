#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> A;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		A.push_back(data);
	}

	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());

	for (int i = 0; i < A.size(); i++) {
		cout << A.at(i) << " ";
	}

	return 0;
}