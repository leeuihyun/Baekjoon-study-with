#include <iostream>
#include <vector>
#include <algorithm>
typedef unsigned long long int ull;
using namespace std;

int N, index;
vector<pair<ull, ull>> A;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ull start, end, count = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;
        A.push_back({start, end});
    }

    struct
    {
        bool operator()(pair<ull, ull> a, pair<ull, ull> b)
        {
            if (a.second != b.second)
                return a.second < b.second;
            else
                return a.first < b.first;
        }
    } compare;

    sort(A.begin(), A.end(), compare);

    index = 0;
    count++;

    for (int i = 1; i < A.size(); i++)
    {
        if (A[i].first < A[index].second)
            continue;
        count++;
        index = i;
    }

    cout << count;

    return 0;
}