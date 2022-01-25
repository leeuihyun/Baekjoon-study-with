#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, K;
ll result = 0;
vector<pair<ll, ll>> jewel;
vector<int> bag;
priority_queue<ll> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> K;

    ll M, V;
    int w;

    for (int i = 0; i < N; i++)
    {
        cin >> M >> V;
        jewel.push_back({M, V});
    }
    sort(jewel.begin(), jewel.end());

    for (int i = 0; i < K; i++)
    {
        cin >> w;
        bag.push_back(w);
    }
    sort(bag.begin(), bag.end());

    int j = 0;
    for (int i = 0; i < K; i++)
    {
        for (j; j < N; j++)
        {
            if (bag[i] < jewel[j].first)
                break;
            q.push(jewel[j].second);
        }

        if (q.empty())
            continue;
        result += q.top();
        q.pop();
    }

    cout << result;

    return 0;
}