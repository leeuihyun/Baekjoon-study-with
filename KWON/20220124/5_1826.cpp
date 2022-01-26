#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, cnt = 0;
vector<pair<int, int>> gs;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    int L, P;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        gs.push_back({a, b});
    }
    sort(gs.begin(), gs.end());
    cin >> L >> P;

    int cur_P = P;
    int index = 0;

    while (cur_P < L)
    {
        while (gs[index].first <= cur_P && index < N)
        {
            pq.push(gs[index++].second);
        }
        if (pq.empty())
        {
            cnt = -1;
            break;
        }

        cur_P += pq.top();
        pq.pop();
        cnt++;
    }

    cout << cnt;

    return 0;
}