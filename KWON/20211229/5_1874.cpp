#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int A[100001] = { 0, };
int B[100001] = { 0, };
int stack[100001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, data;
	int top = -1;
	int A_index = 0, B_index = 0;
	string result = "";

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> data;
		A[i] = data;
		B[i] = data;
	}

	sort(B, B + n);

	stack[++top] = B[B_index];
	result += "+";
	while (A_index < n - 1) {
		if (stack[top] == A[A_index]) {
			top--;
			A_index++;
			result += "-";
		}
		else if (B_index < n - 1) {
			stack[++top] = B[++B_index];
			result += "+";
		}
		if (stack[top] > A[A_index]) {
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < result.length(); i++)
		cout << result[i] << "\n";

	return 0;
}