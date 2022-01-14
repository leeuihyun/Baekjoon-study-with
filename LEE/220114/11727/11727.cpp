#include <iostream>

using namespace std;
int dp[1001];

int solve(int number);
int main() {
	int n;
	cin >> n;
	printf("%d", solve(n));
	return 0;
}

int solve(int number) {
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= number; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % 10007;
	}
	return dp[number];
}