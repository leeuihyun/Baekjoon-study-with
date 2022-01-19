#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, K;
vector<ll> L;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;
    ll line;

    for (int i = 0; i < K; i++)
    {
        cin >> line;
        L.push_back(line);
    }

    ll result = 0, mid = 0, left = 1, right = *max_element(L.begin(), L.end());
    int cnt = 0;

    while (left <= right)
    {
        mid = (left + right) / 2;
        cnt = 0;
        for (int i = 0; i < K; i++)
        {
            if (mid == 0)
                continue;
            cnt += L[i] / mid;
        }
        if (cnt < N)
            right = mid - 1;
        else
        {
            left = mid + 1;
            if (result < mid)
                result = mid;
        }
    }

    cout << result;

    return 0;
}