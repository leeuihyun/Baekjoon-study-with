#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> T;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M;
    int H;

    for (int i = 1; i <= N; i++)
    {
        cin >> H;
        T.push_back(H);
    }

    long long sum;
    int result = 0, mid = 0, left = 0, right = *max_element(T.begin(), T.end());
    while (right >= left)
    {
        sum = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < N; i++)
        {
            if (T[i] < mid)
                continue;
            sum += (T[i] - mid);
        }
        if (sum >= M)
        {
            if (result < mid)
                result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << result;

    return 0;
}