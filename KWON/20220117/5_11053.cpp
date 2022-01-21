#include <iostream>
#include <algorithm>
using namespace std;

int N, result = 0;
int A[1001] = {
    0,
};
int dp[1001] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    int data;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        A[i] = data;
    }

    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[j] < A[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        result = max(result, dp[i]);
    }

    cout << result;

    return 0;
}