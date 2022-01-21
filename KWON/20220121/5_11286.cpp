#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

struct compare
{
    bool operator()(ll a, ll b)
    {
        if (abs(a) != abs(b))
            return abs(a) > abs(b);
        else
            return a > b;
    }
};

int N;
ll x;
priority_queue<ll, vector<ll>, compare> heap;
vector<ll> result;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x == 0)
        {
            if (heap.size() > 0)
            {
                result.push_back(heap.top());
                heap.pop();
            }
            else
                result.push_back(0);
        }
        else
            heap.push(x);
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}