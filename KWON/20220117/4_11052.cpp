#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int P[1001] = {
    0,
};
int dp[1001] = {
    0,
};

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int card;
        cin >> card;
        P[i] = card;
    }

    dp[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i - j] + P[j], dp[i]);
        }
    }

    cout << dp[N];

    return 0;
}