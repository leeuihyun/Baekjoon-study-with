#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[10000] = {
    0,
};
int dp[10000];
int result = 0;

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
    dp[1] = A[0] + A[1];
    dp[2] = max({A[0] + A[2], A[1] + A[2], A[0] + A[1]});
    result = dp[2];
    for (int i = 3; i < N; i++)
    {
        dp[i] = max({dp[i - 3] + A[i - 1] + A[i], dp[i - 2] + A[i], dp[i - 1]});
        if (result < dp[i])
            result = dp[i];
    }

    cout << result;

    return 0;
}