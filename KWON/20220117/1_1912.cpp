#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long result = 0, sum = 0;
int A[100000] = {
    0,
};
long long dp[100000] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;
        A[i] = data;
    }

    dp[0] = A[0];
    result = dp[0];

    for (int i = 1; i < N; i++)
    {
        dp[i] = A[i];
        if (dp[i] < dp[i - 1] + dp[i])
        {
            dp[i] = dp[i - 1] + dp[i];
        }
        if (result < dp[i])
        {
            result = dp[i];
        }
    }

    cout << result;

    return 0;
}