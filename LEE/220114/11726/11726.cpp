#include <iostream>

using namespace std;

int dp[1001];

int main() {
	int number;
	scanf("%d", &number);
	dp[1] = 1;
	dp[2] = 2;
	if (number > 2) {
		for (int i = 3; i <= number; i++) {
			dp[i] = (dp[i-1]%10007+dp[i-2]%10007) % 10007;
		}
	}
	printf("%d", dp[number]);
	return 0;
}