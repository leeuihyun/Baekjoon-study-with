#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int N, S;

vector<int> A;
int result = 0;

void numSum(int index, int sum) {
	if (index >= N)
		return;

	sum += A.at(index);
	
	/*
	if(sum > S)
		return;
	*/

	if (sum == S)
		result++;

	numSum(index + 1, sum);
	numSum(index + 1, sum - A.at(index));
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		A.push_back(data);
	}

	numSum(0, 0);

	cout << result << "\n";

	return 0;
}