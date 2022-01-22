#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int answer;

int n, c;
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        v.push_back(number);
    }
    sort(v.begin(), v.end());
    int left = 1;
    int right = v.back() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int current = 0;
        int sum = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i] - v[current] >= mid)
            {
                current = i;
                sum++;
            }
        }
        if (sum >= c)
        {
            answer = max(answer, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << answer;
    return 0;
}