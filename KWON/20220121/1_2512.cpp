#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> A;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int budget;

    for (int i = 0; i < N; i++)
    {
        cin >> budget;
        A.push_back(budget);
    }

    cin >> M;

    int left = 1, right = *max_element(A.begin(), A.end());
    int mid = 0, result = 0, sum = 0, data = 0;

    while (left <= right)
    {
        sum = 0;
        mid = (left + right) / 2;

        for (int i = 0; i < N; i++)
        {
            data = A[i];
            if (data > mid)
                data = mid;

            sum += data;
        }

        if (sum > M)
            right = mid - 1;
        else
        {
            if (result < mid)
                result = mid;
            left = mid + 1;
        }
    }

    cout << result;

    return 0;
}