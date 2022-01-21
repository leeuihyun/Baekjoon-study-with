#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C;
vector<int> x;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> C;
    int location;

    for (int i = 0; i < N; i++)
    {
        cin >> location;
        x.push_back(location);
    }

    sort(x.begin(), x.end());

    int left = 1, right = x.back() - 1;
    int mid = 0, cnt = 0, x_index = 0, result = 0;

    while (left <= right)
    {
        mid = (left + right) / 2;
        cnt = 1;
        x_index = 0;

        for (int i = 1; i < N; i++)
        {
            if (x[i] - x[x_index] >= mid)
            {
                x_index = i;
                cnt++;
            }
        }

        if (cnt >= C)
        {
            if (result < mid)
                result = mid;
            left = mid + 1;
        }
        else if (cnt < C)
            right = mid - 1;
    }

    cout << result;

    return 0;
}