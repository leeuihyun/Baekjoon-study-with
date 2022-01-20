#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> rope;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    int data, w = 0, k = N;

    for (int i = 0; i < N; i++)
    {
        cin >> data;
        rope.push_back(data);
    }

    sort(rope.begin(), rope.end());

    w = rope[0] * k;
    k--;

    for (int i = 1; i < N; i++)
    {
        if (w < rope[i] * k)
            w = rope[i] * k;
        k--;
    }

    cout << w;

    return 0;
}